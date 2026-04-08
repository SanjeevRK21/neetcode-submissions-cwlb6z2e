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
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* curr = head;

        while (curr && curr->next) {
            int g = gcd(curr->val, curr->next->val);

            // create new node
            ListNode* newNode = new ListNode(g);

            // insert between curr and curr->next
            newNode->next = curr->next;
            curr->next = newNode;

            // move to next original node
            curr = newNode->next;
        }

        return head;
    }
};