#include <assert.h>
#include <setjmp.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "CuTest.h"
#include "Questions.h"
    

    
    
//=========Question 1==================================
void TestQ1_add(CuTest *tc) {

	int n = 5;
	double input1[5] = {3.60, 4.78, 6.00, 10.00, 0.01};
	double input2[5] = {1.50, 2.00, 3.30, 9.90, 1.00};
	double actual[5];
	double expected [5] = {5.10, 6.78, 9.30, 19.90, 1.01};
	add_vectors(input1,input2,actual,n);
	int i;
	for (i=0; i<n; i++)
		CuAssertDblEquals(tc, expected[i], actual[i],0.009);
}

void TestQ1_addB(CuTest *tc) {

	int n = 1;
	double input1[1] = {0.00};
	double input2[1] = {0.00};
	double actual[1];
	double expected [1] = {0.00};
	add_vectors(input1,input2,actual,n);
	int i;
	for (i=0; i<n; i++)
		CuAssertDblEquals(tc, expected[i], actual[i],0.009);
}

void TestQ1_addC(CuTest *tc) {

	int n = 1;
	double input1[1] = {-1.20};
	double input2[1] = {-2.20};
	double actual[1];
	double expected [1] = {-3.40};
	add_vectors(input1,input2,actual,n);
	int i;
	for (i=0; i<n; i++)
		CuAssertDblEquals(tc, expected[i], actual[i],0.009);
}

void TestQ1_addD(CuTest *tc) {

	int n = 1;
	double input1[1] = {999};
	double input2[1] = {-999};
	double actual[1];
	double expected [1] = {0.00};
	add_vectors(input1,input2,actual,n);
	int i;
	for (i=0; i<n; i++)
		CuAssertDblEquals(tc, expected[i], actual[i],0.009);
}
    
void TestQ1_scalar_prod(CuTest *tc) {

	int n = 5;
	double input1[5] = {3.60, 4.78, 6.00, 10.00, 0.01};
	double input2[5] = {1.50, 2.00, 3.30, 9.90, 1.00};
	double expected=133.770 ;
	double actual = scalar_prod(input1,input2,n);

	CuAssertDblEquals(tc, expected, actual,0.009);
}

void TestQ1_scalar_prodB(CuTest *tc) {

	int n = 2;
	double input1[2] = {'\0',1};
	double input2[2] = {'!','!'};
	double expected=33.000 ;
	double actual = scalar_prod(input1,input2,n);

	CuAssertDblEquals(tc, expected, actual,0.009);
}

void TestQ1_scalar_prodC(CuTest *tc) {

	int n = 2;
	double input1[2] = {0.00,'\0'};
	double input2[2] = {0.00,'!'};
	double expected=0.000 ;
	double actual = scalar_prod(input1,input2,n);

	CuAssertDblEquals(tc, expected, actual,0.009);
}

void TestQ1_scalar_prodD(CuTest *tc) {

	int n = 2;
	double input1[2] = {0.00,1};
	double input2[2] = {'!','!'};
	double expected=33.000 ;
	double actual = scalar_prod(input1,input2,n);

	CuAssertDblEquals(tc, expected, actual,0.009);
}

void TestQ1_norm(CuTest *tc) {

	int n = 5;
	double input1[5] = {3.60, 4.78, 6.00, 10.00, 0.01};
	double expected=13.108 ;
    double actual = norm2(input1,n);

    CuAssertDblEquals(tc, expected, actual,0.009);
}

void TestQ1_normB(CuTest *tc) {

	int n = 2;
	double input1[2] = {0.00,0.00};
	double expected=0.000 ;
    double actual = norm2(input1,n);

    CuAssertDblEquals(tc, expected, actual,0.009);
}

void TestQ1_normC(CuTest *tc) {

	int n = 2;
	double input1[2] = {'!','\0'};
	double expected=33.000 ;
    double actual = norm2(input1,n);

    CuAssertDblEquals(tc, expected, actual,0.009);
}

void TestQ1_normD(CuTest *tc) {

	int n = 2;
	double input1[2] = {-10,'!'};
	double expected=34.482 ;
    double actual = norm2(input1,n);

    CuAssertDblEquals(tc, expected, actual,0.009);
}

//===========================================================
//=================Question 2================================  

void TestQ2(CuTest *tc) {
	int n = 3;
	int input[3][3] = {{1, 2, 3},{ 5, 8, 9},{ 0, 3, 5}};
	int expected[9]= {1, 2, 5, 3, 8, 0, 9, 3, 5};
	int actual[9];
	diag_scan(input,actual);

	int i;
	for (i=0; i<n*n; i++)
		CuAssertIntEquals(tc, expected[i], actual[i]);
}


