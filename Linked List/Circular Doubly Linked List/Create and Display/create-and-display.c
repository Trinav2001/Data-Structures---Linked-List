#include<stdio.h>
#include<stdlib.h>

struct Node
{
	struct Node *prev;
	int data;
	struct Node *next;
}*Head;

void create(int A[],int n)
{
	struct Node *temp,*last;
	Head = (struct Node *)malloc(sizeof(struct Node));
	Head->data = A[0];
	Head->prev = Head->next = Head;
	int i;
	last = Head;
	for(i=1;i<n;i++)
	{
		temp = (struct Node *)malloc(sizeof(struct Node));
		temp->data = A[i];
		temp->prev = last;
		temp->next = last->next;
		last->next = temp;
		Head->prev = temp;
		last = temp;
	}
}

void Display(struct Node *h)
{
	do
	{
		printf("%d ",h->data);
		h = h->next;
	}while(h!=Head);
}

int main()
{
	int A[] = {3,4,6,7,9,10},n=6;
	create(A,n);
	Display(Head);
	return 0;
}
