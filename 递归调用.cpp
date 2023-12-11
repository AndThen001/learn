#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#define MAX 100
int D[MAX][MAX];
int Maxsum[MAX][MAX];
int n = 0;
using namespace std;
int Func(int x, int y) 
{
//Maxsum[x][y]不等于-1，将Maxsum的值返回给函数值Func（x，y）
//因为不再需要继续调用函数
	if (Maxsum[x][y] != -1) return Maxsum[x][y];
//在最底层，即x=n时，最大值为该位置的值本身
	if (x == n) Maxsum[x][y] = D[x][y];
	else 
	{
//往下走一格
		int a = Func(x + 1, y);
//往下走一格，往右走一格
		int b = Func(x + 1, y + 1);
//选择往下还是右下
		Maxsum[x][y] = max(a, b) + D[x][y];
	}
}
int main() 
{
	cout << "输入层数" << endl;
	cin >> n;
	for(int i=1;i<=n;i++)
		for (int j = 1; j <= i; j++)
		{
			cin >> D[i][j];
		}
	cout << Func(1,1);
}