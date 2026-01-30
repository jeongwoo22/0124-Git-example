// Standard input output
#include <stdio.h>

int main3(void)
{
	int count = 65;
	/*****
	Example1 : for loop
	*****/
	for (int i = 0; i < 5; i++)
		printf("%d-", i);
	printf("\n");

	/*****
	Example2 : while loop
	*****/
	while (count < 91)
		printf("%c-", count++);
	printf("\n");

	/*****
	Example3 : if break continue 
	*****/
	while (count < 91)
	{
		if (count++ % 2 == 1 || count == 90)
			continue;
		printf("%c-", count);

		if (0)
			printf("NO!\n");
		else if (count > 80 && count < 82)
			break;
	}
	printf("\n");

	/*****
	Practice1 : print below with for
	LOVE
	LOVELOVE
	LOVELOVELOVE
	LOVELOVE
	LOVE
	*****/


	return 0;
}