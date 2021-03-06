/*
Paint House II
There are a row of n houses, each house can be painted with one of the k colors. The cost of painting each house with 
a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.

The cost of painting each house with a certain color is represented by a n x k cost matrix. For example, costs[0][0] 
is the cost of painting house 0 with color 0; costs[1][2] is the cost of painting house 1 with color 2, and so on... 
Find the minimum cost to paint all houses.

Note:
All costs are positive integers.

Follow up:
Could you solve it in O(nk) runtime?
*/

class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        if (costs.empty() || costs[0].empty()) return 0;
        int n = costs.size();
        int k = costs[0].size();
        vector<int> mincosts(k);
        for (int i = 0; i < k; i++) {
            mincosts[i] = costs[0][i];
        }
        for (int i = 1; i < n; i++) {
            int min = mincosts[0];
            int min2 = INT_MAX;
            int minindex = 0;
            for (int j = 1; j < k; j++) {
                if (mincosts[j] < min) {
                    min2 = min;
                    min = mincosts[j];
                    minindex = j;
                }
                else if (mincosts[j] < min2) {
                    min2 = mincosts[j];
                }
            }
            for (int j = 0; j < k; j++) {
                if (j != minindex) {
                    mincosts[j] = min + costs[i][j];
                }
                else {
                    mincosts[j] = min2 + costs[i][j];
                }
            }
        }
        int res = mincosts[0];
        for (int i = 0; i < k; i++) {
            res = min(res, mincosts[i]);
        }
        return res;
    }
};
