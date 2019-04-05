#include<stdio.h>
main(){
   int c;
   int num_space=0;
   int num_tab = 0;
   int num_line = 0;
   while((c = getchar())!= EOF)
        switch(c){
	    case '\n':
	        num_line++;
		break;
	    case '\t':
		num_tab++;
		break;
	    case ' ':
		num_space++;
		break;
	}

   printf("%d %d %d",num_line,num_tab,num_space);
		
}
