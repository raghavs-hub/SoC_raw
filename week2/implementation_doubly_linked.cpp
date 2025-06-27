#include<bits/stdc++.h>
using namespace std;

template <typename T>
struct my_node{
    T val;
    my_node* next;
    my_node* prev;
my_node(T val):val(val){
    next = prev = nullptr;
}
my_node(){next = prev = nullptr;}
};

template <typename T>
struct my_double_list{
    my_node<T>* head;
    my_node<T>* tail;
    int size=0;

my_double_list(){
    head = new my_node<T>;
    tail = new my_node<T>;
    head->prev = tail->next = nullptr;
    head->next=tail;
    tail->prev=head;
}

void insert_node(my_node<T>* new_node){
    size++;
    new_node->next = head->next;
    new_node->prev = head;
    new_node->next->prev = new_node;
    head->next=new_node;
}

void print_list(){
    for(my_node<T>* tmp=head->next;tmp != tail;tmp = tmp->next){
        cout << tmp->val << " ";
    }
    cout << "\n";
}

bool search(T value){
    for(my_node<T>* tmp=head->next;tmp != tail;tmp = tmp->next){
        if(tmp->val == value) return true;
    }
    return false;
}

void delete_value(T value){

if(!(search(value))) cout << "Element not in list!\n";    
else{
    my_node<T>* tmp=head->next;
    while(tmp->val != value){
        tmp=tmp->next;
    }
    tmp->prev->next = tmp->next;
    tmp->next->prev = tmp->prev;
    delete tmp;
    size--;
}
}

~my_double_list(){
    my_node<T>* current = head->next;
    my_node<T>* deletor = head;
    while(current != nullptr){
        delete deletor;
        deletor = current;
        current = current->next;
    }
    delete deletor;
    deletor = nullptr;
}
};


/*      for trial

int main()
{
    my_double_list<char> list;
    char c; cin >> c;
    while(c != '!'){
        my_node<char>* nc = new my_node(c);
        list.insert_node(nc);
        cin >> c;
    }
    list.print_list();
    list.delete_value('e');
    list.print_list();
    list.delete_value('w');
    list.print_list();
    cout << list.size << "\n";
}

*/