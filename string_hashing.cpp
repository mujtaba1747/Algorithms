/*-In the name of God-

Author : Syed Mujtaba
Seek knowledge from the Cradle to the Grave !!
https://www.linkedin.com/in/syed-mujtaba
*/

#include <bits/stdc++.h>
using namespace std;
#define int             long long
#define ld              long double
#define ll              long long
#define pb              push_back
#define fi              first
#define se              second
#define MAXN            200064
#define mod             1000000007  //998244353 // 1e9 + 7
#define MAX             8000000000000000064LL
#define MIN            -8000000000000000064LL
#define mt              make_tuple
#define eps             1e-6
#define endl            '\n'
#define test            int T_T; cin>>T_T; while(T_T--)
#define fast_io         ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

//-----------Global Variables needed for Hash-----------------------//
int P = 31; // 53 For Upper+LowerCase

int m1 = 1e9 + 9;
int p_pow1[1000001];
int inv1[1000001];

int m2 = 1e9 + 7;
int p_pow2[1000001];
int inv2[1000001];
//------------------------------------------------------------------//

int xyp(int x,int y, int M) // modular exponentiation
{
	int res=1;
	while(y>0)
	{
		if(y%2==1) 
			res=(res*x)%M;
		x = (x*x)%M;
		y/=2;
	}
	return res%M;
}
int inv(int x, int M) // modular inverse
{
	return xyp(x, M - 2, M);
}
void cal()  // precal
{
	p_pow1[0] = 1;
	p_pow2[0] = 1;
	for(int i = 1; i <= 1e6; i++)
	{
		p_pow1[i] = (P * p_pow1[i - 1])%m1;
		inv1[i] = inv(p_pow1[i], m1);
		p_pow2[i] = (P * p_pow2[i - 1])%m2;
		inv2[i] = inv(p_pow2[i], m2);
	}
	inv1[0] = 1;
	inv2[0] = 1;
}
struct hash
{
	int n;
	vector < int > h1, h2;
	hash(string &s)
	{
		n = s.size();
		h1.resize(n + 1, 0);
		h2.resize(n + 1, 0);
		for(int i = 0; i < s.size(); i++)
		{
			h1[i + 1] = (h1[i] + ((s[i] - 'a' + 1) * p_pow1[i])%m1)%m1; // Change if Capital
			h2[i + 1] = (h2[i] + ((s[i] - 'a' + 1) * p_pow2[i])%m2)%m2; // Change if Capital
		}
	}
	int get1(int l, int r) // 1-Based Indexing
	{
		int z = (h1[r] - h1[l - 1] + m1) % m1;
		z = (z * inv1[l - 1]) % m1;
		return z;
	}
	int get2(int l, int r) // 1-Based Indexing
	{
		int z = (h2[r] - h2[l - 1] + m2) % m2;
		z = (z * inv2[l - 1]) % m2;
		return z;
	}
};
signed main()
{
    fast_io
    cal();
    string s;
    cin >> s;
    hash h(s);
    cout << h.get1(1, s.size()) << endl;
    cout << h.get2(1, s.size()) << endl;
}