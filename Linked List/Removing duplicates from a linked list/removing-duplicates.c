#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *next;
}*first=NULL;

void create(int A[], int n)
{
	struct Node *temp, *last;
	int i;
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
	while(p!=0)
	{
		printf("%d ", p->data);
		p = p->next;
	}
}

void removeduplicates(struct Node *p)
{
	struct Node *q = p->next;
	while(q!=0)
	{
		if(p->data == q->data)
		{
			p->next = q->next;
			free(q);
			q = p->next;
		}
		else
		{
			p = q;
			q = q->next;
		}
	}
}

int main()
{
	int A[] = {3,5,5,7,8,8,8};
	create(A,6);
	display(first);
	printf("\n\nAfter removing duplicate \n\n");
	removeduplicates(first);
	display(first);
}
