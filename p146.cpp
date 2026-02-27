#include <unordered_map>

using namespace std;
/*
146. LRU Cache
*/
struct Node {
    int key;
    int value;
    Node* prev;
    Node* next;
    Node(int k, int v): key(k), value(v), prev(nullptr), next(nullptr) {}
    /*
    Node(int k, int v) {
        key = k;
        value = v;
        prev = nullptr;
        next = nullptr;
    }
    */
};

class LRUCache {
private:
    int capacity;
    unordered_map<int, Node*> cache;
    Node* head;
    Node* tail;

    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void addToHead(Node* node) {
        node->next = head->next; //插入者右手牽當前第一個（假頭下一個)
        node->prev = head;       //插入者左手牽假頭
        head->next->prev = node; //當前第一個（假頭下一個）的左手牽插入者
        head->next = node;       //假頭右手牽插入者
    }

    void moveToHead(Node* node) {
        removeNode(node);
        addToHead(node);
    }

public:
    LRUCache(int capacity) : capacity(capacity){
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(cache.find(key) == cache.end()) return -1; // 等於沒找到
        Node* node = cache[key];
        moveToHead(node);
        return node->value;
    }
    
    void put(int key, int value) {
        // map裡面已經有要改值，改完移到最前面
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            node->value = value;
            moveToHead(node);
        } else {
            // map裡面沒有，要新增，加完移到最前面
            Node* newNode = new Node(key, value);
            cache[key] = newNode;
            addToHead(newNode);

            //檢查cache 有超過大小嗎
            if (cache.size() > capacity) {
                Node* last = tail->prev;
                removeNode(last);
                cache.erase(last->key);
                delete last;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */