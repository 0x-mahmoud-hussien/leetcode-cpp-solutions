
// https://leetcode.com/problems/remove-linked-list-elements
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
    ListNode* removeElements(ListNode* head, int val) 
    {
        while (head != NULL && head->val == val) 
        {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }

        if (!head) return NULL;

        ListNode* current = head;
        while (current->next != NULL) 
        {
            if (current->next->val == val) 
            {
                ListNode* temp = current->next;
                current->next = current->next->next;
                delete temp;
            } 
            else 
                current = current->next;
        }

        return head;
    }
};


void printList(ListNode* head) 
{
    while (head != NULL) 
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() 
{
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(6);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next->next = new ListNode(6);

    Solution sol;
    head = sol.removeElements(head, 6);

    printList(head); 

    return 0;
}