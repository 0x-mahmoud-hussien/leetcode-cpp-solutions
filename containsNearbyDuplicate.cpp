
// https://leetcode.com/problems/contains-duplicate-ii?envType=problem-list-v2&envId=array
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) 
    {
        unordered_set<int> window;

        for (int i = 0; i < (int)nums.size(); ++i) 
        {
            if (window.count(nums[i])) 
                return true;

            window.insert(nums[i]);

            if (i >= k)
                window.erase(nums[i - k]);
        }

        return false; 
    }
};

int main() 
{
    Solution sol;

    vector<int> nums1 = {1, 2, 3, 1};
    cout << boolalpha << sol.containsNearbyDuplicate(nums1, 3) << endl; 

    vector<int> nums2 = {1, 0, 1, 1};
    cout << boolalpha << sol.containsNearbyDuplicate(nums2, 1) << endl; 

    vector<int> nums3 = {1, 2, 3, 1, 2, 3};
    cout << boolalpha << sol.containsNearbyDuplicate(nums3, 2) << endl; 

    return 0;
}