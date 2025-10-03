
// https://leetcode.com/problems/transformed-array
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> result(n);

        for (int i = 0; i < n; i++) 
        {
            if (nums[i] == 0) 
                result[i] = 0;
            else 
            {
                int steps = abs(nums[i]) % n; 
                int newIndex;

                if (nums[i] > 0) 
                    newIndex = (i + steps) % n;
                else
                    newIndex = (i - steps + n) % n;

                result[i] = nums[newIndex];
            }
        }
        return result;
    }
};

int main() 
{
    Solution sol;

    vector<int> nums1 = {3, -2, 1, 1};
    vector<int> res1 = sol.constructTransformedArray(nums1);

    cout << "Result 1: ";
    for (int x : res1) cout << x << " ";
    cout << endl;

    vector<int> nums2 = {-1, 4, -1};
    vector<int> res2 = sol.constructTransformedArray(nums2);

    cout << "Result 2: ";
    for (int x : res2) cout << x << " ";
    cout << endl;

    return 0;
}