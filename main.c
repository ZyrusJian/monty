#define _GNU_SOURCE
#include "monty.h"

/**
 * execute_instructions - Executes the Monty bytecode instructions
 * @file: Pointer to the input file
 * @instructions: Array of instruction structs
 */

void execute_instructions(FILE *file, instruction_t *instructions)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	stack_t *head = NULL;
	unsigned int line_number = 0;
	int i;

	while ((read = getline(&line, &len, file)) != -1)
	{
		char *opcode = strtok(line, " \n");

		line_number++;
		if (opcode == NULL || opcode[0] == '#')
			continue;
		i = 0;
		while (instructions[i].opcode != NULL)
		{
			if (strcmp(opcode, instructions[i].opcode) == 0)
			{
				instructions[i].f(&head, line_number);
				break;
			}
			i++;
		}

		if (instructions[i].opcode == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
			exit(EXIT_FAILURE);
		}
	}
	free(line);
}

/**
 * main - Entry point for the Monty bytecode interpreter
 * @argc: Number of command-line arguments
 * @argv: Array of command-line argument strings
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */

int main(int argc, char **argv)
{
	FILE *file;
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},/* Add more instructions here */
		{NULL, NULL}
	};

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	execute_instructions(file, instructions);
	fclose(file);
	return (EXIT_SUCCESS);
}
