
#include<stdio.h>

void main(){
    char mainSentence[1000],targetWord[45];
    int i = 0, j = 0, count = 0, temp;

    scanf(" %[^\n]", mainSentence);
    scanf(" %s", targetWord);

    for (i = 0; mainSentence[i] != '\0'; i++) {
        // Step 3: Check if word matches at this position
        if (mainSentence[i] == targetWord[0]) {
            temp = i;
            for (j = 0; targetWord[j] != '\0'; j++) {
                if (mainSentence[temp] != targetWord[j]) {
                    break;
                }
                temp++;
            }
            // Step 4: Ensure full word matches
            if (targetWord[j] == '\0') {
                // Step 5: Manual boundary checks

                // Check the character before the word (if not at the start of the sentence)
                if (mainSentence[i - 1] == ' ') {

                    // Check the character after the word (if not at the end of the sentence)
                    if (mainSentence[temp] == '\0' || mainSentence[temp] == ' 'It) {
                        count++;
                    }
                }
            }
        }
    }
    printf("%d", count);
}
