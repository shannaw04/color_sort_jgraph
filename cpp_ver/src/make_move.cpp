#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <fstream>
#include "../include/ColorSort.hpp"
using namespace std;


int main(int argc, char *argv[]) {

    string input;        // User's input
    int from, to;        // Number of bottles moving color from and to
    string level;        // String containing level data
    ifstream input_file; // File to read input from
    ColorSort *game = new ColorSort;  // Game
    ofstream outfile;
 
    if (argc != 4){
        cerr << "Usage: " << argv[0] << " <input_file>\n";
        return -1;
    }

    from = stoi(argv[1]);
    to = stoi(argv[2]);

    input_file.open(argv[3]);
    if (input_file.fail()){
        return -1;
    }


    getline(input_file, level);
    if (level.length() < 8){
        return -1;
    }

    // Load level
    if (!game->load_level(level)){
        return -1;
    }
    input_file.close();

    if (game->make_move(from, to) == false){ 
        return -1;
    } else {
        // write updated file to output
        outfile.open(argv[3]);
        if (outfile.fail()){
            return -1;
        }
        game->print_level_data(outfile);

    }

    return 0;
}
