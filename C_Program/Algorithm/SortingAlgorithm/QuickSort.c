#include<stdio.h>
void quickSort(int array[], int left, int right);
int partition(int array[], int left, int right);
int main(){
    int size, i, j;
    printf("Enter how many digit you want: ");
    scanf("%d",&size);
    int array[size];

    for(i=0; i<size; i++){
        printf("Enter digit no %d: ",i+1);
        scanf("%d",&array[i]);
    }

    quickSort(array, 0, size-1);

    printf("Quick sort -- Assending Order:");
    for(i=0; i<size; i++){
        printf("\t%d",array[i]);
    }


    return 0;
}

void quickSort(int array[], int left, int right){
    int pivotIndex;
    if(left<right){
        pivotIndex = partition(array, left, right);
        quickSort(array, 0, pivotIndex-1);
        quickSort(array, pivotIndex+1, right);
    }
}

int partition(int array[], int left, int right){
    int temp;
    int pivot = array[left];
    while(left != right){
        if(pivot==array[left]){
            if(array[left]<=array[right]){
                right--;
            }
            else if(array[left]>array[right]){
                temp=array[left];
                array[left]=array[right];
                array[right]=temp;

                pivot = array[right];
                left++;
            }
        }
        else if(pivot==array[right]){
            if(array[right]<array[left]){
                temp=array[left];
                array[left]=array[right];
                array[right]=temp;

                pivot = array[left];
                right--;
            }
            else if(array[right]>array[left]){
                left++;
            }

        }
    }
    return left;

}
