// SortList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <malloc.h>
#include <conio.h>
#define MAX 4

struct test
{
	int input[20];
	int size;
	int output[20];
}testcase[MAX] = { { { 1, 2, 7, 20, 15, 10 }, 6, { 1, 2, 7, 10, 15, 20 } },
{ { 1, 2, 3, 8, 7, 6, 5, 4 }, 8, { 1, 2, 3, 4, 5, 6, 7, 8 } },
{ { 1, 2, 4, 3 }, 4, { 1, 2, 3, 4 } },
{ { 1, 2, 3, 6, 5, 4 }, 6, { 1, 2, 3, 4, 5, 6 } } };

struct node
{
	int data;
	struct node *next;
}*head = NULL, *temp = NULL;

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
		newnode->next = NULL;

		if (head == NULL)
		{
			head = newnode;
			head->next = NULL;
		}
		else
		{
			temp = head;

			while (temp->next != NULL)
				temp = temp->next;

			temp->next = newnode;
			newnode->next = NULL;
		}
	}
	return head;
}

void sortList(struct node *head, struct node *temp)
{
	struct node *temp1;
	int i, *arr;
	arr = (int *)malloc(sizeof(int) * 10);

	temp = head;
	if (temp == NULL)
		return;
	if (temp->next == NULL)
		return;

	while (temp->data < temp->next->data)
	{
		temp = temp->next;
		if (temp == NULL)
			break;
	}

	temp1 = temp;
	i = 0;

	while (temp1 != NULL)
	{
		if (temp1->next == NULL)
			break;
		if (temp1->data > temp1->next->data)
		{
			arr[i++] = temp1->data;

			if (temp1->next != NULL)
				temp1 = temp1->next;
			else
				break;

			arr[i] = temp1->data;

		}
		else
			break;
	}

	while (temp != temp1->next)
	{
		temp->data = arr[i];
		temp = temp->next;
		i--;
	}

	if (temp != NULL)
		sortList(head, temp);
}

int compare(int a[], int size, struct node *h)
{
	struct node *t = h;
	int i = 0;

	for (i = 0; i < size; i++)
	{
		if (a[i] != t->data)
			return 1;

		t = t->next;
	}

	return 0;
}

void testMethod()
{
	int i = 0, ans = 0;

	for (i = 0; i < MAX; i++)
	{
		head = linkedList(testcase[i].input, testcase[i].size, head);

		sortList(head, temp);

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

	return 0;
}

