#include<stdio.h>
void main(){
    int n,vowels = 0;
    scanf("%d",&n);
    char array[n];
    for(int i=0;i<n;i++){
        scanf("%c", &array[i]);
    }
    for(int i = 0; i<n; i++){
        char ch = array[i];
        if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' || ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
            vowels++;
        }
    }
    printf("Count: %d",vowels);
}
