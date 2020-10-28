#include <stdio.h>
#include <ctype.h>

#define STACK_SIZE 10   /* Stack Size */
int stack[STACK_SIZE]; /* Stack Area */
int sp;                /* Stack Point */

void push(int data)
{
    if(sp<STACK_SIZE-1){
        stack[++sp]=data;
    }else{
        printf("The array stack is full!!\n");
    }
}

int pop()
{
    if(sp>=0){
        return stack[sp--];
    }else{
        return -1;
    }
}

void initialize()
{
    // sp の値を初期化
    sp=-1;
}

void display()
{
    int i;
    for (int i=STACK_SIZE-1;i>=0;i--) {
        if (i==sp){
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
    // スタックを初期化
    initialize();

    FILE *fp;
    char c;

    fp = fopen("formula.txt","r"); // ファイルオープン

    // データの読み込み
    while(fscanf(fp,"%c",&c)!=EOF){
        if(c=='\n'){
            int result=pop();
            printf("result=%d\n",result);
            // スタックを初期化
            initialize();
            continue;
        }



        if(isdigit(c)){
            int num=c-'0';
            push(num);
            printf("number %d\n",num);
        }else{
            int a,b,ans;
            a=pop();
            b=pop();

            switch (c)
            {
            case '+':
                ans=a+b;
                push(ans);
                break;
            case '-':
                ans=b-a;
                push(ans);
                break;
            case '*':
                ans=a*b;
                push(ans);
                break;
            case '/':
                ans=b/a;
                push(ans);
                break;
            default:
                printf("error\n");
                break;
            }
            printf("operator %c\n",c);
        }

        display();
        printf("\n");

    }

    fclose(fp);


}
