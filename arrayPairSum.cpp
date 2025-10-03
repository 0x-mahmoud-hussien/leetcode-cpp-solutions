
// https://leetcode.com/problems/array-partition
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution 
{
public:
    int arrayPairSum(vector<int>& nums) 
    {
        if (nums.empty()) return 0;

        sort(nums.begin(), nums.end());

        int sum = 0;
        for (int i = 0; i < nums.size(); i += 2)  
        {
            sum += nums[i];
        }
        return sum; 
    }
};

int main()
{
    Solution sol;

    vector<int> nums1 = {1, 4, 3, 2};
    cout << "Result 1: " << sol.arrayPairSum(nums1) << endl; 

    vector<int> nums2 = {6, 2, 6, 5, 1, 2};
    cout << "Result 2: " << sol.arrayPairSum(nums2) << endl;

    return 0;
}