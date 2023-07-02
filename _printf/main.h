#ifndef MAIN_H
#define MAIN_H

#define UNSED(x) (void)(x)
#define BUFFERSIZE 1024

typedef unsigned int uint;
typedef unsigned long int ulint;
typedef long int lint;
typedef long long int llint;
typedef unsigned long long int ullint;
typedef short int sint;
typedef unsigned short int usint;
typedef short char schar;
typedef unsigned short char uschar;
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

void *getint(va_list);
void *getdouble(va_list);
void *getuint(va_list);
void *getstr(va_list);
void *getchar(va_list);
void *getschar(va_list);
void *getuschar(va_list);	
void *getsint(va_list);
void *getusint(va_list);
void *getlint(va_list);
void *getulint(va_list);
void *getllint(va_list);
void *getullint(va_list);
void *getldouble(va_list);
void *getwchar(va_list);
void *getintmax(va_list);
void *getwint(va_list);
void *getsize_t(va_list);
void *getssize_t(va_list);
int _printf(const char *format, ...);
int _putchar(char c);
int _strlen(char *s);
char *_putstr(void *ptrdata, int fwdth, int prcn, char *flags, char cnv);
char *_ctostr(void *ptrdata, int fwdth, int prcn, char *flags, char cnv);
char *_itostr(void *ptrdata, int fwdth, int prcn, char *flags, char cnv);
char *_ui2binstr(void *ptrdata, int fwdth, int prcn, char *flags, char cnv);
char *_ui2octstr(void *ptrdata, int fwdth, int prcn, char *flags, char cnv);
char *_ui2hexstr(void *ptrdata, int fwdth, int prcn, char *flags, char cnv);
char *dftostr(void *ptrdata, int fwdth, int prcn, char *flags, char cnv);
char *detostr(void *ptrdata, int fwdth, int prcn, char *flags, char cnv);
char *dgtostr(void *ptrdata, int fwdth, int prcn, char *flags, char cnv);
char *datostr(void *ptrdata, int fwdth, int prcn, char *flags, char cnv);
char *_putptr(void *ptrdata, int fwdth, int prcn, char *flags, char cnv);
int _printstrdata(char *strbuffer, struct dataformat **arrdata);
int _getdata(struct dataformat *arrdata[], va_list arg);
void *(*getptrfun[8][5])(va_list ap) = {{getstr, getint,getuint,getdouble,getptr},\
					{NULL,getsint,getusint,NULL,NULL,NULL}, \
					{getwchar,getlint,getulint,NULL,NULL},\
					{NULL, getllint,getullint,getldouble,NULL},\
					{NULL,getssize_t,getsize_t,NULL,NULL},\
					{NULL,NULL,NULL,NULL,NULL,NULL},\
					{NULL,getllint,getullint,getldouble,NULL}
					{NULL,getschar, getuschar,NULL,NULL}};


char *(*tostrptrfun[])(void *ptrdata, int fwdth, int prcn, char *flags, char *cnvchar) = { _putstr,_ctostr,_itostr,_itostr, _ui2binstr,_ui2octstr,_ui2hexstr,_ui2hexstr,dftostr, dftostr,detostr,detostr, dgtostr, dgtostr,datostr, datostr, _putptr};



#endif
