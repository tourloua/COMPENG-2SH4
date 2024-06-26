#include <stdio.h>
#include "MacUILib.h"
#include "myStringLib.h"   // This is your first custom C library
#include <stdlib.h>
#include <time.h>
// [TODO] Import the required library for rand() and srand()
// [TODO] Import the required library for accessing the current time - for seeding random number generation
// PREPROCESSOR DIRECTIVE CONSTANTS
// ================================
// For program-wide constants, define them here using #define.  Add as seen needed.
int exitFlag; // Program Exiting Flag - old stuff
int delay=(100000);//this program will have 5 speeds. 20 fps, 13.33 fps, 10 fps, 8 fps and 6.67 fps
float fps;
// For storing the user input - from PPA1
char input;
char PrevInput;//gets the previous input
char flipchecker;//prevents our character from doing 180 degree turns
char Time;
char uniquechars[10]="McasterEC-";//the unique characters in the string "McMaster-ECE"
// [TODO] : Define objPos structure here as described in the lab document
struct objPos {
    int x;
    int y;
    char symbol;
};
struct objPos player;
struct objPos* chars;//our characters that will populate the gameboard
char output_array[200];

// [COPY AND PASTE FROM PPA2] Copy your additional preprocessor constants from PPA2 and paste them below

// [TODO] Then, define more constants here as seen needed.
int MoveCount=0;//counts the number of moves
const char goal_string[13] = "McMaster-ECE";
char* mystery_string;
const int xRange=18;
const int yRange=8;
const int listSize=5;
int victory_flag=0;//Turns to 1 once the player completes the mystery string

// GLOBAL VARIABLES
// ================================

// [COPY AND PASTE FROM PPA2] Copy your additional global from PPA2 and paste them below

// [TODO] Declare More Global Variables as seen needed.

// [TODO] Declare Global Pointers as seen needed / instructed in the manual.



// FUNCTION PROTOTYPES
// ================================
// Declare function prototypes here, so that we can organize the function implementation after the main function for code readability.

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);
void GenerateItems(struct objPos list[], const int listSize, const struct objPos *playerPos, const int xRange, const int yRange, const char* str);
// [TODO] In PPA3, you will need to implement this function to generate random items on the game board
//        to set the stage for the Scavenger Hunter game.
// list[]       The pointer to the Item Bin
// listSize     The size of the Item Bin (5 by default)
// playerPos    The pointer to the Player Object, read only.
// xRange       The maximum range for x-coordinate generation (probably the x-dimension of the gameboard?)
// yRange       The maximum range for y-coordinate generation (probably the y-dimension of the gameboard?)
// str          The pointer to the start of the Goal String (to choose the random characters from)

// MAIN PROGRAM
// ===============================
int main(void)
{
    Initialize();
    
    while(!exitFlag && !victory_flag)  
    {
        GetInput();

        RunLogic();

        DrawScreen();

        LoopDelay();
    }

    CleanUp();

}




