/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

void divide(char arr[], int i1, int dates[10], int months[10],  long int years[10]);
int cal(char a[]);
long int calyear(char a[]);
int countGreaterNumbers(struct transaction *Arr, int len, char *date)
{
	int i1 = 0;
	int dates[10], months[10];
	long int years[10];
	for (i1 = 0; i1 < len; i1++)
		divide(Arr[i1].date, i1, dates, months, years);
    int i, j;
	char date1[5], month1[5], year1[5];
	int date11, month11, year11;
	for (i = 0; i < 2; i++)
		date1[i] = date[i];
	date1[i] = '\0';
	date11 = cal(date1);
	for (i = 3, j = 0; i < 5; i++, j++)
	month1[j] = date[i];
	month1[j] = '\0';
	month11 = cal(month1);
 for (i = 6, j = 0; i < 10; i++, j++)
	year1[j] = date[i];
	year1[j] = '\0';
	year11 = cal(year1);
	int t = 0, c = 0;
	for (t = 0; t < len; t++)
	{
		if (years[t] > year11)
			c++;
		else if (years[t] == year11)
		{
			if (months[t] > month11)
				c++;
			else if (months[t] == month11)
			{
				if (dates[t] > date11)
					c++;
				else if (dates[t] == date11)
				{

				}
			}
		}
	}
	return c;
}
void divide(char arr[], int i1,int dates[10],int months[10],long int years[10])
{
	int i, j;
	char date1[5], month1[5], year1[5];
	int date11, month11;
	long int year11;
	for (i = 0; i < 2; i++)
		date1[i] = arr[i];
	date1[i] = '\0';
	date11 = cal(date1);
	dates[i1] = date11;

	for (i = 3, j = 0; i < 5; i++, j++)
		month1[j] = arr[i];
	month1[j] = '\0';
	month11 = cal(month1);
	months[i1] = month11;

	for (i = 6, j = 0; i < 11; i++, j++)
		year1[j] = arr[i];
	arr[i] = '\0';
	year11 = calyear(year1);
	years[i1] = year11;
}
int cal(char a[])
{
	int val = 0, i1;
	for (i1 = 0; a[i1] != '\0'; i1++)
		val = val * 10 + (a[i1] - '0');
	return val;
}
long int calyear(char a[])
{
	long int val = 0, i1;
	for (i1 = 0; a[i1] != '\0'; i1++)
		val = val * 10 + (a[i1] - '0');
	return val;
}

