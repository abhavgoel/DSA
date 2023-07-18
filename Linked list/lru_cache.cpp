class node{
    public:
    int key;
    int val;
    node *next;
    node *prev;
    node(int key_,int val_)
    {
        key=key_;
        val=val_;

    }

};
class LRUCache {
public:

int cap;//capacity;
node *head = new node(-1,-1);
node *tail = new node(-1,-1);
unordered_map<int,node*>mp;//storing if value present in memory or not

void addnode(node* newnode)//adding node after head
{
    node *temp =head->next;
    head->next=newnode;
    newnode->prev = head;
    temp->prev = newnode;
    newnode->next = temp;
}
void deletenode(node *delnode)//delete at any position
{  
    node *delnext = delnode->next;
    node *delprev = delnode->prev;
    delnext->prev=delprev;
    delprev->next = delnext;

}
    LRUCache(int capacity) {
        cap=capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end())
        {
            node *res = mp[key];
            mp.erase(key);
            deletenode(res);//deleting the node
            addnode(res);//adding node next to head ptr
            mp[key]=head->next;//assigning address to the recently added node
            return res->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end())
        {
            node *existing = mp[key];
            mp.erase(key);
            deletenode(existing);
        }
        if(mp.size()==cap)
        {
            mp.erase(tail->prev->key);
            deletenode(tail->prev);

        }
        addnode(new node(key,value));
        mp[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */