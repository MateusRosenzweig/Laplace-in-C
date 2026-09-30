#include <stdio.h>

void separa_matrizes(int n, int m[20][20], int matrizes[20][20][20]){
    int ni = 0, nj = 0;

    for(int k = 0; k < n; k++){
        ni = 0;
        for(int i = 1; i < n; i++){
            nj = 0;
            for(int j = 0; j < n; j++){
                if(j == k) continue;
                    matrizes[k][ni][nj] = m[i][j];
                    nj++;
            }
            if(i != 0) ni++;
        }
    }

}

int determinantes(int n, int m[20][20]){
    if(n == 1) return m[0][0];

    if(n == 2){
        return (m[0][0] * m[1][1]) - (m[1][0] * m[0][1]);
    }

    int mtam = n - 1, matrizes[20][20][20], det = 0;

    separa_matrizes(n, m, matrizes);


        for(int k = 0; k < n; k++){
            int termo;

            if(k % 2 != 0) termo = -1 * (m[0][k] * determinantes(mtam, matrizes[k]));
            else termo = (m[0][k] * determinantes(mtam, matrizes[k]));

            det += termo;
        }

return det;
}

int main(void){

    int m[20][20];
    int n;
    printf("Tamanho matriz:");
    scanf("%d", &n);

    printf("Matriz:");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &m[i][j]);
        }
    }

    printf("%d\n", determinantes(n, m));


    return 0;
}

