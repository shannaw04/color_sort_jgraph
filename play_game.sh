#!/bin/sh

# so need to call color sort
# so should we try calling the game and see what happens

echo $1 | cpp_ver/bin/create1 > game.txt
cpp_ver/bin/play1 game.txt 
