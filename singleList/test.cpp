#include <stdio.h>
#include <stdlib.h>
#include "singlelist.h"
int main(void)
{
	PNode head;
	head = createList(5);
	traverse(head);
	printf("length = %d\n",length(head));
	insert(head, 0, 100);
	printf("length = %d\n",length(head));
	traverse(head);
	insert(head,6,100);
	printf("length = %d\n",length(head));
	traverse(head);
	insert(head,1,200);
	printf("length = %d\n",length(head));
	traverse(head);
	insert(head,8,300);
	printf("length = %d\n",length(head));
	traverse(head);
	del(head,9);
	printf("length = %d\n",length(head));
	traverse(head);
	del(head,1);
	printf("length = %d\n",length(head));
	traverse(head);
	del(head,4);
	printf("length = %d\n",length(head));
	traverse(head);
	//printf("locate2: %d",locate(head,2)->data);
	//printf("get2: %d",get(head,2)->data);

	head = sort(head);
	traverse(head);
	reverse(head);
	traverse(head);
	system("pause");
	return 0;
}