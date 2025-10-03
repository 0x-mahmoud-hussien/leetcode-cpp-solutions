
// https://leetcode.com/problems/monotonic-array
#include <iostream>
#include <vector>
using namespace std;

class Solution 
{
public:
    bool isMonotonic(vector<int>& nums) 
    {
        bool inc = true, dec = true;

        for (int i = 1; i < nums.size(); i++) 
        {
            if (nums[i] > nums[i - 1]) dec = false; 
            if (nums[i] < nums[i - 1]) inc = false; 
        }

        return inc || dec;
    }
};

int main()
{
    Solution sol;
    vector<int> nums1 = {1, 2, 2, 3};
    vector<int> nums2 = {6, 5, 4, 4};
    vector<int> nums3 = {1, 3, 2};
    cout << boolalpha << endl;
    cout << sol.isMonotonic(nums1) << endl; 
    cout << sol.isMonotonic(nums2) << endl; 
    cout << sol.isMonotonic(nums3) << endl; 

    return 0;
}