import sys
from types import *

# Referenced from solution of surwdkgo(TW)

def debug(x):
#    print(x)
    return

def fillMine(R, C, M):
    emptySpace = R * C - M
    debug('R: %d, C: %d, M: %d, empty: %d' % (R, C, M, emptySpace))
    mineMap = [['*' for c in range(C)] for r in range(R)]
    for r in mineMap:
        debug(''.join(r))

    if M == 0:
        for r in range(R):
            for c in range(C):
                mineMap[r][c] = '.'
        mineMap[0][0] = 'c'
        return mineMap

    if emptySpace == 1:
        for r in range(R):
            for c in range(C):
                mineMap[r][c] = '*'
        mineMap[0][0] = 'c'
        return mineMap

    if R == 1:
        for c in range(C):
            mineMap[0][c] = '.' if c < emptySpace else '*'
        mineMap[0][0] = 'c'
        return mineMap

    if C == 1:
        for r in range(R):
            mineMap[r][0] = '.' if r < emptySpace else '*'
        mineMap[0][0] = 'c'
        return mineMap

    if R == 2:
        if emptySpace == 2 or emptySpace % 2 == 1:
            return None

        emptySpace /= 2;
        for r in range(R):
            for c in range(C):
                mineMap[r][c] = '.' if c < emptySpace else '*'
        mineMap[0][0] = 'c';
        return mineMap;

    if C == 2:
        if emptySpace == 2 or emptySpace % 2 == 1:
            return None

        emptySpace /= 2;
        for r in range(R):
            for c in range(C):
                mineMap[r][c] = '.' if r < emptySpace else '*'
        mineMap[0][0] = 'c';
        return mineMap

    if emptySpace == 2 or emptySpace == 3 or emptySpace == 5 or emptySpace == 7:
        return None

    fillRows = int(emptySpace / C) + (1 if emptySpace % C != 0 else 0);
    if fillRows <= 2:
        fillRows = 3
    if fillRows > R:
        fillRows = R

    for r in range(R):
        for c in range(C):
            mineMap[r][c] = '.' if r < fillRows and c * fillRows + r < emptySpace else '*'

    if emptySpace % fillRows == 1:
        targetColumn = int(emptySpace/fillRows)
        mineMap[1][targetColumn] = '.'
        mineMap[fillRows - 1][targetColumn - 1] = '*'

    mineMap[0][0] = 'c'

    return mineMap

N = int(input())
debug('N: ' + str(N))

for n in range(N):
    param = [int(p) for p in input().split(' ')]
    mineMap = fillMine(param[0], param[1], param[2])
    print('Case #%d:' % (n + 1))
    if mineMap == None:
        print('Impossible')
    else:
        for r in mineMap:
            print(''.join(r))

