#include "monty.h"

/**
 * main - main entry point to prgram
 * @argc: number of arguments
 * @argv: opcode passed to main program
 * Return: always 0 on success
 */

int main(int argc, char **argv)
{
	stack_t *stack = NULL;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		error_exit(&stack);
	}

	read_file(argv[1], &stack);
	free_list(stack);

	return (0);
}

void read_file(char *filename, stack_t **stack)
{
	FILE *file = fopen(filename, "r");
	char *buffer = NULL;
	size_t bufsize = 0;
	ssize_t read;

	if (file == NULL)
	{
		printf("Error: Can't open file %s\n", filename);
		error_exit(stack);
	}

	while ((read = getline(&buffer, &bufsize, file)) != -1)
	{
		char *line = strtok(buffer, "\n ");
		int line_count = 1;

		if (line == NULL || line[0] == '#')
			continue;

		instruction_t *instruction = get_instruction(line);
		if (instruction == NULL)
		{
			printf("line %d: unknown instruction %s\n", line_count, line);
			error_exit(stack);
		}

		instruction->f(stack, line_count);
		line_count++;
	}

	free(buffer);
	fclose(file);
}

instruction_t *get_instruction(char *str)
{
	instruction_t instructions[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"pchar", _pchar},
		{"add", _add},
		{"sub", _sub},
		{"mul", _mul},
		{"div", _div},
		{"mod", _mod},
		{"nop", _nop},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{"pstr", _pstr},
		{"stack", _stack},
		{"queue", _queue},
		{NULL, NULL}
	};

	for (int i = 0; instructions[i].opcode != NULL; i++)
	{
		if (strcmp(instructions[i].opcode, str) == 0)
			return (&instructions[i]);
	}

	return (NULL);
}

void error_exit(stack_t **stack)
{
	free_list(*stack);
	exit(EXIT_FAILURE);
}
