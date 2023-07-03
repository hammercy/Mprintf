#include "main.h"

/**
 * _getdata - gets the data using each conversion specifier
 * @arrdata: pointer to struct dataformat array pointer.
 * @ap: pointer to the optional variable arguments
 * 
 */

int _getdata(struct dataformat *garrdata[], va_list *ap)
{
	void *gptr;
	char *gflgs;
	int i;
	int gprcn;
	int gfwdth;
	int gpsnflg;
	int lk = 0;
	int ck = 0;
	int sk = 0;
	char gcnvchar;
	void *(*_getdatafisseha[8][5])(va_list *ap) = {{_xgetstr, _xgetint,_xgetuint, _xgetdouble, _xgetptr},\
						       {NULL,_xgetsint,_xgetusint,NULL,NULL}, \
						       {NULL,_xgetlint,_xgetulint,NULL,NULL}, \
						       {NULL, NULL,NULL,_xgetldouble,NULL}, \
						       {NULL,NULL,NULL,NULL,NULL}, \
						       {NULL,NULL,NULL,NULL,NULL}, \
						       {NULL,NULL,NULL,_xgetldouble,NULL}, \
						       {NULL,NULL, NULL,NULL,NULL} \
	};


	char* (*_tostrgfisseha[])(void *ptrdata, int fwdth, int prcn, char *flags, char cnv) = \
		{ _putstr, _ctstr, _itstr, _itstr, _ui2binstr, _ui2octstr, \
		  _ui2hexstr, _ui2hexstr, _dftstr, _dftstr, _detstr, _detstr, \
		  _dgtstr, _dgtstr, _datstr, _datstr, _putptr};



	
	(void)gpsnflg;
	if (garrdata == NULL)
		return (0);
	
	for (i = 0; garrdata[i] != NULL; i++)
	{
		gprcn = garrdata[i]->precision;
		gfwdth = garrdata[i]->fwidth;
		lk = garrdata[i]->lengmdfr;
		ck = garrdata[i]->getcnvindex;
		sk = garrdata[i]->tostrindex;
		gflgs = garrdata[i]->flags;
		gpsnflg = garrdata[i]->psnflg;
		gcnvchar = garrdata[i]->convspcfr;
		
		if (gflgs[5] == '*' && gflgs[6] != '$')
		{
			garrdata[i]->fwidth = _xgetfwdth(ap);
			gfwdth = garrdata[i]->fwidth;
		}
		if (gflgs[7] == '*' && gflgs[7] != '$')
		{
			garrdata[i]->precision = _xgetprcn(ap);
			gprcn = garrdata[i]->precision;
		}

		gptr = _getdatafisseha[lk][ck](ap);
		garrdata[i]->ptrdata = gptr;
		garrdata[i]->strdata = _tostrgfisseha[sk](gptr,gfwdth,gprcn,gflgs, gcnvchar);

	}
	return (1);

}
/**
 * _xgetfwdth - get the width from next optional argument list
 * @ap: pointer to optional argument list.
 *
 * Return: the pointer to integer value extracted and stored in memory.
 */
int _xgetfwdth(va_list *ap)
{
	int fwdth;

	fwdth = va_arg(*ap, int);
	return (fwdth);
}
/**
 * _xgetprcn - get the width from next optional argument list
 * @ap: pointer to optional argument list.
 *
 * Return: the pointer to integer value extracted and stored in memory.
 */
int _xgetprcn(va_list *ap)
{
	int prcn;

	prcn = va_arg(*ap, int);
	return (prcn);
}
/**
 * _xgetptr - get the pointer value in hexadecimal.
 * @ap: pointer to optional argument list.
 * 
 * Return: pointer to the string extracted and stored in memory.
 */
void *_xgetptr(va_list *ap)
{
	char *ptr;
	ptr = (char *)malloc(sizeof(char *));
	
	ptr = va_arg(*ap, void *);

	return (ptr);
}

	
/**
 * _xgetstr - get the pointer value in hexadecimal.
 * @ap: pointer to optional argument list.
 * 
 * Return: pointer to the string extracted and stored in memory.
 */
void *_xgetstr(va_list *ap)
{
	char *sptr;

	sptr = va_arg(*ap, char *);

	return (sptr);
}
/**
 * _xgetchar - get character from optinal argument list
 * @ap: pointer to optional argument list.
 * 
 * Return: pointer to the string containing single character and null.
 */

void *_xgetchar(va_list *ap)
{
	char *cptr;

	cptr = (char *)malloc(2);
	if (cptr == NULL)
		return (NULL);

	cptr[0] = (char)va_arg(*ap,int);
	cptr[1] = '\0';

	return (cptr);
}
/**
 * _xgetschar - get character from optinal argument list
 * @ap: pointer to optional argument list.
 * 
 * Return: pointer to the string containing single character and null.
 *
void *_xgetschar(va_list *ap);
{
	schar *cptr;

	scptr = (schar *)malloc(2);
	if (cptr == NULL)
		return (NULL);

	scptr[0] = va_arg(*ap, schar);
	scptr[1] = '\0';

	return (scptr);
}
*/	
/**
 * _xgetuschar - get character from optinal argument list
 * @ap: pointer to optional argument list.
 * 
 * Return: pointer to the string containing single character and null.
 *
void *_xgetuschar(va_list *ap);
{
	uschar *cptr;

	uscptr = (uschar *)malloc(2);
	if (uscptr == NULL)
		return (NULL);

	uscptr[0] = va_arg(*ap, uschar);
	uscptr[1] = '\0';

	return (uscptr);
}
*/	

