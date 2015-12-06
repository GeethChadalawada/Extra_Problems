// SortedLinkedLists.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#define MAX 8

struct test
{
	int arr1[20];
	int size1;
	int arr2[20];
	int size2;
	int output[20];
	int size3;
}testcase[MAX] = { { { 1, 3, 5, 7, 9 }, 5, { 2, 4, 6, 8, 10 }, 5, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }, 10 },
{ { 2, 4, 6, 8, 10 }, 5, { 1, 3, 5, 7, 9 }, 5, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }, 10 },
{ { 1, 2, 3, 4 }, 4, { 1, 2, 3, 4 }, 4, { 1, 1, 2, 2, 3, 3, 4, 4 }, 8 },
{ { 2, 2, 2, 2 }, 4, { 3, 3, 3, 3 }, 4, { 2, 2, 2, 2, 3, 3, 3, 3 }, 8 },
{ { 1, 2, 3, 4, 5 }, 5, { 6, 7, 8, 9, 10 }, 5, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }, 10 },
{ { 6, 7, 8, 9, 10 }, 5, { 1, 2, 3, 4, 5 }, 5, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }, 10 },
{ { 1, 3, 5 }, 3, { 2, 4 }, 2, { 1, 2, 3, 4, 5 }, 5 },
{ { 2, 4 }, 2, { 1, 3, 5 }, 3, { 1, 2, 3, 4, 5 }, 5 } };

struct node
{
	int data;
	struct node *ptr;
}*head1 = NULL, *head2 = NULL, *head3 = NULL, *newnode = NULL, *temp = NULL, *temp1 = NULL, *temp2 = NULL;

struct node *linkedList(int *array, int size, struct node *head)
{
	int i = 0;
	head = NULL;

	for (i = 0; i < size; i++)
	{
		newnode = (struct node*)malloc(sizeof(struct node));

		newnode->data = array[i];
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


struct node *mergeLists(struct node *head1, struct node *head2)
{
	while (head1 != NULL || head2 != NULL)
	{
		if (head1 != NULL && head2 != NULL)
		{
			if (head1->data == head2->data)
			{
				if (head3 == NULL)
				{
					temp1 = head1;
					temp2 = head2;
					head1 = head1->ptr;
					head2 = head2->ptr;
					head3 = temp1;
					temp1->ptr = temp2;
					temp2->ptr = NULL;
				}
				else
				{
					temp = head3;

					while (temp->ptr != NULL)
						temp = temp->ptr;

					temp1 = head1;
					temp2 = head2;
					head1 = head1->ptr;
					head2 = head2->ptr;
					temp->ptr = temp1;
					temp1->ptr = temp2;
					temp2->ptr = NULL;
				}
			}
			else if (head1->data < head2->data)
			{
				if (head3 == NULL)
				{
					head3 = head1;
					head1 = head1->ptr;
					head3->ptr = NULL;
				}
				else
				{
					temp = head3;

					while (temp->ptr != NULL)
						temp = temp->ptr;

					temp->ptr = head1;
					head1 = head1->ptr;
					temp = temp->ptr;
					temp->ptr = NULL;
				}
			}
			else
			{
				if (head3 == NULL)
				{
					head3 = head2;
					head2 = head2->ptr;
					head3->ptr = NULL;
				}
				else
				{
					temp = head3;

					while (temp->ptr != NULL)
						temp = temp->ptr;

					temp->ptr = head2;
					head2 = head2->ptr;
					temp = temp->ptr;
					temp->ptr = NULL;
				}
			}
		}
		else if (head1 == NULL && head2 != NULL)
		{
			temp = head3;
			
			while (temp->ptr != NULL)
				temp = temp->ptr;

			temp->ptr = head2;
			head2 = NULL;
		}
		else if (head2 == NULL && head1 != NULL)
		{
			temp = head3;
			
			while (temp->ptr != NULL)
				temp = temp->ptr;

			temp->ptr = head1;
			head1 = NULL;
		}
	}

	return head3;
}

int compare(int *array, int size, struct node *head)
{
	int i = 0;
	temp = head;

	for (i = 0; i < size; i++)
	{
		if (array[i] != temp->data)
			return 1;

		temp = temp->ptr;
	}

	return 0;
}

void testMethod()
{
	int i = 0, ans = 0;

	for (i = 0; i < MAX; i++)
	{
		head1 = linkedList(testcase[i].arr1, testcase[i].size1, head1);
		head2 = linkedList(testcase[i].arr2, testcase[i].size2, head2);

		head3 = mergeLists(head1, head2);

		ans = compare(testcase[i].output, testcase[i].size3, head3);

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