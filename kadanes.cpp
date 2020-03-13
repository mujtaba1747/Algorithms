#include <bits/stdc++.h>
using namespace std;
int kd(vector < int > a)
{
	int size = a.size();
	int max_so_far = INT_MIN, max_ending_here = 0; 
    for (int i = 0; i < size; i++) 
    { 
        max_ending_here = max_ending_here + a[i]; 
        if (max_so_far < max_ending_here) 
            max_so_far = max_ending_here; 
  
        if (max_ending_here < 0) 
            max_ending_here = 0; 
    } 
    return max_so_far; 
}
int main()
{
	int n;
	cin >> n;
	vector < int > a(n);
	for(auto &z : a)
		cin >> z;
	cout << kd(a) << endl;
}