#include <stdio.h>
#include <stdlib.h>

#define ERR_BAD_MAGICIAN (-1)
#define ERR_VOLUNTEER_CHEAT (-2)

int findCard(int selectedRow1st[4], int selectedRow2nd[4])
{
    // incoming row data is sorted
    int matchNumber = 0;
    int i = 0, j = 0;
    while(i < 4 && j < 4) {
        if (selectedRow1st[i] == selectedRow2nd[j]) {
            if (matchNumber) {
                return ERR_BAD_MAGICIAN;
            }
            matchNumber = selectedRow1st[i];
            i++;
            j++;
        } else if (selectedRow1st[i] <= selectedRow2nd[j]) {
            i++;
        } else {
            j++;
        }
    }

    if (matchNumber) {
        return matchNumber;
    }

    return ERR_VOLUNTEER_CHEAT;
}

int compareInt(const void *first, const void *second)
{
    return (*(int *)first - *(int *)second);
}

void selectCard(/* out */ int rowData[4])
{
    int selectedRow, selectedRangeMin, selectedRangeMax;

    scanf("%d", &selectedRow);
    selectedRangeMin = (selectedRow - 1) * 4;
    selectedRangeMax = selectedRangeMin + 4;

    int cardNumber, *pRowData = rowData;
    for (int i = 0; i < 16; i++) {
        scanf("%d", &cardNumber);
        if (i >= selectedRangeMin && i < selectedRangeMax) {
            *pRowData = cardNumber;
            pRowData++;
        }
    }

    // sort rowData
    qsort(rowData, 4, sizeof(int), compareInt);
}

int main(int argc, char *argv[])
{
    int T;
    scanf("%d", &T);

    int selectedRow1st[4], selectedRow2nd[4], result;
    for (int i = 0; i < T; i++) {
        selectCard(selectedRow1st);
        selectCard(selectedRow2nd);
        result = findCard(selectedRow1st, selectedRow2nd);

        printf("Case #%d: ", i + 1);
        switch (result) {
        case ERR_BAD_MAGICIAN:
            printf("Bad magician!\n");
            break;
        case ERR_VOLUNTEER_CHEAT:
            printf("Volunteer cheated!\n");
            break;
        default:
            printf("%d\n", result);
            break;
        }
    }

    return 0;
}
