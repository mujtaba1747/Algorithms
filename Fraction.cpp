// Author : Syed Mujtaba
// Seek knowledge from the Cradle to the Grave !!
// https://www.linkedin.com/in/syed-mujtaba

// This is a struct that can be used for positive fractions 
// Can be inserted into maps and pushed into vectors and can be sorted as well.

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast_io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

struct frac
{
	int num, den;
	frac()
	{
		num = 1;
		den = 1;
	}
	bool operator<(struct frac other) const
	{
		return other.num * den > num * other.den;
	}
	bool operator<=(struct frac other) const
	{
		return other.num * den >= num * other.den;
	}
	bool operator>(struct frac other) const
	{
		return other.num * den < num * other.den;
	}
	bool operator>=(struct frac other) const
	{
		return other.num * den < num * other.den;
	}
	bool operator==(struct frac other) const
	{
		return other.num * den == num * other.den;
	}
};
signed main()
{
	fast_io
	frac x;
	x.num = 1;
	x.den = 2;
	vector < frac > v;
	v.push_back(x);
	map < frac, int > mp;
	mp[x] = 1;
}