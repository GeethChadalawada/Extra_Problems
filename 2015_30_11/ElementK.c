// elementK.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#define MAX 11

struct test
{
	int num1;
	int num2;
	int k;
	int ans;
}testcase[MAX] = { { 2, 3, 8, 4 },
{ 2, 3, 2, 0 },
{ 2, 3, 15, 9 },
{ 3, 5, 3, 0 },
{ 3, 5, 12, 5 },
{ 3, 5, 24, 10 },
{ 10, 20, 80, 7 },
{ 10, 20, 90, 8 },
{ 20, 10, 30, 2 },
{ 8, 9, 48, 10 },
{ 9, 8, 24, 4 } };

int lcm(int a, int b)
{
	int max = (a > b) ? a : b;

	while (1)                     
	{
		if (max % a == 0 && max % b == 0)
			break;
		
		max++;
	}

	return max;
}

int getK(int n1, int n2, int k)
{
	int ans = 0;

	if (k % n1 != 0 && k % n2 != 0)
		return -1;

	ans = ((k / n1) + (k / n2) - (k / lcm(n1,n2))) - 1;

	return ans;
}

int compare(int a, int b)
{
	if (a == b)
		return 0;
	
	return 1;
}

void testMethod()
{
	int i = 0;
	int answer = 0;

	for (i = 0; i < MAX; i++)
	{
		answer = getK(testcase[i].num1, testcase[i].num2, testcase[i].k);

		answer = compare(answer, testcase[i].ans);

		if (answer == 0)
			printf("\nTestcase %d PASSED", (i + 1));
		else
			printf("\nTestcase %d FAILED", (i + 1));
	}
}

int main()
{
	testMethod();

	getch();

	return 1;
}