#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <array>

struct Solution
{
    int part1;
    int part2;
};

Solution solvePuzzle(std::ifstream& input);
std::string getLowerAndUpper(std::string idRange);

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
    std::string idRange;

    while (std::getline(input,idRange, ','))
    {
        std::string lowerAndUpper[2] = getLowerAndUpper(idRange);

        
        std::cout << "Lower: " << lowerAndUpper[0] << "\n";
        std::cout << "Upper: " << lowerAndUpper[1] << "\n";

    }


    return {
        0,
        0
    };
}

std::array<std::string, 2> getLowerAndUpper(std::string idRange)
{
    std::stringstream ss(idRange);
    std::string lowerAndUpper[2];

    for (int i = 0; i < 2; i++)
    {
        std::getline(ss, lowerAndUpper[i], '-');
    }

    return lowerAndUpper;
}



