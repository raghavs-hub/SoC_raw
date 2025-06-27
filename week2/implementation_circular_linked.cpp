#include<bits/stdc++.h>
using namespace std;

template <typename T>
struct my_node
{
    my_node* next;
    T value;
    my_node(T val,my_node* next):value(val) ,next(next){}
    my_node(T val):value(val){
        next = nullptr;
    }
    my_node(){next = nullptr;}
};

template <typename T>
struct node_list{
my_node<T>* head;
int size =0;

node_list(){
    head = nullptr;
}

void add_node(my_node<T>* p){
    if(head==nullptr) {head = p; head->next = p;}
    else{
    my_node<T>* end = head;
    for(int i=0;i<size-1;i++){
        end = end->next;
    }
    end->next =p;
    p->next = head;
    head =p;}
    size++;
}

bool search(T val){
    my_node<T>* tmp = head;
    for(int i=0;i<size;i++, tmp=tmp->next){
        if(tmp->value == val) return true;
    }
    return false;
}

void delete_value(T val){
    if(!(this->search(val))){
        cout << "element not in the list\n";
    } else if(size == 1){
        size--;
        delete head;
        head = nullptr;
    }else{
        my_node<T>* tmp = head;
        for(;;tmp = tmp->next){
            if(tmp->next->value == val) break;
        }
        my_node<T>* tmp1 = tmp->next->next;
        delete tmp->next;
        tmp->next = tmp1;
        size--;
    }}


void printlist(){
    my_node<T>* tmp=head;
    for(int i=0;i<2*size;i++ , tmp = tmp->next){
        cout << tmp->value << " ";
    }
    cout << "\n";
}


};

/*
int main()
{

int n; cin >> n;
node_list<int> list;
while(n != -1){
    my_node<int>* p = new my_node(n);
    list.add_node(p);
    cin >> n;
}

list.printlist();
cout << (list.search(2)?"true\n":"false\n");
list.delete_value(2);
cout << list.size << "\n";
//list.printlist();
list.delete_value(7);
cout << list.size << "\n";
//list.printlist();



}

*/