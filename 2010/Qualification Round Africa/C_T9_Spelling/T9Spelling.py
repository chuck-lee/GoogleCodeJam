import sys
from functools import reduce

def debug(x):
#    print(x)
    return

keyMap = {
    ' ': '0',
    'a': '2',
    'b': '22',
    'c': '222',
    'd': '3',
    'e': '33',
    'f': '333',
    'g': '4',
    'h': '44',
    'i': '444',
    'j': '5',
    'k': '55',
    'l': '555',
    'm': '6',
    'n': '66',
    'o': '666',
    'p': '7',
    'q': '77',
    'r': '777',
    's': '7777',
    't': '8',
    'u': '88',
    'v': '888',
    'w': '9',
    'x': '99',
    'y': '999',
    'z': '9999'
}

N = int(input())
debug('N: ' + str(N))

for n in range(N):
    print('Case #%d: %s' % (n + 1,
            reduce(lambda x, y: x + y if x[len(x) - 1] != y[0] else x + ' ' + y,
                   [keyMap[p] for p in input()])))
