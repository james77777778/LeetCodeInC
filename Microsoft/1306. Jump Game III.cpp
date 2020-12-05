#include "leetcode.h"

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        vector<bool> visited(arr.size(), false);
        return DFS(arr, start, visited);
    }
    bool DFS(vector<int>& arr, int cur, vector<bool>visited) {
        if(cur < 0 || cur >= arr.size() || visited[cur])
            return false;
        visited[cur] = true;
        if(arr[cur] == 0)
            return true;
        return DFS(arr, cur + arr[cur], visited) || DFS(arr, cur - arr[cur], visited);
    }
};

int main() {
    vector<int> arr{4, 2, 3, 0, 3, 1, 2};
    Solution s;
    cout << s.canReach(arr, 5) << endl;
}