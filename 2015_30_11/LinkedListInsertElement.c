// SingleSortedLinkedList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#define MAX 15

struct test
{
	int isize;
	int input[30];
	int insert;
	int osize;
	int output[30];
}testcase[MAX] = { { 4, { 1, 2, 3, 4 }, 0, 5, { 0, 1, 2, 3, 4 } }, 
{ 4, { 1, 2, 3, 4 }, 5, 5, { 1, 2, 3, 4, 5 } },
{ 4, { 1, 3, 4, 5 }, 2, 5, { 1, 2, 3, 4, 5 } },
{ 4, { 1, 2, 4, 5 }, 3, 5, { 1, 2, 3, 4, 5 } },
{ 4, { 1, 2, 3, 5 }, 4, 5, { 1, 2, 3, 4, 5 } },
{ 4, { 1, 2, 3, 4 }, 1, 5, { 1, 1, 2, 3, 4 } },
{ 4, { 1, 1, 1, 1 }, 1, 5, { 1, 1, 1, 1, 1 } },
{ 4, { 1, 2, 3, 4 }, 4, 5, { 1, 2, 3, 4, 4 } },
{ 4, { -4, -3, -2, -1 }, -1, 5, { -4, -3, -2, -1, -1 } },
{ 4, { -5, -4, -2, -1 }, -3, 5, { -5, -4, -3, -2, -1 } },
{ 4, { -1, -1, -1, -1 }, -1, 5, { -1, -1, -1, -1, -1 } },
{ 4, { -4, -3, -2, -1 }, -2, 5, { -4, -3, -2, -2, -1 } },
{ 4, { -2, -2, -1, -1 }, -3, 5, { -3, -2, -2, -1, -1 } },
{ 4, { -2, -1, 1, 2 }, 0, 5, { -2, -1, 0, 1, 2 } },
{ 5, { 1, 1, 1, 3, 3 }, 2, 6, { 1, 1, 1, 2, 3, 3} } };

struct node
{
	int data;
	struct node *ptr;
}*head = NULL, *newnode = NULL, *temp = NULL, *temp1 = NULL;

void create(int val)
{
	newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = val;
	newnode->ptr = NULL;
}

void insert(int val)
{
	create(val);

	if (head == NULL)
	{
		head = newnode;
		head->ptr = head;
	}
	else
	{
		temp = head;
		temp1 = temp->ptr;

		while (temp1 != head)
		{
			temp = temp1;
			temp1 = temp1->ptr;
		}

		temp->ptr = newnode;
		newnode->ptr = temp1;
	}
}


void insertnode(int ele)
{
	create(ele);

	if (head == NULL)
	{
		
		head = newnode;
		head->ptr = head;
	}
	else if (ele < head->data)
	{
		newnode->ptr = head;
		temp = head;
		
		while (temp->ptr != head)
			temp = temp->ptr;

		head = newnode;
		temp->ptr = head;
	}
	else
	{
		temp = head;
		temp1 = temp->ptr;

		while (temp1 != head && (ele > temp->data && ele > temp1->data))
		{
			temp = temp1;
			temp1 = temp1->ptr;
		}

		temp->ptr = newnode;
		newnode->ptr = temp1;
	}
}

int compare(int size, int *arr, struct node *ptr)
{
	int i = 0;
	temp = head;

	for (i = 0; i < size; i++)
	{
		if (arr[i] != temp->data)
			return 0;

		temp = temp->ptr;
	}
	return 1;
}

void testMethod()
{
	int i = 0, j = 0;

	for (i = 0; i < MAX; i++)
	{
		head = NULL;

		for (j = 0; j < testcase[i].isize; j++)
			insert(testcase[i].input[j]);

		insertnode(testcase[i].insert);

		j = compare(testcase[i].osize, testcase[i].output, head);

		if (j == 1)
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

