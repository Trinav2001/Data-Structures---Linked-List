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

int count(struct Node *p)
{
	int c=0;
	while(p!=0)
	{
		c++;
		p = p->next;
	}
	return c;
}

int Delete(struct Node *p, int index)
{
	int i, x=0;
	struct Node *q = NULL;
	if(index<=0 || index>count(p))
	{
		return -1;
	}
	else
	{
		for(i=0;i<index-1;i++)
		{
			q = p;
			p = p->next;
		}
		if(p==first)
		{
			first = first->next;
			x = p->data;
			free(p);
			return x;
		}
		else
		{
			q->next = p->next;
			x= p->data;
			free(p);
			return x;
		}
		
	}	
}

int main()
{
	int A[] = {10,20,30,40,50};
	create(A,5);
	display(first);
	printf("\n\nNodes = %d",count(first));
	printf("\n\n");
	printf("Deleted element is %d\n", Delete(first, 2));
	display(first);
	printf("\nNodes = %d",count(first));
}
