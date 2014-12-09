import sys

def debug(x):
#    print(x)
    return

T = int(input())
debug('T: ' + str(T))

def getWins(player, opponent):
    wins = 0
    playerIndex = 0
    for o in opponent:
        while playerIndex < len(player) and player[playerIndex] < o:
            playerIndex = playerIndex + 1
        if playerIndex == len(player):
            return wins
        wins = wins + 1
        playerIndex = playerIndex + 1

    return wins

for t in range(T):
    N = int(input())
    naomiBlock = sorted([float(b) for b in input().split(' ')])
    kenBlock = sorted([float(b) for b in input().split(' ')])

    debug('nomi: ' + ' '.join([str(b) for b in naomiBlock]))
    debug('ken: ' + ' '.join([str(b) for b in kenBlock]))

    warResult = 0
    deceitfulWarResult = 0

    print('Case #%d: %d %d' % (t + 1, getWins(naomiBlock, kenBlock),
                               (N - getWins(kenBlock, naomiBlock))))