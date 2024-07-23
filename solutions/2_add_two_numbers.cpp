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
        ListNode* left = l1;
        ListNode* right = l2;
        ListNode* result = new ListNode();
        ListNode* resultCursor = result;
        int16_t carry = 0;
        int16_t sum = 0;
        while(left || right){
            sum = carry;
            if(left){
                sum += left->val;
                left = left->next;
            }
            if(right){
                sum += right->val;
                right = right->next;
            }
            resultCursor->val = (sum % 10);
            if(sum >= 10){
                carry = 1;
            }else{
                carry = 0;
            }
            if(left || right){
                resultCursor->next = new ListNode();
                resultCursor = resultCursor->next;
            }

        }
        if(carry){
            resultCursor->next = new ListNode();
            resultCursor->next->val = carry;
        }
        return result;
    }
};