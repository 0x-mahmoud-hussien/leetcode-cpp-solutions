
// https://leetcode.com/problems/remove-duplicates-from-sorted-list
#include <iostream>
using namespace std;

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution 
{
public:
    ListNode* deleteDuplicates(ListNode* head) 
    {
        ListNode* current = head;

        while (current != NULL && current->next != NULL) 
        {
            if (current->val == current->next->val) 
                current->next = current->next->next;
            else
                current = current->next;
        }
        return head;
    }
};

int main() 
{
    ListNode* head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(3);

    Solution sol;
    head = sol.deleteDuplicates(head);

    ListNode* temp = head;
    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }

    return 0;
}