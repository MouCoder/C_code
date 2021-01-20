#define _CRT_SECURE_NO_WARNINGS 1
#include"BinaryTree.h"

//��ʼ������
void QueueInit(Queue* q)
{
	assert(q);
	q->front = NULL;
	q->rear = NULL;
}
//����
void QueuePush(Queue* q, BTNode* node)
{
	assert(q);
	QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
	newNode->_data = node;
	newNode->_next = NULL;
	//�������Ϊ�գ����ͷ��βָ��ýڵ�
	if (q->front == NULL)
		q->front = q->rear = newNode;
	else
	{
		q->rear->_next = newNode;
		q->rear = newNode;
	}
}
//����
void QueuePop(Queue* q)
{
	assert(q);
	if (q->front == NULL)
	{
		printf("�ն��У��޷����г��Ӳ���\n");
		return;
	}
	QueueNode* del = q->front;
	q->front = q->front->_next;
	free(del);
}
//�жӿ�
bool QueueIsEmpty(Queue* q)
{
	assert(q);
	return !(q->front);
}

// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
BTNode* BinaryTreeCreate(BTDataType* a, int* pi)
{
	/*ע�⣺������#��ʾNULL*/
	//���ΪNULL�����ؿգ������ΪNULL�������ڵ㼰�����Һ���
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
// ����������
void BinaryTreeDestory(BTNode** root)
{
	//�����������������ɾ�����Һ�������ɾ�����ڵ�
	if (*root == NULL)
		return;
	BinaryTreeDestory(&(*root)->_left);
	BinaryTreeDestory(&(*root)->_right);
	free(*root);
}
// �������ڵ����
int BinaryTreeSize(BTNode* root)
{
	//����������������ڵ�ΪNULL������0�������ΪNULL����������ڵ������1+�����ӽڵ����
	if (root == NULL)
		return 0;
	return 1 + BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right);
}
// ������Ҷ�ӽڵ����
int BinaryTreeLeafSize(BTNode* root)
{
	//��������Ҷ�ӽڵ���� = ��������Ҷ�ӽڵ���� + ������Ҷ�ӽڵ����
	//���Ϊ������Ҷ�ӽڵ����Ϊ0�����һ���ڵ������������Ϊ��������Ҷ�ӽڵ����Ϊ1������͵���������+������Ҷ�ӽڵ����
	if (root == NULL)
		return 0;
	if (root->_left == NULL && root->_right == NULL)
		return 1;
	return BinaryTreeLeafSize(root->_left)+BinaryTreeLeafSize(root->_right);
}
// ��������k��ڵ����
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	//���������k��ڵ�������Էֽ�Ϊ��������Ϊ��2��ʱ���k-1��...���εݹ飬ֱ��k=1��ʾ��ǰ��ڵ����
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	k--;
	return BinaryTreeLevelKSize(root->_left, k) + BinaryTreeLevelKSize(root->_right,k);
}
// ����������ֵΪx�Ľڵ�
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	//�����һ������������NULL��������ǿ������жϸ��ڵ������Ҫ���ҵ�ֵ�ͷ��ظ��ڵ㣬������ڵ㲻�����ж������������Ƿ����
	if (root == NULL)
		return NULL;
	if (root->_data == x)
		return root;
	if (BinaryTreeFind(root->_left, x) == NULL)
		return BinaryTreeFind(root->_right,x);
	return NULL;
}
// ������ǰ����� 
void BinaryTreePrevOrder(BTNode* root)
{
	if (root == NULL)
		return;
	printf("%c ",root->_data);
	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);
}
// �������������
void BinaryTreeInOrder(BTNode* root)
{
	if (root == NULL)
		return;
	BinaryTreeInOrder(root->_left);
	printf("%c ", root->_data);
	BinaryTreeInOrder(root->_right);
}
// �������������
void BinaryTreePostOrder(BTNode* root)
{
	if (root == NULL)
		return;
	BinaryTreePostOrder(root->_left);
	BinaryTreePostOrder(root->_right);
	printf("%c ", root->_data);
}
// �������
void BinaryTreeLevelOrder(BTNode* root)
{
	//�ø��ڵ���ӣ��ڳ��ӣ�����ʱ�������Һ�����ӣ����εݹ�
	if (root == NULL)
		return;
	struct Queue q;
	QueueInit(&q);
	QueuePush(&q,root);
	while (!QueueIsEmpty(&q))
	{
		if (q.front->_data == NULL)
		{
			//������еĽڵ�ֵΪNULL��ֱ�ӳ��Ӽ���
			QueuePop(&q);
		}
		else
		{
			//�ö��е�ͷ�����ӣ��������Һ��ӽڵ����
			printf("%c ",q.front->_data->_data);
			QueuePush(&q,q.front->_data->_left);
			QueuePush(&q,q.front->_data->_right);
			QueuePop(&q);
		}
	}
}
// �ж϶������Ƿ�����ȫ������
int BinaryTreeComplete(BTNode* root)
{
	//����������������������еĽڵ�ΪNULLʱֹͣ���鿴�����еĽڵ��Ƿ�ȫΪNULL�������������ȫ��������������
	if (root == NULL)
		return true;
	struct Queue q;
	QueueInit(&q);
	QueuePush(&q, root);
	while (!QueueIsEmpty(&q))
	{
		if (q.front->_data == NULL)
		{
			//������еĽڵ�ֵΪNULL��ֱ�ӳ��Ӽ���
			break;
		}
		else
		{
			//�ö��е�ͷ�����ӣ��������Һ��ӽڵ����
			QueuePush(&q, q.front->_data->_left);
			QueuePush(&q, q.front->_data->_right);
			QueuePop(&q);
		}
	}
	//�ж϶�����ʣ��Ľڵ��Ƿ�ȫΪNULL
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