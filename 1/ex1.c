/* �㋉C�v���O���~���OB �o����F2020/10/5
   3I 8�� ���� �s�Ë� ��o���F2020/10/14 */
/* ���K1 �|�C���^�̕��K
   �t�@�C���� ex1.c */

#include <stdio.h>

int main()
{
    /* �ʏ�̃|�C���^�ϐ� */
    {
        int a;
        a = 5;
        int *p;
        p = &a;  /* �����ɏ����� int *p=&a; */
        printf("&a : %p, a : %d\n", &a, a);
        /* �ݖ�P�Fp���w���ϐ��̃A�h���X�Cp���w���ϐ��̒l��p��p���ďo�� */
        printf("&a:%p, a: %d\n",p,*p);
    }

    {
        int a[5] = {1, 2, 3, 4, 5};
        int *p1, *p2;
        p1 = &a[2];
        p2 = &a[4];
        printf("&a[2] : %p, a[2] : %d\n", &a[2], a[2]);
        printf("&a[4] : %p, a[4] : %d\n", &a[4], a[4]);
        /* �ݖ�Q�F
        p1���w���ϐ��̃A�h���X�Cp1���w���ϐ��̒l��p1��p���ďo��

        p2���w���ϐ��̃A�h���X�Cp2���w���ϐ��̒l��p2��p���ďo��

        */
        printf("&a[2]:%p,a[2]:%d\n", p1, *p1);
        printf("&a[4]:%p,a[4]:%d\n", p2, *p2);
    }

    /* �z��Ƃ��Ẵ|�C���^ */
    {
        int a[5] = {1, 2, 3, 4, 5};
        int *p;
        p = a;   /* p = &a[0]; �������Ӗ� */
        printf("&a[0] : %p, a[0] : %d\n", &a[0], a[0]);
        printf("&a[2] : %p, a[2] : %d\n", &a[2], a[2]);
        /* �ݖ�R�Fp���w���ϐ��i�z��j�̃A�h���X�Cp���w���z��̐擪�̒l��p��p���ďo�͂��� */
        printf("a:%p,a[0]:%d\n",p,*p);
            /* �ݖ�S�Fa[2]�̃A�h���X�C�l��p��p���ďo�� */
            printf("&a[2]:%p,a[2]:%d\n",p+2,*(p + 2));
        /* �ݖ�T�Fa[2]�̃A�h���X�C�l��p��p���ďo�́i�z�񕗂̋L�q�Łj */
        printf("&a[2]:%p,a[2]:%d\n", &p[2], p[2]);
        /* �ݖ�U�Fa[2]�̃A�h���X�C�l��a��p���ďo�́i�|�C���^���̋L�q�Łj */
        printf("&a[2]:&p,a[2]:%d\n", &a[2], a[2]);
    }

    /* �֐��|�C���^ */
    // {
    //     int func(int); /* �v���g�^�C�v�錾 */
    //     int (*p_func)(int);
    //     p_func = func;
    //     printf("func�̃A�h���X : %p, func(5) : %d\n", func, func(5));
    //     /* �ݖ�V�F�֐��|�C���^ p_func ���w���A�h���X�Cp_func���w���֐����Ăяo�� */

    // }

    {
        /* �ݖ�W�F�������v���g�^�C�v�錾���� */
        void swap(              );
        int a[2] = {5, 3};
        printf("a[0] = %d, a[1] = %d\n", a[0], a[1]);
        /* �ݖ�X�F������ swap�֐��Ăяo���Ca[0]��a[1]�̒l���������� */
        swap(&a[0],&a[1]);
        /* �\�����Ċm�F */
        printf("swap��\n");
        printf("a[0]=%d, a[1]=%d\n", a[0], a[1]);
    }

    return 0;
}

/* �֐��|�C���^�ŊǗ�����֐��D�ύX�̕K�v�Ȃ� */
int func(int i)
{
    return i;
}

/* �ݖ�P�O�Fswap�֐����쐬���� */
void swap(int *a, int *b)
{
    int tmp;
    tmp=*a;
    *a = *b;
    *b = tmp;
}
