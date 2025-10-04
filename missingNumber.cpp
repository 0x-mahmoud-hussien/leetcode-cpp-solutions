
// https://leetcode.com/problems/missing-number?envType=problem-list-v2&envId=array
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) 
    {
        int n = nums.size();
        int totalSum = n * (n + 1) / 2; 
        int currentSum = 0;

        for (int num : nums)
            currentSum += num;

        return totalSum - currentSum;
    }
};

int main() 
{
    Solution s;
    vector<int> nums = {3, 0, 1};
    cout << s.missingNumber(nums) << endl;
    return 0;
}