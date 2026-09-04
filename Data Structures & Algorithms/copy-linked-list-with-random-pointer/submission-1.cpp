/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head)
    {
        unordered_map<Node*, Node*> copy;

        Node* temp = head;
        Node* dummy = new Node(0);
        Node* dummyCopy = dummy;

        while(temp)
        {
            Node* node = new Node(temp->val);
            copy[temp] = node;

            dummyCopy->next = node;
            dummyCopy = dummyCopy->next;
            temp = temp->next;
        }

        Node* oldPtr = head;
        Node* newPtr = dummy->next;

        while(newPtr && oldPtr)
        {
            Node* rnd = oldPtr->random;
            if(rnd)
            {
                newPtr->random = copy[rnd];
            }

            oldPtr = oldPtr->next;
            newPtr = newPtr->next;
        }

        return dummy->next;
    }
};
