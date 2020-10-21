#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 4 // 要素数

int main(){
    // 課題1
    typedef struct kadai
    {
        int num;
        char name[20];
        int middle_exam;
        int regular_exam;
    }KADAI;

    // 課題２
    KADAI *kadai_p;
    kadai_p=malloc(sizeof(KADAI)*N);

    // エラー処理
    if (kadai_p == NULL) {
        printf("cannot allocate!\n");
        exit(1);
    }

    // N人分のデータを取得
    for (size_t i = 0; i < N; i++)
    {
        // 番号
        printf("番号：");
        scanf("%d",&kadai_p[i].num);
        printf("\n");
        // 名前
        printf("名前：");
        scanf("%s",kadai_p[i].name);
        printf("\n");

        // 中間試験
        printf("中間試験：");
        scanf("%d",&kadai_p[i].middle_exam);
        printf("\n");

        // 定期試験
        printf("定期試験：");
        scanf("%d",&kadai_p[i].regular_exam);
        printf("\n");
    }

    for (size_t i = 0; i < N; i++)
    {
        // 全員のステータスを表示
        printf("%d %s %d %d\n",kadai_p[i].num,kadai_p[i].name,kadai_p[i].middle_exam,kadai_p[i].regular_exam);
    }

    // 課題3
    printf("********************************\n");


    int min=0; // 最低得点者
    double total_score[N]; // 評価点

    for (size_t i = 0; i < N; i++)
    {
        // 評価点の算出
        total_score[i]=(double)kadai_p[i].middle_exam*0.3+(double)kadai_p[i].regular_exam*0.7;
        printf("%s : %.2lf\n",kadai_p[i].name,total_score[i]);

        // 最低点の判定
        if(total_score[min]>total_score[i]){
            min=i;
        }
    }

    // 最低得点者の表示
    printf("最低点は%sで%.2lf点でした",kadai_p[min].name,total_score[min]);

    free(kadai_p);
    return 0;
}