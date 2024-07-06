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
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        
        ListNode* cursor = head->next;
        ListNode* prevNode = head;
        ListNode* nextNode = cursor->next;
        head->next = nullptr;

        while(cursor->next != nullptr){
            //std::cout << cursor->val << "\n";
            cursor->next = prevNode;
            prevNode = cursor;
            cursor = nextNode;
            nextNode = cursor->next;
        }
        cursor->next = prevNode;
        return cursor;
    }
};