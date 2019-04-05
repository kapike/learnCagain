#include<stdio.h>
#include<stdlib.h>
#define MAXLINE 5
int mygetline(char **line,int maxline);
void mycopy(char to[], char from[]);

void entab(char*s, int len){
    int loc = 0;
    int num_tab, num_space;
    for(int i = 0; i < len; i++){
        if(s[i] == ' '){
            int num = 0;
            while(s[i] == ' '){
                i++;
                num ++;
            }
            num_tab = num/8;
            num_space = num%8;
            int end = loc + num_tab;
            while(loc < end){
                s[loc++] = '\t';
            }
            end = loc + num_space;
            while(loc < end){
                s[loc++] = ' ';
            }
        }else{
            s[loc++] = s[i];
        }
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
