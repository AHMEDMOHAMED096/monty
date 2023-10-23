#include "monty.h"

/**
 * get_instruction - Checks for the opcode and return it
 * @str: The opcode
 * Return: The opcode on success or NULL on failure
 */

instructs_func get_instruction(char *str)
{
	int i = 0;

	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"pchar", pchar},
		{"add", add},
		{"sub", sub},
		{"mul", mul},
		{"div", div},
		{"mod", mod},
		{"nop", nop},
		{"rotl", rotl},
		{"rotr", rotr},
		{"pstr", pstr},
		{"stack", stack},
		{"queue", queue},
		{NULL, NULL}
	};

	for (i = 0; instructions[i].f != NULL; i++)
	{
		if (strcmp(instructions[i].opcode, str) == 0)
			return (instructions[i].f);
	}

	return (NULL);
}

#include "monty.h"

/**
* read_file - Reads the given file
* @filename: The name of the given file
* @stack: Pointer to the stack
*/

void read_file(char *filename, stack_t **stack)
{
	char *buffer = NULL;
	char *line;
	size_t i = 0;
	int line_count = 1;
	instructs_func result;
	int check;
	int read;
	FILE *file = fopen(filename, "r");

	if (file == NULL)
	{
		printf("Error: Can't open file %s\n", filename);
		error_exit(stack);
	}
	while ((read = getline(&buffer, &i, file)) != -1)
	{
		line = tokenizing(buffer);
		if (line == NULL || line[0] == '#')
		{
			line_count++;
			continue;
		}
		result = get_instruction(line);
		if (result == NULL)
		{
			printf("line %d: unknown instruction %s\n", line_count, line);
			error_exit(stack);
		}
		result(stack, line_count);
		line_count++;
	}
	free(buffer);
	check = fclose(file);
	if (check == -1)
		exit(-1);
}

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
