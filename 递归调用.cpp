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
//Maxsum[x][y]������-1����Maxsum��ֵ���ظ�����ֵFunc��x��y��
//��Ϊ������Ҫ�������ú���
	if (Maxsum[x][y] != -1) return Maxsum[x][y];
//����ײ㣬��x=nʱ�����ֵΪ��λ�õ�ֵ����
	if (x == n) Maxsum[x][y] = D[x][y];
	else 
	{
//������һ��
		int a = Func(x + 1, y);
//������һ��������һ��
		int b = Func(x + 1, y + 1);
//ѡ�����»�������
		Maxsum[x][y] = max(a, b) + D[x][y];
	}
}
int main() 
{
	cout << "�������" << endl;
	cin >> n;
	for(int i=1;i<=n;i++)
		for (int j = 1; j <= i; j++)
		{
			cin >> D[i][j];
		}
	cout << Func(1,1);
}