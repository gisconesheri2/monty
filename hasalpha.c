#include "monty.h"
/**
 * has_only_nums - check if word contains only numbers
 * @word: string to check
 * Return: 1 if only contains nums, 0 if it has other characters
 */

int has_only_nums(char *word)
{
	int i, hon, num;
	i = hon = 0;
	num = 48;
	if (word == NULL)
		return (0);
	if (word[0] == '-')
		i++;

	for (; word[i] != '\0'; i++)
	{
		while (num < 58)
		{
			if (word[i] == num)
			{
				hon = 1;
				num = 48;
				break;
			}
			num++;
		}
		if (num  >= 58)
			hon = 0;
	}
	return (hon);
}
