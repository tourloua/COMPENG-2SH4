#include <stdio.h>
#include <stdlib.h>

#include "Questions.h"

void diag_scan(int mat [][N3], int arr [])
{
//N3 is an integer denoting how many rows and columns in our square matrix
int squared=N3*N3;
int diagonal=1;//how many "diagonal passes" we have made
int row=0;//the current row number of our matrix
int column=0;//the current column number of our matrix
int arr_index=0;//the index of where we are adding to our array
arr[arr_index]=(mat[row][column]);
if (N3==1)
{
    return;//do not move the second diagonal in a 1x1 matrix!
}
diagonal++;
while (diagonal<=N3)/*the first N3 and last N3 diagonal matrices have different algorithms
for adding their entries to the array :arr"*/
{
    row=0;
    column=(diagonal-1);
    while (column>=0)
    {
        arr_index++;
        arr[arr_index]=mat[row][column];
        row++;
        column--;
    }
    diagonal++;
}
while (diagonal<(2*N3))
{
    row=(diagonal%N3);
    column=(N3-1);
    while (row!=N3)
    {
        arr_index++;
        arr[arr_index]=(mat[row][column]);
        row++;
        column--;
    }
    diagonal++;
}
}
