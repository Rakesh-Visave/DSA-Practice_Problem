#include<vector>
#include<iostream>
using namespace std;

bool isPossible(vector<int> arr, int m, int n, int mid) {

	int studentCount = 1;
    int pageSum = 0;

	for (int i = 0; i < n; i++) {
    	if (pageSum + arr[i] <= mid) {
			pageSum += arr[i];
    	} 
		else{
			studentCount++;
        	if (studentCount > m) {
				return false;
        	}
	 		pageSum = arr[i];
    	}
	 
    }
	return true;
}
int allocateBooks(vector<int> arr, int n, int m)
{
	int s = 0;
	int sum = 0;

    for (int i = 0; i < n; i++) {
		sum += arr[i];		
	}
	
	int e = sum;
	int ans = -1;
	int mid = s +(e-s)/2;

    while (s <= e) {
      if (isPossible(arr, m, n, mid)) {
		  ans = mid;
		  e = mid - 1;
      } 
	  else {
        s = mid + 1;
      }
      mid = s + (e - s) / 2;
    }
    return ans;
}

int main()
{
    vector<int> arr = {14,7,8,17,5,10};
    int  m = 4;
    int n = 6;

    int allocate = allocateBooks(arr,n,m);

    cout<<"The allocated books pages is"<<allocate;
}
