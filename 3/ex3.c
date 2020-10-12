/* �㋉C�v���O���~���OB �o����F2020/10/12
3I 8�� ���� �s�Ë� ��o���F2020/10/19�Y�ꂸ�ɋL���I�I */
/* ���K3 �o�u���\�[�g�̃f�[�^�\����ÓI�z�񂩂瓮�I�z��ɕύX����
    �t�@�C���� ex3.c */

#include <stdio.h>
#include <stdlib.h>  // �ݖ�P�F�K�v�ȃw�b�_�t�@�C���̃C���N���[�h

#define N 100000

/* �v���g�^�C�v�錾 */
void bsort(int[], int); /* �o�u���\�[�g */
void set_random(int[], int); /* �z��Ƀ����_���Ȑ������Z�b�g */

int main(){
    /* �ݖ�Q�F�ꎟ���z��ɑ��������A���̃|�C���^ a ��錾���� */
    int *a;
    int n, i; /* n �͗v�f�� */
    /* �ݖ�R�F�v�f���̎擾 */
    printf("�v�f������́F");
    scanf("%d",&n);

    /* �ݖ�S�F�v�f����ϐ��Ŏw�肵�ė̈�𓮓I�Ɋm�ۂ��� */
    a=malloc(sizeof(int)*n);
    /* �G���[���� */
    if (a == NULL) {
        printf("cannot allocate!\n");
        exit(1);
    }

    set_random(a, n); /* �z��������� */
    printf("�\�[�g�O\n");
    // �ݖ�T�F�z��̒��g���o�́ifor���Łj
    for (size_t i = 0; i < n; i++)
    {
        printf("a[%d]=%d\n",i,a[i]);
    }

    /* �ݖ�U�F�o�u���\�[�g���s���֐����Ăяo���āCa ���\�[�g */
    bsort(a,n);
    printf("�\�[�g��\n");
    // �ēx�o�́i�ݖ�T�Ɠ����j
    for (size_t i = 0; i < n; i++)
    {
        printf("a[%d]=%d\n",i,a[i]);
    }
    /* �ݖ�V�F�z��̗��p���I�������C�̈��������� */
    free(*a);
}

/* �ȉ��C�֐���`�D�ύX�̕K�v�͂Ȃ� */
void bsort(int a[], int n){
    int i, j; int tmp;
    for (i=0; i<n-1; i++) {
        for (j=0; j<n-1-i; j++)
            if (a[j]>a[j+1]) {
                tmp=a[j]; a[j]=a[j+1]; a[j+1]=tmp;
            }
    }
}

void set_random(int a[], int n){
    int i;
    for (i=0; i<n; i++)
        a[i] = rand()%n;
}
