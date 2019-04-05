#include<stdio.h>
int main(void){
    char c;
    for(int i = 0; i<5 ;i++){
        if((c=getchar())=='\n') break;
        if(c == EOF) break;
    }
}
