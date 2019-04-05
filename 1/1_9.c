#include<stdio.h>
main(){
   int c;
   int flag = 1;
   while((c = getchar())!=EOF){
       if(c == ' '){
         if(flag){
	    flag = 0;
	    putchar(c);
	 }
       }else{
         flag = 1;
	 putchar(c);
       }
   }
}
