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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(n == 1 && head->next == nullptr){
            return nullptr;
        }else if(n==1){
            ListNode* prevNode = head;
            ListNode* currentNode = head->next;
            while(currentNode && currentNode->next != nullptr){
                prevNode = currentNode;
                currentNode = currentNode->next;
            }
            prevNode->next = nullptr;
            return head;
        }

        ListNode* offsetNode = head;
        ListNode* prevOffsetNode = nullptr;
        ListNode* currentNode = head;

        for(int i = 1; i < n; ++i){
            currentNode = currentNode->next;
        }

        while(currentNode && currentNode->next != nullptr){
            prevOffsetNode = offsetNode;
            offsetNode = offsetNode->next;
            currentNode = currentNode->next;
        }
        //head is the node that needs to be removed
        if(offsetNode == head){
            head = head->next;
        }else{
            prevOffsetNode->next = offsetNode->next;
        }
        

        return head;
        
    }
};