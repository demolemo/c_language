#include <stdio.h>


int main() {
    int c;
    int letters_cnt[26];

    for (int i = 0; i < 26; ++i) {
        letters_cnt[i] = 0;
    }

    /* count only letters,
     can be modified to include non-letters
     but that's boring */

    while ((c = getchar()) != EOF) {
        if (c >= 'A' && c <= 'Z') {
            ++letters_cnt[c - 'A'];
        } else if (c >= 'a' && c <= 'z') {
            ++letters_cnt[c - 'a'];
            
        }
    }
   
    /* use vertical histogram from the last task */
    printf("vertical histogram\n");

    int max_count = 0;
    for (int i = 0; i < 26; ++i) {
        if (letters_cnt[i] > max_count) {
            max_count = letters_cnt[i];
        }
    }
    
    for (int i = max_count; i > -1; --i) {
        for (int j = 0; j < 26; ++j) {
            if (letters_cnt[j] > i) {
                printf(" # "); 
            } else {
                printf("   ");
            }
        }
        printf("\n");
    }

    for (int i = 0; i < 26; ++i) {
        printf(" %c ", 'a' + i);
    }
    return 0;
}
