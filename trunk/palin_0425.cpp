using namespace std;
#define TRUE 1
#define FALSE 0

#include <vector>
#define MAX_LNG 1000000

void init_num(vector<int>& pal, int& src_num);
void adj_up_part(vector<int>& pal, int& up_pos);
void cp_up_part(vector<int>& pal, int& star_pos);
void gen_pal(vector<int>& pal, int& up_pos);
void prt_int_array(vector<int>& pal);

int main()
{
	int ln_num;
	scanf ("%d",&ln_num);
	
	int src_num;
	vector<int> pal;
	
	for(int i=0; i<ln_num; i++)
	{
		scanf ("%d",&src_num);
		init_num(pal, src_num);
		int up_pos = pal.size()/2;
		gen_pal(pal, up_pos);
		prt_int_array(pal);
		pal.clear();
	}
}


void init_num(vector<int>& pal, int& src_num)
{
	for(; src_num!=0; src_num /= 10)
	{
		pal.push_back(src_num%10);
	}
}	

void prt_int_array(vector<int>& pal)
{
	for(int i=0; i<pal.size(); i++)
	{
		printf("%d", pal[i]);
	}
	printf("\n");
}

void cp_up_part(vector<int>& pal, int& star_pos)
{
	for(; star_pos!=0;  star_pos--)
	{
		pal[star_pos-1] = pal[pal.size()-star_pos];
	}
}

void adj_up_part(vector<int>& pal, int& up_pos)
{
	if(pal[up_pos]!=9)
	{       
		pal[up_pos]++;
	}
	else
	{
		if(up_pos<MAX_LNG)
		{
			pal[up_pos++] = 0;
			if(up_pos==pal.size())
			{
				pal.push_back(1);
			}
			else
			{
				adj_up_part(pal, up_pos);
			}
		}
		else
		{
			printf("exceed max length!");
			return;
		}
	}
}			   




void gen_pal(vector<int>& pal, int& up_pos)
{
	if(pal[up_pos] == pal[pal.size()-1-up_pos])
	{
		if(up_pos!=(pal.size()-1))
		{
			gen_pal(pal, ++up_pos);
			return;
		}
	}
	else if(pal[up_pos] > pal[pal.size()-1-up_pos])
	{
		cp_up_part(pal, up_pos);
		return;
	}
	
	int adj_up_pos = pal.size()/2;
	adj_up_part(pal, adj_up_pos);
	adj_up_pos = pal.size()/2;
	cp_up_part(pal, adj_up_pos);
}


