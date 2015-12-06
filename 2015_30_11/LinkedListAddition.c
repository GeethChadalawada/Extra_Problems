// LinkedListAddition.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <malloc.h>
#include <conio.h>
#define MAX 13

struct node
{
	int data;
	struct node *ptr;
}*head1 = NULL, *head2 = NULL, *head3 = NULL, *temp = NULL, *temp1 = NULL, *temp2 = NULL, *atemp = NULL, *btemp = NULL, *newnode = NULL;

struct test
{
	int input1[20];
	int size1;
	int input2[20];
	int size2;
	int output[20];
	int size3;
}testcase[MAX] = { { { 1 }, 1, { 1 }, 1, { 2 }, 1 }, 
{ { 1, 2, 3, 4 }, 4, { 4, 3, 2, 1 }, 4, { 5, 5, 5, 5 }, 4 },
{ { 1, 2, 3 }, 3, { 4, 5, 6 }, 3, { 5, 7, 9 }, 3},
{ { 7, 8, 9 }, 3, { 0, 0, 1 }, 3, { 7, 9, 0 },  3},
{ { 9, 9, 9 }, 3, { 0, 0, 1 }, 3, { 1, 0, 0, 0 }, 4 },
{ { 1, 2, 3, 4 }, 4, { 4, 3, 2 }, 3, { 1, 6, 6, 6 }, 4 },
{ { 9, 9, 9, 9 }, 4, { 1, 1, 1 }, 3, { 1, 0, 1, 1, 0 }, 5 },
{ { 1, 1, 1 }, 3, { 9, 9, 9, 9 }, 4, { 1, 0, 1, 1, 0 }, 5 },
{ { 1, 1, 1, 1 }, 4, { 0, 0, 0, 0 }, 4, { 1, 1, 1, 1 }, 4 },
{ { 1, 1, 1, 1 }, 4, { 0 }, 1, { 1, 1, 1, 1 }, 4 },
{ { 0 }, 1, { 1, 1, 1, 1 }, 4, { 1, 1, 1, 1 }, 4 },
{ {  }, 0, {  }, 0, {  }, 0 },
{ { 9 }, 1, { 9 }, 1, { 1, 8 }, 2 } };


struct node *linkedList(int *arr, int size, struct node *head)
{
	int i = 0;
	head = NULL;

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

struct node *addLists(struct node *h1, int size1, struct node *h2, int size2)
{
	struct node *h = NULL, *t = NULL;
	int auxcarry = 0;
	temp1 = h1;
	temp2 = h2;

	if (size1 == size2)
	{
		while (temp2 != NULL)
		{
			temp = (struct node*)malloc(sizeof(struct node));

			temp->data = temp1->data + temp2->data + auxcarry;
			temp->ptr = NULL;
			auxcarry = 0;
			temp1 = temp1->ptr;
			temp2 = temp2->ptr;

			if (temp->data >= 10)
			{
				temp->data -= 10;
				auxcarry = 1;
			}

			if (h == NULL)
			{
				h = temp;
				t = temp;
			}
			else
			{
				t->ptr = temp;
				t = temp;
			}
		}
		if (auxcarry != 0)
		{
			temp = (struct node*)malloc(sizeof(struct node));

			temp->data = 1; 
			temp->ptr = NULL;

			t->ptr = temp;
			t = temp;
		}
	}
	else
	{
		while (temp2 != NULL)
		{
			temp = (struct node*)malloc(sizeof(struct node));

			temp->data = temp1->data + temp2->data + auxcarry;
			temp->ptr = NULL;
			auxcarry = 0;
			temp1 = temp1->ptr;
			temp2 = temp2->ptr;

			if (temp->data >= 10)
			{
				temp->data -= 10;
				auxcarry = 1;
			}

			if (h == NULL)
			{
				h = temp;
				t = temp;
			}
			else
			{
				t->ptr = temp;
				t = temp;
			}
		}
		while (temp1 !=NULL)
		{
			temp = (struct node*)malloc(sizeof(struct node));

			temp->data = temp1->data + auxcarry;
			temp->ptr = NULL;
			auxcarry = 0;
			temp1 = temp1->ptr;

			if (temp->data >= 10)
			{
				temp->data -= 10;
				auxcarry = 1;
			}

			t->ptr = temp;
			t = temp;
		}
		if (auxcarry != 0)
		{
			temp = (struct node*)malloc(sizeof(struct node));

			temp->data = 1;
			temp->ptr = NULL;

			t->ptr = temp;
			t = temp;
		}
	}

	return h;
}

int compare(int *a, int size, struct node *b)
{
	struct node *t = b;
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

	for (i = 0; i < MAX; i++)
	{
		head1 = linkedList(testcase[i].input1, testcase[i].size1, head1);
		head1 = reverseLinkedList(head1);

		head2 = linkedList(testcase[i].input2, testcase[i].size2, head2);
		head2 = reverseLinkedList(head2);

		if (testcase[i].size1 >= testcase[i].size2)
			head3 = addLists(head1, testcase[i].size1, head2, testcase[i].size2);
		else if (testcase[i].size1 < testcase[i].size2)
			head3 = addLists(head2, testcase[i].size2, head1, testcase[i].size1);
		head3 = reverseLinkedList(head3);

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

