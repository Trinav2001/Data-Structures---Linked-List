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

int max(struct Node *p)
{
	int max = INT_MIN;
	while(p)
	{
		if(p->data>max)
		{
			max = p->data;
		}
		p = p->next;
	}
	return max;
}

int Rmax(struct Node *p)
{
	int x=0;
	if(p==0)
	{
		return INT_MIN;
	}
	
	x = Rmax(p->next);
	return p->data<x?x:p->data;
}

int main()
{
	int A[8] = {7,23,1,8,9,45,3,11};
	create(A,8);
	display(first);
	printf("\n\nmax = %d",max(first));
	printf("\n\nmax = %d",Rmax(first));
}
