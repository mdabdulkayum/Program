
    // Regrassion Analysis -- recognize strings under 'a*', 'a*b+', 'abb'.

#include<stdio.h>
#include<string.h>
int main(){

    char text[20];
    int i, state=0;
    printf("Enter your text: ");
    gets(text);

    int txtLen = strlen(text);
    
    for(i=0; i<txtLen; i++){
        if(text[i] == 'a' && state == 0){
            state=0;
        }
        else if (text[i] == 'a' && state == 1){
            state=3;
        }
        else if(text[i] != 'a' && text[i] != 'b'){
            state=3;
        }
        else if(state == 0 || state == 1 && text[i] == 'b'){
            state = 1;
        }       
    }

    if(state == 0){
        printf("Accept under a*");
    }
    else if(state == 1){
        if(text[0] == 'a' && text[1] == 'b' && text[2] == 'b'){
            printf("Accept under a*b+ and abb");
        }
        else{
        printf("Accept under a*b+");
        }
    }
    else if(state == 3){
        printf("Rejected");
    }

    return 0;
}