#include<stdio.h>
#include<stdlib.h>

struct Poly
{
	int coef;
	int exp;
	struct Node *next;
}*poly=NULL;

void create()
{
	struct Poly *temp,*last=NULL;
	int n,i;
	printf("Enter no of terms in the polynomial");
	scanf("%d",&n);
	printf("\nEnter coefficients and exponents of the terms ");
	
	for(i=0;i<n;i++)
	{
		temp = (struct Poly *)malloc(sizeof(struct Poly));
		scanf("%d %d",&temp->coef,&temp->exp);
		temp->next = NULL;
		if(poly==NULL)
		{
			poly = last = temp;
		}
		else
		{
			last->next = temp;
			last = temp;
		}
	}
	
}

void Display(struct Poly *p)
{
	while(p)
	{
		printf("%dx%d + ",p->coef,p->exp);
		p = p->next;
	}
	printf("\n");
}

long Eval(int x)
{
	long sum = 0;
	struct Poly *p = poly;
	while(p)
	{
		sum = sum + (p->coef*pow(x,p->exp));
		p = p->next;
	}
	return sum;
}

int main()
{
	create();
	Display(poly);
	printf("Sum = %ld",Eval(2));
	return 0;
}
