#include <fstream>
#include <iostream>
#include <string>

struct Instruction
{
    char direction;
    int distance;
};

int solvePuzzle(std::ifstream& input);
Instruction parseLine(const std::string& line);
int rotateDial(int dialPosition, Instruction instruction);

int main()
{
    std::ifstream puzzleInput ("src/2025/day-01/input.txt");

    if (!puzzleInput)
    {
        std::cerr << "file not found";
        return 1;
    }

    int solution = solvePuzzle(puzzleInput);
    std::cout << "Solution: " << solution;

    return 0;
}

int solvePuzzle(std::ifstream& input)
{
    int dialPosition = 50;
    int dialAtZeroCount = 0;
    std::string line;

    while (std::getline(input, line))
    {
        Instruction instruction = parseLine(line);

        dialPosition = rotateDial(dialPosition, instruction);
        std::cout << dialPosition << "\n";

        if (dialPosition == 0)
        {
            dialAtZeroCount++;
        }
    }

    return dialAtZeroCount;
}

Instruction parseLine(const std::string& line)
{
    return {
        line[0],
        std::stoi(line.substr(1))
    };
}

int rotateDial(int dialPosition, Instruction instruction)
{
    const int lowerLimit = 0;
    const int upperLimit = 99;
    const int dialRange = upperLimit - lowerLimit + 1;

    if (instruction.direction == 'L')
    {
        dialPosition -= instruction.distance % dialRange;
    }
    else if (instruction.direction == 'R')
    {
        dialPosition += instruction.distance % dialRange;
    }

    if (dialPosition < lowerLimit)
    {
        dialPosition += dialRange;
    }
    else if (dialPosition > upperLimit)
    {
        dialPosition -= dialRange;
    }

    return dialPosition;
}
