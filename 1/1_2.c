#include<stdio.h>

main(){
    printf("hello ");
    printf("1_2.c");
    printf("\c");
}

/*
 * 使用\c的时候会出
 * warning: unknown escape sequence '\
 * 这是因为\在c语言中是起转义的作用，而\c没有对应的转义
 */
