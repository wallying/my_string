/**
 * file:    main.c
 * author:  wallying@foxmail.com
 * date:    2019-12-26
 **/


#include <stdio.h>
#include "lib_str.h"


char testStrA[] = {'A','B','C',' '};
char testStrB[] = "   ";
char testStrC[] = {'X','Y','Z',' '};

int main(int argc, char *argv[])
{
    printf("testStrA = %p\n", testStrA);
    printf("testStrB = %p\n", testStrB);
    printf("testStrC = %p\n", testStrC);

    printf("%s-->%d\n", testStrB, str_len(testStrB));
    str_trim(testStrB);
    printf("%s-->%d\n", testStrB, str_len(testStrB));

    getchar();
    return 0;
}
