
// https://leetcode.com/problems/valid-mountain-array
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool validMountainArray(vector<int>& arr) 
    {
        int n = arr.size();
        if (n < 3) return false;

        int i = 0;


        while (i + 1 < n && arr[i] < arr[i + 1]) 
        {
            i++;
        }


        if (i == 0 || i == n - 1) return false;


        while (i + 1 < n && arr[i] > arr[i + 1]) 
        {
            i++;
        }

        return i == n - 1;
    }
};

int main() 
{
    Solution solution;  

    vector<int> arr1 = {0, 3, 2, 1};
    vector<int> arr2 = {3, 5, 5};
    vector<int> arr3 = {2, 1};
    vector<int> arr4 = {1, 2, 3, 4, 5, 3, 1};

    cout << boolalpha; 

    cout << "arr1: " << solution.validMountainArray(arr1) << endl;
    cout << "arr2: " << solution.validMountainArray(arr2) << endl; 
    cout << "arr3: " << solution.validMountainArray(arr3) << endl; 
    cout << "arr4: " << solution.validMountainArray(arr4) << endl; 

    return 0;
}