template <typename K, typename V>
struct Node{
    K key;
    V val;
    Node* pre;
    Node* next;
    Node(){};
    Node(K k, V v):key(k), val(v){};
};

class LRUCache{
private:
    int _capacity;
    int len;
    Node<int, int> *head;
    Node<int, int> *tail;
    unordered_map<int, Node<int, int>*> *map;
public:
    //LRUCache(){};
    LRUCache(int capacity) {
        _capacity = capacity;
        len = 0;
        head = nullptr;
        tail = nullptr;
        map = new unordered_map<int, struct Node<int, int>*>();
    };
    
    int get(int key) {
        unordered_map<int, Node<int, int>*>::iterator it =  map->find(key);
        if(it !=map->end()){
            Node<int, int> *node = it->second;
            removeNode(node);
            setHead(node);
            return node->val;
        }
        else{
            return - 1;
        }
        
    }
    Node<int, int>* removeNode(Node<int, int> *node){
        if(node == NULL || len == 0) return nullptr;
        Node<int, int> *pre = node->pre;
        Node<int, int> *next = node->next;
        len--;
        if(node == head){
            head = next;
            if(head != NULL)
                head->pre = NULL;
            if(len == 0)
                tail = NULL;
        }
        else if(node == tail){
            tail = pre;
            if(tail != NULL)
                tail->next = NULL;
            if(len == 0)
                head = NULL;
        }
        else{
            pre->next = next;
            next->pre = pre;
        }
        return node;
    }

    void set(int key, int value) {
        if(_capacity == 0)return;
        unordered_map<int, Node<int, int>*>::iterator it =  map->find(key);
        if(it != map->end()){
            Node<int, int> *node = it->second;
            node->val = value;
            removeNode(node);
            setHead(node);
        }
        else{
            Node<int, int> *newNode = new Node<int, int>(key, value);
            map->insert({key, newNode});
            if(len < _capacity){
                setHead(newNode);
            }
            else{
                Node<int, int> *rNode = removeNode(tail);
                setHead(newNode);
                map->erase(map->find(rNode->key));
            }
            
        }
    }
    
    
    void setHead(Node<int, int> *node){
        node->next = head;
        node->pre = NULL;
        if(head == NULL){
            head = tail = node;
        }
        else{
            head->pre = node;
            head = node;
        }
        len++;
    }
};

