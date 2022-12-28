#include<stdio.h>
int main(){
    int size, i, j, value, count=0;
    printf("Enter how many value you want: ");
    scanf("%d",&size);
    int array[size];

    for(i=0; i<size; i++){
        printf("Enter digit no %d: ", i+1);
        scanf("%d",&array[i]);
    }

    printf("Enter value for search: ");
    scanf("%d", &value);

    for(i=0; i<size; i++){
        if(array[i]==value){
            count++;
            break;
        }
    }
    if(count>0){
        printf("Value %d found at %d position",value, i+1);
    }
    else{
        printf("Value %d not found",value);
    }

    return 0;
}
