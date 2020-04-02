#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

void *fibonnacci(void *n);

void main()
{
	pthread_t th1;
	int n,i;
	printf("\nEnter number of terms you want to print=");
	scanf("%d",&n);
	int *a;
	while(n<=0)
	{
		printf("\nenter value bigger than 0!");
		scanf("%d\n",&n);
	}
	pthread_create(&th1,NULL,fibonnacci,(void*)&n);
	pthread_join(th1,(void*)&a);
	a = *(int*)a;
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
}
void *fibonnacci(void *n)
{
	int f1=0,f2=1,x = *(int*)n,i;
	int a[x],nxt;
	for(i=0;i<x;i++)
	{
		a[i]=f1;
		nxt = f1 + f2;
		f1 = f2;
		f2 = nxt;
	}
	pthread_exit(a);
}
