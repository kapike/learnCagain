#include<stdio.h>
#include<limits.h>
int main(void){

    //learn from: www.learntosolveit.com/cprogramming/Ex_2.1_cal_limits.html
    printf("Minimum Signed Char %d\n",-(char)((unsigned char) ~0 >> 1) - 1);
    printf("Maximum Signed char %d\n",(char)((unsigned char)~0>>1));
    //learn from https://www.tutorialspoint.com/c_standard_library/limits_h.htm
    printf("The minimum value of SIGNED CHAR = %d\n", SCHAR_MIN);
}
