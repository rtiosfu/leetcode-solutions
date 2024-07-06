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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* currentZeroHead = head;
        ListNode* nextZero = head->next;
        uint32_t totalSum = 0;
        //ListNode* newHead = nullptr;
        //ListNode* returnListCursor = nullptr;
        while(nextZero){
            while(nextZero && nextZero->val != 0){
            totalSum += nextZero->val;
            nextZero = nextZero->next;
            }
            currentZeroHead->val = totalSum;
            //ListNode* sumNode = new ListNode(totalSum);
            totalSum = 0;
            /*if(!newHead){
                newHead = sumNode;
                returnListCursor = newHead;
            }else{
                returnListCursor->next = sumNode;
                returnListCursor = returnListCursor->next;
            }*/
            if(nextZero->next != nullptr){
                currentZeroHead->next = nextZero;
                currentZeroHead = nextZero;
                
            }else{
                currentZeroHead->next = nullptr;
            }
            nextZero = nextZero->next;
            
        }
        return head;
    }
};