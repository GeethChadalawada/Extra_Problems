// elementK3.cpp : Defines the entry point for the console application.
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
	int num3;
	int k;
	int ans;
}testcase[MAX] = { { 1, 2, 3, 10, 9 },
{ 1, 2, 3, 10, 9 },
{ 2, 3, 4, 5, -1 },
{ 2, 3, 4, 12, 7 },
{ 3, 4, 5, 20, 11 },
{ 3, 4, 5, 3, 0 },
{ 5, 4, 3, 3, 0 },
{ 4, 5, 3, 18, 10 },
{ 4, 3, 5, 21, 12 },
{ 10, 20, 30, 100, 9 },
{ 10, 20, 30, 5, -1} };

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

int getK(int n1, int n2, int n3, int k)
{
	int ans1 = 0, ans2 = 0, ans = 0;

	if (k % n1 != 0 && k % n2 != 0 && k % n3 != 0)
		return -1;

	ans = ((k / n1) + (k / n2) + (k / n3) - (k / lcm(n1, n2)) - (k / lcm(n2, n3)) - (k / lcm(n1, n3)) + (k / lcm(lcm(n1, n2), n3))) - 1;

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
	int answer = 0, i = 0;

	for (i = 0; i < MAX; i++)
	{
		answer = getK(testcase[i].num1, testcase[i].num2, testcase[i].num3, testcase[i].k);

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

	getchar();

	return 1;
}