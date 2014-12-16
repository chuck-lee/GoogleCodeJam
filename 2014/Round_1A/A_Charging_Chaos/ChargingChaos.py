import sys

def debug(x):
#    print(x)
    return

def bitStreamToInt(str):
    val = 0
    for c in str:
        val = val << 1
        val = val | (1 if c == '1' else 0)
    return val

def countBit(val):
    debug('countBit: %d' % (val))
    count = 0
    while val != 0:
        count = count + (1 if val & 1 == 1 else 0)
        val = val >> 1
    debug('countBit: result %d' % (count))
    return count

def solve(t):
    param = [int(p) for p in input().split(' ')]
    N = param[0]
    L = param[1]

    originalFlow = sorted([bitStreamToInt(str) for str in input().split(' ')])
    debug('originalFlow: ' + ' '.join([str(f) for f in originalFlow]))
    device = sorted([bitStreamToInt(str) for str in input().split(' ')])
    debug('device: ' + ' '.join([str(d) for d in device]))
    switchPatterns = [(device[0] ^ flow) for flow in originalFlow]
    debug('switchPatterns: ' + ' '.join([str(s) for s in switchPatterns]))

    minMove = L + 1
    for pattern in switchPatterns:
        newFlow = sorted([(pattern ^ flow) for flow in originalFlow])
        debug('newFlow: ' + ' '.join([str(f) for f in newFlow]))
        if newFlow == device:
            minMove = min(countBit(pattern), minMove)

    if minMove > L:
        print("Case #%d: NOT POSSIBLE" % (t + 1));
    else:
        print("Case #%d: %d" % ((t + 1), minMove));

T = int(input())

for t in range(T):
    solve(t)