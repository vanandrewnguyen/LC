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
    Node* copyRandomList(Node* head) {
        // Weird question...

        // Create map for original nodes vs copied
        std::unordered_map<Node*, Node*> nMap;
        Node* tmp = new Node(0);
        Node* current = tmp;
        Node* original = head;

        // Loop once, create copy of each node
        while (original) {
            Node* copy = new Node(original->val);
            nMap[original] = copy;
            current->next = copy;

            // Move
            original = original->next;
            current = current->next;
        }

        // Loop once to set random pointers
        original = head;
        current = tmp->next;
        while (original) {
            if (original->random) {
                current->random = nMap[original->random];
            }

            // Move
            original = original->next;
            current = current->next;
        }

        // Return base
        return tmp->next;
    }
};
