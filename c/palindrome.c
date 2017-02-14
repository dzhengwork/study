#include <string.h>
#include <stdio.h>

int palindrome(const char* str)
{
	int len = strlen(str);
	for (int i=0; i<len/2; i++) {
		if (str[i] == str[len-i-1]) {
			continue;
		}
		else if((str[i] - 'A' + 'a') == str[len-i-1]) {
			continue;
		}
		else if((str[i] - 'a' + 'A') == str[len-i-1]) {
			continue;
		}
		else {
			return 0;
		}
	}
	return 1;
}

int main()
{
	char str[100];
	printf("enter string: ");
	scanf("%[^\n]", str);
	if (palindrome(str)) {
		printf("%s is a palindrome\n", str);
	}
	else {
		printf("%s is not a palindrome\n", str);
		char revstr[100];
		int len = strlen(str);
		for (int i=0; i<len; i++) {
			revstr[i] = str[len-i-1];
		}
		printf("rev: %s\n", revstr);
	}

	return 0;
}
