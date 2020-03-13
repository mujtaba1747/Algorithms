#include <bits/stdc++.h>
using namespace std;
#define int long long
// Prime Factorisation in O(log(n))
map < int, int > factorize(int n) 
{
	int count = 0;
	map < int, int > mp;
	while(!(n % 2))
	{
		n /= 2;
		count++;
	}
	if(count)
		mp[2] = count;
	for(int i = 3; i <= sqrt(n); i += 2)
	{
		count = 0;
		while(!(n % i))
		{
			count++;
			n /= i;
		}
		if(count)
			mp[i] = count;
	}
	if(n > 2)
		mp[n] = 1;
	return mp;
}
signed main()
{
	int n;
	cin >> n;
	map < int, int > mp = factorize(n);
	for(auto z : mp)
	{
		cout << z.first << " " << z.second << endl;
 	}
}