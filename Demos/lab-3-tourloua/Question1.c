#include <stdio.h>
#include <stdlib.h>

#include "Questions.h"


int my_strlen(const char * const str1)
{
	int number_of_characters=0;
	int i;
	for (i=0;*(str1+i)!='\0';i++)
	{
		number_of_characters++;
	}
	// Returns the length of the string - the number of characters, but IGNORING the terminating NULL character
	return number_of_characters;
}

int my_strcmp(const char * const str1, const char * const str2)
{
	int i=0;
	int difference=1;
	while(*(str1+i)!='\0'&&*(str2+i)!='\0')
		{
			if(*(str1+i)!=*(str2+i))
				{
					difference=0;
					break;
				}
			i++;	
		}
	if ((*(str1+i)=='\0'&&*(str2+i)!='\0')||(*(str1+i)!='\0'&&*(str2+i)=='\0'))
		{
			difference=0;
		}
	return difference;
}


int my_strcmpOrder(const char * const str1, const char * const str2)
{
	int i=0;
	while(*(str1+i)!='\0' && *(str2+i)!='\0')
	{
		if(*(str1+i)>(*(str2+i)))
		{
			return 1;
		}
		if(*(str1+i)<(*(str2+i)))
		{
			return 0;
		}
		i++;
	}
	if(*(str1+i)=='\0' && *(str2+i)=='\0')
	{
		return -1;
	}
	if(*(str1+i)!='\0' && *(str2+i)=='\0')
	{
		return 1;
	}
	if(*(str1+i)=='\0' && *(str2+i)!='\0')
	{
		return 0;
	}

}


char *my_strcat(const char * const str1, const char * const str2){

	/* this is the pointer holding the string to return */
	char *z = NULL;
	
	/*write your implementation here*/
	int i=0;//i calculates the sum of the characters in both strings
	int j;//run of the mill indexing variable
	int first;
	int second;//#of characters in the first and second strings
	while(*(str1+i)!='\0')
	{
		i++;
	}
	first=i;
	i=0;
	while(*(str2+i)!='\0')
	{
		i++;
	}
	second=i;
	z= (char*)malloc((first+second+1)*sizeof(char));
	for(j=0;j<=first;j++)
	{
		*(z+j)=str1[j];
	}
	for(j=(first);j<(first+second);j++)
	{
		*(z+j)=str2[j-first];
	}
	*(z+first+second)='\0';
	/* finally, return the string*/
	return z;

	// IMPORTANT!!  Where did the newly allocated memory being released?
	// uhh...in the test cases?
	
} 
