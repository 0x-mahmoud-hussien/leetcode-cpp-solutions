
// https://leetcode.com/problems/split-the-array
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool splitArray(vector<int>& nums, vector<int>& nums1, vector<int>& nums2)
    {
        unordered_map<int, int> freq; 

        for (int num : nums)
        {
            freq[num]++;
            if (freq[num] > 2)
                return false;
        }

        unordered_map<int, int> used; 

        for (int num : nums)
        {
            if (used[num] == 0)
            {
                nums1.push_back(num);
                used[num]++;
            }
            else if (used[num] == 1)
            {
                nums2.push_back(num); 
                used[num]++;
            }
        }

        return true;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 1, 2, 2, 3, 4};
    vector<int> nums1, nums2;

    if (s.splitArray(nums, nums1, nums2))
    {
        cout << "✅ The array can be split successfully:\n";
        cout << "nums1 = [ ";
        for (int x : nums1) cout << x << " ";
        cout << "]\n";

        cout << "nums2 = [ ";
        for (int x : nums2) cout << x << " ";
        cout << "]\n";
    }
    else
        cout << "❌ It is impossible to split the array without duplicates inside a group.\n";

    return 0;
}