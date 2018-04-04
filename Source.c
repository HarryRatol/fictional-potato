#include<stdio.h>

/* getMissingNo takes array and size of array as arguments*/
int getMissingNo(int a[], int n)
{
	int i, total;
	/**Algorithm to find the missing number**/
	total = (n + 1)*(n + 2) / 2;
	for (i = 0; i< n; i++)
		total -= a[i];
	return total;
}

/*program to test above function */
int main()
{
	int a[] = { 1,2,3,5,6,7,8,9 };
	//calculating the size of array//
	int n = sizeof(a) / sizeof(a[0]);
	int miss = getMissingNo(a, n);
	printf("%d", miss);
	getchar();
}