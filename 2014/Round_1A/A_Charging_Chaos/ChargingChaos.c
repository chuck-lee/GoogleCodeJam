#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compareLongLong(const void *a, const void *b)
{
    long long valueA = *((const long long *)a);
    long long valueB = *((const long long *)b);

    return (valueA > valueB ? 1 : -1);
}

int countBit(long long value)
{
    int count = 0;
    while (value) {
        if (value & 1) {
            count++;
        }
        value >>= 1;
    }
    return count;
}

long long bitStreamToValue(const char *bitStream, int length)
{
    long long value = 0;
    for (int i = 0; i < length; i++) {
        value <<= 1;
        value |= bitStream[i] == '1' ? 1 : 0;
    }

    return value;
}

void solve(int t)
{
    int N, L;
    scanf("%d %d", &N, &L);

    char bitStream[41];
    // Read bit stream of flow pattern and transform into value.
    long long originFlow[150];
    for (int n = 0; n < N; n++) {
        scanf("%s", bitStream);
        originFlow[n] = bitStreamToValue(bitStream, L);
    }

    // Read bit stream of device pattern and transform into value.
    long long device[150];
    for (int n = 0; n < N; n++) {
        scanf("%s", bitStream);
        device[n] = bitStreamToValue(bitStream, L);
    }
    qsort(device, N, sizeof(long long), compareLongLong);

    // Calculate switch pattern of 1st device vs. every flow pattern.
    long long flowSwtich[150];
    for (int n = 0; n < N; n++) {
        flowSwtich[n] = device[0] ^ originFlow[n];
    }

    // Apply switch pattern one by one and test if it works.
    long long modifiedFlow[150];
    int move = -1;
    for (int n = 0; n < N; n++) {
        // Apply switch pattern to create new flow pattern
        for (int i = 0; i < N; i++) {
            modifiedFlow[i] = originFlow[i] ^ flowSwtich[n];
        }
        qsort(modifiedFlow, N, sizeof(long long), compareLongLong);

        // Check if flow pattern and device pattern matches.
        int match = 1;
        for (int i = 0; i < N; i++) {
            if (modifiedFlow[i] != device[i]) {
                match = 0;
                break;
            }
        }
        if (match) {
            int thisMove = countBit(flowSwtich[n]);
            if (move < 0 || thisMove < move) {
                move = thisMove;
            }
        }
    }

    if (move >= 0) {
        printf("Case #%d: %d\n", t + 1, move);
    } else {
        printf("Case #%d: NOT POSSIBLE\n", t + 1);
    }
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
