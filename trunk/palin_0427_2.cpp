using namespace std;
#include <iostream>
#define TRUE 1
#define FALSE 0

#define BUF_LNG 999999
#define END '\0'

struct palin{
	char nums[BUF_LNG];
	int lng;
};

int chat_to_int(char c);
void init_num(palin& pal);
void prt_int_array(palin& pal);

void adj_up_part(palin& pal, int& up_pos);
void cp_up_part(palin& pal, int& star_pos);
void gen_pal(palin& pal, int& up_pos);


int get_up_pos(int lng);

int main()
{
	int ln_num;
	scanf ("%d",&ln_num);
	palin pal;
	
	for(int i=0; i<ln_num; i++)
	{
		init_num(pal);
		int up_pos = get_up_pos(pal.lng);
		gen_pal(pal, up_pos);
		prt_int_array(pal);
	}
}

int get_up_pos(int lng)
{
	return lng/2-1;
}
	
int chat_to_int(char c)
{
	return c-48;
}

void init_num(palin& pal)
{
	scanf("%s",pal.nums);
	for(pal.lng=0; pal.nums[pal.lng]!=END; pal.lng++);
}


void prt_int_array(palin& pal)
{
	if(pal.nums[0]=='0')
	{
		printf("1");
	}
	printf("%s\n", pal.nums);
}

void cp_up_part(palin& pal, int& star_pos)
{
	for(; star_pos!=0;  star_pos--)
	{
		pal.nums[pal.lng-star_pos-1] = pal.nums[star_pos];
	}
	if(pal.nums[0]!='0')
	{
		pal.nums[pal.lng-1] = pal.nums[0];
	}
	else
	{
		pal.nums[pal.lng-1] = '1';
	}
}

void adj_up_part(palin& pal, int& up_pos)
{
	if(pal.nums[up_pos]!='9')
	{       
		pal.nums[up_pos]++;
	}
	else
	{
		pal.nums[up_pos] = '0';
		if(up_pos!=0)
		{
			adj_up_part(pal, --up_pos);
		}
	}
}			   

void gen_pal(palin& pal, int& up_pos)
{
	if(pal.nums[up_pos] == pal.nums[pal.lng-up_pos-1])
	{
		if(up_pos!=0)
		{
			gen_pal(pal, --up_pos);
			return;
		}
	}
	else if(pal.nums[up_pos] > pal.nums[pal.lng-up_pos-1])
	{
		cp_up_part(pal, up_pos);
		return;
	}
	
	int adj_up_pos = (pal.lng-1)/2;
	adj_up_part(pal, adj_up_pos);
	adj_up_pos = get_up_pos(pal.lng);
	cp_up_part(pal, adj_up_pos);
}



