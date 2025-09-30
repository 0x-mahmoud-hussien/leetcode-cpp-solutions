
// https://leetcode.com/problems/search-in-rotated-sorted-array
#include <iostream>
#include <vector>
using namespace std;

class Solution 
{
public:
    int search(vector<int>& nums, int target) 
    {
        int n = (int)nums.size();
        if (n == 0) return -1;

        int left = 0, right = n - 1;
        while (left <= right) 
        {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) return mid; 

            if (nums[left] <= nums[mid]) 
            {
                if (nums[left] <= target && target < nums[mid]) 
                    right = mid - 1;
                else 
                    left = mid + 1;
            } 
            else 
            {
                if (nums[mid] < target && target <= nums[right]) 
                    left = mid + 1;
                else 
                    right = mid - 1;
            }
        }

        return -1;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {4,5,6,7,0,1,2};
    cout << "Index of 0 = " << sol.search(nums, 0) << " (expected 4)\n";
    cout << "Index of 3 = " << sol.search(nums, 3) << " (expected -1)\n";
    return 0;
}