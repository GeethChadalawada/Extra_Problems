// LinkedListMedian.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#define MAX 14

struct test
{
	int inputsize;
	int input[20];
	int output;
}testcase[MAX] = { { 0, {}, -1 },
{ 3, { 1, 2, 3 }, 2 },
{ 3, { 2, 3, 4 }, 3 },
{ 5, { 1, 2, 3, 4, 5 }, 3 },
{ 5, { 2, 3, 4, 5, 6 }, 4 },
{ 7, { 1, 2, 3, 4, 5, 6, 7 }, 4 },
{ 7, { 2, 3, 4, 5, 6, 7, 8 }, 5 },
{ 2, { 1, 2 }, 1 },
{ 0, {}, -1 },
{ 2, { 2, 3 }, 2 },
{ 4, { 1, 2, 3, 4 }, 2 },
{ 4, { 2, 3, 4, 5 }, 3 },
{ 6, { 1, 2, 3, 4, 5, 6 }, 3 },
{ 6, { 2, 3, 4, 5, 6, 7 }, 4 } };

struct node
{
	int value;
	struct node *ptr;
}*newnode = NULL, *head = NULL, *temp = NULL;

struct node *createList(int ip[], int size)
{
	int i = 0;
	head = NULL;

	for (i = 0; i < size; i++)
	{
		newnode = (struct node*)malloc(sizeof(struct node));
		newnode->value = ip[i];
		newnode->ptr = NULL;

		if (head == NULL)
			head = newnode;
		else
		{
			temp = head;

			while (temp->ptr != NULL)
				temp = temp->ptr;

			temp->ptr = newnode;
		}
	}
	
	return head;
}

int getMedian(struct node *head)
{
	int i = 0, j  = 0;
	int median = -1;

	temp = head;

	if (head == NULL)
		return median;

	for (i = 0; temp->ptr != NULL; i++)
		temp = temp->ptr;

	temp = head;

	if (i % 2 == 0)
	{
		for (j = 0; j <= (i / 2) - 1; j++)
			temp = temp->ptr;

		median = temp->value;
		temp = temp->ptr;
		median = median + temp->value;

		median /= 2;
	}
	else
	{
		for (j = 0; j < (i / 2); j++)
			temp = temp->ptr;

		median = temp->value;
	}

	return median;
}

int compare(int a, int b)
{
	if (a != b)
		return 1;

	return 0;
}


void testMethod()
{
	int i = 0, j = 0;
	struct node *list;

	for (i = 0; i < MAX; i++)
	{
		list = createList(testcase[i].input, testcase[i].inputsize);

		j = getMedian(list);

		j = compare(j, testcase[i].output);

		if (j == 0)
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