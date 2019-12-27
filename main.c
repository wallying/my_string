/**
 * file:    main.c
 * author:  wallying@foxmail.com
 * date:    2019-12-27
 **/


#include <stdio.h>
#include "lib_str.h"

#include <string.h>

char String1[30] = "12345";
char String2[] = "ABCDEF";




void string_init(void);
void print_cpy(char *dst, const char *src);
void print_cat(char *dst, const char *src);
void print_trim(void);


int main(int argc, char *argv[])
{
    print_cpy(String1, String2);

//    print_cat(String1, String2);

//    print_trim();

    getchar();
    return 0;
}



void string_init(void)
{
    memset(String1, 0x00, sizeof(String1));
    String1[0] = '0';
    String1[1] = '1';
    String1[2] = '2';
    String1[3] = '3';
    String1[4] = '4';
    String1[5] = '5';
    String1[6] = '6';
    String1[7] = '7';
    String1[8] = '8';
    String1[9] = '9';
    String1[10] = '\0';
}

void print_cpy(char *dst, const char *src)
{
    printf("\n============print_cpy()============\n");

    string_init();
    printf("%s-->%d\n", dst, str_len(dst));
    printf("%s-->%d\n", src, str_len(src));
    strcpy(dst, src);
    printf("%s-->%d\n\n", dst, str_len(dst));

    string_init();
    printf("%s-->%d\n", dst, str_len(dst));
    printf("%s-->%d\n", src, str_len(src));
    str_cpy(dst, src);
    printf("%s-->%d\n\n", dst, str_len(dst));


    string_init();
    printf("%s-->%d\n", dst, str_len(dst));
    printf("%s-->%d\n", src, str_len(src));
    strncpy(dst, src, 10);
    printf("%s-->%d\n\n", dst, str_len(dst));

    string_init();
    printf("%s-->%d\n", dst, str_len(dst));
    printf("%s-->%d\n", src, str_len(src));
    str_ncpy(dst, src, 10);
    printf("%s-->%d\n\n", dst, str_len(dst));
}

void print_cat(char *dst, const char *src)
{
    printf("\n============print_cat()============\n");

    string_init();
    printf("%s-->%d\n", dst, str_len(dst));
    printf("%s-->%d\n", src, str_len(src));
    strcat(dst, src);
    printf("%s-->%d\n\n", dst, str_len(dst));

    string_init();
    printf("%s-->%d\n", dst, str_len(dst));
    printf("%s-->%d\n", src, str_len(src));
    str_cat(dst, src);
    printf("%s-->%d\n\n", dst, str_len(dst));

    string_init();
    printf("%s-->%d\n", dst, str_len(dst));
    printf("%s-->%d\n", src, str_len(src));
    strncat(dst, src, 10);
    printf("%s-->%d\n\n", dst, str_len(dst));

    string_init();
    printf("%s-->%d\n", dst, str_len(dst));
    printf("%s-->%d\n", src, str_len(src));
    str_ncat(dst, src, 10);
    printf("%s-->%d\n\n", dst, str_len(dst));
}

void print_trim(void)
{
    printf("\n============print_trim()============\n");

    char *str = NULL;

    char tirmStr1[] = "12345";
    str = tirmStr1;
    printf("%s-->%d\n", str, str_len(str));
    str_trim(str);
    printf("%s-->%d\n\n", str, str_len(str));

    char tirmStr2[] = "   12345";
    str = tirmStr2;
    printf("%s-->%d\n", str, str_len(str));
    str_trim(str);
    printf("%s-->%d\n\n", str, str_len(str));

    char tirmStr3[] = "12345   ";
    str = tirmStr3;
    printf("%s-->%d\n", str, str_len(str));
    str_trim(str);
    printf("%s-->%d\n\n", str, str_len(str));

    char tirmStr4[] = "   12345   ";
    str = tirmStr4;
    printf("%s-->%d\n", str, str_len(str));
    str_trim(str);
    printf("%s-->%d\n\n", str, str_len(str));

    char tirmStr5[] = "   ";
    str = tirmStr5;
    printf("%s-->%d\n", str, str_len(str));
    str_trim(str);
    printf("%s-->%d\n\n", str, str_len(str));

    char tirmStr6[] = "";
    str = tirmStr6;
    printf("%s-->%d\n", str, str_len(str));
    str_trim(str);
    printf("%s-->%d\n\n", str, str_len(str));

    char tirmStr7 = '\0';
    str = &tirmStr7;
    printf("%s-->%d\n", str, str_len(str));
    str_trim(str);
    printf("%s-->%d\n\n", str, str_len(str));
}


