#include "monty.h"

int main(int argc, char **argv)
{
	size_t i;
	unsigned int nLine = 0;
	char str[100];
	stack_t *head = NULL;
	char *token;
	void *funct();
	FILE *fp;

	if (argc < 1)
		exit (101);
	fp = fopen("bytecode/00.m", "r");
	while (fgets(str, 100, fp))
	{
		nLine++;
		token = strtok(str, " \t");
		while (token != NULL)
		{
			if (getCoco(token, &head, nLine) == 1)
				printf("token: %s\n", token);
			token = strtok(NULL, " \t");
		}
	}
	printf("%u\n", nLine);
	close(fp);
	return (0);
}
