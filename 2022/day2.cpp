#include <iostream>
#include <fstream>

// part 1 - input file is in format: [ opponent move ] [ my move ]
// part 2 - input file is in format: [ opponent move ] [ game result ]

int main(int argc, char** argv){
    std::ifstream inputString;
    char game[4];
    int part1Score = 0;
    int part2Score = 0;
    int part1BasedLookupTable [3][3] = {
        { 4, 8, 3 },
        { 1, 5, 9 },
        { 7, 2, 6 }
    };
    int part2LookupTable [3][3] = {
        { 3, 4, 8 },
        { 1, 5, 9 },
        { 2, 6, 7 }
    };

    inputString.open("input-files/day2-full.txt");
    if(inputString.fail()){exit(1);}    // Handle file error

    while(inputString.get(game, 4)){
        part1Score += part1BasedLookupTable[game[0] - 'A'][game[2] - 'X'];
        part2Score += part2LookupTable[game[0] - 'A'][game[2] - 'X'];
        inputString.ignore(1);
    }

    std::cout << "part 1 score: " << part1Score << std::endl;
    std::cout << "part 2 score: " << part2Score << std::endl;
    inputString.close();
}
