// LastKLines.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <malloc.h>

FILE *getKLines(FILE *fp, int k)
{
	int i = 0;
	char ch;
	FILE *p = (FILE*)malloc(sizeof(FILE) * 10);
	
	while (!(feof(fp)))
	{
		if ((ch = fgetc(fp)) == '\n')
			p[i++] = *fp;
	}

	*fp = p[i - k];
	
	return fp;
}

int main()
{
	FILE *fp;
	int k = 0, j = 0;
	char ch;
	int i = 0;
	//

	fp = fopen("G:/face.java", "r");

	scanf("%d", &k);

	fp = getKLines(fp, k);

	while (!(feof(fp)))
	{
		ch = fgetc(fp);
		printf("%c", ch);
	}

	getch();

	return 0;
}

