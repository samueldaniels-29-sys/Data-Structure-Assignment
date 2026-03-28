#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top=-1;

void push(char ch){
    if(top==MAX-1){
        printf("stack is overflow\n");
    }else{
        top++;
        stack[top]=ch;
    }
}

char pop(){
    if(top==-1){
    printf("stack is underflow\n");
    return '\0';
    }else{
        return stack[top--];
    }
}

int main(){
    char str[MAX];
    int i;

    printf("enter the string");
    scanf("%s",str);

    for(i=0;i<strlen(str);i++){
        push(str[i]);

    }
    for(i=0;i<strlen(str);i++){
        str[i]=pop();
    }
    printf("reversed string:%s\n",str);

    return 0;
}