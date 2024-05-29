#include<stdio.h>
#include<string.h>

struct words {
    char word[10];
    int count;

};

struct words store[5];
int storepos = 0;
char sent[] = "hello how how";

void hashmap(int startpos, int endpos) {
    char temp[10] = " ";
    char temppos = 0;
    for (int i = startpos; i < endpos; i++) {
        temp[temppos] = sent[i];
        temppos += 1;
    }

    for (int j = 0; j <= storepos; j++) {
        int result =strcmp(store[j].word , temp);
        if (result == 0) {
            store[j].count += 1;
            return 0;
        }
    }
    

    strcpy(store[storepos].word, temp);
    store[storepos].count = 1;
    storepos += 1;
    return 0;
}

int main() {

    int startpos = 0;
    int endpos = 0;

    for (int i = startpos; i <= strlen(sent); i++) {
        if (sent[i] == ' ' || sent[i] == '\0') {
            endpos = i;
            hashmap(startpos, endpos);
            startpos = endpos + 1;
        }
    }
    
    for (int i = 0; i < storepos; i++) {
        printf(" %s count = %d \n",store[i].word , store[i].count);
    }

    return 0;
}
