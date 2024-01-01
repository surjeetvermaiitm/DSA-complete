1. Last stone weight
   Link: https://leetcode.com/problems/last-stone-weight/description/

```cpp
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(),stones.end());
        while(pq.size()>1){
            int y=pq.top();
            pq.pop();
            int x=pq.top();
            pq.pop();
            if(x!=y){
                pq.push(y-x);
            }
        }
        return pq.size()>0 ?pq.top():0;

    }
};
```

```py
class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        # convert stones to negative numbers for max heap
        max_heap = [-stone for stone in stones]
        heapq.heapify(max_heap)

        while len(max_heap) > 1:
            # get the two largest stones
            stone1 = heapq.heappop(max_heap)
            stone2 = heapq.heappop(max_heap)

            # smash the two stones together
            if stone1 != stone2:
                heapq.heappush(max_heap, stone1 - stone2)

        # if there is only one stone left, return its positive value
        if max_heap:
            return -max_heap[0]
        else:
            return 0
```

2. Merge k sorted list
   Link: https://leetcode.com/problems/merge-k-sorted-lists/description/
   Approach 1

```cpp
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

```

Approach2:

```cpp
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
```

Qn3 Kth smallest ele in sorted matrix
Link: https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/

```cpp

```
