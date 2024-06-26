#include <stdio.h>
#include <stdlib.h>
#include "Questions.h"


// this is the very first question without hints in the comments.  read the manual to develop your own algorithm

// Read Questions.h to understand the definition of Q3Struct

void efficient(const int source[], struct Q3Struct effVector[], int size)
//effVector is an array of data type "struct Q3Struct"
{
    int i;
    int nonzeros=0;//determines what index to add  our value-position pair to in effVectore
    for (i=0; i<size;i++)
    {
        if (source[i]!=0)
        {
            effVector[nonzeros].val=source[i];
            effVector[nonzeros].pos=i;
            nonzeros++;
        }
    }
    }
    


void reconstruct(int source[], int m, const struct Q3Struct effVector[], int n)
{
    int i;
    for (i=0;i<n;i++)
    {
        source[effVector[i].pos]=effVector[i].val;
    }
}
