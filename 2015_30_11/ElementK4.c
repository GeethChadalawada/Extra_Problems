// emementK4.cpp : Defines the entry point for the console application.
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
	int num4;
	int k;
	int ans;
}testcase[MAX] = { { 1, 2, 3, 4, 5, 4 },
{ 1, 2, 3, 4, 10, 9 },
{ 1, 2, 3, 4, 1000, 999 },
{ 2, 4, 6, 8, 24, 11 },
{ 8, 4, 6, 2, 24, 11 },
{ 5, 10, 15, 20, 10, 1},
{ 5, 10, 15, 20, 2, -1 },
{ 5, 10, 15, 20, 18, -1 },
{ 2, 4, 8, 16, 3, -1},
{ 2, 3, 5, 7, 8, 5 },
{ 11, 22, 33, 44, 44, 4 } };

int *getTable(int *table, int n, int k)
{
	int i = 0;

	for (i = 0; i < k; i++)
		table[i] = n*(i + 1);

	return table;
}

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

int getK(int n1, int n2, int n3, int n4, int k)
{
	int ans1 = 0, ans2 = 0, ans = 0;

	if (k % n1 != 0 && k % n2 != 0 && k % n3 != 0 && k % n4 != 0)
		return -1;

	ans = ((k / n1) + (k / n2) + (k / n3) + (k / n4) - (k / lcm(n1, n2)) - (k / lcm(n2, n3)) - (k / lcm(n3, n4)) - (k / lcm(n1, n3)) - (k / lcm(n2, n4)) - (k / lcm(n1, n4)) - (k / lcm(lcm(n1, n2), n3)) - (k / lcm(lcm(n2, n3), n4)) - (k / lcm(lcm(n1, n2), n4)) - (k / lcm(lcm(n1, n3), n4)) + (k / lcm(lcm(n1, n2), lcm(n3, n4)))) - 1;

	return ans;
}

int compare(int a, int b)
{
	printf("\n%d\t%d", a, b);

	if (a == b)
		return 0;

	return 1;
}

void testMethod()
{
	int answer = 0, i = 0;

	for (i = 0; i < MAX; i++)
	{
		answer = getK(testcase[i].num1, testcase[i].num2, testcase[i].num3, testcase[i].num4, testcase[i].k);

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