// INITIALIZATION ROUTINE
// ===============================
void Initialize(void)
{   
    MacUILib_init();

    MacUILib_clearScreen();

    // [COPY AND PASTE FROM PPA2] Copy your initialization routine from PPA2 and paste them below
    int i=0;
    input = 0; // NULL
    player.x = 10;
    player.y = 5;
    player.symbol = '@';

    
    // [TODO] Initialize any global variables as required.
    exitFlag = 0;  // 0 - do not exit, non-zero - exit the program

    
    // [TODO] Allocated heap memory for on-demand variables as required.  Initialize them as required.
    mystery_string = (char*)malloc(13*sizeof(char));

for (i = 0; i < 12; i++)
    {
          // Assuming each pointer can point to a 2-character string
        mystery_string[i] = '?';
    }
    mystery_string[12] = '\0';
    
    chars = (struct objPos*)malloc(5 * sizeof(struct objPos));
    GenerateItems(chars, listSize, &player, xRange, yRange, goal_string);

    // [TODO] Seed the random integer generation function with current time.
    
    // [TODO] Generate the initial random items on the game board at the start of the game.
}
// INPUT COLLECTION ROUTINE
// ===============================
void GetInput(void)
{

    // Asynchronous Input - non blocking character read-in
    
    // [COPY AND PASTE FROM PPA2] Copy your input collection routine from PPA2 and paste them below
    if (MacUILib_hasChar())
{
    PrevInput=MacUILib_getChar();
    Time=PrevInput;
    if (
        PrevInput=='W'||PrevInput=='A'||PrevInput=='S'||PrevInput=='D'||
        PrevInput=='w'||PrevInput=='a'||PrevInput=='s'||PrevInput=='d'||PrevInput==' ')   
        {
            input=PrevInput;
        }
}
if (PrevInput=='+'&&delay>=75000&& Time!=0)
{
    delay-=25000;
    Time=0;
    return;
}
if (PrevInput=='-'&&delay<=125000&& Time!=0)
{
    delay+=25000;
    Time=0;
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

    // [TODO] Though optional for PPA3, you may insert any additional logic for input processing.

// MAIN LOGIC ROUTINE
// ===============================
void RunLogic(void)
{
    int i;
    int j;
    if(input != 0)  // if not null character
    {
        MoveCount++;
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
                player.x=19;
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
    for (i=0;i<5;i++)//collision detection
    {
        if (player.x== chars[i].x && player.y== chars[i].y)
        {
         
                for (j=0;j<13;j++)
                {
                    if (chars[i].symbol==goal_string[j])
                    {
                        mystery_string[j]=chars[i].symbol;
                    }
                }
                if (my_strcmp(goal_string,mystery_string)==1)
                {
                    victory_flag++;//if user completes the mystery string, we change the victory flag
                }
                else
                {
                    GenerateItems(chars, listSize, &player, xRange, yRange, goal_string);
                }
        }
    }
    for (i = 0; i < 200; i++) //we are using an array. Not like in PPA2 where we went line by line
    {
        if (i < 20 || i >= 180 || i % 20 == 0 || i % 20 == 19) 
        {
            output_array[i] = '#';
        }
        else if (i==((player.y*20)+player.x)) 
        {
            output_array[i]=player.symbol;
        }
        else if (i==((chars[0].y*20)+chars[0].x))//add the four other chars 
        {
            output_array[i]=chars[0].symbol;
        }
        else if (i==((chars[1].y*20)+chars[1].x))//add the four other chars 
        {
            output_array[i]=chars[1].symbol;
        }
        else if (i==((chars[2].y*20)+chars[2].x))//add the four other chars 
        {
            output_array[i]=chars[2].symbol;
        }
        else if (i==((chars[3].y*20)+chars[3].x))//add the four other chars 
        {
            output_array[i]=chars[3].symbol;
        }
        else if (i==((chars[4].y*20)+chars[4].x))//add the four other chars 
        {
            output_array[i]=chars[4].symbol;
        }
        else 
        {
            output_array[i] = ' ';
        }
    }
    
    return; 
}
    // [COPY AND PASTE FROM PPA2] Copy your main logic routine from PPA2 and paste them below

    // [TODO]   Implement the Object Collision logic here
    //
    //      Simple Collision Algorithm
    //      1. Go through all items on board and check their (x,y) against the player object x and y.
    //      2. If a match is found, use the ASCII symbol of the collided character, and 
    //         find all the occurrences of this ASCII symbol in the Goal String
    //      3. For every occurrence, reveal its ASCII character at the corresponding location in the
    //         Collected String
    //      4. Then, determine whether the game winning condition is met.

    // [TODO]   Implement Game Winning Check logic here
    //
    //      Game Winning Check Algorithm
    //      1. Check if the contents of the Collected String exactly matches that of the Goal String.
    //         YOU MUST USE YOUR OWN my_strcmp() function from Lab 3.
    //      2. If matched, end the game.
    //      3. Otherwise, discard the current items on the game board, and 
    //         generate a new set of random items on the board.  Game continues.
// DRAW ROUTINE
// ===============================
void DrawScreen(void)
{
    int j;//indexing variables
    MacUILib_clearScreen();
    int i;
    for (i = 0; i < 200; i++) 
    {
        MacUILib_printf("%c", output_array[i]);
        if (i % 20 == 19) 
        {
            MacUILib_printf("\n");
        }
    }
    flipchecker=input;
    MacUILib_printf("Mystery string: ");
    for (i=0;i<13;i++)
    {
        MacUILib_printf("%c",mystery_string[i]);
    }

    MacUILib_printf("\nMoves: %d\n",MoveCount);
    if(!victory_flag)
    {
        MacUILib_printf("Press + to increase speed, - to decrease speed\n");
        MacUILib_printf("Press SPACE to exit\n");
        MacUILib_printf("%f fps\n",fps);
    }
    else
    {
        MacUILib_printf("You won!");//prints the victory message
    }
}
       
    // [COPY AND PASTE FROM PPA2] Copy your draw logic routine from PPA2 and paste them below

    // [TODO]   Insert somewhere in the draw routine to draw the randomly generated items on the board.

    // [TODO]   Display the "Mystery String" contents at the bottom of the game board
    //          To help players keep track of their game progress.

// DELAY ROUTINE
// ===============================
void LoopDelay(void)
{
    
    MacUILib_Delay(delay);    
}

// TEAR-DOWN ROUTINE
// ===============================
void CleanUp(void)
{

    // Free dynamically allocated memory
    free(mystery_string);
    free(chars);

    // Uninitialize MacUILib
    MacUILib_uninit();
}

// The Item Generation Routine
////////////////////////////////////
void GenerateItems(struct objPos list[], const int listSize, const struct objPos *playerPos, const int xRange, const int yRange, const char* str)
{
    srand(time(NULL));
    int impact;
    int i = 0;
    int j = 0;
    int a;
    int b;
    int c;
    int d;
    while (i < 2)//first two randomly generated characters are from the goal string
    {
        impact = 0;
        a = rand() % xRange + 1;
        b = rand() % yRange + 1;
        c = rand() % 12;//generates a random integer for x, y and the index of the character in the goal string
        if (a == playerPos->x && b == playerPos->y)
        {//here we make sure the character isn't generated on top of our player
            impact++;//impact gets incremented whenever characters are duplicates, or they overlap
            //the player or another character
        }
        if (i > 0)
        {
            for (j = 0; j < i; j++)
            {
                if ((a == list[j].x && b == list[j].y) || str[c] == list[j].symbol)
                {//this makes sure that there are no overlapping characters
                    impact++;
                }
            }
        }
        if (impact == 0)
        {
            list[i].x = a;
            list[i].y = b;
            list[i].symbol = str[c];
            i++;
        }
    }
    while (i < 5)//generates the three random characters
    {
        impact = 0;
        a = rand() % xRange + 1;
        b = rand() % yRange + 1;
        d = (rand() % 93)+33;
        if (a == playerPos->x && b == playerPos->y)
        {
            impact++;
        }
        if (i > 2)
        {
            for (j = 0; j < i; j++)
            {
                if ((a == list[j].x && b == list[j].y) || (char)(d) == list[j].symbol||(char)(d) == '@'
                ||(char)(d) == ' '||(char)(d) == '#'||(char)(d) == 'M'||(char)(d) == 'c'
                ||(char)(d) == 'a'||(char)(d) == 's'||(char)(d) == 't'||(char)(d) == 'e'||(char)(d) == 'r'
                ||(char)(d) == '-'||(char)(d) == 'E'||(char)(d) == 'C')//the randomly generated
                //characters can't be in the goal string, #s becuase of the border, spaces, or @s
                //so as not to confuse the player
                {
                    impact++;
                }
            }
        }
        if (impact == 0)
        {
            list[i].x = a;
            list[i].y = b;
            list[i].symbol = (char)(d);
            i++;
        }
    }
    return;
}
