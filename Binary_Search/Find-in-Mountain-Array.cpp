#include <iostream>
#include <vector>
using namespace std;

class MountainArray {
private:
    vector<int> arr;

public:
    MountainArray(vector<int>& a) : arr(a) {}

    int get(int index) {
        return arr[index];
    }

    int length() {
        return arr.size();
    }
};

class Solution {
public:
    int peakIndexInMountainArray(MountainArray &mountainArr) {
        int n = mountainArr.length();

        int l = 0;
        int r = n-1;

        while(l < r) {

            int mid = l + (r-l)/2;

            if(mountainArr.get(mid) < mountainArr.get(mid+1))
                l = mid+1;
            else
                r = mid;

        }

        return l;
    }

    int binarySearch(MountainArray &mountainArr, int l, int r, int target) {

        int mid;
        while(l <= r) {
            mid = l + (r-l)/2;

            if(mountainArr.get(mid) == target) {
                return mid;
            } else if(mountainArr.get(mid) > target) {
                r = mid-1;
            } else {
                l = mid+1;
            }
        }

        return -1;

    }

    int reverseBinarySearch(MountainArray &mountainArr, int l, int r, int target) {
        int mid;
        while(l <= r) {
            mid = l + (r-l)/2;

            if(mountainArr.get(mid) == target) {
                return mid;
            } else if(mountainArr.get(mid) > target) { //Because the array in right side of peak is in descending order
                l = mid+1;
            } else {
                r = mid-1;
            }
        }

        return -1;

    }

    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();

        int peakIndex = peakIndexInMountainArray(mountainArr);

        int idx = binarySearch(mountainArr, 0, peakIndex, target);

        if(idx == -1) {
            return reverseBinarySearch(mountainArr, peakIndex, n-1, target);
        }

        return idx;

    }
};

int main() {
    vector<int> arr = {1, 3, 5, 4, 2}; // Initialize your array

    MountainArray mountainArr(arr); // Create an instance of MountainArray

    int target = 3;
    Solution solution;

    int result = solution.findInMountainArray(target, mountainArr);

    if (result != -1) {
        cout << "Element " << target << " found at index " << result << endl;
    } else {
        cout << "Element " << target << " not found in the mountain array." << endl;
    }

    return 0;
}
