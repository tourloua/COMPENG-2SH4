#include <assert.h>
#include <setjmp.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "CuTest.h"
#include "Questions.h"
    


   
    
//=========Question 1==================================
	void TestQ1_strlen_case1(CuTest *tc)
	{
		char str[] = "This is a test!";
		int expected = 15;
		int actual = 0;

		actual = my_strlen(str);

		CuAssertIntEquals(tc, expected, actual);
	}
	
	void TestQ1_strlen_case2(CuTest *tc)
	{
		char str[] = "This is another test...";
		int expected = 23;
		int actual = 0;

		actual = my_strlen(str);

		CuAssertIntEquals(tc, expected, actual);
	}

	void TestQ1_strlen_case0(CuTest *tc)
	{
		char str[] = "";
		int expected = 0;
		int actual = 0;

		actual = my_strlen(str);

		CuAssertIntEquals(tc, expected, actual);
	}

	void TestQ1_navy_seal_Greek_copypasta(CuTest *tc)
	{
		char str[] = "Τι στο διάολο είπες για μένα, ρε μαλάκα;";
		int expected = 71;
		int actual = 71;

		actual = my_strlen(str);

		CuAssertIntEquals(tc, expected, actual);
	}

	void TestQ1_I_am_the_danger(CuTest *tc)
	{
		char str[] = "Who are you talking to right now? Who is it that you think you see? Do you know how much I make a year? I mean, even if I tell you, you wouldn’t believe it. Do you know what happens if I suddenly decide to stop going into work? A business big enough it could be listed on the NASDAQ goes belly-up. Gone. It ceases to exist without me. No, you clearly don’t know who you’re talking to so let me clue you in. I am not in danger, Skylar. I am the danger. A guy opens his front door and gets shot, and you think that of me? No. I am the one who knocks.";
		int expected = 554;
		int actual = 554;

		actual = my_strlen(str);

		CuAssertIntEquals(tc, expected, actual);
	}
	void TestQ1_strlen_case_Tab(CuTest *tc)
	{
		char str[] = "\t";
		int expected = 1;
		int actual = 1;

		actual = my_strlen(str);

		CuAssertIntEquals(tc, expected, actual);
	}
	void TestQ1_strlen_case_Another_Zero(CuTest *tc)
	{
		char str[] = "0";
		int expected = 1;
		int actual = 1;

		actual = my_strlen(str);

		CuAssertIntEquals(tc, expected, actual);
	}

	void TestQ1_strcmp_caseEqual(CuTest *tc)
	{
		char str1[] = "This is a test!";
		char str2[] = "This is a test!";
		int expected = 1;
		int actual = 0;

		actual = my_strcmp(str1, str2);

		CuAssertIntEquals(tc, expected, actual);
	}

	void TestQ1_strcmp_caseUnequalLength(CuTest *tc)
	{
		char str1[] = "This is a test!";
		char str2[] = "This is a test! ";
		int expected = 0;
		int actual = 0;

		actual = my_strcmp(str1, str2);

		CuAssertIntEquals(tc, expected, actual);
	}

	void TestQ1_strcmp_caseUnequalContents(CuTest *tc)
	{
		char str1[] = "This is a test!";
		char str2[] = "This is a pass!";
		int expected = 0;
		int actual = 0;

		actual = my_strcmp(str1, str2);

		CuAssertIntEquals(tc, expected, actual);
	}

	void TestQ1_strcmp_caseEmpty(CuTest *tc)
	{
		char str1[] = "";
		char str2[] = "";
		int expected = 1;
		int actual = 0;

		actual = my_strcmp(str1, str2);

		CuAssertIntEquals(tc, expected, actual);
	}

	void TestQ1_strcmpOrder_caseSmaller(CuTest *tc)
	{
		char str1[] = "Absolutely";
		char str2[] = "new start";
		int expected = 0;
		int actual = 0;

		actual = my_strcmpOrder(str1, str2);

		CuAssertIntEquals(tc, expected, actual);
	}

	void TestQ1_strcmpOrder_caseLarger(CuTest *tc)
	{
		char str1[] = "more than";
		char str2[] = "an apple";
		int expected = 1;
		int actual = 0;

		actual = my_strcmpOrder(str1, str2);

		CuAssertIntEquals(tc, expected, actual);
	}

	void TestQ1_strcmpOrder_caseSame(CuTest *tc)
	{
		char str1[] = "Timeless Content";
		char str2[] = "Timeless Content";
		int expected = -1;
		int actual = 0;

		actual = my_strcmpOrder(str1, str2);

		CuAssertIntEquals(tc, expected, actual);
	}

	void TestQ1_strcmpOrder_caseSomewhatDiff(CuTest *tc)
	{
		char str1[] = "Timeless Content";
		char str2[] = "Timeless Contents";
		int expected = 0;
		int actual = 0;

		actual = my_strcmpOrder(str1, str2);

		CuAssertIntEquals(tc, expected, actual);
	}
	void TestQ1_strcmpOrder_empty(CuTest *tc)
	{
		char str1[] = "";
		char str2[] = "";
		int expected = -1;
		int actual = -1;

		actual = my_strcmpOrder(str1, str2);

		CuAssertIntEquals(tc, expected, actual);
	}
	void TestQ1_strcmpOrder_half_empty(CuTest *tc)
	{
		char str1[] = "";
		char str2[] = "asdkczkxcv";
		int expected = 0;
		int actual = 0;

		actual = my_strcmpOrder(str1, str2);

		CuAssertIntEquals(tc, expected, actual);
	}
	
	void TestQ1_strcat_TwoStrings(CuTest *tc) 
	{
		char str_expected[] = "HelloWorld!";
		char str1[] = "Hello";
		char str2[] = "World!";
		char* str_actual = my_strcat(str1, str2);
		
		CuAssertStrEquals(tc, str_expected, str_actual);

		free(str_actual);
	}

	void TestQ1_strcat_FirstEmpty(CuTest *tc) 
	{
		char str_expected[] = "World!";
		char str1[] = "";
		char str2[] = "World!";
		char* str_actual = my_strcat(str1, str2);
		
		CuAssertStrEquals(tc, str_expected, str_actual);

		free(str_actual);
	}

	void TestQ1_strcat_SecondEmpty(CuTest *tc) 
	{
		char str_expected[] = "Hello";
		char str1[] = "Hello";
		char str2[] = "";
		char* str_actual = my_strcat(str1, str2);
		
		CuAssertStrEquals(tc, str_expected, str_actual);

		free(str_actual);
	}
	void TestQ1_strcat_Two_Empty_Strings(CuTest *tc) 
	{
		char str_expected[] = "";
		char str1[] = "";
		char str2[] = "";
		char* str_actual = my_strcat(str1, str2);
		
		CuAssertStrEquals(tc, str_expected, str_actual);

		free(str_actual);
	}
