#include<stdio.h>
#include<stdlib.h>
#define MAXLINE 5
#define OUT 0
#define IN 1
int mygetline(char **line,int maxline);
void mycopy(char to[], char from[]);

void linerstrip(char*s, int len){
    for(int i = len; s[i]!= ' ' && s[i]!= '\t' && s[i]>=0; i--);
    s[i+1] = '\0';
}
void fold(char*s,int len, int column){
    char* newline = (char*) malloc(sizeof(char) *len);
    int pos = 0;
    for(int i =0; i<len; i++){
        newline[pos] = s[i];
        if()
    }
}


main(){
    int len = 0;
    char *line;
    while ((len = mygetline(&line,MAXLINE)) > 0){
        entab(line,len);
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
