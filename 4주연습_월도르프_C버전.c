#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <string.h>

#define MAX_M 50
#define MAX_N 50

static char a[MAX_M][MAX_N];
static int m, n;

// ��ġ (i, j)���� �����Ͽ� 8�������� �ܾ� word�� ã�´�
int find_match(char word[], int start_i, int start_j)
{
    // 8���⿡ ���� i, j �������� ����صд�
    static int di[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
    static int dj[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };
    int i, j, t, dir;
    for (dir = 0; dir < 8; dir++) { // 8������ �����鼭 ���ο��� ���Ѵ�.
        i = start_i;
        j = start_j;
        t = 0;
        while (i >= 0 && i < m && j >= 0 && j < n
            && word[t] != '\0' && word[t] == a[i][j]) { // �׸��� ������ ���������� �ʵ��� while�� �̸� ����ģ��.
            i += di[dir];
            j += dj[dir];
            t++;
        }
        if (word[t] == '\0')    // while���� ���� ���������� ��, �װ� �ܾ ������ �������� ���̶�� �ش� �ܾ ��ġ�� ���̹Ƿ� ���� ����.
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
        // �׸��带 �о� ���δ�
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
        // �ܾ���� �Է� �޾� �˻��Ѵ�
        scanf("%d", &k);
        fgets(line, 256, stdin); // gets(line);
        while (k-- > 0) {
            fgets(word, 256, stdin); // gets(word);
            word[strlen(word) - 1] = '\0'; // ������ newline ����
            for (i = 0; i < strlen(word); i++)
                if (word[i] >= 'A' && word[i] <= 'Z')
                    word[i] += ('a' - 'A'); // �빮�ڸ� �ҹ��ڷ� ����
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