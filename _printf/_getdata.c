#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * _getdata - gets the data using each conversion specifier
 * @arrdata: pointer to struct dataformat array pointer.
 * @arg: pointer to the optional variable arguments
 * @convspcfr: string containing the conversion specifiers.
 * @datatype: string containing the datatype for arg in vardiac.
 * 
 */

int _getdata(struct dataformat *arrdata[], va_list arg)
{
	void *ptr;
	char *flgs;
	uint i, j;
	int prcn;
	int fwdth;
	int lk;
	int ck;
	int sk;
	char cnvchar;
	
	if (arrdata == NULL)
		return (0);
	
	for (i = 0; arrdata[i] != NULL; i++)
	{
		prcn = arrdata[i]->precision;
		fwdth = arrdata[i]->fwidth;
		lk = arrdata[i]->lengmdfr;
		ck = arrdata[i]->getcnvindex;
		sk = arrdata[i]->tostrindex;
		flgs = arrdata[i]->flags;
		psnflg = arradata[i]
		
		if (flags[5] == '*' && flags[6] != '$')
		{
			arrdata[i]->fwidth = getfwdth(arg);
			fwdth = arrdata[i]->fwidth;
		}
		if (flags[7] == '*' && flags[7] != '$')
		{
			arrdata[i]->precision = getprcn(arg);
			prcn = arrdata[i]->precision;
		}

		ptr = getptrfunc[lk][ck](arg);
		arrdata[i]->ptrdata = ptr;
		arrdata[i]->strdata = tostrptrfun[sk](ptr,fwdth,prcn,flgs, cnvchar);

	}
	return (1);

}
/**
 * getwidth - get the width from next optional argument list
 * @ap: pointer to optional argument list.
 *
 * Return: the pointer to integer value extracted and stored in memory.
 */
int getfwidth(va_list ap)
{
	int fwdth;

	fwdth = va_agr(ap, int);
	return (fwdth);
}
/**
 * getwidth - get the width from next optional argument list
 * @ap: pointer to optional argument list.
 *
 * Return: the pointer to integer value extracted and stored in memory.
 */
int getprcn(va_list ap)
{
	int prcn;

	prcn = va_agr(ap, int);
	return (prcn);
}
	
/**
 * getstr - get the pointer value in hexadecimal.
 * @ap: pointer to optional argument list.
 * 
 * Return: pointer to the string extracted and stored in memory.
 */
void *getstr(va_list ap)
{
	char *sptr;
	
	sptr = va_arg(ap, (char *));

	return (sptr);
}
/**
 * getchar - get character from optinal argument list
 * @ap: pointer to optional argument list.
 * 
 * Return: pointer to the string containing single character and null.
 */

void *getchar(va_list)
{
	char *cptr;

	cptr = (char *)malloc(2);
	if (cptr == NULL)
		return (NULL);

	cptr[0] = va_arg(ap, char);
	cptr[1] = '\0';

	return (cptr);
}
/**
 * getschar - get character from optinal argument list
 * @ap: pointer to optional argument list.
 * 
 * Return: pointer to the string containing single character and null.
 */
void *getschar(va_list);
{
	schar *cptr;

	scptr = (schar *)malloc(2);
	if (cptr == NULL)
		return (NULL);

	scptr[0] = va_arg(ap, schar);
	scptr[1] = '\0';

	return (scptr);
}	
/**
 * getuschar - get character from optinal argument list
 * @ap: pointer to optional argument list.
 * 
 * Return: pointer to the string containing single character and null.
 */
void *getuschar(va_list);
{
	uschar *cptr;

	uscptr = (uschar *)malloc(2);
	if (uscptr == NULL)
		return (NULL);

	uscptr[0] = va_arg(ap, uschar);
	uscptr[1] = '\0';

	return (uscptr);
}	

/**
 * getint - get the int value from optional argument list
 * @ap: pointer optional arguments list.
 *
 * Return: pointer to integer extracted.
 */
void *getint(va_list ap)
{
	int *iptr;

	iptr = (int *)malloc(sizeof(int));
	if (iptr == NULL)
		return (NULL);
	*iptr = va_arg(ap, int);
	return (iptr);
}
/**
 * getlint - get the int value from optional argument list
 * @ap: pointer optional arguments list.
 *
 * Return: pointer to integer extracted.
 */
void *getlint(va_list ap)
{
	lint *liptr;

	liptr = (lint *)malloc(sizeof(lint));
	if (liptr == NULL)
		return (NULL);
	*liptr = va_arg(ap, lint);
	return (liptr);
}
/**
 * getllint - get the int value from optional argument list
 * @ap: pointer optional arguments list.
 *
 * Return: pointer to integer extracted.
 */
void *getllint(va_list ap)
{
	llint *lliptr;

	lliptr = (llint *)malloc(sizeof(llint));
	if (lliptr == NULL)
		return (NULL);
	*lliptr = va_arg(ap, llint);
	return (lliptr);
}
/**
 * getulint - get the int value from optional argument list
 * @ap: pointer optional arguments list.
 *
 * Return: pointer to integer extracted.
 */
void *getulint(va_list ap)
{
	ulint *uliptr;

	uliptr = (ulint *)malloc(sizeof(ulint));
	if (uliptr == NULL)
		return (NULL);
	*uliptr = va_arg(ap, ulint);
	return (uliptr);
}
/**
 * getullint - get the int value from optional argument list
 * @ap: pointer optional arguments list.
 *
 * Return: pointer to integer extracted.
 */
