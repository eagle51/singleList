#ifndef _SINGLE_LIST_H
#define _SIGNLE_LIST_H
typedef struct node {
	int data;
	struct node *next;
}Node,*PNode;

PNode createList(int n);
void traverse(PNode pHead);
int length(PNode pHead);
int insert(PNode pHead,int pos,int val);
int del(PNode pHead, int  pos);
PNode locate(PNode pHead, int value);//按元素值查找
PNode get(PNode pHead, int k);//按序号查找
bool isEmpty(PNode pHead);
PNode sort(PNode pHead);
PNode reverse(PNode pHead);
#endif // !SINGLE_LIST_H
