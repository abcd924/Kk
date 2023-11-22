#include<stdio.h>
int main()
{
	int i,j,n,a[50],frame[10],no,k,avail,count=0;
	
	printf("Enter no of pages:\n");
	scanf("%d",&n);
	
	printf("enter page no's\n");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	
	
	printf("enter no of frames");
	scanf("%d",&no);
	
	for(i=0;i<no;i++)
	frame[i]=-1;
	j=0;
	printf("ref string\tpage frame\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t\t",a[i]);
		avail=0;
		for(k=0;k<no;k++)
			if(frame[k]==a[i])
				avail=1;
			if(avail==0)
			{
				frame[j]=frame[i];
				j=(j+1)%no;
				count++;
				for(k=0;k<no;k++)
				printf("%d\t",frame[k]);
			}
			printf("\n");
	}
	printf("page fault  is===%d",count);
	return 0;
}
