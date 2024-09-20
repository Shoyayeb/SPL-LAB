#include<stdio.h>

void main(){
    char sentence[1000],word[45];
    int i = 0, j = 0, count = 0, temp;

    scanf(" %[^\n]", sentence);
    scanf(" %s", word);

    for (i = 0; sentence[i] != '\0'; i++) {
        if (sentence[i] == word[0]) {
            temp = i;
            for (j = 0; word[j] != '\0'; j++) {
                if (sentence[temp] != word[j]) {
                    break;
                }
                temp++;
            }
            if (word[j] == '\0') {
                if ((i == 0 || sentence[i - 1] == ' ') && (sentence[temp] == '\0' || sentence[temp] == ' ')) {
                    count++;
                }
            }
        }
    }
    printf("%d", count);
}