/**
 * _xgetint - get the int value from optional argument list
 * @ap: pointer optional arguments list.
 *
 * Return: pointer to integer extracted.
 */
void *_xgetint(va_list *ap)
{
	int *iptr;

	iptr = (int *)malloc(sizeof(int));
	if (iptr == NULL)
		return (NULL);
	*iptr = va_arg(*ap, int);
	return (iptr);
}
/**
 * _xgetlint - get the int value from optional argument list
 * @ap: pointer optional arguments list.
 *
 * Return: pointer to integer extracted.
 */
void *_xgetlint(va_list *ap)
{
	lint *liptr;

	liptr = (lint *)malloc(sizeof(lint));
	if (liptr == NULL)
		return (NULL);
	*liptr = va_arg(*ap, lint);
	return (liptr);
}
/**
 * getllint - get the int value from optional argument list
 * @ap: pointer optional arguments list.
 *
 * Return: pointer to integer extracted.
 *
void *getllint(va_list ap)
{
	llint *lliptr;

	lliptr = (llint *)malloc(sizeof(llint));
	if (lliptr == NULL)
		return (NULL);
	*lliptr = va_arg(ap, llint);
	return (lliptr);
}
*/
/**
 * _xgetulint - get the int value from optional argument list
 * @ap: pointer optional arguments list.
 *
 * Return: pointer to integer extracted.
 */
void *_xgetulint(va_list *ap)
{
	ulint *uliptr;

	uliptr = (ulint *)malloc(sizeof(ulint));
	if (uliptr == NULL)
		return (NULL);
	*uliptr = va_arg(*ap, ulint);
	return (uliptr);
}
/**
 * _xgetullint - get the int value from optional argument list
 * @ap: pointer optional arguments list.
 *
 * Return: pointer to integer extracted.
 *
void *_xgetullint(va_list *ap)
{
	ullint *ulliptr;

	ulliptr = (ullint *)malloc(sizeof(ullint));
	if (ulliptr == NULL)
		return (NULL);
	*ulliptr = va_arg(*ap, ullint);
	return (ulliptr);
}
*/
/**
 * _xgetsint - get the int value from optional argument list
 * @ap: pointer optional arguments list.
 *
 * Return: pointer to integer extracted.
 */
void *_xgetsint(va_list *ap)
{
	sint *siptr;

	siptr = (sint *)malloc(sizeof(sint));
	if (siptr == NULL)
		return (NULL);
	*siptr = (sint)va_arg(*ap, int);
	return (siptr);
}
/**
 * getusint - get the int value from optional argument list
 * @ap: pointer optional arguments list.
 *
 * Return: pointer to integer extracted.
 */
void *_xgetusint(va_list *ap)
{
	int *usiptr;

	usiptr = (int *)malloc(sizeof(int));
	if (usiptr == NULL)
		return (NULL);
	*usiptr = va_arg(*ap, int);
	return (usiptr);
}


/**
 * _xgetdouble - get the double value from optional argument lisst
 * @ap: pointer to optional arguments list.
 * 
 * Return: pointer to double value extracted and stored.
 */

void *_xgetdouble(va_list *ap)
{
	double *dptr;

	dptr = (double *)malloc(sizeof(double));
	if (dptr == NULL)
		return (NULL);
	*dptr = va_arg(*ap, double);
	return (dptr);
}
/**
 * _xgetldouble - get the double value from optional argument lisst
 * @ap: pointer to optional arguments list.
 * 
 * Return: pointer to double value extracted and stored.
 */

void *_xgetldouble(va_list *ap)
{
	ldouble *ldptr;

	ldptr = (ldouble *)malloc(sizeof(ldouble));
	if (ldptr == NULL)
		return (NULL);
	*ldptr = va_arg(*ap, ldouble);
	return (ldptr);
}


/**
 * _xgetuint - get the unsigned int value from optional arguments list.
 * @ap: pointer to opteional arguments list.
 *
 * Return: pointer to the uint value extracted and strored.
 */

void *_xgetuint(va_list *ap)
{
	uint *uiptr;

	uiptr = (uint *)malloc(sizeof(uint));
	*uiptr = va_arg(*ap, uint);
	return (uiptr);
}
/**
 * _printstrdata - prints the str in the buffer sequentially.
 * @strbuffer -hold the chara string to be printed
 * @arrdata: holds the str format of  double,int, and char string to be printed
 *
 * Return: number of printed data.
 */
int _printstrdata(char *strbuffer, struct dataformat *arrdata[])
{
	int i, j, k;
	int cnt = 0;

	j = 0;
	for (i = 0; strbuffer[i] != '\0'; i++)
	{
		if (strbuffer[i] == '*' && strbuffer[i + 1] == '$' && strbuffer[ i + 2] == '0')
		{
			if(strbuffer[i + 3] == '#' && strbuffer[i + 4] == '*')
			{
				for (k = 0; arrdata[j]->strdata[k] != '\0'; k++)
				{
					_putchar(arrdata[j]->strdata[k]);
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
	
			
		
	
	
