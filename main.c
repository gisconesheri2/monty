#include "monty.h"

int data = 0;
int true_zero = 0;
instruction_t pushmonty = {"push", push_m};
/**
 * comparator - compares word and string in compare to
 * @word: word to compare
 * @compare_to: wtring to compare to
 * Return: 1 if both words are the same, 0 otherwise
 */

int comparator(char *word, char *compare_to)
{
	int i = 0, same = 0;

	if (word == NULL)
		return (same);
	for (; word[i] != '\0'; i++)
	{
		/*printf("word[%d] is %c\n", i, word[i]);*/
/*		printf("compare_to[%d] is %c\n", i, compare_to[i]);*/
		if (word[i] == compare_to[i])
		{
			same = 1;
			continue;
		}
		same = 0;
		break;
	}
	return (same);
}
/**
 * split_string - split line into one or two words
 * @line: line to split
 * @mlineargs: char pointer array to store the separate strings
 * Return: NOthing
 */

void split_string(char *line, char **mlineargs)
{
	char *opcode;
	char *temp = strtok(line, " ");
	int same = 0;

	if (temp[strlen(temp) - 1] == '\n')
		temp[strlen(temp) - 1] = '\0';
	opcode = temp;

	if (opcode[0] == '\n')
		opcode = NULL;
	same = comparator(opcode, "push");
	if (same == 1)
	{
		temp = strtok(NULL, " ");
		if (temp[strlen(temp) - 1] == '\n')
			temp[strlen(temp) - 1] = '\0';
		mlineargs[1] = temp;
	}
	else
		mlineargs[1] = NULL;
	mlineargs[0] = opcode;
}
/**
 * main - run the monty opcodes
 * @argc: number of arguments passed to main
 * @argv: arguments passed to main
 * Return: EXIT_SUCCESS on successful completion
 * EXIT_FAILURE otherwise
 */

int main(int argc, char **argv)
{
	char *opcode, *arg;
	char *line = NULL;
	size_t len = 0;
	char *file = argv[1];
	FILE *open_file;
	char *mfileargs[2];
	stack_t *stack = NULL;
	instruction_t pintmonty = {"pint", pint_m};
	unsigned int line_number = 1;

	if (argc != 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	open_file = fopen(file, "r");
	if (open_file == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", file);
		exit(EXIT_FAILURE);
	}
	while ((getline(&line, &len, open_file)) != -1)
	{
		split_string(line, mfileargs);
		opcode = mfileargs[0];
		arg = mfileargs[1];
		if (opcode == NULL)
			continue;
		if (comparator(opcode, "push"))
		{
			if (comparator(arg, "0"))
				true_zero = 1;
			data = atoi(arg);
			pushmonty.f(&stack, line_number);
			true_zero = 0;
		}
		else if (comparator(opcode, "pall"))
		{
			pall_m(&stack, line_number);
		}
		else if (comparator(opcode, "pint"))
		{
			pintmonty.f(&stack, line_number);
		}
		else if (comparator(opcode, "pop"))
		{
			pop_m(&stack, line_number);
		}
		line_number++;
	}
	free(line);
	exit(EXIT_SUCCESS);
}
