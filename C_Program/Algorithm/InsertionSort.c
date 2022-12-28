#include<stdio.h>
int main(){
    int size, i, j, temp;
    printf("Enter how many digit you want: ");
    scanf("%d",&size);
    int array[size];

    for(i=0; i<size; i++){
        printf("Enter digit no %d: ",i+1);
        scanf("%d",&array[i]);
    }

    for(i=1; i<size; i++){
        temp = array[i];
        j=i-1;
        while(j>=0 && array[j]>temp){
            array[j+1]=array[j];
            j--;
        }
        array[j+1]=temp;
    }

    printf("Insertion sort -- Assending Order:");
    for(i=0; i<size; i++){
        printf("\t%d",array[i]);
    }

    return 0;
}
