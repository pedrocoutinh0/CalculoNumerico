#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double **criarMatriz(int l, int c){

    double **m;
    
    m = malloc(sizeof(double)*l);
    if (m == NULL)
    {/* Falta de memoria */
        return NULL;
    }

    for (int i = 0; i < l; i++)
    {
        m[i] = malloc(sizeof(double)*c);
        if (m[i] == NULL)
        {/* Falta de memoria */
            for (int j = 0; j < i; j++)
            {
                free(m[j]);
            }
            free(m);
            return NULL;
        }
    }
    return m;    
}

void lerMatriz(double **m, int l, int c){
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("M[%d][%d]: ", i+1,j+1);
            scanf("%lf", &m[i][j]);
        }     
    }   
}

void mostrarMatriz(double **m, int l, int c){
    printf("--------------");
    for (int i = 0; i < l; i++)
    {
        printf("\n");
        for (int j = 0; j < c; j++)
        {
            printf("%lf\t", m[i][j]);
        }
        
    }
}

int main(){
    double **m;
    
    m = criarMatriz(2, 2);

    lerMatriz(m, 2, 2);

    mostrarMatriz(m, 2, 2);

    return 0;
}
