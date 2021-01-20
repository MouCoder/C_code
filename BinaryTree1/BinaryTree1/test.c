#define _CRT_SECURE_NO_WARNINGS 1
#include"BinaryTree.h"

int main()
{
	int i = 0;
	char* a = "ABD##E#H##CF##G##";
	//创建二叉树
	BTNode* root = BinaryTreeCreate(a,&i);
	//二叉树节点个数
	int TreeSize = BinaryTreeSize(root);
	printf("二叉树节点个数：%d\n",TreeSize);
	//二叉树叶子节点个数
	int leafSize = BinaryTreeLeafSize(root);
	printf("二叉树叶子节点个数：%d\n",leafSize);
	//二叉树第k层节点个数
	int k = 3;
	int KSize = BinaryTreeLevelKSize(root,k);
	printf("第%d层节点个数：%d\n",k,KSize);
	//查找二叉树中的节点
	BTDataType find = 'x';
	BTNode* f = BinaryTreeFind(root,find);
	if (f == NULL)
		printf("没有该节点\n");
	else
		printf("找到了，值为%c\n",f->_data);
	//二叉树前序遍历
	printf("前序遍历：");
	BinaryTreePrevOrder(root);
	printf("\n");
	//二叉树的中序遍历
	printf("中序遍历：");
	BinaryTreeInOrder(root);
	printf("\n");
	//后序遍历
	printf("后序遍历：");
	BinaryTreePostOrder(root);
	printf("\n");
	//层序遍历
	printf("层序遍历：");
	BinaryTreeLevelOrder(root);
	printf("\n");
	//判断二叉树是否为完全二叉树
	printf("判断二叉树是否为完全二叉树：");
	bool tf = BinaryTreeComplete(root);
	if (tf == true)
		printf("是完全二叉树\n");
	else
		printf("不是完全二叉树\n");
	//销毁二叉树
	BinaryTreeDestory(&root);
	return 0;
}