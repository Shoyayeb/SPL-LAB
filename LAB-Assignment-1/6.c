#include<stdio.h>
void main(){
    int n,min = 0,max = 0,min_index,max_index;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    min = arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]<min){
            min = arr[i];
            min_index = i;
        }
        if(arr[i]>max){
            max = arr[i];
            max_index = i;
        }
    }
    printf("Max: %d, Index: %d \n",max,max_index);
    printf("Min: %d, Index: %d \n",min,min_index);
}
