#include <fstream>
#include <iostream>
#include <string>

int solvePuzzle(std::ifstream& input);
int rotateDial(int dialPosition, char direction, int distance);

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
    std::string instruction;

    while (getline(input, instruction))
    {
        char direction = instruction[0];
        int distance = stoi(instruction.substr(1));

        dialPosition = rotateDial(dialPosition, direction, distance);
        std::cout << dialPosition << "\n";

        if (dialPosition == 0)
        {
            dialAtZeroCount++;
        }
    }

    return dialAtZeroCount;
}

int rotateDial(int dialPosition, char direction, int distance)
{
    const int lowerLimit = 0;
    const int upperLimit = 99;
    const int dialRange = upperLimit - lowerLimit + 1;

    if (direction == 'L')
    {
        dialPosition -= distance % dialRange;
    }
    else if (direction == 'R')
    {
        dialPosition += distance % dialRange;
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
