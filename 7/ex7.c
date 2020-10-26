/* 上級CプログラミングB 出題日：2020/10/26
   3I 8番 氏名 市古空 提出日：2020/10/26忘れずに記入！！ */
/* ファイル名：ex7.c
    演習7 スタック（棚）
    スタックを操作する関数 push(), pop()を完成させる
 */
#include <stdio.h>

#define STACK_SIZE 5   /* Stack Size */
int stack[STACK_SIZE]; /* Stack Area */
int sp;                /* Stack Point */

// 設問１：push()の完成
void push(int data)
{
    if(sp<STACK_SIZE-1){
        stack[++sp]=data;
    }else{
        printf("The array stack is full!!\n");
    }
}

// 設問２：pop()の完成
int pop()
{
    if(sp>=0){
        return stack[sp--];
    }else{
        return -1;
    }
}

// 設問３：initialize()の完成
void initialize()
{
    // sp の値を初期化
    sp=-1;
}

// 設問４：display()の完成
void display()
{
    int i;
    for (int i=STACK_SIZE-1;i>=0;i--) { // スタックの上から下に for文を回す
        if (i==sp){ // スタックポインタの位置のとき SP-> を出力
            printf("sp->");
        }else{
            printf("    ");
        }
    // 要素番号とスタックの値を出力
        printf("%6d:%d\n",i,stack[i]);
    }
}

int main(void)
{
    int mode = 1, id;
    // 設問５：スタックを初期化
    initialize();

    while (mode) {
        printf("?push(1) or pop(0) = ");
        scanf("%d", &mode);
        if (mode == 1) {
            printf("?id = ");
            scanf("%d", &id);
            // 設問６：id の値をスタックに入力
            push(id);
        } else if (mode == 0) {
            // 設問７：スタックから値を出力し id に代入
            id=pop();
            if (id > 0){
                printf("id = %d was picked\n", id);
            }else{
                printf("pos is failed.\n");
            }
        }
        // 設問８：スタックの中身を表示
        display();

        printf("?continue(1) or quit(0) = ");
        scanf("%d", &mode);
    }
}
