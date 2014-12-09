import sys

def debug(x):
#    print(x)
    return

N = int(input())
debug('N: ' + str(N))

for n in range(N):
    C = int(input())
    debug('C: ' + str(C))

    I = int(input())
    debug('I: ' + str(I))

    P = sorted(
            [{'value': int(p), 'index': index}
                for index, p in enumerate(input().split(' '))],
            key = lambda p: p['value']
        )
    debug('\n'.join(str(p) for p in P))

    start = 0
    end = len(P) - 1
    while start < end:
        c = P[start]['value'] + P[end]['value']
        if c > C:
            end = end -1
        elif c < C:
            start = start + 1
        else:
            index = sorted([P[start]['index'] + 1, P[end]['index'] + 1])
            print('Case #%d: %d %d' % (n + 1, index[0], index[1]))
            break
