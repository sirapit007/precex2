#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;

void sort(float x[], int N)
{
	for(int i = 1; i < N; i++)
	{
		for(int j = i; j > 0; j--)
		{
			if(x[j] > x[j-1])
			{
				float temp = x[j];
				x[j] = x[j-1];
				x[j-1] = temp;
			}
			else
			{
				break;
			} 
		}
	}
}

int main()
{
	ifstream source("score2.txt");
	string line;
	float score[20];
	int x = 0;
	while(getline(source,line))
	{
		score[x] = atof(line.c_str());
		x++;
	}
	for(int z = 0; z < 20; z++)
	{
		sort(score, sizeof(score)/sizeof(score[0]));
	}
	ofstream dest("rank.txt");
	for(int y = 0; y < 20; y++)
	{
		if(score[y] == score[y-1] && score[y] != score[y-2]) dest << score[y] << "=" << y << endl;
		else if(score[y] == score[y-1] && y == 1) dest << score[y] << "=" << y << endl;
		else if(y > 1 && y <= 2 && score[y] == score[y-1] && score[y] == score[y-2]) dest << score[y] << "=" << y-1 << endl;
		else if(score[y] != score[y-3] && score[y] == score[y-1] && score[y] == score[y-2]) dest << score[y] << "=" << y-1 << endl;
		else if(y > 2 && score[y] == score[y-2] && score[y] == score[y-3]) dest << score[y] << "=" << (y-(y-1)) << endl;
		else dest << score[y] << "=" << y+1 << endl;
	}
	dest.close();
}