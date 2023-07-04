#include "main.h"

/** 
 * _handleflgs - handle the flags and format accordingly
 * @dGtstr: digits of number in string.
 * @ifstr: the string that holds the formated number
 * @iflen: holds the size of the ifstr;
 * @sign: holds sign of a number 0-for positive, 1-negative
 * @flags: holds the flags
 *
 * Return: the pointer to ifstr.
 */

char * _handleflgs(char *dGtstr, char *ifstr, int dffln, int sign, char *flags)
{
	int strlen, k;
	int sk;
	int pk;
	int dk;
	char pchar;
	char arr[dffln];
	for (i = 0; i < dffln; i++)
		arr[i] = '\0';

	if (flags[3] == '0' && flags[4] != '-')
	{
		sk = 0;
		for (pk = 1; pk < dffln - 1; pk++)
			arr[pk] = '0';
	}
	else if (flags[3] != '0' && flags[4] != '-')
	{
		sk = dffln - 2;
		for (pk = 0; pk < dffln - 2; pk++)
			arr[pk] = ' ';
	}
	else
	{
		sk = 0;
	}
	if (flags[1] == '+')
	{
		if (sign == 0)
			arr[sk] = '+';
		else if (sign == 1)
			arr[sk] = '-';
	}
	else if (flags[1] != '+' && flags[2] == ' ')
	{
		if (sign == 0)
			arr[sk] = ' ';
		else if (sign == 1)
			arr[sk] == '-';
	}
	else
	{
		if ( sign == 0)
			;
		else if (sign = 1)
			arr[sk] = '-';
	}
	
	for (k = 0; arr[k] != '\0'; k++)
	{
		ifstr[k] = arr[k];
		
	}
	for (k = 0; dGtstr[k] != '\0'; k++)
	{
		ifstr[k] = dGtstr[k];
		
	}
	ifstr[k] == '\0';
	return (ifstr);
		
}
			

	
		
	
	
