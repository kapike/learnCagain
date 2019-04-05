#include<stdio.h>
main(){
    int c = 0;
    while((c = getchar())!=EOF){
        switch(c){
	    case '\t':
//	       putchar('\'');
               putchar('\\')
	       putchar('t');
	       break;
	    default:
	       putchar(c);
	}
    
    }
}
//简略实现 注意此时putchar('\')报错，因为'\' 看成了对'的转义
