#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <limits.h>
#define UNUSED(x) (void)(x)
#define BUFFERSIZE 1024

typedef unsigned int uint;
typedef unsigned long int ulint;
typedef long int lint;
/*typedef long long int llint;
  typedef unsigned long long int ullint;*/
typedef short int sint;
typedef unsigned short int usint;
/*typedef short char schar;
  typedef unsigned short char uschar; */
typedef long double ldouble;
/**
 * struct formatdata - structure for data string to be foramted and its flags
 * @ptrdata : pointer to the actual datatype
 * @strdata: holds the formated string data.
 * @cnvpsn: holds the index for the converstion specifier in optional argument list
 * @psnflg: flags that the value in fwidth and precision are index position in argmunet list.
 * @fwidth: the field width of the number to be printed
 * @precision: the number of digits after decimal point
 * @lengmdfr: holdels the length modifier for the conversion specifiers.
 * @getcnvindex: holds the index for getdata function pointers.
 * @tostrindex: holds the index for tostr function  pointers.
 * @convspcfr: conversion specifiers holder suchas d- decimal i- integer f&d-floatingpoint
 * @flags: holds the flags for the data in which way to be formated.
 *
 * Descritption: in flags position 
 *               0-#(converstionflag) 1-sign flag(+) 2-invisible plus sign(' ')
 *               3-paddingflag(' ' for space, 0 for zero padding) 4-alignment flag (-)
 *              : fieldwidth always precedes precision.
 *              psnflg: 0- the value is in fwidth and prcn is actual value;\
 *                      1- the value in the fwidth and prcn is index postion in argument list.
 *                         
 */
struct dataformat
{
	void *ptrdata;
	char *strdata;
	int cnvpsn;
	int psnflg;
	int fwidth;
	int precision;
	int lengmdfr;
	int getcnvindex;
	int tostrindex;
	char convspcfr;
	char flags[10];
};
char *_brkdGttostr(size_t dGtnum);
int _xgetfwdth(va_list *ap);
int _xgetprcn(va_list *ap);
void *_xgetint(va_list *ap);
void *_xgetdouble(va_list *ap);
void *_xgetuint(va_list *ap);
void *_xgetstr(va_list *ap);
void *_xgetptr(va_list *ap);
void *_getchar(va_list *ap);
/*void *getschar(va_list);*
  void *getuschar(va_list);*/	
void *_xgetsint(va_list *ap);
void *_xgetusint(va_list *ap);
void *_xgetlint(va_list *ap);
void *_xgetulint(va_list *ap);
/*void *getllint(va_list *ap);
  void *getullint(va_list *ap);*/
void *_xgetldouble(va_list *ap);
/*void *getwchar(va_list *ap);
void *getintmax(va_list *ap);
void *getwint(va_list *ap);
void *getsize_t(va_list *ap);
void *getssize_t(va_list *ap);*/

int _printf(const char *format, ...);
int _putchar(char c);
int _strlen(char *s);
char *_putstr(void *ptrdata, int fwdth, int prcn, char *flags, char cnv);
char *_ctstr(void *ptrdata, int fwdth, int prcn, char *flags, char cnv);
char *_itstr(void *ptrdata, int fwdth, int prcn, char *flags, char cnv);
char *_ui2binstr(void *ptrdata, int fwdth, int prcn, char *flags, char cnv);
char *_ui2octstr(void *ptrdata, int fwdth, int prcn, char *flags, char cnv);
char *_ui2hexstr(void *ptrdata, int fwdth, int prcn, char *flags, char cnv);
char *_dftstr(void *ptrdata, int fwdth, int prcn, char *flags, char cnv);
char *_detstr(void *ptrdata, int fwdth, int prcn, char *flags, char cnv);
char *_dgtstr(void *ptrdata, int fwdth, int prcn, char *flags, char cnv);
char *_datstr(void *ptrdata, int fwdth, int prcn, char *flags, char cnv);
char *_putptr(void *ptrdata, int fwdth, int prcn, char *flags, char cnv);
int _printstrdata(char *strbuffer, struct dataformat *arrdata[]);
int _getdata(struct dataformat *garrdata[], va_list *ap);

#endif
