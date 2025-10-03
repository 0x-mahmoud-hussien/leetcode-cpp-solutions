

#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

class Solution 
{
public:
    void rotate(vector<int>& nums, int k) 
    {
        if (nums.empty()) return;
        k = k % nums.size();
        std::rotate(nums.rbegin(), nums.rbegin() + k, nums.rend());
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;

    sol.rotate(nums, k);

    cout << "After rotation: ";
    for (int num : nums)
        cout << num << " ";
    cout << endl;

    return 0;
}