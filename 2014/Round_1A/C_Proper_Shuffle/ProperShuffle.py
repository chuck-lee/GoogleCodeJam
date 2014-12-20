import sys

def debug(x):
#    print(x)
    return

def solve(t):
    N = int(input())
    data = [int(d) for d in input().split(' ')]

    count = 0
    for n in range(N):
        if int(data[n]) <= n:
            count = count + 1

    print(("Case #%d: " % (t + 1)) + ("BAD" if count < 485 else "GOOD"))

T = int(input())

for t in range(T):
    solve(t)