void TestQ2_B(CuTest *tc) {
	int n = 3;
	int input[3][3] = {{1.0, 2.0, 3.0},{ 5.0, 8.0, 9.0},{ 0.0, 3.0, 5.0}};
	int expected[9]= {1, 2, 5, 3, 8, 0, 9, 3, 5};
	int actual[9];
	diag_scan(input,actual);

	int i;
	for (i=0; i<n*n; i++)
		CuAssertIntEquals(tc, expected[i], actual[i]);
}   

void TestQ2_C(CuTest *tc) {
	int n = 3;
	int input[3][3] = {{1.0, 2.0, 3.0},{ 5.0, 8.0, 9.0},{ 0.0, 3.0, '!'}};
	int expected[9]= {1, 2, 5, 3, 8, 0, 9, 3, 33};//ASCII character for ! is 33
	int actual[9];
	diag_scan(input,actual);

	int i;
	for (i=0; i<n*n; i++)
		CuAssertIntEquals(tc, expected[i], actual[i]);
} 

void TestQ2_D(CuTest *tc) {
	int n = 3;
	int input[3][3] = {{'\0', 2.0, 3.0},{ 5.0, 8.0, 9.0},{ 0.0, 3.0, '!'}};
	int expected[9]= {0,2, 5, 3, 8, 0, 9, 3, 33};//null returns zero in c
	int actual[9];
	diag_scan(input,actual);

	int i;
	for (i=0; i<n*n; i++)
		CuAssertIntEquals(tc, expected[i], actual[i]);
} 
//===========================================================
//=================Question 3================================   
void TestQ3_1(CuTest *tc) {
	int n=8;
	int input[]={0,0,23,0,-7,0,0,48};
	struct Q3Struct actual[8] = {0};
	struct Q3Struct expected[8] = {{23, 2}, {-7, 4}, {48, 7}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}};
	efficient(input,actual,n);
    
	int i;
	for (i=0; i<n; i++){
		CuAssertIntEquals(tc, expected[i].val, actual[i].val);
		CuAssertIntEquals(tc, expected[i].pos, actual[i].pos);
	}
}

void TestQ3_zeros(CuTest *tc) {
	int n=8;
	int input[]={0,0,0,0,0,0,0,0};
	struct Q3Struct actual[8] = {0};
	struct Q3Struct expected[8] = {0};
	efficient(input,actual,n);
    
	int i;
	for (i=0; i<n; i++){
		CuAssertIntEquals(tc, expected[i].val, actual[i].val);
		CuAssertIntEquals(tc, expected[i].pos, actual[i].pos);
	}
}

void TestQ3_combined(CuTest *tc) {
	int n=8;
	int input[]={0,0,23,0,-7,0,0,48};
	struct Q3Struct int_result[8] = {0};
	int expected[8] = {0,0,23,0,-7,0,0,48};
	int actual[8] = {0};
	efficient(input,int_result,n);
	reconstruct(actual, 8, int_result, 3);

	int i;
	for (i=0; i<n; i++){
		CuAssertIntEquals(tc, expected[i], actual[i]);
	}
}

void TestQ3_1B(CuTest *tc) {
	int n=8;
	int input[]={17,11,23,4,-7,8,-1,48};
	struct Q3Struct actual[8] = {0};
	struct Q3Struct expected[8] = {{17, 0}, {11, 1}, {23, 2}, {4, 3}, {-7, 4}, {8, 5}, {-1, 6}, {48, 7}};
	efficient(input,actual,n);
    
	int i;
	for (i=0; i<n; i++){
		CuAssertIntEquals(tc, expected[i].val, actual[i].val);
		CuAssertIntEquals(tc, expected[i].pos, actual[i].pos);
	}
}
    
void TestQ3_1C(CuTest *tc) {
	int n=8;
	int input[]={9999,9998,9999,9999,9988,9999,9999,0};
	struct Q3Struct actual[8] = {0};
	struct Q3Struct expected[8] = {{9999, 0}, {9998, 1}, {9999, 2}, {9999, 3}, {9988, 4}, {9999, 5}, {9999, 6}, {0, 0}};
	efficient(input,actual,n);
    
	int i;
	for (i=0; i<n; i++){
		CuAssertIntEquals(tc, expected[i].val, actual[i].val);
		CuAssertIntEquals(tc, expected[i].pos, actual[i].pos);
	}
}

