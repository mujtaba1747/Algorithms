#include <bits/stdc++.h>
using namespace std;
template < typename data > 
void Swap(data &x, data&y) {
	data temp = y;
	y = x;
	x = temp;
}

template < typename data > 
int partition(vector < data > &arr, int low, int high) {

    int rand_idx = low + rand() % (high - low + 1); // Randomized Pivot
    Swap(arr[rand_idx], arr[high]);
    data pivot = arr[high];
    int partition_idx = low;

    for(int i = low; i < high; i++) {
    	if(arr[i] <= pivot) {
    		Swap(arr[i], arr[partition_idx]);
    		partition_idx++;
    	}
    }
    Swap(arr[partition_idx], arr[high]);
    return partition_idx;
}

template < typename data >
void qs(vector < data > &arr, int low, int high) {
    if(low >= high) 
        return;
    int pi = partition(arr, low, high); // pi is position of Pivot in Sorted Array
    qs(arr, low, pi - 1);
    qs(arr, pi + 1, high);
} 
int main()
{
    vector < int > arr(200);
    srand(time(0));
    for(int i = 0; i < 200; i++) {
        arr[i] = rand() % 1500;
    }
    qs(arr, 0, (int)arr.size() - 1);
    for(auto z : arr)
        cout << z << ' ';
    cout << endl;
    return 0;
}
