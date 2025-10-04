
// https://leetcode.com/problems/move-zeroes?envType=problem-list-v2&envId=array
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) 
    {
        int n = nums.size();
        int pos = 0;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] != 0)
            {
                nums[pos] = nums[i];
                pos++;
            }
        }
        while (pos < n)
        {
            nums[pos] = 0;
            pos++;
        }
        cout << "Zeros moved to end!\n";
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {10, 0, 20, 30, 0, 60, 90, 70};

    sol.moveZeroes(nums); 

    cout << "[ ";
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i];
        if (i != nums.size() - 1)
            cout << ", ";
    }
    cout << " ]";
    return 0;
}