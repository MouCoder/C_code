#define _CRT_SECURE_NO_WARNINGS 1
#include"BinaryTree.h"

int main()
{
	int i = 0;
	char* a = "ABD##E#H##CF##G##";
	//����������
	BTNode* root = BinaryTreeCreate(a,&i);
	//�������ڵ����
	int TreeSize = BinaryTreeSize(root);
	printf("�������ڵ������%d\n",TreeSize);
	//������Ҷ�ӽڵ����
	int leafSize = BinaryTreeLeafSize(root);
	printf("������Ҷ�ӽڵ������%d\n",leafSize);
	//��������k��ڵ����
	int k = 3;
	int KSize = BinaryTreeLevelKSize(root,k);
	printf("��%d��ڵ������%d\n",k,KSize);
	//���Ҷ������еĽڵ�
	BTDataType find = 'x';
	BTNode* f = BinaryTreeFind(root,find);
	if (f == NULL)
		printf("û�иýڵ�\n");
	else
		printf("�ҵ��ˣ�ֵΪ%c\n",f->_data);
	//������ǰ�����
	printf("ǰ�������");
	BinaryTreePrevOrder(root);
	printf("\n");
	//���������������
	printf("���������");
	BinaryTreeInOrder(root);
	printf("\n");
	//�������
	printf("���������");
	BinaryTreePostOrder(root);
	printf("\n");
	//�������
	printf("���������");
	BinaryTreeLevelOrder(root);
	printf("\n");
	//�ж϶������Ƿ�Ϊ��ȫ������
	printf("�ж϶������Ƿ�Ϊ��ȫ��������");
	bool tf = BinaryTreeComplete(root);
	if (tf == true)
		printf("����ȫ������\n");
	else
		printf("������ȫ������\n");
	//���ٶ�����
	BinaryTreeDestory(&root);
	return 0;
}