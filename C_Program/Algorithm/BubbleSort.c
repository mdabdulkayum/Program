#include<stdio.h>
int main(){
    int size, i, j, temp;
    printf("Enter how many digit you want: ");
    scanf("%d",&size);
    int num[size];

    for(i=0; i<size; i++){
        printf("Enter Digit %d: ",i+1);
        scanf("%d",&num[i]);
    }

    for(i=0; i<size-1; i++){
        for(j=0; j<(size-1-i); j++){
            if(num[j]>num[j+1]){
                temp=num[j];
                num[j]=num[j+1];
                num[j+1]=temp;
            }
        }
    }

    printf("Bubble sort -- Assending Order: ");
    for(i=0; i<size; i++){
        printf("%d \t",num[i]);
    }

    return 0;
}
