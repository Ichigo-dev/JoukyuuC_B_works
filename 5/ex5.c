/* �㋉C�v���O���~���OB �o����F2020/10/19
3I 8�� ���� �s�Ë� ��o���F2020/10/26�Y�ꂸ�ɋL���I�I */
/* �t�@�C�����Fex5.c
   ���K18 2�����z��̓��I���� */
#include <stdio.h>
#include <stdlib.h> /* �ݖ�P�F�K�v�ȃw�b�_�t�@�C���̃C���N���[�h */

#define N1 10      /* 10�l */
#define N2 5       /* 5�Ȗ� */

int main(void){
    int i, j;     /* i:�s�Cj:�� �̑����p */
    /* �ݖ�Q�F2�����z��ɑΉ�����2�A���|�C���^��錾���� */
    int **a;
    /* �ݖ�R�F2�����z��𓮓I�Ɋm�� */
    a=(int**)malloc(sizeof(int*)*N1);
    for (int i = 0; i < N1; i++)
    {
        a[i]=(int*)malloc(sizeof(int)*N2);
    }

    /* �ݖ�S�Finput.txt ����̃f�[�^���� */
     // �t�@�C���|�C���^��錾
    FILE *fp;
    fp = fopen("input.txt","r"); // �t�@�C���I�[�v��
    for (int i=0;i<N1;i++ ){
        for(int j=0;j<N2;j++){
            // �f�[�^�̓ǂݍ���
            fscanf(fp,"%d",&a[i][j]);
            printf("a[%d][%d]:%d\n",i, j, a[i][j]);  // �ǂݍ��݂Ɠ����Ɋm�F�̂��ߏo��
        }
    }
    fclose(fp);

    /* �ݖ�T�F�f�[�^�� output.csv �ɏo�� */
    fp = fopen("output.csv","w"); // �t�@�C���I�[�v��
    for (int i=0;i<N1;i++){
        int total = 0; // ���v�_
        for (int j=0;j<N2;j++){
            // �f�[�^�̏�������
            fprintf(fp,"%d,",a[i][j]);
        total=total+a[i][j]; // ���v�_�̌v�Z
        }
        fprintf(fp, "%d\n", total); // ���v�_�̏�������
    }
    fclose(fp);

    /* �ݖ�U�F�񎟌��z��̈�̉��(free���鏇�Ԃɒ���) */
    for (int i=0;i<N2;i++){
        free(a[i]);
    }

    free(a);
}