void TestQ1_strcat_Tab(CuTest *tc) 
	{
		char str_expected[] = "a	b";
		char str1[] = "a	";
		char str2[] = "b";
		char* str_actual = my_strcat(str1, str2);
		
		CuAssertStrEquals(tc, str_expected, str_actual);

		free(str_actual);
	}

// This section is commented out because Q2 contains a buggy code to be debugged.

// Uncomment this section only after you are done with Q1.


//===========================================================
//=================Question 2================================  
	void TestQ2_readandSort1(CuTest *tc) {

		char inputFile[] =  "wordlist.txt";
		int size;
		//create list using the input file
		char **actualList = read_words(inputFile,&size);
		sort_words_Bubble(actualList,size);/*this function used to be called sort_words, 
and it was raising an error since there is no function called "sort_words" to call*/

		char *expectedList[]={"apple","banana","hello","milan","programming","zebra"};
		
		int i;
		for (i=0;i<size;i++)
			CuAssertStrEquals(tc, expectedList[i], actualList[i]);
	delete_wordlist(actualList,size);
	}
   
	void TestQ2_readandSort2(CuTest *tc) {

		char inputFile[] =  "wordlist.txt";
		int size;
		//create list using the input file
		char **actualList = read_words(inputFile,&size);
		sort_words_Bubble(actualList,size);

		char *expectedList[]={"apple","banana","hello","milan","programming","zebra"};

		

		int i;
		for (i=0;i<size;i++)
			CuAssertStrEquals(tc, expectedList[i], actualList[i]);
		delete_wordlist(actualList,size);
	}
