//Yay
//License: Copyleft.
/*Additional disclaimer: I claim no responsibility for
 *anything that may happen because of this application or any part of it in any way.
 *I really doubt there are any confetti risks here,
 *but if there are, you agree to take those risks of your own volition.
 *Make sure not to choke on the confetti; it'd be a really lame way to die.
 */
//- Kirbykirby56

#include<iostream>
#include<vector>
#include<unistd.h>
#include<sys/ioctl.h>

using namespace std;

vector<vector<char>>grid;
int probabilitySpace = 5;

void genConfetti(short X, short Y) {
//Add our confetti characters
char acceptableChars[7] = {'*', '~', '/', '|', '\\', ',', '.'};
//Start building the grid
for(int iY = 0; iY < Y; iY++) {
//Resize the grid so that we don't get SIGSEGV
grid[iY].resize(X);
//If we generate a rand number under probabilitySpace, we write a confetti character, else a space.
for(int iX = 0; iX < X; iX++) grid[iY][iX] = rand() % 100 < probabilitySpace ? acceptableChars[rand() % 7] : ' ';
    }
}

//Main function, one argument: probabilitySpace(0-100)
int main(int argc, char *argv[]) {
bool confettiOnly = false;
//Get the console window's size- we want to fill it with confetti
struct winsize siz;
//This stores the info in a short name. cCX = console Characters X, cCY ditto
short cCX=0, cCY=0;
//Seed the random to time, because the same confetti every time is awfully boring.
srand(time(0));
//Get the probability of a space
if(argc > 1) probabilitySpace = atoi(argv[1]);
//Get if the user wants to not use the 'yay' that appears at the bottom
if(argc > 2) confettiOnly = atoi(argv[2]);
//Get the window's size
ioctl(STDOUT_FILENO, TIOCGWINSZ, &siz);

//Store info in cCX & cCY
cCX = siz.ws_col;
cCY = siz.ws_row;

//Resize the Y-Grid to cCY to stop from SIGSEGV
grid.resize(cCY);
//Generate the confetti
genConfetti(cCX, cCY);
//Draw the confetti
for(int i = 0; i < cCY; i++)
{
//Write the grid's info
for(int ii = 0; ii < cCX; ii++) cout << grid[i][ii];
//End the line for more epic confetti
cout << endl;

}
if (!confettiOnly) cout << "yay";
//Normal operation
return 0;
}
