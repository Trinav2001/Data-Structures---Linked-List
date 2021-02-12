#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *next;
}*first=NULL;

void create(int A[], int n)
{
	int i;
	struct Node *temp, *last;
	first = (struct Node *)malloc(sizeof(struct Node));
	first->data = A[0];
	first->next = NULL;
	last = first;
	for(i=1;i<n;i++)
	{
		temp = (struct Node *)malloc(sizeof(struct Node));
		temp->data = A[i];
		temp->next = NULL;
		last->next = temp;
		last = temp;
	}
}

void display(struct Node *p)
{
	while(p)
	{
		printf("%d ",p->data);
		p = p->next;
	}
}

void insertSorted(struct Node *p, int x)
{
	struct Node *temp, *q=NULL;
	temp = (struct Node *)malloc(sizeof(struct Node));
	temp->data = x;
	temp->next = NULL;
	if(first==NULL)
	{
		first = temp;
	}
	else
	{
		while(p && x>p->data)
		{
			q = p;
			p = p->next;
		}
		if(p==first)
		{
			temp->next = first;
			first = temp;
		}
		else
		{
			temp->next = q->next;
			q->next = temp;
		}
	}
}

int main()
{
	int A[] = {10,20,30,40,50};
	create(A,5);
	display(first);
	printf("\n\n\n");
	insertSorted(first, 45);
	display(first);
}
