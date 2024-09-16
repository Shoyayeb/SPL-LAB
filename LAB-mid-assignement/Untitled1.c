
#include<stdio.h>

void main(){
    char mainSentence[1000],targetWord[45];
    int i = 0, j = 0, count = 0, temp;

    scanf(" %[^\n]", mainSentence);
    scanf(" %s", targetWord);

    for (i = 0; mainSentence[i] != '\0'; i++) {
        if (mainSentence[i] == targetWord[0]) {
            temp = i;
            for (j = 0; targetWord[j] != '\0'; j++) {
                if (mainSentence[temp] != targetWord[j]) {
                    break;
                }
                temp++;
            }
            if (targetWord[j] == '\0') {
                if (mainSentence[i - 1] == ' ') {
                    if (mainSentence[temp] == '\0' || mainSentence[temp] == ' 'It) {
                        count++;
                    }
                }
            }
        }
    }
    printf("%d", count);
}
