#include <bits/stdc++.h>

using namespace std;

class LinkedList{

    private:

    struct Node{
        int value;
        struct Node *next;
        struct Node *prev;

        bool operator==(const Node a) const{
            return value == a.value && next == a.next && prev == a.prev;
        }
    };

    struct Node *head, *tail;
    int size;

    bool isFirst(Node *a){
        return a == head ? true : false;
    }
    
    bool isLast(Node *a){
        return a == tail ? true : false;
    }

    public:

    LinkedList(){
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    ~LinkedList(){
        Node* curr = head;
        while(curr != nullptr){
            Node* aux = curr->next;
            curr = nullptr;
            free(curr);
            curr = aux;
        }
    }

    int getSize(){
        return size;
    }

    bool isEmpty(){
        return size > 0 ? false : true;
    }

    Node* first(){
        if(size == 0){
            cerr << "Sem elementos na lista\n";
            return 0;
        }

        return head;
    }

    Node* last(){
        if(size == 0){
            cerr << "Sem elementos na lista\n";
            return 0;
        }

        return tail;
    }

    Node* before(Node *a){
        if(a->prev == nullptr){
            cerr << "Primeiro elemento da lista\n";
            return 0;
        }
        
        return a->prev;
    }

    Node* after(Node *a){
        if(a->next == nullptr){
            cerr << "Ultimo elemento da lista\n";
            return 0;
        }

        return a->next;
    }

    void replaceElement(Node *a, Node *b){
        b->prev = a->prev;
        b->next = a->next;
        b->value = a->value;

        a->prev->next = b;
        a->next->prev = b;

        a = nullptr;
        free(a);
    }

    void swapElement(Node *a, Node *b){
        Node *aux = a;
        
        a->value = b->value;
        a->prev = b->prev;
        a->next = b->next;

        b->value = aux->value;
        b->prev = aux->prev;
        b->next = aux->next;
    }

    void insertBefore(Node* a, int o){
        Node* new_node = (struct Node*)malloc(sizeof(struct Node));
        new_node->value = o;
        new_node->next = a;
        new_node->prev = a->prev;

        a->prev = new_node;
        a->prev->next = new_node;

        size++;
    }

    void insertAfter(Node* a, int o ){
        Node* new_node = (struct Node*)malloc(sizeof(struct Node));
        new_node->value = o;
        new_node->prev = a;
        new_node->next = a->next;

        a->next = new_node;
        a->next->prev = new_node;

        size++;
    }

    void insertFirst(int o){
        Node* new_node = (struct Node*)malloc(sizeof(struct Node));
        new_node->value = o;
        new_node->prev = nullptr;

        if(head == nullptr && tail == nullptr){
            tail = new_node;
            new_node->next = nullptr;
        } else if(head == tail){
            new_node->next = tail;
            tail->prev = new_node;
        } else{    
            new_node->next = head;
            head->prev = new_node; 
        } 
        
        head = new_node;

        size++;
    }

    void insertLast(int o){
        Node* new_node = (struct Node*)malloc(sizeof(struct Node));
        new_node->value = o;
        new_node->next = nullptr;

        if(head == nullptr && tail == nullptr){
            new_node->prev = nullptr;
            head = new_node;
        } else if(head == tail){
            new_node->prev = head;
            head->next = new_node;
        } else {
            new_node->prev = tail;
            tail->next = new_node;
        }

        tail = new_node;

        size++;
    }

    void remove(Node* n){
        n->prev->next = n->next;
        n->next->prev = n->prev;

        n=nullptr;
        free(n);
        size--;
    }

    void printList(){
        Node* curr = head;
        while(curr != nullptr){
            cout << curr->value << " ";
            curr = curr->next;
        }
    }

    Node* getAt(int ind){
        Node* curr;

        if(ind <= size/2){
            curr = head;
            
            for(int i = 0; i < ind; i++){
                if(curr->next != nullptr)
                    curr = curr->next;
                else
                    break;
            }
        } else {
            curr = tail;

            for(int i = 0; i < (size - ind); i++){
                if(curr->prev != nullptr)
                    curr = curr->prev;
                else
                    break;
            }
        }

        return curr;
    }

    int rankOf(Node* n){
        Node* curr = head;
        int r = 0;
        while(curr != nullptr && curr != n){
            curr = curr->next;
            r++;
        }

        return r;
    }
};

int main(){

    LinkedList dll;

    cout << "inserindo no comeco..." << endl;
    dll.insertFirst(1);
    dll.insertFirst(2);
    dll.insertFirst(3);
    dll.insertFirst(4);
    dll.printList();

    cout << endl << "inserindo no final..." << endl;
    dll.insertLast(55);
    dll.insertLast(54);
    dll.insertLast(53);
    dll.insertLast(52);
    dll.printList();

    cout << endl << "removendo elemento na posicao 2..." << endl;
    dll.remove(dll.getAt(2));
    dll.printList();

    cout << "\n" << dll.rankOf(dll.getAt(3));

    return 0;
}