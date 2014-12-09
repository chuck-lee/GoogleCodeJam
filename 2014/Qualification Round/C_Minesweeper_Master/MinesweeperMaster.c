#include <stdio.h>
#include <string.h>

//#define DEBUG
// Referenced from solution of surwdkgo(TW)

#define MINE_CELL_EMPTY         ('.')
#define MINE_CELL_MINED         ('*')
#define MINE_CELL_FIRST_CLICK   ('c')

int fillMine(int R, int C, int M, unsigned char mineMap[50][50])
{
    int emptySpace = R * C - M;
    int i, j;

    if (M == 0) {
        for (i = 0; i < R; i++) {
            for (j = 0; j < C; j++) {
                mineMap[i][j] = MINE_CELL_EMPTY;
            }
        }
        mineMap[0][0] = MINE_CELL_FIRST_CLICK;
        return 1;
    }

    if (R == 1) {
        /*
         * Single row
         *   +-+-+   +-+-+   +-+
         *   |c|.|~~~|.|*|~~~|*|
         *   +-+-+   +-+-+   +-+
         */
        mineMap[0][0] = MINE_CELL_FIRST_CLICK;
        for (i = 1; i <= (emptySpace - 1); i++) {
            mineMap[0][i] = MINE_CELL_EMPTY;
        }
        for (; i < C; i++) {
            mineMap[0][i] = MINE_CELL_MINED;
        }
        return 1;
    }

    if (C == 1) {
        /*
         * Single column: transform of Single row
         */
        mineMap[0][0] = MINE_CELL_FIRST_CLICK;
        for (i = 1; i <= (emptySpace - 1); i++) {
            mineMap[i][0] = MINE_CELL_EMPTY;
        }
        for (; i < R; i++) {
            mineMap[i][0] = MINE_CELL_MINED;
        }

        return 1;
    }

    if (emptySpace == 1) {
        /*
         * Only one space left
         *   +-+-+   +-+
         *   |c|*|~~~|*|
         *   +-+-+   +-+
         *   |*|*|~~~|*|
         *   +-+-+   +-+
         *     ~~~~~~
         *   +-+-+   +-+
         *   |*|*|~~~|*|
         *   +-+-+   +-+
         */
        for (i = 0; i < R; i++) {
            for (j = 0; j < C; j++) {
                mineMap[i][j] = MINE_CELL_MINED;
            }
        }
        mineMap[0][0] = MINE_CELL_FIRST_CLICK;
        return 1;
    }

    if (R == 2) {
        /*
         * Two rows
         *   +-+-+   +-+-+   +-+
         *   |c|.|~~~|.|*|~~~|*|
         *   +-+-+   +-+-+   +-+
         *   |.|.|~~~|.|*|~~~|*|
         *   +-+-+   +-+-+   +-+
         *
         * Number of mines can't be odd because there will be an
         * unreachable labeled cell(U)
         *   +-+-+   +-+-+-+-+   +-+
         *   |c|.|~~~|.|.|U|*|~~~|*|
         *   +-+-+   +-+-+-+-+   +-+
         *   |.|.|~~~|.|.|*|*|~~~|*|
         *   +-+-+   +-+-+-+-+   +-+
         *
         * Empty space can't be two because there will be an
         * unreachable labeled cell(U)
         *   +-+-+   +-+
         *   |c|*|~~~|*|
         *   +-+-+   +-+
         *   |U|*|~~~|*|
         *   +-+-+   +-+
         */
        if (emptySpace == 2 || (emptySpace % 2)) {
            return 0;
        }

        emptySpace /= 2;
        for (i = 0; i < R; i++) {
            for (j = 0; j < C; j++) {
                mineMap[i][j] = j < emptySpace ? MINE_CELL_EMPTY : MINE_CELL_MINED;
            }
        }
        mineMap[0][0] = MINE_CELL_FIRST_CLICK;
        return 1;
    }

    if (C == 2) {
        /*
         * Two columns: transform of Two rows
         */
        if (emptySpace == 2 || (emptySpace % 2)) {
            return 0;
        }

        emptySpace /= 2;
        for (i = 0; i < R; i++) {
            for (j = 0; j < C; j++) {
                mineMap[i][j] = i < emptySpace ? MINE_CELL_EMPTY : MINE_CELL_MINED;
            }
        }
        mineMap[0][0] = MINE_CELL_FIRST_CLICK;
        return 1;
    }

    if (emptySpace == 2 ||
        emptySpace == 3 ||
        emptySpace == 5 ||
        emptySpace == 7) {
        return 0;
    }

    /*
     * Fill empty column by column, within certain rows.
     */
    int fillRows = emptySpace / C + ((emptySpace % C) ? 1 : 0);
    if (fillRows <= 2) {
        fillRows = 3;
    }

    if (fillRows > R) {
        fillRows = R;
    }

    for (i = 0; i < R; i++) {
        for (j = 0; j < C; j++) {
            mineMap[i][j] = i < fillRows && j * fillRows + i < emptySpace ? '.' : '*';
        }
    }

    if (emptySpace % fillRows == 1) {
        /*
         * Fix exception: if there's single empty space in single column, move
         * another space with it.
         *   +-+-+   +-+-+-+   +-+      +-+-+   +-+-+-+   +-+
         *   |.|.|~~~|.|.|*|~~~|*|      |.|.|~~~|.|.|*|~~~|*|
         *   +-+-+   +-+-+-+   +-+  =>  +-+-+   +-+-+-+   +-+
         *   |.|.|~~~|.|*|*|~~~|*|      |.|.|~~~|.|.|*|~~~|*|
         *   +-+-+   +-+-+-+   +-+      +-+-+   +-+-+-+   +-+
         *   |.|.|~~~|.|*|*|~~~|*|      |.|.|~~~|*|*|*|~~~|*|
         *   +-+-+   +-+-+-+   +-+      +-+-+   +-+-+-+   +-+
         */
        mineMap[1][emptySpace/fillRows] = '.';
        mineMap[fillRows - 1][emptySpace/fillRows - 1] = '*';
    }

    mineMap[0][0] = MINE_CELL_FIRST_CLICK;

    return 1;
}

int main(int argc, char *argv[])
{
    int T;
    scanf("%d", &T);

    unsigned char mineMap[50][50];
    for (int i = 0; i < T; i++) {
        int R, C, M;
        scanf("%d %d %d", &R, &C, &M);

        memset(mineMap, 0, sizeof(mineMap));

        printf("Case #%d:\n", i + 1);
#ifdef DEBUG
        printf("R: %d, C: %d, M: %d\n", R, C, M);
#endif
        if (fillMine(R, C, M, mineMap)) {
#ifdef DEBUG
            int emptySpace = 0, mineSpace = 0;
            for (int i = 0; i < R; i++) {
                for (int j = 0; j < C; j++) {
                    if (mineMap[i][j] == MINE_CELL_MINED) {
                        mineSpace++;
                    } else {
                        emptySpace++;
                    }
                }
            }
            if (mineSpace != M || mineSpace + emptySpace != R * C) {
                printf("Final Check Error!\n");
            }
#endif // DEBUG
            for (int i = 0; i < R; i++) {
                for (int j = 0; j < C; j++) {
                    printf("%c", mineMap[i][j]);
                }
                printf("\n");
            }
        } else {
            printf("Impossible\n");
        }
    }

    return 0;
}
