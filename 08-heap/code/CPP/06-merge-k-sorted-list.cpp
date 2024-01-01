//Link: https://leetcode.com/problems/merge-k-sorted-lists/description/

//approach 1
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

class cmp{
    public:
        bool operator()(const ListNode* l1,const ListNode* l2){
            return l1->val>l2->val;
        }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        priority_queue<ListNode*,vector<ListNode*>,cmp> pq;
        for(int i=0;i<lists.size();i++){
            if(!lists[i]) continue;
            pq.push(lists[i]);
        }
        ListNode *dummy=new ListNode(-1);
        ListNode* ptr=dummy;
        while(!pq.empty()){
            ListNode* curr=pq.top();
            pq.pop();
            if(curr->next){
                pq.push(curr->next);
            }
            ptr->next=curr;
            ptr=ptr->next;
        }
        return dummy->next;
    }
};
//approach2
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int,vector<int>,greater<int>>p;
        
        for(int i=0;i<lists.size();i++)
        {
            ListNode * t=lists[i];
            
            while(t!=NULL)
            {
                p.push(t->val);
                t=t->next;
            }
        }
        
        ListNode*head=NULL;
        if(p.empty())
            return head;
        head=new ListNode(p.top());
        p.pop();
        ListNode*te=head;
        while(!p.empty())
        {
            te->next=new ListNode(p.top());
            p.pop();
            te=te->next;
        }
        te->next=NULL;
        
        return head;
    }
};