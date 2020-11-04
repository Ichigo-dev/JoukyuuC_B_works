#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 5

// 問題１
typedef struct Queue_kouzou
{
    int queue[QUEUE_SIZE]; /* Queue Area */
    int head, tail;         /* Queue in:out Point */
    int count;             /* count of Queue member */
}QUEUE;



// 問題２
void enterq(QUEUE *p,int data)
{
    if(p->count<QUEUE_SIZE){
        p->queue[p->tail++]=data;
        if(p->tail==QUEUE_SIZE){
            p->tail=0;
        }
        p->count++;
    }else{
        printf("queue full.\n");
    }

}

int removeq(QUEUE *p)
{
    if(p->count>0){
        int tmp=p->queue[p->head++];
        if(p->head==QUEUE_SIZE){
            p->head=0;
        }
        p->count--;
        return tmp;
    }else{

        return -1;
    }
}

void initialize(QUEUE *p)
{
    p->head=0;
    p->tail=0;
    p->count=0;
    for (size_t i = 0; i < QUEUE_SIZE; i++)
    {
        p->queue[i]=0;
    }

}

void display(QUEUE *p)
{
    int i;
    // キューの(イメージ的に)左から右に for文を回す
    for (int i=0;i<QUEUE_SIZE;i++) {
        // haed の位置には head-> と出力．でなければスペース
        if(i==p->head){
            printf("head->");
        }else{
            printf("      ");
        }

        // 要素番号とキューの値を出力
        printf("%d:%d",i,p->queue[i]);

        // tail の位置には <-tail と出力．でなければスペース
        if(i==p->tail){
            printf("<-tail\n");
        }else{
            printf("      \n");
        }
    }
}

// 問題３
int main(void)
{
    QUEUE *a,*b;
    a=malloc(sizeof(QUEUE));
    b=malloc(sizeof(QUEUE));
    int mode = 1, id;
    int cart[10]={200,400,800,100,900,600,500,300,700,100};
    initialize(a);
    initialize(b);

    FILE *fp;
    char c;
    int i=0;
    fp=fopen("list.txt","r");
    if(fp==NULL){
        printf("file error.\n");
    }

    // キューにlist.txt,cart[]をもとに値を代入
    while (1)
    {
        c=fgetc(fp);

        if(c==EOF){
            break;
        }else if(c=='\n'){
            continue;
        }

        if(c=='a'){
            enterq(a,cart[i]);
        }
        else if(c=='b'){
            enterq(b,cart[i]);
        }

        i++;
    }
    fclose(fp);

    printf("a:\n");
    display(a);
    printf("b:\n");
    display(b);


    int sum_a=0,sum_b=0;
    for (size_t i = 0; i < QUEUE_SIZE; i++)
    {
        sum_a=sum_a+removeq(a);
        sum_b=sum_b+removeq(b);
    }

    printf("a:%d\n",sum_a);
    printf("b:%d\n",sum_b);

    printf("a:\n");
    display(a);
    printf("b:\n");
    display(b);

    free(a);
    free(b);
    return 0;
}