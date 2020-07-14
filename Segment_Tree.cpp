// Seek knowledge from the Cradle to the Grave !!
// https://www.linkedin.com/in/syed-mujtaba
// http://p.ip.fi/OIxB
#include <bits/stdc++.h>
using namespace std;
#define int             long long
#define ld              long double
#define ll              long long
#define pb              push_back
#define fi              first
#define se              second
#define MAXN            200064
#define mod             1000000007 // 998244353 // 1e9 + 7
#define MAX             8000000000000000064LL
#define MIN            -8000000000000000064LL
#define mt              make_tuple
#define eps             1e-6
#define endl            '\n'
#define test            int T_T; cin>>T_T; while(T_T--)
#define fast_io         ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
struct data
{
	int ele;

	data()
	{
		ele = -1; // can change // default value
	}
};

struct SegTree
{
	int N;
	vector < data > t;
	vector < data > a;
	data base;
	void init(vector < data > &b)
	{
		N = b.size();
		a = b;
		base.ele = 0;  // can change // identity element of function
		t.resize(4 * N + 5);
		build(1, 0, N - 1);
	}
	void merge(data &cur, data &l, data &r)
	{
		if(l.ele == base.ele)
			cur.ele = r.ele;
		else if(r.ele == base.ele)
			cur.ele = l.ele;
		else
			cur.ele = (l.ele + r.ele); // can change to appropriate function
	}
	void build(int v, int tl, int tr) 
	{ 
		if(tl == tr)
		{
			t[v] = a[tl];
		}
		else
		{
			int tm = (tl + tr) / 2;
       		build(v*2, tl, tm);
        	build(v*2+1, tm+1, tr);
        	merge(t[v], t[2*v], t[2*v + 1]);
		}
	}
	data pquery(int v, int tl, int tr, int l, int r)
	{
	    if (l > r) 
	        return base;
	    if (l == tl && r == tr)
	    {
	        return t[v];
	    }
    	    int tm = (tl + tr) / 2;
    	    data temp;
    	    data L = pquery(v*2, tl, tm, l, min(r, tm));
    	    data R = pquery(v*2+1, tm+1, tr, max(l, tm+1), r); 
    	    merge(temp, L, R);
    	    return temp;
	}
	void pupdate(int v, int tl, int tr, int pos, data new_val)
	{
	    if (tl == tr)
	    {
	       	t[v] = new_val;
	    }
	    else
	    {
	       	int tm = (tl + tr) / 2;
	       	if(pos <= tm)
	           	pupdate(v*2, tl, tm, pos, new_val);
	       	else
	           	pupdate(v*2+1, tm+1, tr, pos, new_val);
        	merge(t[v], t[2*v], t[2*v + 1]);
	    }
	}
	void update(int pos, data new_val)
	{
		pupdate(1, 1, N, pos, new_val);
	}
	data query(int l, int r)
	{
		return pquery(1, 1, N, l, r);
	}
};
void Test()
{
	vector < data > b;
	int n;
	cin >> n;
	b.resize(n);
	for(int i = 0; i < n; i++)
		cin >> b[i].ele;
	SegTree s;
	s.init(b);
	int q;
	cin >> q;
	while(q--)
	{
		int x;
		cin >> x;
		if(x == 1)
		{
			int pos, val;
			cin >> pos >> val;
			data dt;
			dt.ele = val;
			s.update(pos, dt);
		}
		else
		{
			int L, R;
			cin >> L >> R;
			cout << s.query(L, R).ele << "\n";
		}
	}
}
signed main()
{
    fast_io
    Test();
    return 0;       
}
