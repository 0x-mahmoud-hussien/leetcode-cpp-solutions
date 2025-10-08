
// https://leetcode.com/problems/remove-nodes-from-linked-list
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode* removeNodes(ListNode* head)
    {
        if (!head || !head->next)
            return head;

        head = reverseList(head);

        int maxSoFar = head->val;
        ListNode* curr = head;

        while (curr && curr->next)
        {
            if (curr->next->val < maxSoFar)
            {
                ListNode* temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
            }
            else
            {
                curr = curr->next;
                maxSoFar = curr->val;
            }
        }

        head = reverseList(head);
        return head;
    }

private:
    ListNode* reverseList(ListNode* head)
    {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr)
        {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }
};

int main()
{
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Empty list.\n";
        return 0;
    }

    cout << "Enter " << n << " values:\n";
    int x;
    cin >> x;
    ListNode* head = new ListNode(x);
    ListNode* curr = head;

    for (int i = 1; i < n; i++)
    {
        cin >> x;
        curr->next = new ListNode(x);
        curr = curr->next;
    }

    Solution s;
    ListNode* result = s.removeNodes(head);

    cout << "Output: ";
    while (result)
    {
        cout << result->val << " ";
        ListNode* temp = result;
        result = result->next;
        delete temp;
    }
    cout << endl;

    return 0;
}