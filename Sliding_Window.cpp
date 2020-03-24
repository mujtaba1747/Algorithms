#include <bits/stdc++.h>
using namespace std;

template <typename E>
std::vector<E> computeSlidingWindowMinOrMax(const std::vector<E> &array, std::size_t window, bool maximize) {
	if (window == 0)
		throw std::domain_error("Window size must be positive");
	
	std::vector<E> result;
	std::deque<E> deque;
	std::size_t countdown = window - 1;
	typename std::vector<E>::const_iterator tail = array.cbegin();
	for (const E &val : array) {
		while (!deque.empty() && ((!maximize && val < deque.back()) || (maximize && val > deque.back())))
			deque.pop_back();
		deque.push_back(val);
		
		if (countdown > 0)
			countdown--;
		else {
			result.push_back(deque.front());
			if (*tail == deque.front())
				deque.pop_front();
			++tail;
		}
	}
	return result;
}


int main()
{
	vector < int > v;
	int n;
	cin >> n;
	while(n--)
	{
		int x;
		cin >> x;
		v.push_back(x);
	}
	vector < int > ans = computeSlidingWindowMinOrMax(v, 2, 0); // vector of size n, window-size, bool = true for max; false for min
	for(auto z : ans)
		cout << z << " ";
	
}
