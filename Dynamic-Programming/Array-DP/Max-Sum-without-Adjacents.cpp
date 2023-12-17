// GFG -- Max Sum without Adjacents


#include <bits/stdc++.h>

using namespace std;

	int findMaxSum(int *arr, int n) {
	     int lastPrev = 0;
        int prev = arr[0];
        int curr = 0;

        for (int i = 1; i < n; ++i) {
            curr = max(prev, arr[i] + lastPrev);
            lastPrev = prev;
            prev = curr;
        }

        return max(lastPrev, prev);
	}
int main() {
    int arr[] = {3, 2, 7, 10};
    int size = sizeof(arr) / sizeof(arr[0]);

    int maxSum = findMaxSum(arr, size);
    cout << "Maximum sum without adjacent elements: " << maxSum << endl;

    return 0;
}