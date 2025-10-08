
// https://leetcode.com/problems/relative-sort-array
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) 
    {
        vector<int> result;  
        vector<int> rest;  

        for (int j = 0; j < arr2.size(); j++)
        {
            for (int i = 0; i < arr1.size(); i++)
            {
                if (arr1[i] == arr2[j])
                {
                    result.push_back(arr1[i]); 
                }
            }
        }

        for (int i = 0; i < arr1.size(); i++)
        {
            bool found = false;
            for (int j = 0; j < arr2.size(); j++)
            {
                if (arr1[i] == arr2[j])
                {
                    found = true;
                    break;
                }
            }
            if (!found)
                rest.push_back(arr1[i]); 
        }


        sort(rest.begin(), rest.end());

        for (int x : rest)
            result.push_back(x);

        return result;
    }
};

int main()
{
    Solution s;

    vector<int> arr1 = {2,3,1,3,2,4,6,7,9,2,19};
    vector<int> arr2 = {2,1,4,3,9,6};

    vector<int> result = s.relativeSortArray(arr1, arr2);

    cout << "Result: [ ";
    for (int x : result)
        cout << x << " ";
    cout << " ] " << endl;

    return 0;
}