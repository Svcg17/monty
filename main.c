#include "monty.h"

int main(int argc, char **argv)
{
	size_t i;
	unsigned int nLine = 0;
	char str[100];
	stack_t *head;
	char *token;
	FILE *fp;

	if (argc < 1)
		exit (101);
	fp = fopen(argv[1], "r");
	while (fgets(str, 100, fp))
	{
		nLine++;
		token = strtok(str, " \t");
		while (token != NULL)
		{
			(*get_line(token))(&head, nLine);
			token = strtok(NULL, " \t");
		}
	}
	printf("%u\n", nLine);
	return (0);
}
