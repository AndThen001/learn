#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#define MAX 100
int D[MAX][MAX];
int Maxsum[MAX][MAX];
int n = 0;
using namespace std;
int main() 
{
	cout << "ÊäÈë²ãÊý" << endl;
	cin >> n;
	for(int i=1;i<=n;i++)
		for (int j = 1; j <= i; j++)
		{
			cin >> D[i][j];
		}
	for (int i = 1; i <= n; i++)
		Maxsum[n][i] = D[n][i];
	for (int i = n - 1; i > 0; i--)
		for (int j = 1; j <= i; j++)
			Maxsum[i][j] = max(Maxsum[i + 1][j], Maxsum[i + 1][j + 1]) + D[i][j];
	cout << Maxsum[1][1];
}