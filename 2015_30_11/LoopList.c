// FindLoopStart.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#define MAX 1

struct test
{
	int array[20];
	int size;
	int loopback;
	int ans;
}testcase[MAX] = { { { 1, 2, 3, 4, 5 }, 5, 2, 3 } };

struct node
{
	int data;
	int ref;
	struct node *ptr;
}*newnode = NULL, *temp = NULL, *head = NULL, *tail = NULL;

struct node *linkedList(int *arr, int size, struct node * head)
{
	newnode = (struct node*)malloc(sizeof(struct node));
	int i = 0;

	for (i = 0; i < size; i++)
	{
		newnode->data = arr[i];
		newnode->ref = 0;
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

int getLoopNode(struct node *head)
{
	int i = 0;

	temp = head;
	
	while (temp->ref == 0)
	{
		temp->ref = 1;
		temp = temp->ptr;
	}

	return temp->data;
}

struct node *loopList(struct node *head, int pos)
{
	int i = 0;
	temp = head;
	tail = head;

	for (i = 0; i < pos; temp = temp->ptr,i++);

	while (tail->ptr != NULL)
		tail = tail->ptr;

	tail->ptr = temp;

	return head;
}

int compare(int a, int b)
{
	if (a == b)
		return 0;
	
	return 1;
}

void testMethod()
{
	int i = 0, answer = 0;

	for (i = 0; i < MAX; i++)
	{
		head = NULL;

		head = linkedList(testcase[i].array, testcase[i].size, head);
		
		head = loopList(head, testcase[i].loopback);
		
		answer = getLoopNode(head);

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

	return 0;
}

