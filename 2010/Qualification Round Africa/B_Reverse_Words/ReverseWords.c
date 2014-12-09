#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    int N;
    scanf("%d\n", &N);

    int n;
    for (n = 0; n < N; n++) {
        char str[1001] = {0};
        gets(str);

        printf("Case #%d: ", n + 1);
        char *s = str + strlen(str) - 1;
        while (s > str) {
            if (*s != ' ') {
                s--;
                continue;
            }

            printf("%s ", s + 1);
            *s = 0;
            s--;
        }
        printf("%s\n", s);
    }

    return 0;
}
