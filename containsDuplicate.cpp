
// https://leetcode.com/problems/contains-duplicate?envType=problem-list-v2&envId=array
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) 
    {
        if (nums.empty()) return false;

        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] == nums[i + 1]) 
                return true;
        }
        return false; 
    }
};

int main() 
{
    Solution s;
    vector<int> nums1 = {1,2,3,1};
    vector<int> nums2 = {1,2,3,4};
    vector<int> nums3 = {1,1,1,3,3,4,3,2,4,2};

    cout << boolalpha; 
    cout << s.containsDuplicate(nums1) << endl; 
    cout << s.containsDuplicate(nums2) << endl; 
    cout << s.containsDuplicate(nums3) << endl; 
}