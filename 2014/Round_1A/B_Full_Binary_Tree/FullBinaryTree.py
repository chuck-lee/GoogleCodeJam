import sys
sys.setrecursionlimit(2000)

def debug(x):
#    print(x)
    return

def maxSubtreeNodes(treeMap, nodeRecord, current, parent, N):
    if nodeRecord[parent][current] != 0:
        return nodeRecord[parent][current]

    childNodes = [0, 0]
    childs = 0

    for n in range(N):
        if n == current or n == parent or treeMap[current][n] != 1:
            continue

        childs = childs + 1
        nodes = maxSubtreeNodes(treeMap, nodeRecord, n, current, N)
        if nodes > childNodes[0]:
            childNodes[1] = childNodes[0]
            childNodes[0] = nodes
        elif nodes > childNodes[1]:
            childNodes[1] = nodes;

    if childs < 2:
        nodeRecord[parent][current] = 1
    else:
        nodeRecord[parent][current] = 1 + childNodes[0] + childNodes[1]

    return nodeRecord[parent][current];

def solve(t):
    N = int(input())
    treeMap = [[0 for i in range(N)] for j in range(N)]
    nodeRecord = [[0 for i in range(N)] for j in range(N)]

    for n in range(N - 1):
        link = [(int(v) - 1) for v in input().split(' ')]
        treeMap[link[0]][link[1]] = treeMap[link[1]][link[0]] = 1

    minCost = N
    for n in range(N):
        cost = N - maxSubtreeNodes(treeMap, nodeRecord, n, n, N)
        if cost < minCost:
            minCost = cost
        if minCost == 0:
            break

    print("Case #%d: %d" % (t + 1, minCost));


T = int(input())

for t in range(T):
    solve(t)