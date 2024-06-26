#include <stdio.h>
#include <stdlib.h>

#include <math.h>
#include "Questions.h"

//GO BACK AND ADD TEST CASES SNN!!!

void add_vectors(double vector1[],double vector2[],double vector3[],int size)
{
    /*vector3 should store the sum of vector1 and vector2. 
	You may assume that all three arrays have the size equal to the input parameter "size"
	
	//write your code below*/
	int dimension;
	for (dimension=0;dimension<size;dimension++)
	{
		vector3[dimension]=(vector2[dimension]+vector1[dimension]);
	}
}

double scalar_prod(double vector1[],double vector2[],int size)
{
	// this is the variable holding the scalar product of the two vectors
    double prod=0;

	//write your code below to calculate the prod value
	int dimension;
	for (dimension=0;dimension<size;dimension++)
	{
		prod+=(vector1[dimension]*vector2[dimension]);
	}
	// return the result
    return prod;
}

double norm2(double vector1[], int size)
{
	//this is the variable holding the L2 norm of the passed vector
    double L2;
	    
	//write your code here
	// you should call function scalar_prod().
	L2=(scalar_prod(vector1,vector1,size));
	L2=pow(L2,0.5);
	//finally, return the L2 norm 
    return L2;
}
