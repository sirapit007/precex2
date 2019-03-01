#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;
char alphabet[8][8];

void showAlphabet();
void randomAlphabet();

int main()
{
	srand(time(0));	
	randomAlphabet();
	showAlphabet();
}

void showAlphabet()
{
	for(int i = 0; i < 8; i++)
	{
		for(int j = 0; j < 8; j++)
		{
			cout << alphabet[j][i] << " ";
		}
		cout << "\n";
	}
}

void randomAlphabet()
{
	char z[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	int h = 0;
	for(int x = 0; x < 8; x++)
	{
		for(int y = 0; y < 8; y++)
		{
			h = rand() % 26;
			alphabet[y][x] = z[h];
		}
	}
}