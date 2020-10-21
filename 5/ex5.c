/* 上級CプログラミングB 出題日：2020/10/19
3I 8番 氏名 市古空 提出日：2020/10/26忘れずに記入！！ */
/* ファイル名：ex5.c
   演習18 2次元配列の動的割当 */
#include <stdio.h>
#include <stdlib.h> /* 設問１：必要なヘッダファイルのインクルード */

#define N1 10      /* 10人 */
#define N2 5       /* 5科目 */

int main(void){
    int i, j;     /* i:行，j:列 の走査用 */
    /* 設問２：2次元配列に対応する2連鎖ポインタを宣言する */
    int **a;
    /* 設問３：2次元配列を動的に確保 */
    a=(int**)malloc(sizeof(int*)*N1);
    for (int i = 0; i < N1; i++)
    {
        a[i]=(int*)malloc(sizeof(int)*N2);
    }

    /* 設問４：input.txt からのデータ入力 */
     // ファイルポインタを宣言
    FILE *fp;
    fp = fopen("input.txt","r"); // ファイルオープン
    for (int i=0;i<N1;i++ ){
        for(int j=0;j<N2;j++){
            // データの読み込み
            fscanf(fp,"%d",&a[i][j]);
            printf("a[%d][%d]:%d\n",i, j, a[i][j]);  // 読み込みと同時に確認のため出力
        }
    }
    fclose(fp);

    /* 設問５：データを output.csv に出力 */
    fp = fopen("output.csv","w"); // ファイルオープン
    for (int i=0;i<N1;i++){
        int total = 0; // 合計点
        for (int j=0;j<N2;j++){
            // データの書き込み
            fprintf(fp,"%d,",a[i][j]);
        total=total+a[i][j]; // 合計点の計算
        }
        fprintf(fp, "%d\n", total); // 合計点の書き込み
    }
    fclose(fp);

    /* 設問６：二次元配列領域の解放(freeする順番に注意) */
    for (int i=0;i<N2;i++){
        free(a[i]);
    }

    free(a);
}
