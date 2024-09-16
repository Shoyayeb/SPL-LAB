#include<stdio.h>
void main()
{
    int n,m;
    scanf("%d",&n);
    int array[n];
    for(int i=0; i<n; i++)
        scanf("%d", &array[i]);
    scanf("%d",&m);
    int found = 0;
    for (int i = 0; i < n; i++){
        if (array[i] == m){
            if (!found)
                printf("FOUND at index position: ");
            printf("%d, ", i);
            found = 1;
        }
    }

    if (!found)
        printf("NOT FOUND");
    printf("\n");
}

