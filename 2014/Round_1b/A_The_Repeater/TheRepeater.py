import sys

def debug(x):
#    print(x)
    return

def solve(t):
    N = int(input())

    strings = [];
    for n in range(N):
        string = input()

        start = string[0]
        length = 0
        chars = []
        for i in range(1, len(string)):
            length = length + 1
            if start != string[i]:
                chars.append((start, length))
                start = string[i]
                length = 0
        chars.append((start, length + 1))
        strings.append(chars)

    for i in range(1, len(strings)):
        if len(strings[i - 1]) != len(strings[i]):
            print(("Case #%d: Fegla Won" % (t + 1)))
            return

        for j in range(len(strings[i])):
            if strings[i - 1][j][0] != strings[i][j][0]:
                print(("Case #%d: Fegla Won" % (t + 1)))
                return

    moves = 0
    for i in range(len(strings[0])):
        lengths = []
        for j in range(len(strings)):
            lengths.append(strings[j][i][1])

        lengths.sort()

        bestLength = lengths[int(len(lengths) / 2)]
        for j in range(len(lengths)):
            moves = moves + abs(lengths[j] - bestLength)

    print("Case #%d: %d" % (t + 1, moves))

T = int(input())

for t in range(T):
    solve(t)