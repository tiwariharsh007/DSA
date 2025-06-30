class Solution
{
public:
    vector<vector<int>> dp;

    int solve(vector<int> &cuts, int lt, int rt)
    {
        if (rt - lt <= 1)
        {
            return 0;
        }
        if (dp[lt][rt] != -1)
        {
            return dp[lt][rt];
        }

        int res = INT_MAX;
        for (int idx = lt + 1; idx < rt; idx++)
        {
            int cost = (cuts[rt] - cuts[lt]) + solve(cuts, lt, idx) + solve(cuts, idx, rt);
            res = min(res, cost);
        }
        return dp[lt][rt] = (res == INT_MAX ? 0 : res);
    }

    int minCost(int n, vector<int> &cuts)
    {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        int m = cuts.size();
        dp.assign(m, vector<int>(m, -1));
        return solve(cuts, 0, m - 1);
    }
};