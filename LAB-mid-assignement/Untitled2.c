#include <stdio.h>

void main(){
    char sentence[100];

    scanf("%[^\n]",sentence);

    int length = 0, start, end;
    char temp[100][100];
    int i = 0,j = 0, wordCount = 0;

    while(sentence[length] != '\0') length++;

    for(int k = 0; k <= length; k++){
        if(sentence[k] == ' ' || sentence[k] == '\0'){
            temp[wordCount][j]= '\0';
            wordCount++;
            j=0;
        } else {
            temp[wordCount][j]=sentence[k];
            j++;
        }
    }

    for (i = wordCount - 1; i >= 0; i--) {
        printf("%s ", temp[i]);
    }

    printf("\n");
}

