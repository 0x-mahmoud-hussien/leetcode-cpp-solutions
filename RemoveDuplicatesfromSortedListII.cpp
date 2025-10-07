
// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii
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
    ListNode* deleteDuplicates(ListNode* head) 
    {
        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;  
        ListNode* curr = head;   

        while (curr != NULL) 
        {
            bool isDuplicate = false;
            while (curr->next != NULL && curr->val == curr->next->val) 
            {
                isDuplicate = true;
                curr = curr->next; 
            }

            if (isDuplicate) 
                prev->next = curr->next; 
            else 
                prev = prev->next;      

            curr = curr->next;
        }

        return dummy->next; 
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
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next->next = new ListNode(5);

    cout << "Original List: ";
    printList(head);

    Solution sol;
    ListNode* result = sol.deleteDuplicates(head);

    cout << "After Removing Duplicates: ";
    printList(result);

    return 0;
}