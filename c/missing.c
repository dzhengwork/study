#include <stdio.h>


int getMissingNum (int a[], int max)
{
	int total = max*(max+1)/2;
	printf("totol %d\n", total);
	for (int i=0; i<max-1; i++) {
		total -= a[i];
	}
	return total;
}

int getMissingNumXOR(int a[], int max)
{
	int exp = 1;
	for(int i = 2; i <= max; i++) {
		exp = exp ^ i;
	}

	int rst = a[0];
	for (int i = 1; i < max -1; i++) {
		rst = rst ^ a[i];
	}

	return (exp ^ rst);
}

int main()
{
	int max = 6;
	int a[] = {2,3,4,5,6};
	int missing = getMissingNum(a, max);
	printf("%d\n", missing);

	int missing2 = getMissingNumXOR(a, max);
	printf("%d\n", missing2);

	return 0;
}

