#include <stdio.h>
#include <stdlib.h>

struct product {
    int price;
    int index;
};

int compare(const void* a, const void* b)
{
    return ((const struct product*)a)->price -
           ((const struct product*)b)->price;
}

int min(int a, int b)
{
    return (a < b ? a : b);
}

int max(int a, int b)
{
    return (a > b ? a : b);
}

int main(int argc, char* argv[])
{
    int N;
    scanf("%d", &N);

    int n;
    for (n = 0; n < N; n++) {
        int C;
        scanf("%d", &C);

        int I;
        scanf("%d", &I);

        int i;
        struct product P[2000];
        for (i = 0; i < I; i++) {
            scanf("%d", &P[i].price);
            P[i].index = i;
        }

        qsort(P, I, sizeof(struct product), compare);

        int start = 0;
        int end = I - 1;
        while (start < end) {
            int c = P[start].price + P[end].price;
            if (c > C) {
                end--;
            } else if (c < C) {
                start++;
            } else {
                printf("Case #%d: %d %d\n", n + 1,
                        min(P[start].index, P[end].index) + 1,
                        max(P[start].index, P[end].index) + 1
                        );
                break;
            }
        }
    }

    return 0;
}
