#include <stdio.h>

unsigned char average(const char * filename)
{
	FILE 	*fp;
	int 	iLen = 0;
	int	iTotal = 0;
	unsigned char ave = 0;
	char	chBuf;

	if (!(fp=fopen(filename, "r")))
	{
		printf("failed to open file.");
		return -1;
	}

	do
	{
		chBuf = getc(fp);
		if(chBuf != EOF)
		{
			iTotal += (int)chBuf;
			iLen ++;
		}
	} while (chBuf != EOF);

	fclose(fp);
	ave = (unsigned char) (iTotal/iLen);
	
	return ave;
}	

int main(int ac, char** av)
{
	unsigned char ave = average(av[1]);
	printf("%u\n", ave);
	return 0;
}	
