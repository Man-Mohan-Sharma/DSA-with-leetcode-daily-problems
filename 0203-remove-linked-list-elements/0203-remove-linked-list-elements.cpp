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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* cur = head;
        ListNode* pre = nullptr;
        while(cur!=nullptr){
            if(cur->val == val){
                ListNode* temp = cur;
                if(pre==nullptr){
                    head = head->next;
                    cur = head;
                }
                else{
                    cur = cur->next;
                    pre->next = temp->next;
                }
                delete(temp);
            }
            else{
                pre = cur;
                cur = cur->next;
                }
        }
        return head;
    }
};