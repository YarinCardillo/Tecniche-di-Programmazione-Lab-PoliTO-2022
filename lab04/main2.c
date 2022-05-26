#include <stdio.h>
#define maxN 30

void ruota(int v[maxN], int N, int P, int dir);

void ruota(int v[maxN], int N, int P, int dir){
    int temp;

    switch (dir) {
        case 1:
            for (int i = 0; i < P; ++i) {
                temp = v[0];
                for (int j = 0; j < N - 1; ++j) {
                    v[j] = v[j + 1];
                }
                v[N - 1] = temp;
            }
            break;

        case -1:
            for (int i = 0; i < P; ++i) {
                temp = v[N - 1];
                for (int j = N - 1; j > 0; --j) {
                    v[j] = v[j - 1];
                }
                v[0] = temp;
            }
            break;
        default:
            printf("Wrong input\n");
    }
}

int main() {

    int V[maxN];
    int nPosiz, size, direction;

    printf("Specify the size of the array (< 30):\n");
    scanf("%d", &size);

    for (int i = 0; i < size; ++i) {
        printf("V[%d]:\n", i);
        scanf("%d", &V[i]);
    }

    fflush(stdin);

    printf("Specify the direction of the shift. \nLeft (1) or Right (-1)?\n");
    scanf("%d", &direction);

    printf("\nBefore shift:\n");
    for (int i = 0; i < size; ++i) {
        printf("V[%d] = %d\n", i, V[i]);
    }
    printf("\n");

    do {
        printf("Specify the number (< %d) of positions to shift (type 0 to end):\n", size);
        scanf("%d", &nPosiz);
        ruota(V, size, nPosiz, direction);
    } while (nPosiz != 0 && nPosiz < size);

    printf("\nAfter shift:\n");
    for (int i = 0; i < size; ++i)
        printf("V[%d] = %d\n", i, V[i]);

    return 0;
}