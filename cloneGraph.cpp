/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    // dfs using hashmap to pair original and new
    // start with any entry

    Node* doDFS(Node* node, std::unordered_map<Node*, Node*>& m) {
        // Clone current
        std::vector<Node*> neighborTmp;
        Node* clone = new Node(node->val);

        m[node] = clone; // create pairing
        for (std::vector<Node*>::iterator it = node->neighbors.begin(); it != node->neighbors.end(); it++) {
            // If in map push to clone, otherwise do dfs
            if (m.find(*it) != m.end()) {
                neighborTmp.push_back(m[*it]);
            } else {
                neighborTmp.push_back(doDFS(*it, m));
            }
        }

        clone->neighbors = neighborTmp;
        return clone;
    }

    Node* cloneGraph(Node* node) {
        std::unordered_map<Node*, Node*> m;

        // Edge case, no nodes
        if (!node) {
            return node;
        }

        // Edge case, single node
        if (node->neighbors.size() == 0) {
            Node* clone = new Node(node->val);
            return clone;
        }

        return doDFS(node, m);
    }
};
