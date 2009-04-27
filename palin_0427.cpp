using namespace std;
#define TRUE 1
#define FALSE 0

#include <vector>
#define BUF_LNG 999999
#define END '\0'

void init_num(vector<int>& pal);
void init_num(vector<int>& pal, char src_num[]);
void adj_up_part(vector<int>& pal, int& up_pos);
void cp_up_part(vector<int>& pal, int& star_pos);
void gen_pal(vector<int>& pal, int& up_pos);
void prt_int_array(vector<int>& pal);
int chat_to_int(char c);
int get_up_pos(int lng);

int main()
{
	int ln_num;
	scanf ("%d",&ln_num);
	// scanf("\n");
	char src_num[BUF_LNG];
	vector<int> pal;
	
	for(int i=0; i<ln_num; i++)
	{
		init_num(pal, src_num);
		
		//init_num(pal);
		int up_pos = get_up_pos(pal.size());
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

void init_num(vector<int>& pal)
{
	pal.clear();
	char c;
	for(scanf("%c",&c); c!=END; scanf("%c",&c))
	{
		pal.push_back(chat_to_int(c));
	}
}

void init_num(vector<int>& pal, char src_num[])
{
	pal.clear();
	scanf ("%s",src_num); //BUF_LNG
	for(int i=0; src_num[i]!=END;i++)
	{
		pal.push_back(chat_to_int(src_num[i]));
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
	for(; star_pos!=-1;  star_pos--)
	{
		pal[pal.size()-star_pos-1] = pal[star_pos];
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
		pal[up_pos] = 0;
		if(up_pos==0)
		{
			pal.insert(pal.begin(),1);
		}
		else
		{
			adj_up_part(pal, --up_pos);
		}
	}
}			   

void gen_pal(vector<int>& pal, int& up_pos)
{
	if(pal[up_pos] == pal[pal.size()-up_pos-1])
	{
		if(up_pos!=0)
		{
			gen_pal(pal, --up_pos);
			return;
		}
	}
	else if(pal[up_pos] > pal[pal.size()-up_pos-1])
	{
		cp_up_part(pal, up_pos);
		return;
	}
	
	int adj_up_pos = (pal.size()-1)/2;
	adj_up_part(pal, adj_up_pos);
	adj_up_pos = get_up_pos(pal.size());
	cp_up_part(pal, adj_up_pos);
}



