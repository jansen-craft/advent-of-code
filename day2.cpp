#include <iostream>
#include <fstream>

int main(int argc, char** argv){
    std::ifstream ins;
    char game[4];
    int score1 = 0;
    int score2 = 0;
    int opp_my [3][3] = {   // lookup table for game output [ opponent move ] [ my move ]
        { 4, 8, 3 },
        { 1, 5, 9 },
        { 7, 2, 6 }
    };
    int opp_res [3][3] = {  // lookup table for game output [ opponent move ] [ game result ]
        { 3, 4, 8 },
        { 1, 5, 9 },
        { 2, 6, 7 }
    };

    ins.open("input-files/day2-full.txt");
    if(ins.fail()){exit(1);}    // Handle file error

    while(ins.get(game, 4)){
        score1 += opp_my[game[0] - 'A'][game[2] - 'X'];
        score2 += opp_res[game[0] - 'A'][game[2] - 'X'];
        ins.ignore(1);
    }

    std::cout << "score-first:  " << score1 << std::endl;
    std::cout << "score-second: " << score2 << std::endl;
}
