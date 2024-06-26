#include <stdio.h>
#include "MacUILib.h"
// PREPROCESSOR DIRECTIVE CONSTANTS
// ================================
// For program-wide constants, define them here using #define.  Add as seen needed.

#define SIZE 20

// GLOBAL VARIABLES
// ================================
int exitFlag;   // Program Exiting Flag, used to determine whether to leave the program loop and shutdown the program
char inputString[SIZE];
int i;//counter we will use to iterate through inputString when we are filling it
int k;//counter we will use when we are printing the inputString
char cmd;//variable that will hold the user input
int directionFlag;//an int that dictates the direction of printing.  1 is right to left.  0 is left to right.  Default direction is right to left(1).
int j;//counter that lets us print out the next 20 elements from k looping back
int b;
int inputFlag;//inputFlag of 0 means that nothing has been inputted. 1 means there has been an input
// Add more variables here as needed
void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);

int main(void)
{

    // Start-Up
    Initialize();

    // Program Loop
    while(!exitFlag)  //keep looping through the functions unless exit key '!' is pressed
    {
        GetInput();

        RunLogic();
        
        DrawScreen();

        LoopDelay();
    }

    // Tear-Down
    CleanUp();
    return 0;
}
void Initialize(void)
{
    // [TODO]: Call the MacUI Library Initialization Function 
    MacUILib_init();
    int z;//a counter to help with the string initialization
    inputFlag=0;
    // [TODO]: Initialize variables
    exitFlag = 0;  // 0 - do not exit, non-zero - exit the program
    inputString[0]='>';//fills the initial input string '>><<                '
    inputString[1]='>';
    inputString[2]='<';
    inputString[3]='<'; 
    for (z=4;z<SIZE;z++)
    {
        inputString[z]=' ';
    }
    
    //MacUILib_printf("It made it to initialize\n");
    i=2;//we will start adding to inputString at the third spot, just before << i.e. i=2
    k=0;//we will begin the inital printing of inputString at the very first element
    directionFlag=1;//default direction is right to left
}

void GetInput(void)
{
//MacUILib_printf("It made it to Getinput\n");

if (!MacUILib_hasChar())//i.e. if nothing has been pressed by user
{
    inputFlag=0;
    return;
}
if(MacUILib_hasChar())
{
    cmd=MacUILib_getChar();
    inputFlag=1;
    return;
}

}

void RunLogic(void)
{
if(cmd=='!')
{
    exitFlag=1;
    return;
}

if((cmd=='@')&&(inputFlag==1))//This is essentially a toggle reversing the print direction 
    {
    if (directionFlag==1)
    {
        directionFlag=0;
        return;
    }
    if (directionFlag==0)
    {
        directionFlag=1;
        return;
    }
    }
if((i<18) && (inputFlag==1))//this means the array is full.  We therefore do not add anything to inputString and just return and the main loop will just print what is already there
{
    inputString[i]=cmd;
    inputString[i+1]='<';
    inputString[i+2]='<';
    i++;
    return;
}
}

void DrawScreen(void)
{
 MacUILib_clearScreen();
MacUILib_printf("McMaster Marquee Display\n====================\n");
 for(j=0;j<SIZE;j++)
 {
    MacUILib_printf("%c",inputString[(k+j)%SIZE]);
 }
 MacUILib_printf("\n====================");
if(directionFlag==1)//we need different iteration formulas for printing in one direction vs another
{
    k=(k+1)%SIZE;
    return;
}

if(directionFlag==0)
{
    k=(k-1+SIZE)%SIZE;
    return;
}
}


void LoopDelay(void)
{
    MacUILib_Delay(100000);
}
void CleanUp(void)
{
    MacUILib_uninit();

}