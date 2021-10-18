#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

typedef struct {
    char current;
    int hand;
    char whosCard[6];
    int max;
    char result[5];
}pok;

void init_pok(pok* q) {
    q->current = '-';
    q->hand = 0;
    q->max = 0;
}

char card(pok* q) {

    int i, j;

    for (i = 0; i < 6; i++) {
        q->hand = 1; //비교대상의 빈도
        for (j = 0; j < 6; j++) {
            if (i == j)
                continue;
            if (q->whosCard[i] == q->whosCard[j]) {
                q->hand++;
                if (q->hand == 2) {
                    q->current = q->whosCard[i];

                    if (q->current < q->whosCard[i]) {
                        q->current = q->whosCard[i];
                    }
                }

            }

        }
        if (q->hand > q->max) {
            q->max = q->hand;
        }

        if (q->hand == 4) {
            q->current = q->whosCard[i];
            break;
        }
        if (q->hand == 3) {
            q->current = q->whosCard[i];
            break;
        }
        if (q->max == 1) {
            q->current = '@';
        }

    }
    return q->current;
}

int main(void) {

    pok Tom;
    pok Jerry;

    init_pok(&Tom);
    init_pok(&Jerry);

    while (scanf("%s %s", Tom.whosCard, Jerry.whosCard) == 1) {

        init_pok(&Tom);
        init_pok(&Jerry);

        card(&Tom);
        card(&Jerry);

        if (Tom.max > Jerry.max) {
            printf("Tom\n");
        }
        else if (Tom.max < Jerry.max) {
            printf("Jerry\n");
        }
        else if (Tom.max == Jerry.max) {
            if (Tom.current > Jerry.current) {
                printf("Tom\n");
            }
            else if (Tom.current < Jerry.current) {
                printf("Jerry\n");
            }
            else if (Tom.current == Jerry.current) {
                printf("Draw\n");
            }
        }


    }


}