void TestQ3_1D(CuTest *tc) {
	int n=8;
	int input[]={'!','!','!','!','!','!','!','!'};
	struct Q3Struct actual[8] = {0};
	struct Q3Struct expected[8] = {{33, 0}, {33, 1}, {33, 2}, {33, 3}, {33, 4}, {33, 5}, {33, 6}, {33, 7}};
	efficient(input,actual,n);
    
	int i;
	for (i=0; i<n; i++){
		CuAssertIntEquals(tc, expected[i].val, actual[i].val);
		CuAssertIntEquals(tc, expected[i].pos, actual[i].pos);
	}
}
//===========================================================
//=================Question 4================================   
void TestQ4_BubbleSort_1(CuTest *tc) 
{
	int n=6;
	struct Q4Struct input[]={{10, 'c'}, {2, 'B'}, {-5, 'k'}, {12, 'z'}, {77, 'a'}, {-42, '?'}};	
	struct Q4Struct expected[]={{-42, '?'}, {-5, 'k'}, {2, 'B'}, {10, 'c'}, {12, 'z'}, {77, 'a'}};		
	
	sortDatabyBubble(input, n);
	
	int i;
	for (i=0; i<n; i++)
	{
		CuAssertIntEquals(tc, expected[i].intData, input[i].intData);
		CuAssertIntEquals(tc, expected[i].charData, input[i].charData);
	}
}

void TestQ4_BubbleSort_2(CuTest *tc) 
{
	int n=8;
	struct Q4Struct input[]={{-23, '='}, {78, ' '}, {11, 'Y'}, {-2, '0'}, {41, '+'}, {0, 'm'}, {55, 'T'}, {-9, 'o'}};	
	struct Q4Struct expected[]={{-23, '='}, {-9, 'o'}, {-2, '0'}, {0, 'm'}, {11, 'Y'}, {41, '+'}, {55, 'T'}, {78, ' '}};		
	
	sortDatabyBubble(input, n);
	
	int i;
	for (i=0; i<n; i++)
	{
		CuAssertIntEquals(tc, expected[i].intData, input[i].intData);
		CuAssertIntEquals(tc, expected[i].charData, input[i].charData);
	}
}
void TestQ4_BubbleSort_3(CuTest *tc) 
{
	int n=6;
	struct Q4Struct input[]={{0, 'c'}, {0, 'B'}, {0, 'k'}, {0, 'z'}, {0, 'a'}, {0, '?'}};	
	struct Q4Struct expected[]={{0, 'c'}, {0, 'B'}, {0, 'k'}, {0, 'z'}, {0, 'a'}, {0, '?'}};		
	
	sortDatabyBubble(input, n);
	
	int i;
	for (i=0; i<n; i++)
	{
		CuAssertIntEquals(tc, expected[i].intData, input[i].intData);
		CuAssertIntEquals(tc, expected[i].charData, input[i].charData);
	}
}
void TestQ4_BubbleSort_4(CuTest *tc) 
{
	int n=1;
	struct Q4Struct input[]={{0, 'c'}};	
	struct Q4Struct expected[]={{0, 'c'}};		
	
	sortDatabyBubble(input, n);
	
	int i;
	for (i=0; i<n; i++)
	{
		CuAssertIntEquals(tc, expected[i].intData, input[i].intData);
		CuAssertIntEquals(tc, expected[i].charData, input[i].charData);
	}
}

void TestQ4_BubbleSort_5(CuTest *tc) 
{
	int n=8;
	struct Q4Struct input[]={{-23, '\0'}, {78, ' '}, {11, 'Y'}, {-2, '0'}, {41, '+'}, {0, 'm'}, {55, 'T'}, {-9, 'o'}};	
	struct Q4Struct expected[]={{-23, 0}, {-9, 'o'}, {-2, '0'}, {0, 'm'}, {11, 'Y'}, {41, '+'}, {55, 'T'}, {78, ' '}};		
	
	sortDatabyBubble(input, n);
	
	int i;
	for (i=0; i<n; i++)
	{
		CuAssertIntEquals(tc, expected[i].intData, input[i].intData);
		CuAssertIntEquals(tc, expected[i].charData, input[i].charData);
	}
}
void TestQ4_SelectionSort_1(CuTest *tc) 
{
	int n=6;
	struct Q4Struct input[]={{10, 'c'}, {2, 'B'}, {-5, 'k'}, {12, 'z'}, {77, 'a'}, {-42, '?'}};	
	struct Q4Struct expected[]={{-42, '?'}, {-5, 'k'}, {2, 'B'}, {10, 'c'}, {12, 'z'}, {77, 'a'}};		
	
	sortDatabySelection(input, n);
	
	int i;
	for (i=0; i<n; i++)
	{
		CuAssertIntEquals(tc, expected[i].intData, input[i].intData);
		CuAssertIntEquals(tc, expected[i].charData, input[i].charData);
	}
}

void TestQ4_SelectionSort_2(CuTest *tc) 
{
	int n=8;
	struct Q4Struct input[]={{-23, '='}, {78, ' '}, {11, 'Y'}, {-2, '0'}, {41, '+'}, {0, 'm'}, {55, 'T'}, {-9, 'o'}};	
	struct Q4Struct expected[]={{-23, '='}, {-9, 'o'}, {-2, '0'}, {0, 'm'}, {11, 'Y'}, {41, '+'}, {55, 'T'}, {78, ' '}};			
	
	sortDatabySelection(input, n);
	
	int i;
	for (i=0; i<n; i++)
	{
		CuAssertIntEquals(tc, expected[i].intData, input[i].intData);
		CuAssertIntEquals(tc, expected[i].charData, input[i].charData);
	}
}

