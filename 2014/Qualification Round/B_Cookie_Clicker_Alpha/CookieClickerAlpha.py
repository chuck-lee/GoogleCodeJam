import sys

def debug(x):
#    print(x)
    return

N = int(input())
debug('N: ' + str(N))

for n in range(N):
    param = [float(v) for v in input().split(' ')]
    C = param[0]
    F = param[1]
    X = param[2]

    cookieRate = 2.0
    timeElapsed = 0.0
    while True:
        # option 1 : make X cookies
        completeTime = X / cookieRate

        # option 2 : make C cookies to build farm, then make X cookies
        buildFarmTime = C / cookieRate
        cookieRate += F
        completeTimeWithFarm = buildFarmTime + X / cookieRate

        # option 1 is faster, then we are done
        if completeTime < completeTimeWithFarm:
            timeElapsed = timeElapsed + completeTime
            break

        # Build farm
        timeElapsed = timeElapsed + buildFarmTime

    print("Case #%d: %f" % (n + 1, timeElapsed))