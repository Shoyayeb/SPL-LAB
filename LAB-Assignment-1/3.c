#include<stdio.h>
void main(){
    int n, sum;
    scanf("%d", &n);
    int array[n];
    for(int i=0;i<n;i++)
        scanf("%d",&array[i]);

    for(int i=0;i<n;i++)
        if(array[i] % 2 == 0)
            sum = sum + array[i];
    printf("%d",sum);

}
