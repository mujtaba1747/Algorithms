#include<bits/stdc++.h>
using namespace std;
#define MAXN ((int)(1e6 + 2))
int sp[MAXN][26];
int lo[MAXN + 1];
void spit(vector <int> &a)
{
	int n = a.size();
	lo[1] = 0;
	for(int x = 2; x <= MAXN; x++)
		lo[x] = lo[x / 2] + 1;
	for(int x = 0; x < a.size(); x++)
		sp[x][0] = a[x];
	int k = 26;
	for(int j = 1; j <= 26; j++)
		for(int i = 0; i + (1 << j) <= n; i++)
			sp[i][j] = min(sp[i][j - 1], sp[i + (1 << (j - 1))][j - 1]);
}
int sum(int l, int r)
{	
	int res = 0;
	for(int j = 26; j >= 0; j--)
	{
		if((1 << j) <= r - l + 1)
		{
			res += sp[l][j];
			l += (1 << j);
		}
	}
	return res;
}
int rmq(int l, int r)
{	
	int j = lo[r - l + 1];
	return min(sp[l][j], sp[r - (1 << j) + 1][j]);
}
int main()
{
	vector <int> a;
	int n;
	cin >> n;
	a.resize(n);
	a[0] = INT_MAX;
	for(int x = 0; x < n; x++)
		cin >> a[x];
	spit(a);
	int t;cin>>t;while(t--)
	{	
		int l, r;
		cin >> l >> r;
		cout << rmq(l, r) << endl;
	}
}
