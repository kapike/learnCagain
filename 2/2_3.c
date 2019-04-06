#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAXLINE 5
int mygetline(char **line,int maxline);
void mycopy(char to[], char from[]);

void myresize(char **line, int len){

    char* newline = (char*) malloc(sizeof(char)*len);
    mycopy(*line,newline);
    free(*line);
    *line = newline;

}
//因为使用了pow 函数 gcc 编译时候加上 -lm  虽然不知道为什么
//https://stackoverflow.com/questions/12824134/undefined-reference-to-pow-in-c-despite-including-math-h
//
//当数据过大时候不能成功
int htois(char *s,int len){
    int num = 0;
    int digit = 0;
    int i =0;
    if(s[0] == '0' &&(s[1]=='X'||s[1]=='x'))
        i = 2;
    for(;i<len;i++){
        if(s[i]>='0' && s[i]<='9')
            digit = s[i]-'0';
        else if(s[i]>='a' &&s[i]<='f')
            digit = 10+(s[i] - 'a');
        else if(s[i]>= 'A' && s[i]<='F')
            digit = 10+(s[i]-'A');
        else{
            printf("error char %c",s[i]);
            exit(1);
        }
        num += digit * pow(16,len-i-1);
    }
    return  num;
}
int main(){
    int len = 0;
    char *line;
    while ((len = mygetline(&line,MAXLINE)) > 0){
        printf("%d",htois(line,len-1));
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
