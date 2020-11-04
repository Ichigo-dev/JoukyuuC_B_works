/* 上級CプログラミングB 出題日：2020/11/2
   3I 8番 氏名 市古 空 提出日：2020/11/2忘れずに記入！！ */
/* ファイル名：ex9.c
   演習9 キュー（待ち行列）
   キューを操作する関数 enterq(), removeq()を完成させる
 */
#include <stdio.h>

#define QUEUE_SIZE 5
int queue[QUEUE_SIZE]; /* Queue Area */
int head, tail;         /* Queue in:out Point */
int count;             /* count of Queue member */

// 設問１：enterqの完成
void enterq(int data)
{
    if(count<QUEUE_SIZE){
        queue[tail++]=data;
        if(tail==QUEUE_SIZE){
            tail=0;
        }
        count++;
    }else{
        printf("queue full.\n");
    }

}

// 設問２：removeqの完成
int removeq()
{
    if(count>0){
        int tmp=queue[head++];
        if(head==QUEUE_SIZE){
            head=0;
        }
        count--;
        return tmp;
    }else{

        return -1;
    }
}

// 設問３：initializeの完成
void initialize()
{
    head=0;
    tail=0;
    count=0;
    for (size_t i = 0; i < QUEUE_SIZE; i++)
    {
        queue[i]=0;
    }

}

// 設問４：displayの完成
void display()
{
    int i;
    // キューの(イメージ的に)左から右に for文を回す
    for (int i=0;i<QUEUE_SIZE;i++) {
        // haed の位置には head-> と出力．でなければスペース
        if(i==head){
            printf("head->");
        }else{
            printf("      ");
        }

        // 要素番号とキューの値を出力
        printf("%d:%d",i,queue[i]);

        // tail の位置には <-tail と出力．でなければスペース
        if(i==tail){
            printf("<-tail\n");
        }else{
            printf("      \n");
        }
    }
}

int main(void)
{
    int mode = 1, id;
    initialize();
    while (mode) {
        printf("?enter(1) or remove(0) = ");
        scanf("%d", &mode);
        if (mode==1) {
            printf("?id = ");
            scanf("%d", &id);
            // 設問５：id の値をキューに入力
            enterq(id);
        } else if (mode==0) {
            // 設問６：キューから値を出力し，id に代入
            id=removeq();
            if (id>0){
                printf("id = %d was removed\n", id);
            }else{
                printf("queue empty.\n");
            }
        }
        // 設問７：キューの中身を表示
        display();

        printf("?continue(1) or quit(0) = ");
        scanf("%d", &mode);
    }

    return 0;
}

/* ?enter(1) or remove(0) = 1
?id = 1
head->0:1
      1:0<-tail
      2:0
      3:0
      4:0
?continue(1) or quit(0) = 1
?enter(1) or remove(0) = 1
?id = 2
head->0:1
      1:2
      2:0<-tail
      3:0
      4:0
?continue(1) or quit(0) = 1
?enter(1) or remove(0) = 1
?id = 3
head->0:1
      1:2
      2:3
      3:0<-tail
      4:0
?continue(1) or quit(0) = 1
?enter(1) or remove(0) = 1
?id = 4
head->0:1
      1:2
      2:3
      3:4
      4:0<-tail
?continue(1) or quit(0) = 1
?enter(1) or remove(0) = 1
?id = 5
head->0:1<-tail
      1:2
      2:3
      3:4
      4:5
?continue(1) or quit(0) = 1
?enter(1) or remove(0) = 1
?id = 6
queue full.
head->0:1<-tail
      1:2
      2:3
      3:4
      4:5
?continue(1) or quit(0) = 1
?enter(1) or remove(0) = 0
id = 1 was removed
      0:1<-tail
head->1:2
      2:3
      3:4
      4:5
?continue(1) or quit(0) = 1
?enter(1) or remove(0) = 0
id = 2 was removed
      0:1<-tail
      1:2
head->2:3
      3:4
      4:5
?continue(1) or quit(0) = 1
?enter(1) or remove(0) = 0
id = 3 was removed
      0:1<-tail
      1:2
      2:3
head->3:4
      4:5
?continue(1) or quit(0) = 1
?enter(1) or remove(0) = 0
id = 4 was removed
      0:1<-tail
      1:2
      2:3
      3:4
head->4:5
?continue(1) or quit(0) = 1
?enter(1) or remove(0) = 0
id = 5 was removed
head->0:1<-tail
      1:2
      2:3
      3:4
      4:5
?continue(1) or quit(0) = 1
?enter(1) or remove(0) = 0
queue empty.
head->0:1<-tail
      1:2
      2:3
      3:4
      4:5
?continue(1) or quit(0) = 0 */