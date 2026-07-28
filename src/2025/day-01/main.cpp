#include <fstream>
#include <iostream>
#include <string>

struct Solution
{
    int part1;
    int part2;
};

struct Instruction
{
    char direction;
    int distance;
};

struct RotationResult
{
    int dialPosition;
    int dialPassedZeroCount;
};

Solution solvePuzzle(std::ifstream& input);
Instruction parseLine(const std::string& line);
RotationResult rotateDial(int dialPosition, const Instruction& instruction);

int main()
{
    std::ifstream puzzleInput ("src/2025/day-01/input.txt");

    if (!puzzleInput)
    {
        std::cerr << "file not found";
        return 1;
    }

    Solution solution = solvePuzzle(puzzleInput);
    std::cout << "Answer to part 1: " << solution.part1 << "\n";
    std::cout << "Answer to part 2: " << solution.part2;

    return 0;
}

Solution solvePuzzle(std::ifstream& input)
{
    int dialPosition = 50;
    int dialAtZeroCount, dialPassedZeroCount = 0;
    //int dialPassedZeroCount = 0;
    std::string line;

    while (std::getline(input, line))
    {
        Instruction instruction = parseLine(line);

        RotationResult rotationResult = rotateDial(dialPosition, instruction);
        dialPosition = rotationResult.dialPosition;

        if (dialPosition == 0)
        {
            dialAtZeroCount++;
        }

        dialPassedZeroCount += rotationResult.dialPassedZeroCount;
    }

    return {
        dialAtZeroCount,
        dialPassedZeroCount
    };
}

Instruction parseLine(const std::string& line)
{
    return {
        line[0],
        std::stoi(line.substr(1))
    };
}

RotationResult rotateDial(int dialPosition, const Instruction& instruction)
{
    const int lowerLimit = 0;
    const int upperLimit = 99;
    const int dialRange = upperLimit - lowerLimit + 1;
    int dialPassedZeroCount = 0;

    if (instruction.direction == 'R')
    {
        dialPassedZeroCount = (dialPosition + instruction.distance) / dialRange;
        dialPosition = (dialPosition + instruction.distance) % dialRange;
    }
    else if (instruction.direction == 'L')
    {
        dialPassedZeroCount = (instruction.distance + (dialRange - dialPosition) % dialRange) / dialRange;
        dialPosition = ((dialPosition - instruction.distance) % dialRange + dialRange) % dialRange;
    }

    return {
        dialPosition,
        dialPassedZeroCount
    };
}
