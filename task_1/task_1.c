#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 4 // �v�f��

int main(){
    // �ۑ�1
    typedef struct kadai
    {
        int num;
        char name[20];
        int middle_exam;
        int regular_exam;
    }KADAI;

    // �ۑ�Q
    KADAI *kadai_p;
    kadai_p=malloc(sizeof(KADAI)*N);

    // �G���[����
    if (kadai_p == NULL) {
        printf("cannot allocate!\n");
        exit(1);
    }

    // N�l���̃f�[�^���擾
    for (size_t i = 0; i < N; i++)
    {
        // �ԍ�
        printf("�ԍ��F");
        scanf("%d",&kadai_p[i].num);
        printf("\n");
        // ���O
        printf("���O�F");
        scanf("%s",kadai_p[i].name);
        printf("\n");

        // ���Ԏ���
        printf("���Ԏ����F");
        scanf("%d",&kadai_p[i].middle_exam);
        printf("\n");

        // �������
        printf("��������F");
        scanf("%d",&kadai_p[i].regular_exam);
        printf("\n");
    }

    for (size_t i = 0; i < N; i++)
    {
        // �S���̃X�e�[�^�X��\��
        printf("%d %s %d %d\n",kadai_p[i].num,kadai_p[i].name,kadai_p[i].middle_exam,kadai_p[i].regular_exam);
    }

    // �ۑ�3
    printf("********************************\n");


    int min=0; // �Œᓾ�_��
    double total_score[N]; // �]���_

    for (size_t i = 0; i < N; i++)
    {
        // �]���_�̎Z�o
        total_score[i]=(double)kadai_p[i].middle_exam*0.3+(double)kadai_p[i].regular_exam*0.7;
        printf("%s : %.2lf\n",kadai_p[i].name,total_score[i]);

        // �Œ�_�̔���
        if(total_score[min]>total_score[i]){
            min=i;
        }
    }

    // �Œᓾ�_�҂̕\��
    printf("�Œ�_��%s��%.2lf�_�ł���",kadai_p[min].name,total_score[min]);

    free(kadai_p);
    return 0;
}