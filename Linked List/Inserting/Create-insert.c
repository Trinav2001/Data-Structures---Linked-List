#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *next;
}*first=NULL;

void display(struct Node *p)
{
	while(p)
	{
		printf("%d ",p->data);
		p = p->next;
	}
}

void insertCreate(struct Node *p, int x)
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
	insertCreate(first, 45);
	display(first);
	printf("\n\n");
	insertCreate(first, 50);
	display(first);
	printf("\n\n");
	insertCreate(first, 10);
	display(first);
	printf("\n\n");
	insertCreate(first, 20);
	display(first);
}
