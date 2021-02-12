#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *next;
}*Head=NULL;

void create(int A[],int n)
{
	struct Node *temp,*last;
	Head = (struct Node *)malloc(sizeof(struct Node));
	Head->data = A[0];
	Head->next = Head;
	last = Head;
	int i;
	for(i=1;i<n;i++)
	{
		temp = (struct Node *)malloc(sizeof(struct Node));
		temp->data = A[i];
		temp->next = last->next;
		last->next = temp;
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
	printf("\n\n");
}

void Rdisplay(struct Node *h)        //Recursive Display
{
	static int flag = 0;
	if(h!=Head || flag==0)
	{
		flag = 1;
		printf("%d ",h->data);
		Rdisplay(h->next);
	}
	flag = 0;
}

int main()
{
	int A[] = {3,4,2,6,8}, n = 5;
	create(A,n);
	Display(Head);
	Rdisplay(Head);
	return 0;
	
}
