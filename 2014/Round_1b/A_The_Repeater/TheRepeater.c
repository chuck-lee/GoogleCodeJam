#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct charInfo {
    char c;
    int length;
};

struct stringInfo {
    struct charInfo chars[101];
    int length;
};

int compareInt(const void *a, const void *b)
{
    return (*(const int *)a - *(const int *)b);
}

void solve(int t)
{
    int N;
    scanf("%d", &N);

    struct stringInfo strings[100] = { 0 };
    char string[101];
    for (int n = 0; n < N; n++) {
        scanf("%s", string);

        char *start = string;
        int length = 0;
        while (start[length]) {
            length++;
            if (start[0] != start[length]) {
                strings[n].chars[strings[n].length].c = start[0];
                strings[n].chars[strings[n].length].length = length;
                strings[n].length++;
                start += length;
                length = 0;
            }
        }
    }

    int match = 1;
    for (int n = 1; n < N && match; n++) {
        if (strings[n - 1].length != strings[n].length) {
            match = 0;
            break;
        }

        for (int i = 0; i < strings[n].length; i++) {
            if (strings[n - 1].chars[i].c != strings[n].chars[i].c) {
                match = 0;
                break;
            }
        }
    }

    if (!match) {
        printf("Case #%d: Fegla Won\n", t + 1);
        return;
    }

    int moves = 0;
    int lengths[100];
    for (int i = 0; i < strings[0].length; i++) {
        for (int n = 0; n < N; n++) {
            lengths[n] = strings[n].chars[i].length;
        }

        qsort(lengths, N, sizeof(int), compareInt);

        int bestLength = lengths[N / 2];
        for (int n = 0; n < N; n++) {
            moves += abs(lengths[n] - bestLength);
        }
    }

    printf("Case #%d: %d\n", t + 1, moves);
}

int main(int argc, char *argv[])
{
    int T;
    scanf("%d", &T);

    for (int t = 0; t < T; t++) {
        solve(t);
    }

    return 0;
}
