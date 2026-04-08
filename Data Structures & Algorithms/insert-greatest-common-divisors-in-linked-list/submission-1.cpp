/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (!head || !head->next) return head;

        int g = gcd(head->val, head->next->val);

        // create gcd node
        ListNode* newNode = new ListNode(g);

        // insert it
        newNode->next = head->next;
        head->next = newNode;

        // recurse on next original node
        insertGreatestCommonDivisors(newNode->next);

        return head;
    }
};