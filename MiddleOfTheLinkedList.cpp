
// https://leetcode.com/problems/middle-of-the-linked-list
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) 
    {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;      
            fast = fast->next->next;  
        }

        return slow; 
    }
};

void printList(ListNode* head)
{
    while (head != NULL)
    {
        cout << head->val;
        if (head->next != NULL) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);

    cout << "Original List: ";
    printList(head);

    Solution sol;
    ListNode* mid = sol.middleNode(head);

    cout << "Middle Node and onward: ";
    printList(mid);

    return 0;
}