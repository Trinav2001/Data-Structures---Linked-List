#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *next;
}*first=NULL;

void create(int A[], int n)
{
	struct Node *temp,*last;
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
	int i;
	while(p!=0)
	{
		printf("%d ", p->data);
		p = p->next;
	}
}

struct Node * search(struct Node *p, int key)
{
	while(p)
	{
		if(p->data==key)
		{
			return (p);
		}
		p = p->next;
	}
	return NULL;
}

struct Node * Rsearch(struct Node *p, int key)
{
	if(p==0)
	{
		return 0;
	}
	if(p->data==key)
	{
		return p;
	}
	return Rsearch(p->next, key);
}

struct Node * Lsearch(struct Node *p, int key)   // Key becomes the first node of the linked list
{
	struct Node *q=NULL;
	while(p)
	{
		if(p->data==key)
		{
			q->next = p->next;
			p->next = first;
			first = p;
			return p;
		}
		q = p;
		p = p->next;
	}
	return NULL;
}

int main()
{
	struct Node *temp;
	int A[8] = {7,23,1,8,9,45,3,11};
	create(A,8);
	display(first);
	temp = Lsearch(first, 45);
	printf("\n\n");
	display(first);
	if(temp)
	{
		printf("\n\nKey is found %d", temp->data);
	}
	else
	{
		printf("\n\nKey not found");
	}
	return 0;
}
