#define _CRT_SECURE_NO_WARNINGS 1
#include"BinaryTree.h"

//初始化队列
void QueueInit(Queue* q)
{
	assert(q);
	q->front = NULL;
	q->rear = NULL;
}
//进队
void QueuePush(Queue* q, BTNode* node)
{
	assert(q);
	QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
	newNode->_data = node;
	newNode->_next = NULL;
	//如果队列为空，则队头队尾指向该节点
	if (q->front == NULL)
		q->front = q->rear = newNode;
	else
	{
		q->rear->_next = newNode;
		q->rear = newNode;
	}
}
//出队
void QueuePop(Queue* q)
{
	assert(q);
	if (q->front == NULL)
	{
		printf("空队列，无法进行出队操作\n");
		return;
	}
	QueueNode* del = q->front;
	q->front = q->front->_next;
	free(del);
}
//判队空
bool QueueIsEmpty(Queue* q)
{
	assert(q);
	return !(q->front);
}

// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
BTNode* BinaryTreeCreate(BTDataType* a, int* pi)
{
	/*注意：序列中#表示NULL*/
	//如果为NULL，返回空，如果不为NULL，创建节点及其左右孩子
	if (a[*pi] == '#')
	{
		(*pi)++;
		return NULL;
	}
	struct BinaryTreeNode* root = (BTNode*)malloc(sizeof(BTNode));
	//BTNode* root = (BTNode*)malloc(sizeof(BTNode));
	root->_data = a[*pi];
	(*pi)++;
	root->_left = BinaryTreeCreate(a, pi);
	root->_right = BinaryTreeCreate(a, pi);

	return root;
}
// 二叉树销毁
void BinaryTreeDestory(BTNode** root)
{
	//后序遍历二叉树，先删除左右孩子树在删除根节点
	if (*root == NULL)
		return;
	BinaryTreeDestory(&(*root)->_left);
	BinaryTreeDestory(&(*root)->_right);
	free(*root);
}
// 二叉树节点个数
int BinaryTreeSize(BTNode* root)
{
	//遍历二叉树，如果节点为NULL，返回0；如果不为NULL，则二叉树节点个数的1+左右子节点个数
	if (root == NULL)
		return 0;
	return 1 + BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right);
}
// 二叉树叶子节点个数
int BinaryTreeLeafSize(BTNode* root)
{
	//二叉树的叶子节点个数 = 左子树节叶子节点个数 + 右子树叶子节点个数
	//如果为空树，叶子节点个数为0，如果一个节点的左右子树都为空树，则叶子节点个数为1，否则就等于左子树+右子树叶子节点个数
	if (root == NULL)
		return 0;
	if (root->_left == NULL && root->_right == NULL)
		return 1;
	return BinaryTreeLeafSize(root->_left)+BinaryTreeLeafSize(root->_right);
}
// 二叉树第k层节点个数
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	//求二叉树第k层节点个数可以分解为：当层数为第2层时求第k-1层...依次递归，直到k=1表示当前层节点个数
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	k--;
	return BinaryTreeLevelKSize(root->_left, k) + BinaryTreeLevelKSize(root->_right,k);
}
// 二叉树查找值为x的节点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	//如果是一个空树，返回NULL；如果不是空树，判断根节点如果是要查找的值就返回跟节点，如果根节点不是则判断左右子树中是否存在
	if (root == NULL)
		return NULL;
	if (root->_data == x)
		return root;
	if (BinaryTreeFind(root->_left, x) == NULL)
		return BinaryTreeFind(root->_right,x);
	return NULL;
}
// 二叉树前序遍历 
void BinaryTreePrevOrder(BTNode* root)
{
	if (root == NULL)
		return;
	printf("%c ",root->_data);
	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);
}
// 二叉树中序遍历
void BinaryTreeInOrder(BTNode* root)
{
	if (root == NULL)
		return;
	BinaryTreeInOrder(root->_left);
	printf("%c ", root->_data);
	BinaryTreeInOrder(root->_right);
}
// 二叉树后序遍历
void BinaryTreePostOrder(BTNode* root)
{
	if (root == NULL)
		return;
	BinaryTreePostOrder(root->_left);
	BinaryTreePostOrder(root->_right);
	printf("%c ", root->_data);
}
// 层序遍历
void BinaryTreeLevelOrder(BTNode* root)
{
	//让跟节点入队，在出队，出队时让其左右孩子入队，依次递归
	if (root == NULL)
		return;
	struct Queue q;
	QueueInit(&q);
	QueuePush(&q,root);
	while (!QueueIsEmpty(&q))
	{
		if (q.front->_data == NULL)
		{
			//如果队列的节点值为NULL，直接出队即可
			QueuePop(&q);
		}
		else
		{
			//让队列的头结点出队，让其左右孩子节点入队
			printf("%c ",q.front->_data->_data);
			QueuePush(&q,q.front->_data->_left);
			QueuePush(&q,q.front->_data->_right);
			QueuePop(&q);
		}
	}
}
// 判断二叉树是否是完全二叉树
int BinaryTreeComplete(BTNode* root)
{
	//层序遍历二叉树，当队列中的节点为NULL时停止，查看队列中的节点是否全为NULL，如果是则是完全二叉树，否则不是
	if (root == NULL)
		return true;
	struct Queue q;
	QueueInit(&q);
	QueuePush(&q, root);
	while (!QueueIsEmpty(&q))
	{
		if (q.front->_data == NULL)
		{
			//如果队列的节点值为NULL，直接出队即可
			break;
		}
		else
		{
			//让队列的头结点出队，让其左右孩子节点入队
			QueuePush(&q, q.front->_data->_left);
			QueuePush(&q, q.front->_data->_right);
			QueuePop(&q);
		}
	}
	//判断队列中剩余的节点是否全为NULL
	while (!QueueIsEmpty(&q))
	{
		if (q.front->_data != NULL)
			return false;
		else
		{
			QueuePop(&q);
		}
	}
	return true;
}