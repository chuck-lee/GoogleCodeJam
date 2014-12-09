#include <stdio.h>
#include <stdlib.h>

int compareDouble(const void *a, const void *b)
{
    if (*(double *)a > *(double *)b) return 1;
    if (*(double *)a < *(double *)b) return -1;
    return 0;
}

int getOptWins(double player[1000], double opponent[1000], int numOfBlocks)
{
    int wins = 0, playerSelection = 0;

    for (int i = 0; i < numOfBlocks; i++) {
        for (;playerSelection < numOfBlocks && player[playerSelection] < opponent[i];
             playerSelection++) {
        }
        if (playerSelection >= numOfBlocks) {
            break;
        }
        wins++;
        playerSelection++;
    }

    return wins;
}

void dumpBlocks(const char *name, double blocks[1000], int numOfBlock)
{
    printf("########## Block of %s ##########\n", name);
    for (int i = 0; i < numOfBlock; i++) {
        printf("%f\n", blocks[i]);
    }
}

int main(int argc, char *argv[])
{
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        int numOfBlocks;
        scanf("%d", &numOfBlocks);

        double naomiBlocks[1000];
        for (int j = 0; j < numOfBlocks; j++) {
            scanf("%lf", &naomiBlocks[j]);
        }
        qsort(naomiBlocks, numOfBlocks, sizeof(double), compareDouble);

        double kenBlocks[1000];
        for (int j = 0; j < numOfBlocks; j++) {
            scanf("%lf", &kenBlocks[j]);
        }
        qsort(kenBlocks, numOfBlocks, sizeof(double), compareDouble);

//        dumpBlocks("Naomi", naomiBlocks, numOfBlocks);
//        dumpBlocks("Ken", kenBlocks, numOfBlocks);

        int naomiDecetifulResult = getOptWins(naomiBlocks, kenBlocks, numOfBlocks);
        int naomiWarResult = numOfBlocks - getOptWins(kenBlocks, naomiBlocks, numOfBlocks);
        printf("Case #%d: %d %d\n", i + 1, naomiDecetifulResult, naomiWarResult);
    }

    return 0;
}

