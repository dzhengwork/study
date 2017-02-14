#include <stdio.h>

int main()
{
	int n1 = 0;
	int n2 = 1;
	int next = 0;
	int num;
	printf("enter number: ");
	scanf("%d", &num);
	
	printf("fibonacci series: \n");
	for (int i=0; i<num; i++) {
		if (i==0) {
			printf("%d, ", n1);
			continue;
		}
		if (i==1) {
			printf("%d, ", n2);
			continue;
		}
		
		next = n1 + n2;
		printf("%d, ", next);
		n1 = n2;
		n2 = next;
	}
	printf("\n");
	return 0;
}
