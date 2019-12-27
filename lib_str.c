/**
 * file:    lib_str.c
 * author:  wallying@foxmail.com
 * date:    2019-12-26
 **/


#include "lib_str.h"



void *mem_set(void *buf, int val, unsigned int num)
{
    char *ptr = buf;
    while (num--) {
        *ptr++ = (char)val;
    }
    return buf;
}


void *mem_cpy(void *dst, const void *src, unsigned int num)
{
    char *ptr = dst;
    while (num--) {
        *ptr++ = *(char *)src++;
    }
    return dst;
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
        if ((ret = *(char *)buf1++ - *(char *)buf2++) != 0) {
            break;
        }
    }
    return ret;
}


char *str_cpy(char *dst, const char *src)
{
    char *ptr = dst;
    for (; (*ptr = *src); ++ptr, ++src);
    return dst;
}


char *str_ncpy(char *dst, const char *src, unsigned int num)
{
    char *ptr = dst;
    for (; num; --num) {
        if ((*ptr++ = *src) != '\0') {
            ++src;
        }
    }
    return dst;
}


char *str_cat(char *dst, const char *src)
{
    char *ptr = dst;
    for (; *ptr; ++ptr);
    for (; (*ptr = *src); ++ptr, ++src);
    return dst;
}


char *str_ncat(char *dst, const char *src, unsigned int num)
{
    char *ptr = dst;
    if (num) {
        for (; *ptr; ++ptr);
        for (; num && (*ptr = *src); --num, ++ptr, ++src);
        *ptr = '\0';
    }
    return dst;
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


char *str_chr(const char *str, int chr)
{
    for (; *str != (char)chr; ++str) {
        if (*str == '\0') {
            return NULL;
        }
    }
    return (char *)str;
}


char *str_nchr(const char *str, unsigned int num, int chr)
{
    while (num--) {
        if (*str == (char)chr) {
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
    for (; *ptr; ++ptr);
    return ptr - str;
}


#define isspace(c) \
    (((c) == ' ')  || ((c) == '\n') || ((c) == '\t') || \
     ((c) == '\r') || ((c) == '\f') || ((c) == '\v'))

char *str_trim(char *str)
{
    char *ptr = str;
    char *end = str;

    while ((isspace(*ptr))) {
        ++ptr;
    }

    if (ptr == str) {
        for (; *end; ++end);
    } else {
        for (; (*end = *ptr); ++end, ++ptr);
    }

    do {
        --end;
    } while ((end >= str) && (isspace(*end)));
    *(end + 1) = '\0';

    return str;
}
