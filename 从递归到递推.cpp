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
	cout << "输入层数" << endl;
//输入层数
	cin >> n;
//初始化三角形
	for(int i=1;i<=n;i++)
		for (int j = 1; j <= i; j++)
		{
			cin >> D[i][j];
		}
//遍历第n层
	for (int i = 1; i <= n; i++)
		Maxsum[n][i] = D[n][i];
//遍历n-1层至1层
	for (int i = n - 1; i > 0; i--)
		for (int j = 1; j <= i; j++)
//求出i，j位置的最大值，直到递推到1，1位置
			Maxsum[i][j] = max(Maxsum[i + 1][j], Maxsum[i + 1][j + 1]) + D[i][j];
	cout << Maxsum[1][1];
}