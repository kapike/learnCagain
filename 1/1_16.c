#include<stdio.h>
#include<stdlib.h>
#define MAXLINE 5
int mygetline(char **line,int maxline);
void mycopy(char to[], char from[]);


main(){
    int len = 0;
    int max = 0;
    char *line;
    char *longest = NULL;

    max = 0;
    while ((len = mygetline(&line,MAXLINE)) > 0)
        if(len > max){
            max = len;
            if(longest != NULL)
                free(longest);
            longest = line;
        }
    if(max > 0)
        printf("%s", longest);
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
