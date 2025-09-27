#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int size;
    cout << "How Many Items In Vector? ";
    cin >> size;

    vector<int> nums;
    for (int i = 0; i < size; i++)
    {
        int value;
        cout << "Enter Element " << i + 1 << ": ";
        cin >> value;
        nums.push_back(value);
    }


    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (nums[j] > nums[j + 1])
            {
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
    }

    int itemSearch;
    cout << "Enter Item To Search: ";
    cin >> itemSearch;

    int left = 0;  
    int right = size - 1;
    int result = -1; 

    while (left <= right)
    {
        int mid = (right + left) / 2;

        if (nums[mid] == itemSearch)
        {
            result = mid;
            break;
        }
        else if (nums[mid] < itemSearch)
            left = mid + 1;
        else
            right = mid - 1;
    }

    if (result != -1)
        cout << "Found at index: " << result << endl;
    else
        cout << "Not found" << endl;
    
    return 0;
}