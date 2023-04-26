#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

void print_buffer(char buffer[], int *buff_ind);
int handle_print(const char *fmt, int *i, va_list list, char buffer[], int flags, int width, int precision, int size);
int handle_write_char(char c, char buffer[], int flags, int width, int precision, int size);
int write_number(int is_positive, int ind, char buffer[], int flags, int width, int precision, int size);
int write_num(int ind, char bff[], int flags, int width, int precision, int length, char padd, char extra_c);
int write_pointer(char buffer[], int ind, int length, int width, int flags, char padd, char extra_c, int padd_start);


typedef unsigned int uint;
int _ignorefpfwlm(const char *format, uint index);
int _putbin(uint uinum);
int _putaddrp(void *addr);
int _putoct(uint inum);
int _puthex(uint inum);
int _putuint(uint uinum);
char *convrtbase(uint uinum, char c);
char *dectoprntdgt(uint uinum);
int _printf(const char *format, ...);
int _putchar(char c);
int _putstr(char *str);
int _putint(int inum);
int _putfloat(float fnum);
>>>>>>> f30836aafb267ffc7edbb57c4eadd5ca16b87c4a

#endif
