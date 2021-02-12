#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *next;
}*first = NULL;

void create(int A[],int n)
{
	struct Node *temp,*last;
	first = (struct Node *)malloc(sizeof(struct Node));
	first->data = A[0];
	first->next = NULL;
	last = first;
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

void Display(struct Node *p)
{
	while(p)
	{
		printf("%d ",p->data);
		p = p->next;
	}
}

int middleNodeData1(struct Node *p)      //Method - 1
{
	int len = 0;
	while(p)
	{
		len++;
		p = p->next;
	}
	int i;
	p = first;
	for(i=0;i<len/2;i++)
	{
		p = p->next;
	}
	return p->data;
}

int middleNodeData2(struct Node *p)            //Method - 2(requires only one time scanning)
{
	struct Node *q=p;
	while(q)
	{
		q = q->next;
		if(q)
		{
			q = q->next;
		}
		if(q)
		{
			p = p->next;
		}
	}
	return p->data;
}

int main()
{
	int A[] = {3,4,6,7,9,11,13,14},n = 7;
	create(A,n);
	Display(first);
	printf("\n\n%d",middleNodeData2(first));
	return 0;
}
