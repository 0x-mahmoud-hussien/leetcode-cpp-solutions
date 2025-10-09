
// https://leetcode.com/problems/concatenation-of-array
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) 
    {
        vector<int> v = nums;
        nums.insert(nums.end(), v.begin(), v.end());
        return nums;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1,3,2,1};
    vector<int> result = s.getConcatenation(nums);

    cout << "The New Vector Is: [ ";
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
        if (i != nums.size() - 1) cout << ", ";
    }
    cout << " ]" << endl;
}
