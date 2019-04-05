#include<stdio.h>
#include<stdlib.h>
#define MAXLINE 5
int mygetline(char **line,int maxline);
void mycopy(char to[], char from[]);

void myresize(char **line, int len){

    char* newline = (char*) malloc(sizeof(char)*len);
    mycopy(*line,newline);
    free(*line);
    *line = newline;

}

void detab(char**line, int len){
    len = 2 * len;
    char *s = *line;
    char *newline = (char*) malloc(sizeof(char) * len);
    int loc = 0;
    int spacenum = 0;
    int s_len = len;
    for(int i = 0; i<=s_len; i++){
        if(s[i] == '\t'){
            spacenum = 8 - loc%8;
           // printf("%d",loc+spacenum-1);
            if(loc + spacenum-1  >= len ){
                newline[loc] = '\0';
                len = len*2;
                myresize(&newline,len);
            }
            spacenum = loc + spacenum;
            while(loc < spacenum)
                newline[loc++] = ' ';
        }else{
            if(loc >= len){
                newline[loc] = '\0';
                len = len*2;
                myresize(&newline,len);
            }
            newline[loc++] = s[i];
        }
    }
    free(s);
    *line = newline;
}
main(){
    int len = 0;
    char *line;
    while ((len = mygetline(&line,MAXLINE)) > 0){
        detab(&line,len);
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
