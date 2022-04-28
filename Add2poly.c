#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef struct poly
{
	int exp; 	//index 
	int coef;	//coefficient 
	struct poly *next;
	
}PNode,*PLinklist;
/*Linked list initialization*/
int Init(PLinklist *head)
{
	*head=(PLinklist)malloc(sizeof(PNode));
	if(*head)
	{
		(*head)->next=NULL;
		return 1;
	}
	else
		return 0;		
}
/*Creating linked list by tail interpolation*/ 
int CreateFromTail(PLinklist*head)
{
	PNode *pTemp,*pHead;
	int c;		//Storage factor 
	int exp;	//Storage index 
	int i=1	;	//Counter 
	pHead=*head;
	scanf("%d,%d",&c,&exp);
	while(c!=0)//When the coefficient is zero, end the input
	{
		pTemp=(PLinklist)malloc(sizeof(PNode));
		if(pTemp)
		{
			pTemp->exp=exp;		//Acceptance index 
			pTemp->coef=c;		//Acceptance coefficient 
			pTemp->next=NULL;
			pHead->next=pTemp;
			pHead=pTemp;
			scanf("%d,%d",&c,&exp);
		 } 
		 else
		 return 0;
	 } 
	 return 1;
}
/*Add two polynomials*/ 
void Polyadd(PLinklist LA,PLinklist LB)
{
	PNode*LAI=LA->next;		//Pointer LAI moves in polynomial A 
	PNode*LBI=LB->next;		 
	PNode*temp;				//Pointer temp saves the node to be deleted 
	int sum=0;				//Sum of preservation factors 
	/*Compare the exponential terms of the nodes referred to by LAI and LBI*/ 
	while(LAI&&LBI)
	{
		if(LAI->exp<LBI->exp){		  
			LA->next=LAI;
			LA=LA->next;
			LAI=LAI->next;
		}
		else if(LAI->exp==LBI->exp)
		{
			sum=LAI->coef+LBI->coef;
			if(sum)
			{
				LAI->coef=sum;
				LA->next=LAI;
				LA=LA->next;
				LAI=LAI->next;
				temp=LBI;
				LBI=LBI->next;
				free(temp);
				
			}
			else
			{
				temp=LAI;
				LAI=LAI->next;
				free(temp);
				temp=LBI;
				LBI=LBI->next;
				free(temp);
				
			}
		}
		else
		{
			LA->next=LBI;
			LA=LA->next;
			LBI=LBI->next;
		}
		
	}
	if(LAI)
		LA->next=LAI;
	else
		LA->next=LBI; 
}
/*Subtraction of two polynomials*/ 
void Polysub(PLinklist LA,PLinklist LB)
{
	PNode*LAI=LA->next;		//Pointer LAI moves in polynomial A 
	PNode*LBI=LB->next;		 
	PNode*temp;				//Pointer temp saves the node to be deleted 
	int difference=0;				//Preservation factor
	/*Compare the exponential terms of the nodes referred to by LAI and LBI*/ 
	while(LAI&&LBI)
	{
		if(LAI->exp<LBI->exp){		  
			LA->next=LAI;
			LA=LA->next;
			LAI=LAI->next;
		}
		else if(LAI->exp==LBI->exp)
		{
			difference=LAI->coef-LBI->coef;
			if(difference)
			{
				LAI->coef=difference;
				LA->next=LAI;
				LA=LA->next;
				LAI=LAI->next;
				temp=LBI;
				LBI=LBI->next;
				free(temp);
				
			}
			else
			{
				temp=LAI;
				LAI=LAI->next;
				free(temp);
				temp=LBI;
				LBI=LBI->next;
				free(temp);
				
			}
		}
		else
		{
			LA->next=LBI;
			LA=LA->next;
			LBI=LBI->next;
		}
		
	}
	if(LAI)
		LA->next=LAI;
	else
		LA->next=LBI; 
}
void Print(PLinklist head)
{
	head=head->next;
	while(head)
	{
		if(head->exp)
			printf("(%dx^%d)",head->coef,head->exp);
		else
			printf("%d",head->coef);
		if(head->next)
			printf("+");
		else
			break;
		head=head->next;
	}
}

int main(void)
{
	PLinklist LA;
	PLinklist LB;
	Init(&LA);
	Init(&LB);
	printf("Please enter the coefficient of the first polynomial,index,Enter 0,0 End input\n");
	CreateFromTail(&LA);
	printf("Please enter the coefficient of the second polynomial,index,Enter 0,0 End input\n");
	CreateFromTail(&LB);
	Print(LA);
	printf("\n");
	Print(LB);
	printf("\n");
	
	int i; 
	
	printf("(Please enter 1 for addition polynomial and 0 for subtraction polynomial)\n"); 
	scanf("%d",&i);
	
	if(1==i){
		Polyadd(LA,LB);
		printf("The result of adding two polynomials:\n");
		Print(LA);
		printf("\n");
	}
	else if(0==i){
		Polysub(LA,LB);
		printf("The result of subtracting two polynomials:\n");
		Print(LA);
		printf("\n");
	}
	else 
		printf("Please enter the correct characters");
	return 0;
	
}
