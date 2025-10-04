
// https://leetcode.com/problems/third-maximum-number?envType=problem-list-v2&envId=array
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end(), greater<int>());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());

        if (nums.size() >= 3)
            return nums[2];
        else
            return nums[0]; 
    }
};

int main() 
{
    Solution sol;
    vector<int> nums = {2,2,3,1};
    cout << sol.thirdMax(nums); 
    return 0;
}