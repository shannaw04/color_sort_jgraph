#include "../include/ColorSort.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstring>
#include <sstream>
#include <sys/wait.h>
#include <unistd.h>
using namespace std;


int main(int argc, char *argv[]){

    int i, j;

    // game info
    ColorSort *cs = new ColorSort;
    int rows;
    int cols;
    int num_blocks;
    vector <int> bottles;
    int num_bottles;
    string level_data;

    // output file for jgraph points
    ofstream jgraph_pts;

    // to create the jgraph
    double x, y;
    double display_x = 10;
    double display_y = 33;
    double x_border = 1;
    double x_bottle_spacing = 2;
    double y_bottle_spacing = 8;
    double marksize_x = 1;
    double marksize_y = 2;
    double rowsize;
    char buf[1000];
    string border_l;
    string border_r;


    // read level data from stdin and load the level
    getline(cin, level_data);
    if (cs->load_level(level_data) == false){
        cerr << "create_jgraph: Could not load level data\n";
        return -1;
    }

    rows = cs->get_rows();
    cols = cs->get_cols();
    num_blocks = cs->get_blocks();
    bottles = cs->get_bottles();
    num_bottles = cs->get_num_bottles();

    // open jgraph output file
    jgraph_pts.open("points.txt");
    if (jgraph_pts.fail()){
        cerr << "points.txt: " << strerror(errno) << endl;
        cerr << "Color Sort jpg creation failed.\n" << endl;
        return -1;
    }  


    // start with bottle 1 in upper left corner
    x = x_border;
    y = display_y;

    // generate points for one side of bottles and the blocks
    for (i = 0; i < num_bottles; i++){
        border_l = "BORDER";
        border_r = "BORDER";

        // put number above bottle
        jgraph_pts << "NUMBER " << x << " y " << y+3 << " : " << i+1 << endl;
        
        for (j = 0; j < num_blocks; j++){

            // print block
            jgraph_pts << "BLOCK color " << bottles[i*num_blocks + j] << " " << marksize_x << " " << marksize_y << " pts " << x << " " << y << endl;

            // border around the block
            // if this is top block we want border to be a little higher
            if (j == 0){
                sprintf(buf, " %lf %lf ", (x - (marksize_x / 2)), (y + 0.25 + (marksize_y / 2)));
                border_l += buf;
                sprintf(buf, " %lf %lf ", (x + marksize_x - (marksize_x / 2)), (y+(marksize_y / 2)) + 0.25);
                border_r += buf;
                
           
            } else {
                sprintf(buf, " %lf %lf ", (x - (marksize_x / 2)), (y + 1));
                border_l += buf;
                sprintf(buf, " %lf %lf ", (x + marksize_x - (marksize_x / 2)), (y + 1));
                border_r += buf;
           } 
           y -= marksize_y;
        }
        
        // complete the side borders
        sprintf(buf, " %lf %lf ", (x - (marksize_x / 2)), (y + (marksize_y / 2)));
        border_l += buf;
        sprintf(buf, " %lf %lf ", (x + marksize_x - (marksize_x / 2)), (y + (marksize_y / 2)));
        border_r += buf;
        jgraph_pts << border_l << endl << border_r << endl;

        // bottom border
        sprintf(buf, " %lf %lf  %lf %lf  %lf %lf  %lf %lf ", (x - (marksize_x / 2)), (y+ (marksize_y / 2)), (x - .25), y, (x + .25), y, (x+(marksize_x / 2)), (y + (marksize_y / 2)));
        jgraph_pts << "BOTTOM color " << bottles[i*num_blocks + (j-1)] << " pts" << buf << endl;
 
         rowsize = (marksize_y * num_blocks) + y_bottle_spacing;
         y = display_y - ( ( (i+1) / cols) * rowsize);

         // move to next row
         if ((i+1) % cols == 0){
            x = x_border;
            // moving to next column on same row
         } else {
             x += x_bottle_spacing;                                               
         }
    }

    jgraph_pts.close();
    return 0;

}
