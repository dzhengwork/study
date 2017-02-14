#include <stdio.h>

int main()
{
	char str[] = "abcdtabcd";
	int len = sizeof(str)/sizeof(char);
	printf("len: %d\n", len);

	for(int i=0; i<len; i++) {
		if(str[i] == 't') {
			str[i] = 'T';
		}
	}

	printf("str: %s\n", str);
	return 0;
}
