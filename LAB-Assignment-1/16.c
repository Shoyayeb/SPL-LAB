#include<stdio.h>
void main(){
    int n,m;
    scanf("%d",&n);
    int arrayA[n];
    for(int i=0;i<n;i++)
        scanf("%d",&arrayA[i]);
    scanf("%d",&m);
    int arrayB[m];
    for(int i=0;i<m;i++)
        scanf("%d",&arrayB[i]);
    for(int i=0;i<n;i++){
        int doesExist =0;
        for(int j=0;j<m;j++){
            if(arrayA[i]==arrayB[j]){
                doesExist=1;
                break;
            }
        }
        if(!doesExist)
            printf("%d ",arrayA[i]);
    }
}
