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
	vector < bool > clazy;
	vector < data > lazy;
	data laze;
	data base;
	void init(vector < data > &b)
	{
		N = b.size();
		a = b;
		base.ele = 0;  // can change // identity element of function
		laze.ele = 0;
		t.resize(4 * N + 5);
		clazy.assign(4 * N + 5, false);
		lazy.assign(4 * N + 5, laze);
		build(1, 0, N - 1);
	}
	void merge(data &cur, data &l, data &r)
	{
		if(l.ele == base.ele)
			cur.ele = r.ele;
		else if(r.ele == base.ele)
			cur.ele = l.ele;
		else
			cur.ele = min(l.ele, r.ele);
			// cur.ele = (l.ele + r.ele); // can change to appropriate function
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
	// Handle Propagation Appropriately
	void propagate(int v, int l, int r) 
	{
		if(l != r)
		{
			clazy[v * 2] = true;
			clazy[v * 2 + 1] = true;
			lazy[v * 2] = lazy[v];
			lazy[v * 2 + 1] = lazy[v]; // handle
		}
		// handle
		t[v] = lazy[v];
		// t[v] += (r - l + 1)*(lazy[v]);
		clazy[v] = false;
		lazy[v] = base;
	}
	data rquery(int v, int tl, int tr, int l, int r)
	{
		if(clazy[v])
		{
			propagate(v, tl, tr);
		}
	    if (l > r) 
	        return base;
	    if (l == tl && r == tr)
	    {
	        return t[v];
	    }
    	int tm = (tl + tr) / 2;
    	data temp;
    	data L = rquery(v*2, tl, tm, l, min(r, tm));
    	data R = rquery(v*2+1, tm+1, tr, max(l, tm+1), r); 
    	merge(temp, L, R);
    	return temp;
	}
	data pquery(int v, int tl, int tr, int pos)
	{
		if(clazy[v])
		{
			propagate(v, tl, tr);
		}
		if(tl == tr)
			return t[v];
		int tm = (tl + tr)/2;
		if(pos <= tm)
			return pquery(2*v, tl, tm, pos);
		else
			return pquery(2*v + 1, tm + 1, tr, pos);
	}
	void rupdate(int v, int tl, int tr, int l, int r, data new_val)
	{
		if(clazy[v])
		{
			propagate(v, tl, tr);
		}
		if(l > r)
			return;
	    if (l == tl && r == tr)
	    {
	       	clazy[v] = true;
	       	// handle
	       	lazy[v] = new_val; // lazy[v]+=new_val 
	       	propagate(v, tl, tr);
	    }
	    else
	    {
	       	int tm = (tl + tr) / 2;
	        rupdate(v*2, tl, tm, l, min(r, tm), new_val);
	        rupdate(v*2+1, tm+1, tr, max(l, tm + 1), r, new_val);
        	merge(t[v], t[2*v], t[2*v + 1]);
	    }
	}
	void pupdate(int v, int tl, int tr, int pos, data new_val)
	{
		if(clazy[v])
		{
			propagate(v, tl, tr);
		}
	    if (tl == tr)
	    {
	    	clazy[v] = true;
	    	lazy[v] = new_val;
	       	propagate(v, tl, tr);
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

	// Sweet Wrapper Functions
	data query(int pos)
	{
		return pquery(1, 1, N, pos);
	}
	data query(int l, int r)
	{
		return rquery(1, 1, N, l, r);
	}
	void update(int pos, data val)
	{
		pupdate(1, 1, N, pos, val);
	}
	void update(int l, int r, data val)
	{
		rupdate(1, 1, N, l, r, val);
	}
	
};
signed main()
{
   fast_io
   vector < data > v;
   int n;
   cin >> n;
   v.resize(n);
   SegTree s;
   for(int i = 0; i < n; i++)
   {
   		cin >> v[i].ele;
   }
   s.init(v);
}
