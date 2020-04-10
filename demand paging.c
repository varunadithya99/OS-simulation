#include <stdio.h>
#include <unistd.h>

int main()
{
	float pf_empty,pf_mod,mem_acc,p,max,pf_rate;
	printf("Enter time taken to service page fault(empty frame or not modified)(miliseconds)=");
	scanf("%f",&pf_empty);
	printf("\nEnter time taken to service page fault if replaced page is modified(miliseconds)=");
	scanf("%f",&pf_mod);
	printf("\nMemory access time(nano seconds)=");
	scanf("%f",&mem_acc);
	printf("\nPercentage of time the page to be replaced is modified=");
	scanf("%f",&p);
	printf("\nMaximum allowed access time=");
	scanf("%f",&max);
	p = p/100;
	pf_rate = (max - mem_acc)/(p*pf_mod*1000000 + (1-p)*pf_empty*1000000 - mem_acc);
	printf("Maximum acceptable page fault rate = %f",pf_rate);
	return 0;
}
