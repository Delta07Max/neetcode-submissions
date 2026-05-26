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
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        if(lists.empty())
        {
            return NULL;
        }

        auto cmp = [](ListNode* a, ListNode* b) { return a->val > b->val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> minHeap(cmp);

        for(int i=0; i<lists.size(); i++)
        {
            if(lists[i] != NULL)
            {
                minHeap.push(lists[i]);
            }
        }

        ListNode* temp = new ListNode(0);
        ListNode* result = temp;

        while(!minHeap.empty())
        {
            ListNode* node = minHeap.top();
            minHeap.pop();
            result->next = node;
            result = result->next;
            
            node = node->next;
            if(node != NULL)
            {
                minHeap.push(node);
            }
        }
        return temp->next;
    }
};
