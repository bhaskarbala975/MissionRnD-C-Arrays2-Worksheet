/*
OVERVIEW: You are given 2 bank statements that are ordered by date - 
Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int compare(char date[], char datex[]);
int calc(char a[]);
struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) 
{
	int i = 0, j = 0, k = 0, res=0;
	if (A==NULL||B==NULL)
	return NULL;
	struct transaction *result;
	result = (struct transaction*)malloc(sizeof(struct transaction)*100);
	while (i < ALen&&j < BLen)
	{
		res = compare(A[i].date, B[j].date);
		if (res == 1)
		{
			result[k] = A[i];
			i++;
			k++;
		}
		else
		{
			result[k] = B[j];
			j++;
			k++;
		}
	}
	while (i < ALen)
	{
		result[k] = A[i];
		k++;
		i++;
	}
	while (j < BLen)
	{
		result[k] = B[j];
		k++;
		j++;
	}
	return result;
}
int compare(char date[], char datex[])
{
	int date11, month11, year11, date22, month22, year22;
	char date1[5], month1[5], year1[10], date2[5], month2[5], year2[10];
	int i, j;
	for (i = 0; i < 2; i++)
		date1[i] = date[i];
	date1[i] = '\0';
	date11 = calc(date1);
	for (i = 3, j = 0; i < 5; i++, j++)
		month1[j] = date[i];
	month1[j] = '\0';
	month11 = calc(month1);
	for (i = 6, j = 0; i < 11; i++, j++)
		year1[j] = date[i];
	year1[j] = '\0';
	year11 = calc(year1);

	for (i = 0; i < 2; i++)
		date2[i] = datex[i];
	date2[i] = '\0';
	date22 = calc(date2);
	for (i = 3, j = 0; i < 5; i++, j++)
		month2[j] = datex[i];
	month2[j] = '\0';
	month22 = calc(month2);
	for (i = 6, j = 0; i < 11; i++, j++)
		year2[j] = datex[i];
	year2[j] = '\0';
	year22 = calc(year2);

	if (year11 < year22)
		return 1;
	else if (year11 == year22)
	{
		if (month11 < month22)
			return 1;
		else if (month11 == month22)
		{
			if (date11 <= date22)
				return 1;

		}

	}
	return 2;
}
int calc(char a[])
{
	int val = 0, i1;
	for (i1 = 0; a[i1] != '\0'; i1++)
		val = val * 10 + (a[i1] - '0');
	return val;
}