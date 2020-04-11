#include <stdio.h>
#include <unistd.h>

int main()
{
	float pf_empty,pf_mod,mem_acc,p,max,pf_rate;
	printf("Enter time taken to service page fault(empty frame or not modified)(miliseconds)=");
	scanf("%f",&pf_empty);
	while(pf_empty<=0)
	{
		printf("\nenter value bigger than 0! ");
		fflush(stdin);
		scanf("%f",&pf_empty);
	}

	printf("\nEnter time taken to service page fault if replaced page is modified(miliseconds)=");
	scanf("%f",&pf_mod);
	while(pf_mod<=0)
	{
		printf("\nenter value bigger than 0!");
		fflush(stdin);
		scanf("%f",&pf_mod);
	} 

	printf("\nMemory access time(nano seconds)=");
	scanf("%f",&mem_acc);
	while(mem_acc<=0)
	{
		printf("\nenter value bigger than 0!");
		fflush(stdin);
		scanf("%f",&mem_acc);
	}

	printf("\nPercentage of time the page to be replaced is modified=");
	scanf("%f",&p);
	while(p<=0)
	{
		printf("\nenter value bigger than 0!");
		fflush(stdin);
		scanf("%f",&p);
	}

	printf("\nMaximum allowed access time=");
	scanf("%f",&max);
	while(max<=0)
	{
		printf("\nenter value bigger than 0!");
		fflush(stdin);
		scanf("%f",&max);
	}

	p = p/100;
	pf_rate = (max - mem_acc)/(p*pf_mod*1000000 + (1-p)*pf_empty*1000000 - mem_acc);
	printf("Maximum acceptable page fault rate = %f",pf_rate);
	return 0;
}
