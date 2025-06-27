#include<bits/stdc++.h>
using namespace std;

class my_stack{
    int cap = 1;
    int size = 0;
    int* arr = new int[cap];
public:
    int get_top(){
        if (!(*this).empty()) return arr[size-1];
    }
    bool empty(){
        if(size==0) return true;
        return false;
    }
    void push(int val){
        if(size==cap){
            cap*=2;
            int* new_arr = new int[cap];
            for(int x=0;x<size;x++){
                new_arr[x] = arr[x];
            } 
            delete[] arr;
            arr = new_arr;
        }
        arr[size++] = val;
    }
    void pop(){
        if((*this).empty()) cout << "Stack is empty";
        else size--;
    }
    void printstack(){
        cout << "---------top-------------\n";
        for(int x=size-1;x>=0;x--) cout << arr[x] << endl;
        cout << "--------bottom----------\n";
    }
};
