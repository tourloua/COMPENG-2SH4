#include <stdio.h>
#include "MacUILib.h"


// PREPROCESSOR CONSTANTS DEFINITION HERE
/////////////////////////////////////////

// GLOBAL VARIABLE DEFINITION HERE
/////////////////////////////////////////
int i;
int exitFlag; // Program Exiting Flag - old stuff
int delay=(100000);//this program will have 5 speeds. 20 fps, 13.33 fps, 10 fps, 8 fps and 6.67 fps
float fps;
// For storing the user input - from PPA1
char input;
char PrevInput;//gets the previous input
char flipchecker;//prevents our character from doing 180 degree turns
char time;
// [TODO] : Define objPos structure here as described in the lab document
struct objPos {
    int x;
    int y;
    char symbol;
};
struct objPos player;

char output_array[210];



// FUNCTION PROTOTYPING DEFINITION HERE
/////////////////////////////////////////
void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



// MAIN PROGRAM LOOP
/////////////////////////////////////////
// This part should be intuitive by now.
// DO NOT TOUCH

int main(void)
{

    Initialize();

    while(!exitFlag)  
    {
        GetInput();

        RunLogic();

        DrawScreen();

        LoopDelay();
    }

    CleanUp();

}

// INITIALIZATION ROUTINE
/////////////////////////////////////////
void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();

    input = 0; // NULL
    exitFlag = 0;  // not exiting    
    player.x = 10;
    player.y = 5;
    player.symbol = '@';
    // [TODO] : Initialize more variables here as seen needed.
    //          PARTICULARLY for the structs!!

}

// INPUT PROCESSING ROUTINE
/////////////////////////////////////////
void GetInput(void)
{
    // [TODO] : Implement Asynchronous Input - non blocking character read-in    
    //          (Same as PPA1)

if (MacUILib_hasChar())
{
    PrevInput=MacUILib_getChar();
    time=PrevInput;
    if (
        PrevInput=='W'||PrevInput=='A'||PrevInput=='S'||PrevInput=='D'||
        PrevInput=='w'||PrevInput=='a'||PrevInput=='s'||PrevInput=='d'||PrevInput==' ')   
        {
            input=PrevInput;
        }
}
if (PrevInput=='+'&&delay>=75000&& time!=0)
{
    delay-=25000;
    time=0;
    return;
}
if (PrevInput=='-'&&delay<=125000&& time!=0)
{
    delay+=25000;
    time=0;
    return;
}
if ((flipchecker=='s'||flipchecker=='S')&&(input=='w'||input=='W'))
{
    input=flipchecker;
}
if ((flipchecker=='w'||flipchecker=='W')&&(input=='s'||input=='S'))
{
    input=flipchecker;
}
if ((flipchecker=='a'||flipchecker=='A')&&(input=='d'||input=='D'))
{
    input=flipchecker;
}
if ((flipchecker=='d'||flipchecker=='D')&&(input=='a'||input=='A'))
{
    input=flipchecker;
}
}

// PROGRAM LOGIC ROUTINE
/////////////////////////////////////////
void RunLogic(void)
{

    if(input != 0)  // if not null character
    {
        switch(input)
        {                      
            case ' ':  // exit character
                exitFlag = 1;
                break;

            case 'W':
            case 'w':
                if (player.y==1)
                player.y=9;
                player.y-=1;
                break;
            case 's':
            case 'S':
                if (player.y==8)
                player.y=0;
                player.y+=1;
                break;
            case 'A':
            case 'a':
                if (player.x==1)
                player.x=18;
                player.x-=1;
                break;
            case 'd':
            case 'D':
                if (player.x==18)
                player.x=0;
                player.x+=1;
                break;
            default:
                break;
        }
    switch(delay)
        {
            case 50000:
            fps=20;
            break;
            case 75000:
            fps=13.333333;
            break;
            case 100000:
            fps=10;
            break;
            case 125000:
            fps=8.333333;
            break;
            case 150000:
            fps=6.666667;
            break;

        }
    }
    for (i = 0; i < 200; i++) 
    {
        if (i < 20 || i >= 180 || i % 20 == 0 || i % 20 == 19) 
        {
            output_array[i] = '#';
        }
        else if (i==((player.y*20)+player.x)) 
        {
            output_array[i]=player.symbol;
        }
        else 
        {
            output_array[i] = ' ';
        }
    }
}
//Drawing Routine
/////////////////
void DrawScreen(void)
{
    int i;
    MacUILib_clearScreen();
    for (i = 0; i < 200; i++) 
    {
        MacUILib_printf("%c", output_array[i]);
        if (i % 20 == 19) 
        {
            MacUILib_printf("\n");
        }
    }
    MacUILib_printf("\n");
    flipchecker=input;
    MacUILib_printf("Press + to increase speed, - to decrease speed\n");
    MacUILib_printf("Press SPACE to exit\n");
    MacUILib_printf("%f fps",fps);

}

void LoopDelay(void)
{
    
    MacUILib_Delay(delay);    
}


void CleanUp(void)
{
    MacUILib_uninit();
}



