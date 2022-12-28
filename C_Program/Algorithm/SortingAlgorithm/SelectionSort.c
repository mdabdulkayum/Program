#include<stdio.h>
int main(){
    int size, i, j, temp, min;
    printf("Enter how many digit you want: ");
    scanf("%d",&size);
    int array[size];

    for(i=0; i<size; i++){
        printf("Enter digit no %d: ",i+1);
        scanf("%d",&array[i]);
    }

    for(i=0; i<size-1; i++){
        min=i;
        for(j=i+1; j<size; j++){
            if(array[min]>array[j]){
                min=j;
            }
        }
        if(i != min){
            temp=array[i];
            array[i]=array[min];
            array[min]=temp;
        }
    }

    printf("Selection sort -- Assending Order:");
    for(i=0; i<size; i++){
        printf("\t%d",array[i]);
    }

    return 0;
}