#include<bits/stdc++.h>
using namespace std;

class custom_vector{
    int CAPACITY =1;
    int SIZE = 0;
    int* ptr = new int[CAPACITY];
public:
    int get_element(int i){
        if(i>=0 && i<SIZE){
            return ptr[i];
        } else{
            cout << "no element exists at this position: returning 0";
            return 0;
        }
    }
    void set_element(int i,int val){
        if(i>=0 && i<SIZE){
            ptr[i] = val;
        } else{
            cout << "no element exists at this position: returning 0";
        }
    }
    void pushback_new_element(int val){
        if(CAPACITY == SIZE){
            CAPACITY*=2;
            int* new_ptr = new int[CAPACITY];
            for(int i=0;i<SIZE;i++){
                new_ptr[i] = ptr[i];
            }
            delete[] ptr;
            ptr = new_ptr;
        }
        ptr[SIZE++] = val;
    }

    int operator[](int i){
        return (*this).get_element(i);
    }

    void remove_element_at_index(int i){
        if(i>=0 && i<SIZE){
            for(int x=i;x<SIZE-1;x++) ptr[x] = ptr[x+1];
            SIZE--;
        }
    }
}
;


