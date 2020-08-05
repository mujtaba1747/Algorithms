#include <bits/stdc++.h>
using namespace std;
#define MAXN 200061
struct TRIE
{
	// int trie[MAXN][26];
	// int en[MAXN];
	vector < vector < int > > trie;
	vector < int > en;
	int state;
	TRIE()
	{
		// memset(trie, 0, sizeof(trie));
		// memset(en, 0, sizeof(en));
		trie.resize(MAXN, vector < int > (26));
		en.resize(MAXN);
		state = 0;
	}
	void add(string word)
	{
		int cur = 0; // Current State
		for(int i = 0; i < word.length(); i++)
		{
			int ch = word[i] - 'a'; // Or 'A' in case of Uppercase

			if( !trie[cur][ch] )
				trie[cur][ch] = ++state; // A new transition

			cur = trie[cur][ch];
		}
		en[cur] = en[cur] + 1; // State - cur has a word ending
	}
	bool find(string word)
	{
		int cur = 0;
		for(int i = 0; i < word.length(); i++)
		{
			int ch = word[i] - 'a'; // or 'A' in case of Uppercase

			if( !trie[cur][ch] )
			{
				return false;
			}
			cur = trie[cur][ch];
		}
		return en[cur] > 0;
	}
};
signed main()
{
	TRIE tr;
	for(int i = 0; i < 4; i++)
	{
		string s;
		cin >> s;
		tr.add(s);
	}
	for(int i = 0; i < 3; i++)
	{
		string y;
		cin >> y;
		cout << tr.find(y) << endl;
	}
}