void TestQ4_SelectionSort_3(CuTest *tc) 
{
	int n=8;
	struct Q4Struct input[]={{0, '='}, {0, ' '}, {0, 'Y'}, {0, '0'}, {0, '+'}, {0, 'm'}, {0, 'T'}, {0, 'o'}};	
	struct Q4Struct expected[]={{0, '='}, {0, ' '}, {0, 'Y'}, {0, '0'}, {0, '+'}, {0, 'm'}, {0, 'T'}, {0, 'o'}};			
	
	sortDatabySelection(input, n);
	
	int i;
	for (i=0; i<n; i++)
	{
		CuAssertIntEquals(tc, expected[i].intData, input[i].intData);
		CuAssertIntEquals(tc, expected[i].charData, input[i].charData);
	}
}
void TestQ4_SelectionSort_4(CuTest *tc) 
{
	int n=1;
	struct Q4Struct input[]={{0, '='}};	
	struct Q4Struct expected[]={{0, '='}};			
	
	sortDatabySelection(input, n);
	
	int i;
	for (i=0; i<n; i++)
	{
		CuAssertIntEquals(tc, expected[i].intData, input[i].intData);
		CuAssertIntEquals(tc, expected[i].charData, input[i].charData);
	}
}

void TestQ4_SelectionSort_5(CuTest *tc) 
{
	int n=8;
	struct Q4Struct input[]={{-23, '\0'}, {78, ' '}, {11, 'Y'}, {-2, '0'}, {41, '+'}, {0, 'm'}, {55, 'T'}, {-9, 'o'}};	
	struct Q4Struct expected[]={{-23, 0}, {-9, 'o'}, {-2, '0'}, {0, 'm'}, {11, 'Y'}, {41, '+'}, {55, 'T'}, {78, ' '}};			
	
	sortDatabySelection(input, n);
	
	int i;
	for (i=0; i<n; i++)
	{
		CuAssertIntEquals(tc, expected[i].intData, input[i].intData);
		CuAssertIntEquals(tc, expected[i].charData, input[i].charData);
	}
}





CuSuite* Lab2GetSuite() {

	CuSuite* suite = CuSuiteNew();

	SUITE_ADD_TEST(suite, TestQ1_add);
	SUITE_ADD_TEST(suite, TestQ1_addB);
	SUITE_ADD_TEST(suite, TestQ1_addC);
	SUITE_ADD_TEST(suite, TestQ1_addD);
	SUITE_ADD_TEST(suite, TestQ1_scalar_prod);
	SUITE_ADD_TEST(suite, TestQ1_scalar_prodB);
	SUITE_ADD_TEST(suite, TestQ1_scalar_prodC);
	SUITE_ADD_TEST(suite, TestQ1_scalar_prodD);
	SUITE_ADD_TEST(suite, TestQ1_norm);
	SUITE_ADD_TEST(suite, TestQ1_normB);
	SUITE_ADD_TEST(suite, TestQ1_normC);
	SUITE_ADD_TEST(suite, TestQ1_normD);

	SUITE_ADD_TEST(suite, TestQ2);
	SUITE_ADD_TEST(suite, TestQ2_B);
	SUITE_ADD_TEST(suite, TestQ2_C);
	SUITE_ADD_TEST(suite, TestQ2_D);

	SUITE_ADD_TEST(suite, TestQ3_1);
	SUITE_ADD_TEST(suite, TestQ3_zeros);
	SUITE_ADD_TEST(suite, TestQ3_combined);
	SUITE_ADD_TEST(suite, TestQ3_1B);
	SUITE_ADD_TEST(suite, TestQ3_1C);
	SUITE_ADD_TEST(suite, TestQ3_1D);

	SUITE_ADD_TEST(suite, TestQ4_BubbleSort_1);
	SUITE_ADD_TEST(suite, TestQ4_BubbleSort_2);
	SUITE_ADD_TEST(suite, TestQ4_BubbleSort_3);
	SUITE_ADD_TEST(suite, TestQ4_BubbleSort_4);
	SUITE_ADD_TEST(suite, TestQ4_BubbleSort_5);
	SUITE_ADD_TEST(suite, TestQ4_SelectionSort_1);
	SUITE_ADD_TEST(suite, TestQ4_SelectionSort_2);
	SUITE_ADD_TEST(suite, TestQ4_SelectionSort_3);
	SUITE_ADD_TEST(suite, TestQ4_SelectionSort_4);
	SUITE_ADD_TEST(suite, TestQ4_SelectionSort_5);

	return suite;
} 
