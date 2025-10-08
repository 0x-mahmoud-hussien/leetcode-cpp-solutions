
// https://leetcode.com/problems/degree-of-an-array
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) 
    {
        unordered_map<int, int> firstIndex;  
        unordered_map<int, int> lastIndex;   
        unordered_map<int, int> count;     

        int degree = 0; 

        for (int i = 0; i < nums.size(); i++) 
        {
            int num = nums[i];

            if (firstIndex.find(num) == firstIndex.end())
                firstIndex[num] = i;        
            lastIndex[num] = i;            
            count[num]++;                  

            degree = max(degree, count[num]); 
        }

        int minLength = nums.size();    
        for (auto& kv : count) {
            if (kv.second == degree) 
            {    
                int len = lastIndex[kv.first] - firstIndex[kv.first] + 1;
                minLength = min(minLength, len);
            }
        }

        return minLength;
    }
};

int main() 
{
    Solution sol;

    vector<int> nums1 = {1, 2, 2, 3, 1};
    cout << "Shortest Subarray Length: " << sol.findShortestSubArray(nums1) << endl;

    vector<int> nums2 = {1, 2, 2, 3, 1, 4, 2};
    cout << "Shortest Subarray Length: " << sol.findShortestSubArray(nums2) << endl;

    return 0;
}