#include <stdio.h>
#include <stdlib.h>
#include "Questions.h"

char **read_words(const char *input_filename, int *nPtr){
    int i;
	    // Step 1:  Open file "input_filename" in ASCII read mode
    // Step 2:  Read the first line of the text file as an integer into nPtr
    //          This is the number of valid lines in the text file containing words to be sorted
    //char **word_list;
    FILE* q2file;
    q2file=fopen(input_filename,"r");
    if (q2file == NULL)
    {
        printf("FILE NOT FOUND\n");
        return NULL;
    }
    fscanf(q2file,"%d",nPtr);
        

    // Step 3:  Allocate an array of nPtr number of char pointer under word_list
     char **word_list = (char** )malloc(*nPtr * sizeof(char*));
    if (word_list == NULL)
    {
        printf("ERROR\n");
        return NULL;
    }
     //this allocates a double array
    //the size of this double array is equal to the integer value from step 2 
    //multiplied by the size of a character pointer
    // Step 4:  Allocate an array of characters for each word under word_list; 
    //Read each line from the input file and save it in the allocated array. 
    for  (i=0;i<*nPtr;i++)
    {
        *(word_list+i) = (char*)malloc(20 * sizeof(char));
        fscanf(q2file, "%s", *(word_list+i));
    }
    // Step 5:  Close the file handle
    // Step 6:  (for debugging purpose) Print out the contents in the string array
    //          This is for your own confirmation.  Remove this printing code before submission.
    fclose(q2file);
    return word_list;

}
void swap(char **str1, char **str2) {
    char *temp = *str1;
    *str1 = *str2;
    *str2 = temp;
}


void delete_wordlist(char **word_list, int size)
{
    int i;
    for (i=0;i<size;i++)
		{
			if (word_list[i]!=NULL)
            {
			free(word_list[i]);
            }
		}
		free(word_list);
    //probably similar to how you deallocated memory in the test cases
    /*This is a helper function that you MUST IMPLEMENT and CALL at the end of every test case*/
    //THINK ABOUT WHY!!!
    // Hint: Review how to deallocate 2D array on heap.  word_list is a 2D array of chars on heap.
    
}

void sort_words_Bubble(char **words, int size)
{
    int i;
    int flag = 0;
    if (size==1||size==0)
    {
        return;
    }
    while (flag == 0) 
    {
        flag = 1;
        for (i = 0; i < (size - 1); i++) 
        {
            if (my_strcmpOrder(*(words+i), *(words+i+1)) == 1)//this is a question 1 function
            {
                swap((words+i), (words+i+1));
                flag = 0;
            }
        }
    }
}
void sort_words_Selection(char **words, int size){

    // This implementation of string-sorting function using Selection Sort contains 2 semantic bugs

    // Fix the code, and document how you've found the bugs using GNU debugger.
    // Take screenshots of the debugger output at the instance where you've determined every bug.

    // You will be tested again at the cross exam.

    // If you forgot how Selection Sort works, review Lab 2 document.

    int i, j;    
    int min, minIndex;
    
    for(i = 0; i < size; i++)
    {
        minIndex = i;

        for(j = i + 1; j < size; j++)
        {
            if(my_strcmpOrder(words[minIndex], words[j]) == 1)
            {
                minIndex = j;
            }                        
        }
       
        if(minIndex != i)
        {
            swap(&words[i], &words[minIndex]);
        }

    }
    
}
