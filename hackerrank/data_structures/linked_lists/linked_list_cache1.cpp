
/**
   *   @brief Solution to the Hackerrank Problem about Polymorphism using Linked Lists 
   * 	@note https://www.hackerrank.com/challenges/abstract-classes-polymorphism/problem
   */

void print_list(const Node* head)
{
    int i=0; 
    while(head != NULL)
    {
        cout << "Element i=" << i << " --> curr=" << head << ", prev=" << head->prev << ", next=" << head->next << " --> key=" << head->key << ", value=" << head->value << endl; 
        i++; 
        if(head == head->next) 
        {
            cout << "INFINITE LOOP DETECTED --> Exiting" << endl; 
            return; 
        }
        else head = head->next; 
    }
}

class LRUCache : public Cache
{
    public: 
    LRUCache(int capacity) : m_size(0), is_debug(false)
    {
        cp = capacity; 
        head = NULL; 
        tail = NULL; 
        /*
        // NOTE: All values need to be strictly positive, so using zero for invalid ones 
        head = new Node(0,0); 
        tail = head; 
        for(int i=1; i<capacity; ++i)
        {
            tail->next = new Node(tail, NULL, 0, 0); 
            tail->next->prev = tail; 
            tail = tail->next; 
        }
        */
    }
    
    int get(int key) 
    {
        auto p_val = mp.find(key); 
        if(p_val != mp.end()) return p_val->second->value; 
        return -1; 
    }
    
    void set(int key, int val) 
    {
        if(is_debug) cout << "Performing set(" << key << ", " << val << ") " << endl; 
        auto p_val = mp.find(key); 
        if(p_val != mp.end()) 
        {
            if(is_debug) cout << "Cache Hit " << endl; 
            // CACHE HIT //
            // NOTE: If node found, make it new head 
            // NOTE: It just affects reordering but not the Map Interface 
            auto p_node = p_val->second; 
            
            // NOTE: Value Update 
            p_node->value = val; 
            
            if(p_node == head) return; 
            
            // NOTE: Reorder 
            if(is_debug) cout << "Pre110" << endl; 
            if(is_debug) print_list(head); 
            if(p_node != head) p_node->prev->next = p_node->next; 
            if(p_node != tail) p_node->next->prev = p_node->prev; 
            else tail = p_node->prev; 
            
            // NOTE: Add as head 
            p_node->next = head; 
            head->prev = p_node; 
            head = p_node; 
            if(is_debug) cout << "Post110" << endl; 
            if(is_debug) print_list(head); 
        }
        else 
        {
            // CACHE MISS //
            // NOTE: If not found, add new head possibly droppping the tail for capacity limit reached 
            // NOTE: Storage to be used for insert 
            if(is_debug) cout << "Cache Miss" << endl; 
            Node* p_node = NULL; 
            if(m_size == cp)
            {
               if(is_debug) cout << "Dropping Tail" << endl; 
                // NOTE: Drop the Tail Node 
                // TODO: Remove the tail key in the map 
                mp.erase(mp.find(tail->key)); 
                p_node = tail; 
                tail = tail->prev; 
                //free(tail->next); 
                
                tail->next = NULL; 
                m_size--; 
            }
            else 
            {
                if(is_debug) cout << "Adding Node" << endl; 
                p_node = new Node(key, val); 
            }
            
            // NOTE: Add the Head Node 
            // TODO: Add the head key in the map 
            //auto t_new_head = new Node(key, val); 
            mp[key] = p_node; 
            
            if(head == NULL)
            {
                // NOTE: First element 
                head = p_node; 
                tail = p_node; 
            }
            else 
            {
                // NOTE: head and tail already set 
                if(is_debug) cout << "Pre111" << endl; 
                if(is_debug) print_list(head); 
                p_node->next = head; 
                head->prev = p_node; 
                head = p_node; 
            }
            if(is_debug) cout << "Post111" << endl; 
            if(is_debug) print_list(head); 
            m_size++; 
        }
    }
    
    private: 
    int m_size; 
    bool is_debug; 
};





