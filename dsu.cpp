/*
Solo at first, lonely trees cherish the ride.
His hand merges our disjoint skies.
Out of many is our root.
Hands stretching, we seek our starry life.
The paths are long, though recursing from The one.
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
int parent[1000000];
int size[1000000];
int rank[1000000];
set < int > pres; // present components
void make_set(int v)
{
	parent[v] = v;
	size[v] = 1;
	rank[v] = 0;
	// pres.insert(v);
} 
int find_set(int v)
{
	if(v == parent[v])
		return v;
	return  parent[v] = find_set(parent[v]); // path compression
}
void union_set(int a, int b)
{
	a = find_set(a);
	b = find_set(b);
	if(a != b)
	{
		if(size[a] < size[b])
			swap(a, b);
		parent[b] = a; // making the smaller a child of bigger (Union by size)
		size[a] += size[b];

	}
	/*
	if(a != b)
	{
		if(rank[a] < rank[b])
			swap(a, b);
		parent[b] = a;
		if(rank[a] == rank[b]) // Union by rank
			rank[a]++;
	}
	*/
	// pres.erase(b);
}
int32_t main()
{

}