void TestQ2_readandSort3(CuTest *tc) {

		char inputFile[] =  "extra_test_case_1.txt";
		int size;
		//create list using the input file
		char **actualList = read_words(inputFile,&size);
		sort_words_Bubble(actualList,size);/*this function used to be called sort_words, 
and it was raising an error since there is no function called "sort_words" to call*/

		char *expectedList[]={"!","~"};
		
		int i;
		for (i=0;i<size;i++)
			CuAssertStrEquals(tc, expectedList[i], actualList[i]);
	delete_wordlist(actualList,size);
	}

void TestQ2_readandSort4(CuTest *tc) {

		char inputFile[] =  "extra_test_case_2.txt";
		int size;
		//create list using the input file
		char **actualList = read_words(inputFile,&size);
		sort_words_Bubble(actualList,size);/*this function used to be called sort_words, 
and it was raising an error since there is no function called "sort_words" to call*/

		char *expectedList[]={"grandfather","macaroni","tomato","xylophone"};
		
		int i;
		for (i=0;i<size;i++)
			CuAssertStrEquals(tc, expectedList[i], actualList[i]);
	delete_wordlist(actualList,size);
	}
	
void TestQ2_readandSort5(CuTest *tc) {

		char inputFile[] =  "extra_test_case_3.txt";
		int size;
		//create list using the input file
		char **actualList = read_words(inputFile,&size);
		sort_words_Bubble(actualList,size);
		char *expectedList[]={"\0"};//the first one is a tab ascii 9 and the second is a spac
		//ascii 32
		
		int i;
		for (i=0;i<size;i++)
			CuAssertStrEquals(tc, expectedList[i], actualList[i]);
	delete_wordlist(actualList,size);
	}
	void TestQ2_readandSort6(CuTest *tc) {

		char inputFile[] =  "extra_test_case_3.txt";
		int size;
		//create list using the input file
		char **actualList = read_words(inputFile,&size);
		sort_words_Bubble(actualList,size);

		char *expectedList[]={"unambiquitous"};
		int i;
		for (i=0;i<size;i++)
			CuAssertStrEquals(tc, expectedList[i], actualList[i]);
	delete_wordlist(actualList,size);
	}
	void TestQ2_readandSort7(CuTest *tc) {

		char inputFile[] =  "wordlist.txt";
		int size;
		//create list using the input file
		char **actualList = read_words(inputFile,&size);
		sort_words_Selection(actualList,size);/*this function used to be called sort_words, 
and it was raising an error since there is no function called "sort_words" to call*/

		char *expectedList[]={"apple","banana","hello","milan","programming","zebra"};
		
		int i;
		for (i=0;i<size;i++)
			CuAssertStrEquals(tc, expectedList[i], actualList[i]);
	delete_wordlist(actualList,size);
	}
   
	void TestQ2_readandSort8(CuTest *tc) {

		char inputFile[] =  "wordlist.txt";
		int size;
		//create list using the input file
		char **actualList = read_words(inputFile,&size);
		sort_words_Selection(actualList,size);

		char *expectedList[]={"apple","banana","hello","milan","programming","zebra"};

		

		int i;
		for (i=0;i<size;i++)
			CuAssertStrEquals(tc, expectedList[i], actualList[i]);
		delete_wordlist(actualList,size);
	}
void TestQ2_readandSort9(CuTest *tc) {

		char inputFile[] =  "extra_test_case_1.txt";
		int size;
		//create list using the input file
		char **actualList = read_words(inputFile,&size);
		sort_words_Selection(actualList,size);/*this function used to be called sort_words, 
and it was raising an error since there is no function called "sort_words" to call*/

		char *expectedList[]={"!","~"};
		
		int i;
		for (i=0;i<size;i++)
			CuAssertStrEquals(tc, expectedList[i], actualList[i]);
	delete_wordlist(actualList,size);
	}

void TestQ2_readandSort10(CuTest *tc) {

		char inputFile[] =  "extra_test_case_2.txt";
		int size;
		//create list using the input file
		char **actualList = read_words(inputFile,&size);
		sort_words_Selection(actualList,size);/*this function used to be called sort_words, 
and it was raising an error since there is no function called "sort_words" to call*/

		char *expectedList[]={"grandfather","macaroni","tomato","xylophone"};
		
		int i;
		for (i=0;i<size;i++)
			CuAssertStrEquals(tc, expectedList[i], actualList[i]);
	delete_wordlist(actualList,size);
	}
	
