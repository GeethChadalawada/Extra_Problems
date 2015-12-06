// LargestSubArray.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#define MAX 9

struct test
{
	int input[20];
	int isize;
	int output[20];
	int osize;
	int sum;
}testcase[MAX] = {{ { 1, -1, -2, 2, 3 }, 5, { 2, 3 },2, 5 },
{ { -1, -1, 0, -1, -1 }, 5, {  }, 0, 0 },
{ { 1, -2, 3, -2, 1 }, 5, { 3 }, 1, 3 },
{ { -2, -3, 4, -1, -2, 1, 5 }, 7, { 4, -1, -2, 1, 5 }, 5, 7 },
{ { 1, 2, 3, 4, 5 }, 5, { 1, 2, 3, 4, 5 }, 5, 15 },
{ { 1, -1, 2, -2, 3 }, 5, { 3 }, 1, 3 },
{ { 1, -3, 2, -5, 7, 6, -1, -4, 11, -23 }, 10, { 7, 6, -1, -4, 11 }, 5,19 },
{ { 1, -3, 2, -5 }, 4, { 2 }, 1, 2 },
{ { 1, 2, 3, 4, 5, -2, -3, -4, -20, 10, 2 }, 11, { 1, 2, 3, 4, 5 }, 5, 15 } };

int *maxSubArray(int a[], int size, int *first, int *last)
{
	int premax = 0, max = 0, i = 0, current = 0;
	int *ret = (int*)malloc(sizeof(int) * 3);

	*first = 0;
	*last = 0;

	for (i = 0; i < size; i++)
	{
		max += a[i];
		if (max <= 0)
		{
			max = 0;
			current = i + 1;
		}
		else if (premax < max)
		{
			premax = max;
			*first = current;
			*last = i;
		}
	}

	ret[0] = premax;
	ret[1] = *first;
	ret[2] = *last;

	return ret;
}

int compare(int a[], int size, int osum, int sum, int b[])
{
	int i = 0;

	if (osum != sum)
		return 1;
	else
	{
		for (i = 0; i < size; i++)
		{
			if (a[i] != b[i])
				return 1;
		}
	}

	return 0;
}

void testMethod()
{
	int i = 0, j = 0, k = 0, ans = 0;
	int *ptr = (int*)malloc(sizeof(int));
	int *arr = (int*)malloc(sizeof(int) * 10);

	for (i = 0; i < MAX; i++)
	{
		k = 0;

		ptr = maxSubArray(testcase[i].input, testcase[i].isize, &ptr[1], &ptr[2]);

		for (j = ptr[1]; j <= ptr[2]; j++)
			arr[k++] = testcase[i].input[j];

		ans = compare(testcase[i].output, testcase[i].osize, testcase[i].sum, ptr[0], arr);

		if (ans == 0)
			printf("\nTestcase %d PASSED", (i + 1));
		else
			printf("\nTestcase %d FAILED", (i + 1));
	}
}

int main()
{
	testMethod();

	getch();

	return 0;
}