#include <stdio.h>

#define TRUE 1
#define FALSE 0

int rvr_num(int src_num)
{
	int rvr_num = 0;
	while(src_num!=0)
	{
		rvr_num = rvr_num*10 + src_num%10;
		src_num /= 10;
	}
	return rvr_num;
}

int is_palin(int n)
{
	if(n==rvr_num(n))
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

int main()
{
	int ln_num;
	scanf ("%d",&ln_num);
	
	int tst_int;
	
	for(int i=0; i<ln_num; i++)
	{
		scanf ("%d",&tst_int);
		
		
		
		printf ("%d\n",is_palin(tst_int));
	}
}

