#include<stdio.h>
int main(){
    int size, i, value, count=0, mid, left, right;
    printf("Enter how many value you want: ");
    scanf("%d",&size);
    int array[size];

    for(i=0; i<size; i++){
        printf("Enter digit no %d: ", i+1);
        scanf("%d",&array[i]);
    }

    printf("Enter value for search: ");
    scanf("%d", &value);

    left=0;
    right = size-1;
    while(left<=right){
        mid = (left+right)/2;
        if(value==array[mid]){
            count++;
            break;
        }
        else if(value<=array[mid]){
            right = mid-1;
        }
        else if(value>=array[mid]){
            left=mid+1;
        }
    }
    
    
    if(count==1){
        printf("Value %d found at %d position",value, (mid+1));
    }
    else{
        printf("Value %d not found",value);
    }

    return 0;
}
