#include <fstream>
#include <iostream>
#include <string>

struct Solution
{
    int part1;
    int part2;
};

Solution solvePuzzle(std::ifstream& input);

int main()
{
    std::ifstream puzzleInput ("src/2025/day-02/input.txt");

    if (!puzzleInput)
    {
        std::cerr << "file not found";
        return 1;
    }

    Solution solution{ solvePuzzle(puzzleInput) };
    std::cout << "Answer to part 1: " << solution.part1 << "\n";
    std::cout << "Answer to part 2: " << solution.part2 << "\n";

    return 0;
}

Solution solvePuzzle(std::ifstream& input)
{
    return {
        0,
        0
    };
}
