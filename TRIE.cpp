// Author : Syed Mujtaba
// Seek knowledge from the Cradle to the Grave !!
// https://www.linkedin.com/in/syed-mujtaba

// Refer : https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ffc7/00000000001d3ff3
// Kickstart 2020 Round A LastQ

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast_io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int n, k;
typedef struct data
{
	data* bit[26];
	int cnt = 0;
	bool end = false;
}trie;

trie* head;

void insert(string &s)
{
	trie* cur = head;
	for(auto &it:s)
	{
		int b = it - 'A';
		if(!cur->bit[b])
			cur->bit[b] = new trie();
		cur = cur->bit[b];
		cur->cnt++;
	}
}

int query(trie* cur, int lvl)
{
	if(!cur)
		return 0;
	int ans = (cur -> cnt / k);
	for(int i = 0; i <= 25; i++)
		if(cur -> bit[i])
			ans += query(cur -> bit[i], lvl + 1);
	return ans;
}



signed main()
{
	fast_io
	head = new trie();
	string s = "TRIE";
	insert(s);
}
