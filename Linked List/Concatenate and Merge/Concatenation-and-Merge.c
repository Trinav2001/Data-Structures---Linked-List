#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *next;
}*first=NULL,*second=NULL,*third=NULL;

void Display(struct Node *p)
{
	while(p)
	{
		printf("%d ",p->data);
		p = p->next;
	}
}

void create1(int A[],int n)
{
	int i;
	struct Node *last,*temp;
	temp = (struct Node *)malloc(sizeof(struct Node));
	temp->data = A[0];
	temp->next = NULL;
	first = last = temp;
	for(i=1;i<n;i++)
	{
		temp = (struct Node *)malloc(sizeof(struct Node));
		temp->data = A[i];
		temp->next = NULL;
		last->next = temp;
		last = temp;
	}
}

void create2(int A[],int n)
{
	int i;
	struct Node *last,*temp;
	temp = (struct Node *)malloc(sizeof(struct Node));
	temp->data = A[0];
	temp->next = NULL;
	second = last = temp;
	for(i=1;i<n;i++)
	{
		temp = (struct Node *)malloc(sizeof(struct Node));
		temp->data = A[i];
		temp->next = NULL;
		last->next = temp;
		last = temp;
	}
}

void Merge(struct Node *p, struct Node *q)
{
	struct Node *last=NULL;
	if(p->data<q->data)
	{
		third = last = p;
		p = p->next;
		third->next = NULL;
	}
	else
	{
		third = last = q;
		q = q->next;
		third->next = NULL;
	}
	while(p&&q)
	{
		if(p->data<q->data)
		{
			last->next = p;
			last = p;
			p = p->next;
		}
		else
		{
			last->next = q;
			last = q;
			q = q->next;
		}
	}
	if(p)
	{
		last->next = p;
		last = p;
		p = p->next;
	}
	if(q)
	{
		last->next = q;
		last = q;
		q = q->next;
	}
}

void Concate(struct Node *p)
{
	third = p;
	while(p->next)
	{
		p = p->next;
	}
	p->next = second;
}

int main()
{
	int A[] = {2,5,8,10}, n=4;
	int B[] = {1,6,7,9,11}, m=5;
	create1(A,n);
	create2(B,m);
	Merge(first,second);
	Display(third);
	return 0;
}
