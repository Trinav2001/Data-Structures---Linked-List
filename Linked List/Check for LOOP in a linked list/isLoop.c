#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *next;
}*first=NULL;

void create(int A[], int n)
{
	struct Node *temp,*last=NULL;
	temp = (struct Node *)malloc(sizeof(struct Node));
	temp->data = A[0];
	temp->next = NULL;
	first = last = temp;
	int i;
	for(i=1;i<n;i++)
	{
		temp = (struct Node *)malloc(sizeof(struct Node));
		temp->data = A[i];
		temp->next = NULL;
		last->next = temp;
		last = temp;
	}
}

int isLoop(struct Node *f)
{
	struct Node *p,*q;
	p = q = f;
	do
	{
		p = p->next;
		q = q->next;
		q = q?q->next:NULL;
	}while(p && q && p!=q);
	if(p==q)
	{
		return 1;
	}
	return 0;
}

int main()
{
	int A[] = {3,5,4,10,9},n=5;
	struct Node *t1,*t2;
	create(A,n);
	t1 = first->next->next;
	t2 = first->next->next->next->next;
	t2->next = t1;
	if(isLoop(first))
	{
		printf("Loop is present\n");
	}
	else
	{
		printf("Linear Linked List\n");
	}
	return 0;
}
