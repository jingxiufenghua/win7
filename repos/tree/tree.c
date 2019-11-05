#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
typedef struct BiNode
{
	char data;
	struct BiNode* lchild, * rchild;
}BiNode, * BiTree;

BiTree CreateBiTree()
{
	char p;
	BiTree T;
	scanf("%c", &p);
	if (p == '#') T = NULL;
	else
	{
		T = (BiTree*)malloc(sizeof(BiNode));
		T->data = p;
		T->lchild = CreateBiTree(T->lchild);
		T->rchild = CreateBiTree(T->rchild);
	}
	return(T);
}
//先序遍历
void PreOrder(BiTree T)
{
	if (T)
	{
		printf("%c", T->data);
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}
//中序遍历
void InOrder(BiTree T)
{
	if (T)
	{
		InOrder(T->lchild);
		printf("%c", T->data);
		InOrder(T->rchild);
	}
}

//后序遍历
void PostOrder(BiTree T)
{
	if (T)
	{
		PostOrder(T->lchild);
		PostOrder(T->rchild);
		printf("%c", T->data);
	}
}

// 计算二叉树叶子节点数
int LeadCount(BiTree T)
{
	if (!T) return 0;
	if (T->lchild == NULL && T->rchild == NULL) return 1;
	else return LeadCount(T->lchild) + LeadCount(T->rchild);
}
//计算二叉树叶子节点数
int NodeCount(BiTree T)
{
	if (!T) return 0;
	else return NodeCount(T->lchild) + NodeCount(T->rchild) + 1;
}

void main()
{
	BiTree Ta;
	Ta = CreateBiTree();
	printf("树");
	printf("\n");
	PreOrder(Ta);
}