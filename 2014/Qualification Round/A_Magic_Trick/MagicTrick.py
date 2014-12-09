import sys

def debug(x):
#    print(x)
    return

N = int(input())
debug('N: ' + str(N))

def getCards():
    R = int(input()) - 1
    debug('R: ' + str(R))
    result = []
    for i in range(4):
        if R != i:
            input()
        else:
            result = sorted([int(p) for p in input().split(' ')])
    debug("### getCards: " + ' '.join([str(r) for r in result]))
    return result

for n in range(N):
    card1 = getCards()
    card2 = getCards()
    answer = [c1 for c1 in card1 for c2 in card2 if c1 == c2]
    debug("### answer: " + ' '.join([str(r) for r in answer]))
    if len(answer) == 1:
        print('Case #%d: %d' % (n + 1, answer[0]))
    elif len(answer) == 0:
        print('Case #%d: Volunteer cheated!' % (n + 1))
    else:
        print('Case #%d: Bad magician!' % (n + 1))