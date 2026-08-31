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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* pre = head;
        ListNode* cur = head->next;
        ListNode* nex = cur->next;
        if(nex==nullptr) return {-1,-1};
        int i = 1;
        vector<int> critical;
        while(nex!=nullptr){
            if((cur->val > pre->val && cur->val > nex->val) || (cur->val < pre->val && cur->val < nex->val)){
                critical.push_back(i);
            }
            i++;
            pre = cur;
            cur = nex;
            nex = nex->next;
        }
        if(critical.size()<2) return {-1,-1};
        int maxx = critical[critical.size()-1]-critical[0];
        int minn = INT_MAX;
        for(int i = 1; i<critical.size(); i++) minn = min(minn,critical[i]-critical[i-1]);
        return {minn,maxx};
    }
};