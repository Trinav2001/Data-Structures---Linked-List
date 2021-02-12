#include<stdio.h>
#include<stdlib.h>

struct Node
{
	struct Node *prev;
	int data;
	struct Node *next;
}*first=NULL;

void create(int A[],int n)
{
	struct Node *temp,*last;
	first = (struct Node *)malloc(sizeof(struct Node));
	first->data = A[0];
	first->prev = first->next = NULL;
	last = first;
	int i;
	for(i=1;i<n;i++)
	{
		temp = (struct Node *)malloc(sizeof(struct Node));
		temp->data = A[i];
		temp->next = last->next;
		temp->prev = last;
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
	printf("\n\n");
}

int Length(struct Node *p)
{
	int len = 0;
	while(p)
	{
		len++;
		p = p->next;
	}
	return len;
}

void Insert(int pos,int x)
{
	struct Node *t;
	t = (struct Node *)malloc(sizeof(struct Node));
	t->data = x;
	if(pos<0 || pos>Length(first))
	{
		return -1;
	}
	if(pos==0)
	{
		t->prev = NULL;
		t->next = first;
		first->prev = t;
		first = t;
	}
	else
	{
		struct Node *p = first;
		int i;
		for(i=0;i<pos-1;i++)
		{
			p = p->next;
		}
		t->next = p->next;
		t->prev = p;
		if(p->next)
		{
			p->next->prev = t;
		}
		p->next = t;
	}
}

int Delete(struct Node *p,int pos)
{
	int x;
	if(pos<1||pos>Length(first))
	{
		return -1;
	}
	if(pos==1)
	{
		first = first->next;
		if(first)
		{
			first->prev = NULL;
		}
		x = p->data;
		free(p);
	}
	else
	{
		int i;
		for(i=0;i<pos-2;i++)
		{
			p = p->next;
		}
		p->prev->next = p->next;
		if(p->next)
		{
			p->next->prev = p->prev;
		}
		x = p->data;
		free(p);
	}
	return x;
}

int main()
{
	int A[] = {3,5,6,8,9},n=5;
	create(A,n);
	Display(first);
	int ele = Delete(first,5);
	Display(first);
	printf("Delete elements is %d",ele);
	return 0;
}
