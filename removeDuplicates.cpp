
// https://leetcode.com/problems/remove-duplicates-from-sorted-array
#include <iostream>
#include <vector>
using namespace std;

class Solution 
{
public:
    int removeDuplicates(vector<int>& nums) 
    {
        if (nums.empty()) return 0;

        int k = 1; 
        for (int i = 1; i < nums.size(); i++) 
        {
            if (nums[i] != nums[i - 1])
            {
                nums[k] = nums[i]; 
                k++; 
            }
        }
        return k;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};

    int k = sol.removeDuplicates(nums);

    cout << "k = " << k << endl;
    cout << "New array: [";
    for (int i = 0; i < k; i++) 
    {
        cout << nums[i];
        if (i < k - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}