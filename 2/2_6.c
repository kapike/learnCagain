#include<stdio.h>
//位数是从右到左从0开始计数的
int setbits(int x,int p, int n,int y){
    x = x & (~(~(~0<<n)<<(p+1-n))); //把p位开始的n个位清0
    x = x | ((y&(~(~0<<n)))<<(p+1-n));
    return x;
}
int main(void){
    printf("%d",setbits(31,3,2,2));
}
