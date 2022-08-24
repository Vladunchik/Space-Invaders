#include <ncurses.h>

int x = 0;
int y = 0;
const int HEIGHT = 19; //CONST
const int WIDTH = 22; //CONST

void painting_map(int x, int y); // Painting map 1 time, because its const
void painting_spaceship(int x, int y); // Painting every tic
void painting_enemies(int x, int y); // Paintng every tic

int main (void) 
{
    initscr(); // Start ncurses
    painting_map(x, y);


    getch();
    endwin(); // End ncurses

    return 0;
}

void painting_map(int x, int y) // Painting map 1 time, because its const 
{
    for (int i = 0; i <= HEIGHT; i++) {
        for (int j = 0; j <= WIDTH; j++) {
            move (i,j); // Move cursor
            if (j == 0 || j == WIDTH) {
                printw("|"); // Print left and right borders
            } else if (i == HEIGHT) {
                printw("-"); // Print bottom borders
            }
            if (i > 10 && i < 14 && ((j > 2 && j < 6) || (j > 9 && j  < 13) || (j > 16 && j < 20))) {
                printw("X"); // Print shields
            }
        }
    }
} 
