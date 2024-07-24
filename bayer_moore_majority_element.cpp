#include <vector>
using namespace std;
// https://www.topcoder.com/thrive/articles/boyer-moore-majority-vote-algorithm
// Can be generalized to n/k:
// https://www.geeksforgeeks.org/boyer-moore-majority-voting-algorithm-for-searching-elements-having-more-than-k-occurrences/

// Probabilistic approach:
// for tries in range(0, 20): // probability of failing (1/k)^20
//     randIndex = rand() % n
//     bool res = checkIfMajorityInONTime(arr, arr[randIndex])
//     if res -> return arr[randIndex]
// return failed_algo // Super low probability that this happens

int findMajority(vector < int > nums) {

  int n = nums.size();
  int num, count = 0;
  for (auto x: nums) {
    if (count == 0)
      num = x;

    count += (x == num ? 1 : -1);
  }

  count = 0;
  for (auto x: nums)
    if (x == num)
      count++;

  if (count > n / 2)
    return num;

  return -1;
}