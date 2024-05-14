

    // // adjust y spacing depending on how many rows
    // if (rows == 3){
    //     marksize_x = 1;
    //     marksize_y = 2;
    //     y = display_y;
    // } else if (rows == 2){
    //     y_bottle_spacing = 7;
    //     marksize_x = 1.5;
    //     marksize_y = 3;
    //     y = display_y;
    // } else {
    //     y_bottle_spacing = 8;
    //     marksize_x = 1;
    //     marksize_y = 2;
    // }
    // y_bottle_spacing = display_y - (rows * (marksize_y * num_bottles)) - 2;
    
    // // adjust x spacing depending on how many cols
    // if (cols == 5){
    //     x_bottle_spacing = 2;
    //     x = 1;
    // } else if (cols == 4){
    // } else if (cols == 3){
    // } else if (cols == 2){
    //     x_bottle_spacing = (display_x - (marksize_x * cols)) / (cols + 1) + marksize_x;
    //     x_border = x_bottle_spacing + (marksize_x / 2) - marksize_x;
    // }


    // // adjust block size based on number of rows
    // // figure out bottle sizes
    // // keep blocks at 1:2 ratio
    // // keep separation under 4
    // // maximize size with sep of 4, then 3 if doesn't fit, then 2
    // // want evenly spaced from 1 10
    // (num_bottles * cols) * (marksize_x + x_bottle_spacing) == 10;

    // want evenly spaced from 1 30
    // marksize_y at least 2
    // (num_blocks * rows) * (marksize_y + y_bottle_spacing) == 30;

