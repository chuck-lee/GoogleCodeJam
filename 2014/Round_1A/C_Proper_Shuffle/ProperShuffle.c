#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Based on official analysis
void solve(int t)
{
    int N;
    scanf("%d", &N);

    int count = 0;
    int v;
    for (int n = 0; n < N; n++) {
        scanf("%d", &v);
        if (v <= n) {
            count++;
        }
    }

    printf("Case #%d: %s\n", t + 1, count < 485 ? "BAD" : "GOOD" );
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
