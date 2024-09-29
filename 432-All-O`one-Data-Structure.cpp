class AllOne {
private:
    struct ListNode {
        int count;
        unordered_set<string> keys;
        ListNode* prev;
        ListNode* next;
        ListNode(int c) : count(c), prev(nullptr), next(nullptr) {}
    };
    
    unordered_map<string, int> keyCount;
    unordered_map<int, ListNode*> countNodes;
    ListNode* head;
    ListNode* tail;
    
    void addNodeAfter(ListNode* node, int count) {
        ListNode* newNode = new ListNode(count);
        newNode->prev = node;
        newNode->next = node->next;
        if (node->next) node->next->prev = newNode;
        node->next = newNode;
        countNodes[count] = newNode;
        if (tail == node) tail = newNode;
    }
    
    void removeNode(ListNode* node) {
        if (node->prev) node->prev->next = node->next;
        if (node->next) node->next->prev = node->prev;
        if (tail == node) tail = node->prev;
        countNodes.erase(node->count);
        delete node;
    }
    
public:
    AllOne() {
        head = new ListNode(0);
        tail = head;
    }
    
    void inc(string key) {
        int count = keyCount[key]++;
        ListNode* currentNode = count ? countNodes[count] : head;
        ListNode* nextNode;
        
        if (countNodes.find(count + 1) != countNodes.end()) {
            nextNode = countNodes[count + 1];
        } else {
            addNodeAfter(currentNode, count + 1);
            nextNode = currentNode->next;
        }
        
        nextNode->keys.insert(key);
        if (count) {
            currentNode->keys.erase(key);
            if (currentNode->keys.empty()) removeNode(currentNode);
        }
        
        keyCount[key] = count + 1;
    }
    
    void dec(string key) {
        int count = keyCount[key];
        ListNode* currentNode = countNodes[count];
        ListNode* prevNode;
        
        if (count == 1) {
            keyCount.erase(key);
        } else {
            keyCount[key]--;
        }
        
        if (count == 1) {
            currentNode->keys.erase(key);
        } else {
            if (countNodes.find(count - 1) != countNodes.end()) {
                prevNode = countNodes[count - 1];
            } else {
                addNodeAfter(currentNode->prev, count - 1);
                prevNode = currentNode->prev;
            }
            prevNode->keys.insert(key);
            currentNode->keys.erase(key);
        }
        
        if (currentNode->keys.empty()) removeNode(currentNode);
    }
    
    string getMaxKey() {
        return tail == head ? \\ : *tail->keys.begin();
    }
    
    string getMinKey() {
        return head->next == nullptr ? \\ : *head->next->keys.begin();
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */