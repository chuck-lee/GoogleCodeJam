#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *getKeyMap(char key)
{
    switch (key) {
    case ' ': return "0";
    case 'a': return "2";
    case 'b': return "22";
    case 'c': return "222";
    case 'd': return "3";
    case 'e': return "33";
    case 'f': return "333";
    case 'g': return "4";
    case 'h': return "44";
    case 'i': return "444";
    case 'j': return "5";
    case 'k': return "55";
    case 'l': return "555";
    case 'm': return "6";
    case 'n': return "66";
    case 'o': return "666";
    case 'p': return "7";
    case 'q': return "77";
    case 'r': return "777";
    case 's': return "7777";
    case 't': return "8";
    case 'u': return "88";
    case 'v': return "888";
    case 'w': return "9";
    case 'x': return "99";
    case 'y': return "999";
    case 'z': return "9999";
    }
    return NULL;
}

int main(int argc, char* argv[])
{
    int N;
    scanf("%d%*c", &N);

    int n;
    for (n = 0; n < N; n++) {
        printf("Case #%d: ", n + 1);
        char c;
        char tail = '\0';
        while (c = getchar()) {
            const char *keymap = getKeyMap(c);
            if (!keymap) {
                break;
            }

            if (tail == keymap[0]) {
                printf(" ");
            }
            printf("%s", keymap);
            tail = keymap[0];
        }
        printf("\n");
    }

    return 0;
}
