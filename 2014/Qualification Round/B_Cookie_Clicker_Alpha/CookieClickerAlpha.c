#include <stdio.h>

int main(int argc, char *argv[])
{
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        double C, F, X;
        scanf("%lf %lf %lf", &C, &F, &X);

        double cookieRate = 2.0, elapsedTime = 0.0;
        while (1) {
            double buildFarmTime = C / cookieRate;
            double remainingTime = X / cookieRate;
            cookieRate += F;
            double remainingTimeExtraFarm = buildFarmTime + X / cookieRate;

            if (remainingTime < remainingTimeExtraFarm) {
                elapsedTime += remainingTime;
                break;
            }
            elapsedTime += buildFarmTime;
        }
        printf("Case #%d: %.7f\n", i + 1, elapsedTime);
    }

    return 0;
}
