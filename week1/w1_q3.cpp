#include<bits/stdc++.h>
using namespace std;

class my_queue{
    int capacity=1,size=0,end=0,start=0;
    int* arr = new int[capacity];
public:
    void enqueue(int val){
        if(size==capacity){
            capacity*=2;
            int* new_arr = new int[capacity];
            for(int x=0,y=end;x<size;x++, y=(y+1)%size){
                new_arr[x] = arr[y];
            }
            start=size;
            end=0;
            delete[] arr;
            arr = new_arr;
        }
            size++;
            arr[start] = val;
            start = (start+1)%capacity;
    }

    bool empty(){
        if(size==0) return true;
        else return false;
    }

    void dequeue(){
        if((*this).empty()) cout << "Empty Queue";
        else{
            end = end+1;
            size--;
        }
    }

    int front(){
        if(!(*this).empty()){
            return arr[(start-1)%capacity];
        } else{
            cout << "Empty Queue : returning 0";
            return 0;
        }
    }

    void printqueue(){
        cout << "---back of queue---   ";
        for(int x=0,y=end;x<size;x++, y=(y+1)%capacity){
            cout << arr[y] << " ";
        }
        cout << "  ---front of queue---\n";
    }
};
