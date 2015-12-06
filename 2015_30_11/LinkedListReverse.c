// ReverseLinkedList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#define MAX 8

struct test
{
	int input[20];
	int size;
	int output[20];
}testcase[MAX] = { { { 1, 2, 3, 4, 5 }, 5, { 5, 4, 3, 2, 1 } },
{ { 5, 4, 3, 2, 1 }, 5, { 1, 2, 3, 4, 5 } },
{ { 1, 2, 3, 4 }, 4, { 4, 3, 2, 1 } },
{ { 1 }, 1, { 1 } },
{ { }, 0, { } },
{ { 1, 1, 2, 2, 3, 3 }, 6, { 3, 3, 2, 2, 1, 1 } },
{ { 8, 6, 8, 6, 4, 8, 8, 8, 0, 9 }, 10, { 9, 0, 8, 8, 8, 4, 6, 8, 6, 8 } },
{ { -1, -2, -3, -4, -5, -6 }, 6, { -6, -5, -4, -3, -2, -1 } } };

struct node
{
	int data;
	struct node *ptr;
};

void display(struct node *head)
{
	struct node *temp;

	temp = head;

	printf("\n");

	while (temp != NULL)
	{
		printf("\t%d", temp->data);
		temp = temp->ptr;
	}
}

struct node *linkedList(int *arr, int size, struct node *head)
{
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	struct node *newnode = (struct node*)malloc(sizeof(struct node));
	head = NULL;
	int i = 0;

	for (i = 0; i < size; i++)
	{
		newnode = (struct node*)malloc(sizeof(struct node));

		newnode->data = arr[i];
		newnode->ptr = NULL;

		if (head == NULL)
		{
			head = newnode;
			head->ptr = NULL;
		}
		else
		{
			temp = head;

			while (temp->ptr != NULL)
				temp = temp->ptr;

			temp->ptr = newnode;
			newnode->ptr = NULL;
		}
	}
	return head;
}

struct node *reverseLinkedList(struct node *head)
{
	struct node *head2;
	if (head == NULL || head->ptr == NULL)
	{
		return head;
	}

	head2 = reverseLinkedList(head->ptr);
	head->ptr->ptr = head;
	head->ptr = NULL;

	return head2;
}

int compare(int *a, int size, struct node *h)
{
	struct node *t = h;
	int i = 0;

	for (i = 0; i < size; i++)
	{
		if (a[i] != t->data)
			return 1;

		t = t->ptr;
	}

	return 0;
}

void testMethod()
{
	int i = 0, ans = 0;
	struct node *head = (struct node*)malloc(sizeof(struct node));

	for (i = 0; i < MAX; i++)
	{
		head = linkedList(testcase[i].input, testcase[i].size, head);
		head = reverseLinkedList(head);

		ans = compare(testcase[i].output, testcase[i].size, head);

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

	return 1;
}