# Replace the color val with the rgb values it corresponds to
# color val n corresponds to line n in colors file (starting at 0)
color_val=0
while IFS= read -r line; do
    sed -i "s/color $color_val /$line /g" "points.txt"
    color_val=$((color_val+1))
done < "colors.txt"

./jgraph -P colorsort.jgr > out.ps
gs -o colorsort.jpg -sDEVICE=pngalpha -g344x551 -dLastPage=1 -c "<</Install {-133 -100 translate}>> setpagedevice" -f out.ps >tmp.txt
rm tmp.txt
