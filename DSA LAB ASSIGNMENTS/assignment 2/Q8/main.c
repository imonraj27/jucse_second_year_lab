#include <stdio.h>

void is_sorted_array(int * arr, int n){
    int ascending=0, descending=0;
    int i;
    for (i = 1; i < n; i++)
    {
        if(arr[i-1] < arr[i]){
            ascending = 1;
        }else if(arr[i-1] > arr[i]){
            descending = 1;
        }

        if(ascending*descending){
            printf("\nUnsorted array!!");
            return;
        }
    }

    if(ascending){
        printf("\nThe array is sorted in Ascending order..");
    }else if(descending){
        printf("\nThe array is sorted in Descending order...");
    }else{
        printf("\nThe array has all equal elements..");
    }
    
}

int main(){
    int n, i;
    printf("\nEnter the array length: ");
    scanf("%d", &n);
    int arr[n];
    for (i = 0; i < n; i++)
    {
        scanf("%d", arr+i);
    }

    is_sorted_array(arr, n);
    
    return 0;
}