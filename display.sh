cd cpp_ver
make
cd ..
rm -f img/colorsort.jpg
cat $1 | cpp_ver/bin/create_jgraph

# Replace the color val with the rgb values it corresponds to
# color val n corresponds to line n in colors file (starting at 0)
color_val=0
while IFS= read -r line; do
    sed -i "s/color $color_val /$line /g" "points.txt"
    color_val=$((color_val+1))
done < "colors.txt"


./jgraph -P colorsort.jgr > colorsort.ps
#gs -o img/colorsort.jpg -sDEVICE=pngalpha -g375x300 -dLastPage=1 -c "<</Install {-118 -530 translate}>> setpagedevice" -f colorsort.ps
gs -o img/colorsort.jpg -sDEVICE=pngalpha -dLastPage=1 -f colorsort.ps