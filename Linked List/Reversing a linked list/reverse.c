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

int count(struct Node *p)
{
	int c=0;
	while(p)
	{
		c++;
		p = p->next;
	}
	return c;
}
void reverse1(struct Node *p)
{
	struct Node *q=p;
	int i=0;
	printf("count = %d\n\n", count(first));
	int A[10]={0};
	while(q!=0)
	{
		A[i] = q->data;
		q = q->next;
		i++;
	}
	q = first;
	i--;
	while(q!=0)
	{
		q->data = A[i];
		q = q->next;
		i--;
	}
}

void reverse2(struct Node *p)
{
	struct Node *q=NULL,*r=NULL;
	while(p!=0)
	{
		r = q;
		q = p;
		p = p->next;
		q->next = r;
	}
	first = q;
}

void reverse3(struct Node *q, struct Node *p)
{
	if(p)
	{
		reverse3(p,p->next);
		p->next = q;
	}
	else
	{
		first = q;
	}
}
int main()
{
	int A[] = {3,4,5,6,7,2,1};
	create(A,6);
	display(first);
	printf("\n\n");
	reverse1(first);
	display(first);
	printf("\n\n");
	reverse2(first);
	display(first);
	printf("\n\n");
	reverse3(NULL,first);
	display(first);
	return 0;
}
