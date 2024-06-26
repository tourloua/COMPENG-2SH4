#include <stdio.h>
#include "Questions.h"

int Q1_for(int num){
	int sum=0;
	int i;
	// calculate your sum below..this has to use for loop
	for (i = num; i <= 1000; i++) {
        	if (i % num == 0) {
            	sum += i;
        	}
    	}
	// here, we return the calcualted sum:
	return sum;
}
int Q1_while(int num){
	int sum=0;
	int i;
    i=num;
	// calculate your sum below..this has to use while loop
	while (i <= 1000) {
        	if (i % num == 0) {
            	sum += i;
        	}
            i++;
    	}
	// here, we return the calcualted sum:
	return sum;
}
int Q1_dowhile(int num){
	int sum=0;
	int i;
    i=num;
	// calculate your sum below..this has to use do-while loop
	do
    {
        if (i%num==0)
        {
            sum+=i;
        }
        i++;
    } while (i<=1000);
	// here, we return the calcualted sum:
	return sum;
}
//===============================================================================================
int Q2_FPN(float Q2_input, float Q2_threshold){
	int result;
	// Determine which range does Q2_input fall into.  Keep in mind the floating point number range.
	// Assign the correct output to the result.
    if(Q2_input>=(-2*Q2_threshold) && Q2_input<(-1*Q2_threshold))
    {
        result= 0;
    }
    else if(Q2_input>=(-1*Q2_threshold) && Q2_input<0)
    {
        result= 1;
    }
    else if(Q2_input>=0 && Q2_input<(1*Q2_threshold))
    {
        result= 2;
    }
    else if(Q2_input>=(Q2_threshold) && Q2_input<=(2*Q2_threshold))
    {
        result= 3;
    }
	else
    {
        result=-999;
    }            
	// Finally, return the result.
	return result;
}
//===============================================================================================
int Q3(int Q3_input, int perfect[]){
		if (Q3_input<0)
	{
		return 0;
	}
	int i;//index variable
	int smaller_than[Q3_input];
	int current_val;
	int j;//another index variable
	int sum;
	int counts=0;
	for (i=1;i<=Q3_input;i++)
	{
		smaller_than[i-1]=i;//every integer <= Q3_input and greater than 0
		//gets appended to the array smaller_than
	}
	for (i=0;i<=(Q3_input-1);i++)
	{
		current_val=smaller_than[i];//current_val represents each number<=Q3_input
		sum=0;//resets the sum of the factors
		for (j=1;j<current_val;j++)//takes the sum of each factor smaller than current_val
		{
			if (current_val%j==0)
			{
				sum+=j;
			}
		}
		if (sum==current_val)
		{
			counts+=1;//adds 1 to the varible that counts the number of perfect numbers
			//<=> Q3_input
			perfect[counts-1]=current_val;//adds each perfect number to the array perfect
		}
	}
	return counts;
}
//===============================================================================================
int Q4_Bubble(int array[], int size){
	int i;
	// This variable tracks the number of passes done on the array to sort the array.
	int passes = 1;
    int placeholder;
    int changed=0;
    int flag=0;
    int second_flag=0;
    while (flag==0)
    {
        second_flag=0;
        for (i=0;i<(size-1);i++)
        {
            if (array[i]>array[i+1])
                {
                    placeholder=array[i];
                    array[i]=array[i+1];
                    array[i+1]=placeholder;
                    changed=1;
                }
            if (i==(size-2) && changed==1)
            {
                passes+=1;
                changed=0;
            }
        }
        for (i=0;i<(size-1);i++)
            {
                if (array[i]>array[i+1])
                    {
                        second_flag=1;
                    }
            }
        if (second_flag==0)
        {
            flag=1;
        }
    }
    return passes;
}
//make then Lab1.exe