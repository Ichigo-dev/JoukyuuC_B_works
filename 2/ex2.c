/* �㋉C�v���O���~���OB �o����F2020/10/7
   3I 8�� ���� �s�Ë� ��o���F2020/10/14 �Y�ꂸ�ɋL���I�I */
/* ���K2 �\���̂̕��K
   �t�@�C���� ex2.c */

#include <stdio.h>
#include <string.h>

int main(){
    /* �ݖ�P�F����(name)�C�g��(height)�C�̏d(weight)���Ǘ����邽�߂̍\���̂��` */

   typedef struct body
   {
      char name[20];
      int height;
      int weight;
   }BODY;





   /* �ݖ�Q�F�\���̕ϐ� a ��錾���C
    �e�����o�� "���ꑾ�Y", 174, 64.2 ���� */

   BODY a={"���ꑾ�Y",174,64.2};





    /* �ݖ�R�F�u�����F���ꑾ�Y�C�g���F174 cm �̏d�F64.2 kg�v�Əo�� */
   printf("���O�F%s,�g���F%d,�̏d�F%d\n",a.name,a.height,a.weight);

    /* �ݖ�S�F�\���̃|�C���^ p ��p���āC�\���� a �̏���ݖ�R�Ɠ��l�ɏo�� */
   BODY *p=&a;
   printf("���O�F%s,�g���F%d,�̏d�F%d\n",(*p).name,(*p).height,(*p).weight);



   /* �ݖ�T�Fstruct body �^�̍\���̔z�� b (�v�f��3) ��錾���C
   0�Ԗڂ̗v�f�� "���ꑾ�Y", 174, 64.2
   1�Ԗڂ̗v�f�� "���ꎟ�Y", 163, 58.1
   2�Ԗڂ̗v�f�� "����O�Y", 168, 70.3
    ���� */


   BODY b[3];
   strcpy(b[0].name,"���ꑾ�Y");
   b[0].height=174;
   b[0].weight=64.2;
   strcpy(b[1].name,"���ꎟ�Y");
   b[1].height=163;
   b[1].weight=58.1;
   strcpy(b[2].name,"����O�Y");
   b[2].height=168;
   b[2].weight=70.3;



    /* �ݖ�U�F�\���̔z��̏���ݖ�R�Ɠ��l�ɏo�́Dfor����p���邱�� */
   int i;
   for(i=0;i<3;i++){
      printf("���O�F%s,�g���F%d,�̏d�F%d\n",b[i].name,b[i].height,b[i].weight);
   }

   return 0;
}
