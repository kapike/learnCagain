#include<stdio.h>
int main(){
    unsigned int x = 10;
    int b = 0;
    for(b=0;x!=0;x&=(x-1))
        b++;
    printf("%d",b);
}
