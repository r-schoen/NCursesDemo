//
//  triangle.cpp
//  NCursesDemo
//
//  Created by Russell Schoen on 3/14/20.
//  Copyright © 2020 Russell Schoen. All rights reserved.
//
#define ITERMAX 10000
#include "triangle.hpp"

// TODO: redundant include? 
#include <stdlib.h>
#include <curses.h>

int triangle(void) {
    long iter;
    int yi, xi;
    int y[3], x[3];
    int index;
    int maxlines, maxcols;
    
    // INITIALIZE NCURSES
    initscr();
    cbreak();
    nocbreak();
    
    clear();
    
    // INITIALIXE TRIANGLE
    
    maxlines = LINES - 1;
    maxcols = COLS - 1;

    y[0] = 0;
    x[0] = 0;

    y[1] = maxlines;
    x[1] = maxcols / 2;
    
    y[2] = 0;
    x[2] = maxcols;
    
    mvaddch(y[0], x[0], '0');
    mvaddch(y[1], x[1], '1');
    mvaddch(y[2], x[2], '2');
    
    yi = get_random_int((int)1, (int)100) % maxlines;
    xi = get_random_int((int)1, (int)100) % maxcols;
    
    mvaddch(yi, xi, '.');
    
    // INITIATE THE TRIANGLE
    for (iter = 0; iter < ITERMAX; iter++) {
        index = get_random_int((int)1, (int)100) % 3;
        
        yi = (yi + y[index]) / 2;
        xi = (xi + x[index]) / 2;
        
        mvaddch(yi, xi, '*');
        refresh();
    }
    
    mvaddstr(maxlines, 0, "Press any key to quit...");
    
    refresh();
    
    getch();
    endwin();
    
    
    exit(0);
}

int get_random_int(int from, int to) {
    return rand() % (to - from) + from;
}
