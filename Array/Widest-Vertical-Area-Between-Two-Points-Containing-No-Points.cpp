#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxWidthOfVerticalArea(vector<vector<int>>& points) {
    int n = points.size();
    sort(begin(points), end(points));
    
    int maxVal = 0;
    
    for(int i = 1; i < n; i++) {
        maxVal = max(maxVal, points[i][0] - points[i-1][0]);
    }
    
    return maxVal;
}

int main() {
    // Hardcoded input
    vector<vector<int>> input = {
        {3, 1},
        {9, 0},
        {1, 5},
        {4, 3}
        // Add more points here if needed
    };

    int result = maxWidthOfVerticalArea(input);
    cout << "The widest vertical area between two points containing no points is: " << result << endl;

    return 0;
}
