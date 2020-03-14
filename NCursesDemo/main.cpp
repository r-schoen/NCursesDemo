//
//  main.cpp
//  NCursesDemo
//
//  Created by Russell Schoen <rschoen8@icloud.com> on 3/8/20.
//  Copyright © 2020 Russell Schoen. All rights reserved.
//
// the triangle function comes from here:
// https://www.linuxjournal.com/content/getting-started-ncurses
// the rest of this comes from here:
// https://www.linuxjournal.com/content/creating-adventure-game-terminal-ncurses
// TODO: Seperate the triangle game out from the adventure game 

#include <curses.h>
#include <stdlib.h>

#define ITERMAX 10000
#define GRASS ' '
#define EMPTY '.'
#define WATER '~'
#define MOUNTAIN '^'
#define PLAYER '*'


int get_random_int(int, int);
bool is_move_ok(int, int);
void draw_map(void);

int main(void) {
    int x, y, ch;
    initscr();
    keypad(stdscr, TRUE);
    cbreak();
    noecho();
    
    clear();
    
    draw_map();
    
    y = LINES - 1;
    x = 0;
    
    // nav loop
    do {
        mvaddch(y, x, PLAYER);
        move(y, x);
        refresh();
        
        ch = getch();
        switch (ch) {
            case KEY_UP:
            case 'w':
            case 'W':
                if ((y>0) && is_move_ok(y-1, x)) {
                    mvaddch(y, x, EMPTY);
                    y = y - 1;
                }
                break;
            case KEY_DOWN:
            case 's':
            case 'S':
                if ((y < LINES - 1) && is_move_ok(y + 1, x)) {
                    mvaddch(y, x, EMPTY);
                    y = y + 1;
                }
                break;
            case KEY_LEFT:
            case 'a':
            case 'A':
                if ((x > 0) && is_move_ok(y, x - 1)) {
                    mvaddch(y, x, EMPTY);
                    x = x - 1;
                }
                break;
            case KEY_RIGHT:
            case 'd':
            case 'D':
                if ((x < COLS - 1) && is_move_ok(y, x + 1)) {
                    mvaddch(y, x, EMPTY);
                    x = x + 1;
                }
                break;
        }
    } while((ch != 'q') && (ch != 'Q'));
    endwin();
    exit(0);
}

bool is_move_ok(int y, int x) {
    int testch;
    
    testch = mvinch(y, x);
    return ((testch == GRASS || testch == EMPTY));
}

void draw_map(void) {
    int y, x;
    
    for (y=0;y<LINES; y++) {
        mvhline(y, 0, GRASS, COLS);
    }
    
    for (x=COLS/2; x<COLS*3/4; x++) {
        mvvline(0, x, MOUNTAIN, LINES);
    }
    mvhline(LINES / 4, 0, GRASS, COLS);
    
    for (y=1;y<LINES / 2; y++) {
        mvhline(y, 1, WATER, COLS / 3);
    }
}
