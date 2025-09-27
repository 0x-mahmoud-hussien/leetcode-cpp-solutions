
// https://leetcode.com/problems/search-insert-position
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) 
    {
        int left = 0;
        int right = (int)nums.size() - 1;

        while (left <= right) 
        {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) 
                return mid; 
            else if (nums[mid] < target) 
                left = mid + 1;
            else 
                right = mid - 1;  
        }

        return left;
    }
};

int main() 
{
    Solution sol;
    vector<int> nums = {1, 3, 5, 6};

    cout << "Example 1: target = 5  -> index = " << sol.searchInsert(nums, 5) << " (expected 2)\n";
    cout << "Example 2: target = 2  -> index = " << sol.searchInsert(nums, 2) << " (expected 1)\n";
    cout << "Example 3: target = 7  -> index = " << sol.searchInsert(nums, 7) << " (expected 4)\n";
    cout << "Example 4: target = 0  -> index = " << sol.searchInsert(nums, 0) << " (expected 0)\n";

    return 0;
}