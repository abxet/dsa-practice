// Leetcode 19. Remove Nth Node From End of List
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

void printListNode(ListNode *node)
{
    ListNode *curr = node;
    while (curr != nullptr)
    {
        cout << curr->val << " -> ";
        curr = curr->next;
    }
    cout << "NULL\n";
}

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *dummy = new ListNode();
        dummy->next = head;

        // Step 1: Compute the length of the list
        ListNode *curr = head;
        int len = 0;
        while (curr != nullptr)
        {
            len++;
            curr = curr->next;
        }

        // Step 2: Find the node just before the one to remove
        curr = dummy;
        for (int i = 0; i < len - n; i++)
        {
            curr = curr->next;
        }

        // Step 3: Remove it
        ListNode *temp = curr->next;
        curr->next = curr->next->next;
        delete temp; // optional, good practice

        // Step 4: Return new head
        ListNode *newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};

int main()
{
    // create list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode *first = new ListNode(1);
    ListNode *second = new ListNode(2);
    ListNode *third = new ListNode(3);
    ListNode *forth = new ListNode(4);
    ListNode *fifth = new ListNode(5);

    first->next = second;
    second->next = third;
    third->next = forth;
    forth->next = fifth;

    cout << "Original List:\n";
    printListNode(first);

    Solution s;
    ListNode *res = s.removeNthFromEnd(first, 2);
    printListNode(res);

    return 0;
}
