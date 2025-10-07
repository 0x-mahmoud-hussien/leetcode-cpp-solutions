
// https://leetcode.com/problems/reverse-linked-list-ii
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
    ListNode* reverseBetween(ListNode* head, int left, int right) 
    {
        if (!head || left == right) return head;

        ListNode dummy(0);    
        dummy.next = head;

        ListNode* prev = &dummy; 

        for (int i = 1; i < left; i++)
            prev = prev->next;

        ListNode* curr = prev->next;
        ListNode* nextNode = nullptr;

        for (int i = 0; i < right - left; i++) 
        {
            nextNode = curr->next;
            curr->next = nextNode->next;
            nextNode->next = prev->next;
            prev->next = nextNode;
        }

        return dummy.next;
    }
};

void printList(ListNode* head)
{
    while (head)
    {
        cout << head->val;
        if (head->next) cout << " -> ";
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

    cout << "Original List: ";
    printList(head);

    Solution sol;
    ListNode* newHead = sol.reverseBetween(head, 2, 4);

    cout << "Reversed (2 to 4): ";
    printList(newHead);

    return 0;
}