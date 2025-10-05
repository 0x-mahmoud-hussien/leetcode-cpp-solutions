
// https://leetcode.com/problems/sort-list
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* merge(ListNode* l1, ListNode* l2) 
    {
        if (!l1) return l2;
        if (!l2) return l1;

        if (l1->val < l2->val) 
        {
            l1->next = merge(l1->next, l2);
            return l1;
        } 
        else 
        {
            l2->next = merge(l1, l2->next);
            return l2;
        }
    }

    ListNode* sortList(ListNode* head) 
    {
        if (!head || !head->next) return head;

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        while (fast && fast->next) 
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = nullptr;

        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(slow);

        return merge(l1, l2);
    }
};

void printList(ListNode* head) 
{
    while(head) 
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() 
{
    ListNode* head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);

    Solution sol;
    ListNode* sorted = sol.sortList(head);
    printList(sorted); 
}