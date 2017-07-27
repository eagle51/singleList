#include <malloc.h>
#include <stdio.h>
#include "singlelist.h"

PNode createList(int n)
{
	int value;
	PNode pHead = (PNode)malloc(sizeof(Node));
	PNode pTail = pHead;
	pTail->next = NULL;
	for (int i = 1;i <= n;++i)
	{
		printf("�������%d���ڵ��ֵ��", i);
		scanf_s("%d", &value);

		PNode pNew = (PNode)malloc(sizeof(Node));
		pNew->data = value;
		pTail->next = pNew;
		pTail = pNew;
		pTail->next = NULL;
	}
	return pHead;
}
void traverse(PNode pHead)
{
	printf("�������Ϊ��\n");
	PNode pTr = pHead;
	while (pTr->next != NULL)
	{
		printf("uuu %d\n", pTr->next->data);
		pTr = pTr->next;
	}
	printf("\n");
}

int length(PNode pHead)
{
	PNode pLen = pHead;
	int len = 0;
	while (pLen->next != NULL)
	{
		pLen = pLen->next;
		len++;
	}
	return len;
}

int insert(PNode pHead, int pos, int val)
{
	PNode pIns = pHead;
	PNode pLen = pHead;
	int len = 0;
	while (pLen->next != NULL)
	{
		pLen = pLen->next;
		len++;
	}
	if ((pIns->next == NULL && pos != 0) || pos < 0 || pos > len) {
		printf("Insert failed!\n");
		return -1;
	}
	else {
		for (int i = 0;i < pos;++i)
			pIns = pIns->next;

		PNode pNew = (PNode)malloc(sizeof(Node));
		pNew->data = val;
		pNew->next = pIns->next;
		pIns->next = pNew;
	}
	return 0;
}

int del(PNode pHead, int pos)
{
	PNode pLen = pHead;
	int len = 0;
	while (pLen->next != NULL) {
		pLen = pLen->next;
		len++;
	}
	if (pos < 1 || pos>len) {
		return -1;
	}
	else {
		PNode pDel = pHead;
		for (int i = 1;i < pos;++i)
			pDel = pDel->next;
		if (pos == len) {
			free(pDel->next);
			pDel->next = NULL;
		}
		else {
			PNode pNext = pDel->next->next;
			free(pDel->next);
			pDel->next = pNext;
		}
	}

	return 0;
}

PNode locate(PNode pHead, int value)
{
	PNode p = pHead->next;
	while (p&&p->data != value)
		p = p->next;

	return p;
}

PNode get(PNode pHead, int k)
{
	PNode p = pHead;
	for (int i = 1;i <= k;++i)
		p = p->next;
	return p;
}

bool isEmpty(PNode pHead)
{
	if (pHead->next == NULL)
		return true;
	else
		return false;
}

PNode sort(PNode pHead)
{
	PNode p;
	int n, temp;
	n = length(pHead);
	if (pHead == NULL || pHead->next == NULL)
		return pHead;
	p = pHead;
	for (int j = 1;j < n;++j) {
		p = pHead->next;
		for (int i = 0;i < n - j;++i) {
			if (p->data > p->next->data) {
				temp = p->data;
				p->data = p->next->data;
				p->next->data = temp;
			}
			p = p->next;
		}
	}
	return pHead;
}

PNode reverse(PNode pHead)
{
	PNode p, q;
	p = pHead->next->next;//�洢�ڶ������
	while (p->next != NULL) {
		q = p->next;		//��¼Ҫ�ƶ��Ľ��
		p->next = q->next;	 //�Ѹý���ԭ�������Ƴ�
		q->next = pHead->next->next;//�Ѹý�����ӵ�pHead֮��
		pHead->next->next = q;
	}
	p->next = pHead->next;	//��pHead�ƶ����±�β����ʱ����ɻ�
	pHead->next = p->next->next;//�ҵ��ƶ���֮�����pHead
	p->next->next = NULL;	//�Ͽ���
	return pHead;
}