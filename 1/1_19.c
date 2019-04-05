#include<stdio.h>
#include<stdlib.h>
#define MAXLINE 5
int mygetline(char **line,int maxline);
void mycopy(char to[], char from[]);
//尽管我已经知道了s的长度 但是为了题目的一致，单独写一个函数求长度
int mylen(char* s){
    int i =0;
    while(s[i++] != '\0');
    i = i - 2;
    return i;
}
void reverse(char* s){
    char temp;
    int i = 0;
    int len = mylen(s);
    if(s[len] == '\n') len--;
    while(i < len - i){
        temp = s[i];
        s[i] = s[len-i];
        s[len - i] = temp;
        i++;
    }
}
main(){
    int len = 0;
    char *line;
    while ((len = mygetline(&line,MAXLINE)) > 0){
        reverse(line);
        printf("%s",line);
    }
    return 0;
}

int mygetline(char **resultLine,int maxline){
    int i;
    char *line = (char*) malloc(sizeof(char) * maxline);
    if(line == NULL){
        printf("malloc faile");
        exit(1);
    }
    char c;
    for(i = 0; (c = getchar())!=EOF && c != '\n'; ){
        line[i] = c;
        i++;
        if(i == maxline-1 ){
            line[i] = '\0';
            maxline *= 2;
            char *newline = (char*)malloc(sizeof(char)*maxline);
            mycopy(line,newline);
            free(line);
            line = newline;
        }

    }
    if(c == '\n'){
        line[i] = '\n';
        i++;
    }
    line[i] = '\0';
    *resultLine = line;
    return i;
}


void mycopy(char from[], char to[]){
    int i;
    i= 0;
    while((to[i] = from[i]) != '\0')
        i++;
}
