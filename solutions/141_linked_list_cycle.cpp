/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == nullptr || head->next == nullptr){
            return false;
        }
        if(head->next == head){
            return true;
        }

        ListNode *cursor = head;
        unordered_set<ListNode*> nodes = {0};

        while(cursor){
            //auto p = nodes.insert(cursor)
            //if insertion fails
            if(!(nodes.insert(cursor).second)){
                return true;
            }
            cursor = cursor->next;
        }

        return false;

        
    }
};