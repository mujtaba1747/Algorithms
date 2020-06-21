// This function can be convieniently used to find intersection of 2-intervals, if any

int MAX = 8e18L + 1024;

pair < int, int > f(pair < int, int > p1, pair < int, int > p2)
{
	if(p2.first > p1.second || p1.first > p2.second)
	{
		pair < int, int > ans;
		ans = {MAX, MAX};
		return ans;
	}
	int os = max(p1.first, p2.first);
	int oe = min(p1.second, p2.second);
	pair < int, int > ans;// {os, oe};
	ans = {os, oe};
	return ans;
}
