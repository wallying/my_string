/**
 * file:    lib_str.c
 * author:  wallying@foxmail.com
 * date:    2019-12-26
 **/


#include "lib_str.h"



void *mem_set(void *buf, int val, unsigned int num)
{
    void *ptr = buf;
    while (num--) {
        *(char *)buf++ = (char)val;
    }
    return ptr;
}


void *mem_cpy(void *dst, const void *src, unsigned int num)
{
    void *ptr = dst;
    while (num--) {
        *(char *)dst++ = *(char *)src++;
    }
    return ptr;
}


void *mem_move(void *dst, const void *src, unsigned int num)
{
    char *pdst = dst;
    const char *psrc = src;
    if (dst <= src) {
        while (num--) {
            *pdst++ = *psrc++;
        }
    } else {
        pdst += num;
        psrc += num;
        while (num--) {
            *--pdst = *--psrc;
        }
    }
    return dst;
}


int mem_cmp(const void *buf1, const void *buf2, unsigned int num)
{
    int ret = 0;
    while (num--) {
        if ((ret = *(char *)buf1++ - * (char *)buf2++) != 0) {
            break;
        }
    }
    return ret;
}


char *str_cpy(char *dst, const char *src)
{
    char *ptr = dst;
    while ((*dst++ = *src++) != '\0');
    return ptr;
}


char *str_ncpy(char *dst, const char *src, unsigned int num)
{
    char *ptr = dst;
    while (num--) {
        if ((*dst++ = *src) != '\0') {
            ++src;
        }
    }
    return ptr;
}


char *str_cat(char *dst, const char *src)
{
    char *ptr = dst;
    while (*dst) {
        ++dst;
    }
    while ((*dst++ = *src++) != '\0');
    return ptr;
}


char *str_ncat(char *dst, const char *src, unsigned int num)
{
    char *ptr = dst;
    if (num) {
        while (*dst) {
            ++dst;
        }
        while ((*dst++ = *src++) != '\0' && !--num) {
            *dst = '\0';
            break;
        }
    }
    return ptr;
}


int str_cmp(const char *str1, const char *str2)
{
    int ret = 0;
    while (1) {
        if ((ret = *str1 - *str2++) != 0 || !*str1++) {
            break;
        }
    }
    return ret;
}


int str_ncmp(const char *str1, const char *str2, unsigned int num)
{
    int ret = 0;
    while (num--) {
        if ((ret = *str1 - *str2++) != 0 || !*str1++) {
            break;
        }
    }
    return ret;
}


char *str_chr(const char *str, int c)
{
    for (; *str != (char)c; ++str) {
        if (*str == '\0') {
            return NULL;
        }
    }
    return (char *)str;
}


char *str_nchr(const char *str, unsigned int num, int c)
{
    while (num--) {
        if (*str == (char)c) {
            return (char *)str;
        }
        if (*str++ == '\0') {
            break;
        }
    }
    return NULL;
}

char *str_str(const char *str, const char *srch)
{
    unsigned int l1, l2;

    l2 = str_len(srch);
    if (!l2) {
        return (char *)str;
    }
    l1 = str_len(str);
    while (l1 >= l2) {
        l1--;
        if (!mem_cmp(str, srch, l2)) {
            return (char *)str;
        }
        str++;
    }
    return NULL;
}

char *str_nstr(const char *str, const char *srch, unsigned int num)
{
    unsigned int len;

    len = str_len(srch);
    if (!len) {
        return (char *)str;
    }
    while (num >= len) {
        num--;
        if (!mem_cmp(str, srch, len)) {
            return (char *)str;
        }
        str++;
    }
    return NULL;
}


unsigned int str_len(const char *str)
{
    const char *ptr = str;
    for (; *ptr != '\0'; ++ptr);
    return ptr - str;
}


#define isspace(c) \
        (((c) == ' ')  || ((c) == '\r') || \
         ((c) == '\n') || ((c) == '\f') || \
         ((c) == '\t') || ((c) == '\v'))

char *str_trim(char *str)
{
    char *ptr = str;
    char *end = str;

    while ((isspace(*ptr))) {
        ++ptr;
    }

    if (ptr != str) {
        while ((*end++ = *ptr++) != '\0');
    } else {
        while (*end++ != '\0');
    }

    end -= 2;
    while ((end >= str) && (isspace(*end))) {
        --end;
    }
    *(end + 1) = '\0';

    return str;
}
