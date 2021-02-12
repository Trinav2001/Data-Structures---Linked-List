#include<stdio.h>
#include<stdlib.h>

struct Node
{
	struct Node *prev;
	int data;
	struct Node *next;
}*Head=NULL;

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
	printf("\n\n\n");
}

int Length(struct Node *h)
{
	int len = 0;
	do
	{
		len++;
		h = h->next;
	}while(h!=Head);
	if(len==1 && Head==NULL)
	{
		return 0;
	}
	return len;
}

void Insert(int pos,int x)
{
	struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
	temp->data = x;
	if(pos<0 || pos>Length(Head))
	{
		return -1;
	}
	if(pos==0)
	{
		temp->next = Head;
		temp->prev = Head->prev;
		Head->prev->next = temp;
		Head->prev = temp;
		Head = temp;
	}
	else
	{
		struct Node *p=Head;
		int i;
		for(i=0;i<pos-1;i++)
		{
			p = p->next;
		}
		temp->next = p->next;
		temp->prev = p;
		p->next->prev = temp;
		p->next = temp;
	}
}

int main()
{
	int A[] = {3,4,6,7,9,10},n=6;
	create(A,n);
	Display(Head);
	Insert(0,2);
	Display(Head);
	return 0;
}
