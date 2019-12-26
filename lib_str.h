/**
 * file:    lib_str.h
 * author:  wallying@foxmail.com
 * date:    2019-12-17
 **/


#ifndef __LIB_STR_H__
#define __LIB_STR_H__


#ifndef NULL
#define NULL ((void *)0)
#endif


void *mem_set(void *buf, int val, unsigned int num);
void *mem_cpy(void *dst, const void *src, unsigned int num);
void *mem_move(void *dst, const void *src, unsigned int num);
int   mem_cmp(const void *buf1, const void *buf2, unsigned int num);

char *str_cpy(char *dst, const char *src);
char *str_ncpy(char *dst, const char *src, unsigned int num);

char *str_cat(char *dst, const char *src);
char *str_ncat(char *dst, const char *src, unsigned int num);

int str_cmp(const char *str1, const char *str2);
int str_ncmp(const char *str1, const char *str2, unsigned int num);

char *str_chr(const char *str, int c);
char *str_nchr(const char *str, unsigned int num, int c);

unsigned int str_len(const char *str);

char *str_trim(char *str);


#endif /* __LIB_STR_H__ */

