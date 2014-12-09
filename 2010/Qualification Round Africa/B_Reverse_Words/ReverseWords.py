import sys

def debug(x):
#    print(x)
    return

N = int(input())
debug('N: ' + str(N))

for n in range(N):
    print('Case #%d: %s' % (n + 1, ' '.join(input().split(' ')[::-1])))
