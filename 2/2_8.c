#include<stdio.h>
//为了方便验证，改成了unsigned char
//位数是从右到左从0开始计数的
unsigned char setbits(unsigned char x,int p, int n,unsigned char y){
    x = x & (~(~(~0<<n)<<(p+1-n))); //把p位开始的n个位清0
    x = x | ((y&(~(~0<<n)))<<(p+1-n));
    return x;
}

int main(void){
    int n = 3;
    unsigned char x = 126;
    unsigned char temp = x & ~(~0<<n);
    printf("%d",setbits(x,6,n,temp));
}
