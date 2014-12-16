#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vertix[1000][1000];
// DP!!! Use this to prevent redundant recursive call. About 60 times faster.
// maxSubtreeNodeRecord[PARENT][CURRENT] = max subtree node count of CURRENT
//                                         node while parent node is PARENT
int maxSubtreeNodeRecord[1000][1000];

int maxSubtreeNodes(int current, int parent, int N)
{
    if (maxSubtreeNodeRecord[parent][current] != 0) {
        return maxSubtreeNodeRecord[parent][current];
    }

    int childNodes[2] = {0};
    int childs = 0;
    for (int n = 0; n < N; n++) {
        if (n == current || n == parent || vertix[current][n] != 1) {
            continue;
        }

        childs++;
        int nodes = maxSubtreeNodes(n, current, N);
        if (nodes > childNodes[0]) {
            childNodes[1] = childNodes[0];
            childNodes[0] = nodes;
        } else if (nodes > childNodes[1]) {
            childNodes[1] = nodes;
        }
    }

    if (childs < 2) {
        maxSubtreeNodeRecord[parent][current] = 1;
    } else {
        maxSubtreeNodeRecord[parent][current] = 1 + childNodes[0] + childNodes[1];
    }

    return maxSubtreeNodeRecord[parent][current];
}

void solve(int t)
{
    int N;
    scanf("%d", &N);
    memset(vertix, 0, sizeof(vertix));
    memset(maxSubtreeNodeRecord, 0, sizeof(maxSubtreeNodeRecord));
    for (int n = 0; n < N - 1; n++) {
        int X, Y;
        scanf("%d %d", &X, &Y);
        vertix[X - 1][Y - 1] = vertix[Y - 1][X - 1] = 1;
    }

    int minCost = N;
    for (int n = 0; n < N; n++) {
        int cost = N - maxSubtreeNodes(n, n, N);
        if (cost < minCost) {
            minCost = cost;
        }
        if (minCost == 0) {
            break;
        }
    }

    printf("Case #%d: %d\n", t + 1, minCost);
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
