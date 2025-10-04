
// https://leetcode.com/problems/reverse-linked-list
#include <iostream>
using namespace std;

struct ListNode 
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) 
    {
        ListNode* prev = NULL;
        ListNode* current = head;
        ListNode* next = NULL;

        while (current != NULL)
        {
            next = current->next;   
            current->next = prev;   
            prev = current;         
            current = next;      
        }

        return prev; 
    }
};


void printList(ListNode* head) 
{
    while (head != NULL)
    {
        cout << head->val;
        if (head->next != NULL)
            cout << " -> ";
        head = head->next;
    }
    cout << " -> NULL\n";
}

int main()
{
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original list:\n";
    printList(head);

    Solution sol;
    head = sol.reverseList(head);

    cout << "\nReversed list:\n";
    printList(head);

    return 0;
}