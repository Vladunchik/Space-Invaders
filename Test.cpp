#include <ncurses.h>
#include <new>
#include <unistd.h>

int x = 5;
int y = 5;
const int HEIGHT = 19; //CONST
const int WIDTH = 22; //CONST
int time = 2;
int x_ship = 5;
int x_patron = 5;

void painting_map(int x, int y); // Painting map 1 time, because its const
void painting_spaceship(int x, int y); // Painting every tic
void painting_enemies(int x, int y); // Paintng every tic
void move_ship();
void move_patron();

int main (void) 
{
    initscr(); // Start ncurses
    curs_set(0);
    painting_map(x, y);

    for (int i = 0; i < 30; i++) {
        move_ship();
        move_patron();
        time++;
    }

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

void move_ship() 
{
    if (time % 3 == 0) {
        move(y,x_ship);
        printw("+");
        move(y, x_ship - 1);
        printw(" ");
        x_ship++;
        refresh();
        usleep(50000);
    }
}

void move_patron()
{
    if (time % 1 == 0) {
        move (y + 1, x_patron);
        printw("~");
        move(y + 1, x_patron - 1);
        printw(" ");
        x_patron++;
        refresh();
        usleep(50000);
    }
}
