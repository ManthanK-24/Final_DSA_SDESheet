class Solution {
public:
    int solve(vector<int>& nums, int k, vector<vector<vector<int>>>& dp, int idx, int op1, int op2) {
        // Base Case: If we reach the end of the array
        if (idx == nums.size())
            return 0;

        // If result is already computed, return it
        if (dp[idx][op1][op2] != -1)
            return dp[idx][op1][op2];

        int ans = INT_MAX;

        // CASE 1: Perform only op1
        if (op1 != 0) {
            int sumOp1 = ceil(nums[idx] / 2.0) + solve(nums, k, dp, idx + 1, op1 - 1, op2);
            ans = min(ans, sumOp1);
        }

        // CASE 2: Perform only op2
        if (op2 != 0 && nums[idx] >= k) {
            int sumOp2 = (nums[idx] - k) + solve(nums, k, dp, idx + 1, op1, op2 - 1);
            ans = min(ans, sumOp2);
        }

        // CASE 3 and CASE 4: Perform both op1 and op2 in different orders
        if (op1 != 0 && op2 != 0) {
            int afterOp1 = ceil(nums[idx] / 2.0);
            if (afterOp1 >= k) {
                // CASE 3: Perform op1 followed by op2
                int sumOp1Op2 = (afterOp1 - k) + solve(nums, k, dp, idx + 1, op1 - 1, op2 - 1);
                ans = min(ans, sumOp1Op2);
            }
            if (nums[idx] >= k) {
                // CASE 4: Perform op2 followed by op1
                int sumOp2Op1 = ceil((nums[idx] - k) / 2.0) + solve(nums, k, dp, idx + 1, op1 - 1, op2 - 1);
                ans = min(ans, sumOp2Op1);
            }
        }

        // CASE 5: Perform no operation
        int sumNoOp = nums[idx] + solve(nums, k, dp, idx + 1, op1, op2);
        ans = min(ans, sumNoOp);

        // Store the result in dp table
        return dp[idx][op1][op2] = ans;
    }

    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        // Initialize dp with -1
        vector<vector<vector<int>>> dp(nums.size(), vector<vector<int>>(op1 + 1, vector<int>(op2 + 1, -1)));

        // Solve the problem
        return solve(nums, k, dp, 0, op1, op2);
    }
};