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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *pNode1 = l1, *pNode2 = l2, *pOut = new ListNode(), *pCur = pOut;
        int       val1, val2, sum, carry                                   = 0, rest;

        while (pNode1 || pNode2 || carry) {
            val1 = (pNode1 ? pNode1->val : 0);
            val2 = (pNode2 ? pNode2->val : 0);

            sum   = val1 + val2 + carry;
            carry = sum / 10;
            sum %= 10;

            if (pNode1) pNode1 = pNode1->next;
            if (pNode2) pNode2 = pNode2->next;

            pCur->val = sum;
            if (pNode1 || pNode2 || carry) {
                pCur->next = new ListNode();
                pCur       = pCur->next;
            }
        }

        return pOut;
    }
};