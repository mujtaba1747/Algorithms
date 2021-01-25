#include <bits/stdc++.h>
using namespace std;
#define int long long

int Merge(vector < int > &arr, vector < int > &temp, int left, int mid, int right) {
    int i, j, k, inv_count = 0;
    i = left;
    j = mid;
    k = left;
    
    while ((i <= mid - 1) && (j <= right)) { 
        if (arr[i] <= arr[j]) { 
            temp[k++] = arr[i++]; 
        } 
        else { 
            temp[k++] = arr[j++]; 
            inv_count = inv_count + (mid - i); 
        } 
    }
    while (i <= mid - 1) 
        temp[k++] = arr[i++]; 
    while (j <= right) 
        temp[k++] = arr[j++];

    for (i = left; i <= right; i++) 
        arr[i] = temp[i];
    return inv_count; 
    
}
int MergeSort(vector < int > &arr, vector < int > &temp, int left, int right) {
    int mid, inv_count = 0;
    if(right > left) {
        mid = (left + right) / 2;
        inv_count += MergeSort(arr, temp, left, mid);
        inv_count += MergeSort(arr, temp, mid + 1, right);
        inv_count += Merge(arr, temp, left, mid + 1, right);
    }
    return inv_count;
}
int InvCount(vector < int > &arr) {
    vector < int > temp(arr.size());
    return MergeSort(arr, temp, 0, arr.size() - 1);
}
signed main() 
{
    vector < int > a = {5, 4, 3, 2, 1, 0};
    cout << InvCount(a) << '\n';
    for(auto z : a) {
        cout << z << ' ';
    }
    cout << '\n';
}