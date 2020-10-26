#include <stdio.h>
#include <stdlib.h>

#define N 11

int main(){
    // –â‘è‚P
    int **hyakumasu;
    hyakumasu=(int**)malloc(sizeof(int*)*N);
    for (size_t i = 0; i < N; i++)
    {
        hyakumasu[i]=(int*)malloc(sizeof(int)*N);
    }

    // –â‘è‚Q
    for (size_t i = 1; i < N; i++)
    {
        printf("hyakumasu[%d][0]:",i);
        scanf("%d",&hyakumasu[i][0]);
        printf("\n");
    }

    for (size_t i = 1; i < N; i++)
    {
        printf("hyakumasu[0][%d]:",i);
        scanf("%d",&hyakumasu[0][i]);
        printf("\n");
    }

    // –â‘è‚R
    hyakumasu[0][0]=0;
    for (size_t i = 1; i < N; i++)
    {
        for (size_t j = 1; j < N; j++)
        {
        hyakumasu[i][j]=hyakumasu[i][0]*hyakumasu[0][j];
        }
    }

    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < N; j++)
        {
            printf("%5d",hyakumasu[i][j]);
            if(j==0){
                printf("|");
            }
        }
        printf("\n");
        if(i==0){
            printf("-----+--------------------------------------------------\n");
        }
    }

    for (size_t i = 0; i < N; i++)
    {
        free(hyakumasu[i]);
    }

    free(hyakumasu);


    return 0;

};
