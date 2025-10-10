
// https://leetcode.com/problems/intersection-of-two-arrays
#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
        set<int> set1(nums1.begin(), nums1.end());
        set<int> result;

        for (int num : nums2)
        {
            if (set1.count(num))
                result.insert(num);
        }

        return vector<int> (result.begin(), result.end());
    }
};

int main()
{
    Solution s;

    vector<int> nums1 = {4, 9, 5};
    vector<int> nums2 = {9, 4, 9, 8, 4};

    vector<int> result = s.intersection(nums1, nums2);
    vector<int>::iterator it = result.begin();
    for (; it != result.end(); it++)
    {
        cout << *it << " ";
    }

    cout << endl;
    return 0;
}