void TestQ2_readandSort11(CuTest *tc) {

		char inputFile[] =  "extra_test_case_3.txt";
		int size;
		//create list using the input file
		char **actualList = read_words(inputFile,&size);
		sort_words_Selection(actualList,size);
		char *expectedList[]={"\0"};//the first one is a tab ascii 9 and the second is a spac
		//ascii 32
		
		int i;
		for (i=0;i<size;i++)
			CuAssertStrEquals(tc, expectedList[i], actualList[i]);
	delete_wordlist(actualList,size);
	}
	void TestQ2_readandSort12(CuTest *tc) {

		char inputFile[] =  "extra_test_case_3.txt";
		int size;
		//create list using the input file
		char **actualList = read_words(inputFile,&size);
		sort_words_Selection(actualList,size);

		char *expectedList[]={"unambiquitous"};
		int i;
		for (i=0;i<size;i++)
			CuAssertStrEquals(tc, expectedList[i], actualList[i]);
	delete_wordlist(actualList,size);
	}

//===========================================================
	CuSuite* Lab3GetSuite() {

		CuSuite* suite = CuSuiteNew();

		SUITE_ADD_TEST(suite, TestQ1_strlen_case1); 
		SUITE_ADD_TEST(suite, TestQ1_strlen_case2);
		SUITE_ADD_TEST(suite, TestQ1_strlen_case0);
		SUITE_ADD_TEST(suite, TestQ1_navy_seal_Greek_copypasta);
		SUITE_ADD_TEST(suite, TestQ1_I_am_the_danger);
		SUITE_ADD_TEST(suite, TestQ1_strlen_case_Tab);
		SUITE_ADD_TEST(suite, TestQ1_strlen_case_Another_Zero);

		SUITE_ADD_TEST(suite, TestQ1_strcmp_caseEqual);
		SUITE_ADD_TEST(suite, TestQ1_strcmp_caseUnequalLength); 
		SUITE_ADD_TEST(suite, TestQ1_strcmp_caseUnequalContents);
		SUITE_ADD_TEST(suite, TestQ1_strcmp_caseEmpty);

		SUITE_ADD_TEST(suite, TestQ1_strcmpOrder_caseSmaller);
		SUITE_ADD_TEST(suite, TestQ1_strcmpOrder_caseLarger); 
		SUITE_ADD_TEST(suite, TestQ1_strcmpOrder_caseSame);
		SUITE_ADD_TEST(suite, TestQ1_strcmpOrder_caseSomewhatDiff);
		SUITE_ADD_TEST(suite, TestQ1_strcmpOrder_empty);
		SUITE_ADD_TEST(suite, TestQ1_strcmpOrder_half_empty);

		SUITE_ADD_TEST(suite, TestQ1_strcat_TwoStrings); 
		SUITE_ADD_TEST(suite, TestQ1_strcat_FirstEmpty);
		SUITE_ADD_TEST(suite, TestQ1_strcat_SecondEmpty);
		SUITE_ADD_TEST(suite, TestQ1_strcat_Two_Empty_Strings);
		SUITE_ADD_TEST(suite, TestQ1_strcat_Tab);

// Uncomment this section only after you are done with Q1.
		SUITE_ADD_TEST(suite, TestQ2_readandSort1);
		SUITE_ADD_TEST(suite, TestQ2_readandSort2);
        SUITE_ADD_TEST(suite, TestQ2_readandSort3);
		SUITE_ADD_TEST(suite, TestQ2_readandSort4);
		SUITE_ADD_TEST(suite, TestQ2_readandSort5);
		SUITE_ADD_TEST(suite, TestQ2_readandSort6);
		SUITE_ADD_TEST(suite, TestQ2_readandSort7);
		SUITE_ADD_TEST(suite, TestQ2_readandSort8);
        SUITE_ADD_TEST(suite, TestQ2_readandSort9);
		SUITE_ADD_TEST(suite, TestQ2_readandSort10);
		SUITE_ADD_TEST(suite, TestQ2_readandSort11);
		SUITE_ADD_TEST(suite, TestQ2_readandSort12);		
       

		return suite;
	}
   