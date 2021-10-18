#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <string.h>

#define MAX_M 50
#define MAX_N 50

static char a[MAX_M][MAX_N];
static int m, n;

// 위치 (i, j)부터 시작하여 8방향으로 단어 word를 찾는다
int find_match(char word[], int start_i, int start_j)
{
    // 8방향에 대한 i, j 증가분을 기록해둔다
    static int di[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
    static int dj[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };
    int i, j, t, dir;
    for (dir = 0; dir < 8; dir++) { // 8방향을 돌리면서 내부에서 비교한다.
        i = start_i;
        j = start_j;
        t = 0;
        while (i >= 0 && i < m && j >= 0 && j < n
            && word[t] != '\0' && word[t] == a[i][j]) { // 그리드 밖으로 빠져나가지 않도록 while로 미리 선수친다.
            i += di[dir];
            j += dj[dir];
            t++;
        }
        if (word[t] == '\0')    // while문을 통해 빠져나왔을 때, 그게 단어가 끝나서 빠져나온 것이라면 해당 단어를 매치한 것이므로 참을 리턴.
            return 1;
    }
    return 0;
}

void main(void)
{
    int num_cases, t, i, j, k;
    char line[256], word[256];
    scanf("%d", &num_cases);
    for (t = 0; t < num_cases; t++) {
        if (t > 0)
            putchar('\n');
        fgets(line, 256, stdin); // gets(line);
        // 그리드를 읽어 들인다
        scanf("%d %d", &m, &n);
        fgets(line, 256, stdin); // gets(line);
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                a[i][j] = getchar();
                if (a[i][j] >= 'A' && a[i][j] <= 'Z')
                    a[i][j] += ('a' - 'A');
            }
            fgets(line, 256, stdin); // gets(line);
        }
        // 단어들을 입력 받아 검색한다
        scanf("%d", &k);
        fgets(line, 256, stdin); // gets(line);
        while (k-- > 0) {
            fgets(word, 256, stdin); // gets(word);
            word[strlen(word) - 1] = '\0'; // 마지막 newline 제거
            for (i = 0; i < strlen(word); i++)
                if (word[i] >= 'A' && word[i] <= 'Z')
                    word[i] += ('a' - 'A'); // 대문자를 소문자로 변경
            for (i = 0; i < m; i++)
                for (j = 0; j < n; j++)
                    if (find_match(word, i, j)) {
                        printf("%d %d\n", i + 1, j + 1);
                        goto end_of_loop_i;
                    }
        end_of_loop_i:
            ;
        }
    }
}