void *getullint(va_list ap)
{
	ullint *ulliptr;

	ulliptr = (ullint *)malloc(sizeof(ullint));
	if (ulliptr == NULL)
		return (NULL);
	*ulliptr = va_arg(ap, ullint);
	return (ulliptr);
}

/**
 * getsint - get the int value from optional argument list
 * @ap: pointer optional arguments list.
 *
 * Return: pointer to integer extracted.
 */
void *getsint(va_list ap)
{
	sint *siptr;

	siptr = (sint *)malloc(sizeof(sint));
	if (siptr == NULL)
		return (NULL);
	*siptr = va_arg(ap, usint);
	return (siptr);
}
/**
 * getusint - get the int value from optional argument list
 * @ap: pointer optional arguments list.
 *
 * Return: pointer to integer extracted.
 */
void *getusint(va_list ap)
{
	sint *siptr;

	usiptr = (usint *)malloc(sizeof(usint));
	if (siptr == NULL)
		return (NULL);
	*usiptr = va_arg(ap, usint);
	return (usiptr);
}


/**
 * getdouble - get the double value from optional argument lisst
 * @ap: pointer to optional arguments list.
 * 
 * Return: pointer to double value extracted and stored.
 */

void *getdouble(va_list ap)
{
	double *dptr;

	dptr = (double *)malloc(sizeof(double));
	if (dptr == NULL)
		return (NULL);
	*dptr = va_arg(ap, double);
	return (dptr);
}
/**
 * getldouble - get the double value from optional argument lisst
 * @ap: pointer to optional arguments list.
 * 
 * Return: pointer to double value extracted and stored.
 */

void *getldouble(va_list ap)
{
	ldouble *dptr;

	ldptr = (ldouble *)malloc(sizeof(ldouble));
	if (ldptr == NULL)
		return (NULL);
	*ldptr = va_arg(ap, ldouble);
	return (ldptr);
}


/**
 * getuint - get the unsigned int value from optional arguments list.
 * @ap: pointer to opteional arguments list.
 *
 * Return: pointer to the uint value extracted and strored.
 */

void *getuint(va_list ap)
{
	uint *uiptr;

	uiptr = (uint *)malloc(sizeof(uint));
	*uiptr = va_arg(ap, uint);
	return (uiptr);
}
/**
 * _putstr - format string in the specified format
 * @ptrdata: pointer to string to be formated
 * @fwidth: field width for the data the minimum array size for the string
 * @precision: precision for decial point ingonerd in this function.
 * @flags: pointer to flags that indicate how to be formated. such alignment
 * 
 * Return: pointer to the formated string.
 */
char *_putstr(void *ptrdata, int fwidth, int precision, char *flags)
{
	int slen, strln, ln;
	uint i, j, k;
	char *strptr;

	UNUSED(precision);
	ptrdata = (char *)ptrdata;
	slen = _strlen(ptrdata);

	if (slen < fwidth)
	{
		strln = fwidth + 1;
		ln = fwidth - slen;
		strptr = (char *)malloc(strln * sizeof(char));
		if (strptr != NULL && flags[4] != '-')
		{
			for (i = 0; i < ln; i++)
				strptr[i] = ' ';
			for (i = ln; i < strln - 1; i++)
				strptr[i] = ptrdata[i - ln];
			strptr[strln - 1] = '\0';
		}
		else if (strptr != NULL  && flags[4] == '-')
		{
			for (i = 0; i < slen; i++)
				strptr[i] = ptrdata[i];
			for (i = slen; i < strln - 1; i++)
				strptr[i] = ' ';
			strptr[strln - 1] = '\0';
		}
		else if (strptr == NULL)
		{
			return (NULL);
		}
			
	}
	else
	{
		strln = slen + 1;
		strptr = (char *)malloc((strln) * sizeof(char));
		if (strptr == NULL)
			return (NULL);
		else
		{
			for (i = 0; i < strln - 1; i++)
				strptr[i] = ptrdata[i];
			strptr[strln - 1] = '\0';
		}
	}
	return (strptr);
}
/**
 * chartostr - change character to string for printing by printf
 * @ptrdata: pointer to string to be formated
 * @fwidth: field width for the data the minimum array size for the string
 * @precision: precision for decial point ingonerd in this function.
 * @flags: pointer to flags that indicate how to be formated. such alignment
 * 
 * Return: pointer to the formated string.
 */
char *chartostr(void *ptrdata, int fwidth, int precision, char *flags)
{
	char *strptr;

	ptrdata = (char *)ptrdata;
	UNUSED(fwidth);
	UNUSEDD(precision);
	UNUSED(flags);

	strptr = (char *)malloc(2*sizeof(char));
	if (strptr == NULL)
	{
		return (NULL);
	}
	else
	{
		strptr[0] = ptrdata[0];
		strptr[1] = '\0';
	}

	return (strptr);
}

int _printstrdata(char *strbuffer, struct dataformat **arrdata)
{
	uint i, j, k;
	int cnt = 0;

	j = 0;
	for (i = 0; strbuffer[i] != '\0'; i++)
	{
		if (strbuffer[i] == '*' && strbuffer[i + 1] == '$' && strbuffer[ i + 2] == '0')
		{
			if(strbuffer[i + 3] == '#' && strbuffer[i + 4] == '*')
			{
				for (k = 0; *arrdata[j]->strdata[k] != '\0'; k++)
				{
					_putchar(*arrdata[j]->strdata[k]);
					cnt++;
				}
				i = i + 5;
				j++;
			}
		}
		_putchar(strbuffer[i]);
		cnt++;
	}
	return (cnt);
}
	
			
		
	
	