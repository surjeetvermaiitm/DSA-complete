Q1.

> Given an array, convert that array to max heap. (no extra space)
> arr=[9,6,1,19,3,2,8,12,5]

Note: Every sorted array will be max heap or min heap but not every heap is a sorted array

Approach 1: sort the array
T-> O(nlogn)

Approach2:
Can we create a new array using Maxheap class using push and pop.
It will require extra space

Approach3:
use Heap to heapify inplace

- At any point of time region of the array which is a valid heap is [0,i]
- using upheapify

```cpp
// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

class MaxHeap{
    vector<int> hp;
    int i;//[0,i] -> maxHeap
    //ci--> child index, pi-> parent index
    void upheapify(int ci){
        while(ci>0){
            int pi = (ci-1)/2;
            if(hp[pi]<hp[ci]){
                swap(hp[pi],hp[ci]);
                ci=pi;
            }else{
                break;
            }
        }
    }
    void downheapify(int idx){
        while(idx<hp.size()){
            int lc=2*idx+1;
            int rc=2*idx+2;
            if(lc>=hp.size()) break;//idx-> leaf
            int maxEl = idx;
            if(hp[lc]>hp[maxEl]){
                maxEl=lc;
            }
            if(rc<hp.size() and hp[rc]>hp[maxEl]){
                maxEl=rc;
            }
            if(maxEl !=idx){
                swap(hp[idx],hp[maxEl]);
                idx=maxEl;//this is for next iteration
            }else{
                break;
            }

        }
    }
public:
    //T-> (log(n))
    void push(int ele){
        hp.push_back(ele);
        upheapify(hp.size()-1);
    }
    //T-> (log(n))
    void pop(){
        if(empty()) return;
        swap(hp[0],hp[hp.size()-1]);
        hp.pop_back();
        if(!empty()){
            downheapify(0);
        }
    }
    //T->O(1)
    int peek(){
        if(empty()) return INT_MIN;
        return hp[0];
    }
    bool empty(){
        return this->hp.size()==0;
    }
    void display(){
        cout<<"[";
        for(int i=0;i<hp.size();i++){
            cout<<hp[i]<<" ";
        }
        cout<<"]";
    }
    //T-> O(nlogn)
    MaxHeap(vector<int> v){
        hp=v;
        for(int i=1;i<hp.size();i++){
            upheapify(i);
        }
    }
};
int main(){
    vector<int> v={9,6,1,19,3,2,8,12,5};
    MaxHeap hp(v);
    hp.display();
    hp.push(100);
    hp.display();
    return 0;
}

```

- T-> O(nlogn)
  Total time complexity: Total itration of upheapification

T = 2^0 _ 0 + 2^1 _ 1 +2^2 _ 2+ ..... 2^h-1 _ (h-1)

AGP
multiply by 2 both side
the subtract bot eqn

T =2^h \* (h-2)+2
T=O(nlogn)

Approach 4:
Optimized approach

- using downhapify to all non leaf nodes. as half of leaf nodes are leaf nodes

T = 2^h-1 _ 0 +2^h-2 _ 1 + ......2^1(h-2)+2^0(h-1)

AGP
multiply be 2 both side

then subtract

T = 2^h -2 + h - 1

T= n-3+logn-1
T=O(n)

optimized code using downheapify cpp

```cpp
// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

class MaxHeap{
    vector<int> hp;
    int i;//[0,i] -> maxHeap
    //ci--> child index, pi-> parent index
    void upheapify(int ci){
        while(ci>0){
            int pi = (ci-1)/2;
            if(hp[pi]<hp[ci]){
                swap(hp[pi],hp[ci]);
                ci=pi;
            }else{
                break;
            }
        }
    }
    void downheapify(int idx){
        while(idx<hp.size()){
            int lc=2*idx+1;
            int rc=2*idx+2;
            if(lc>=hp.size()) break;//idx-> leaf
            int maxEl = idx;
            if(hp[lc]>hp[maxEl]){
                maxEl=lc;
            }
            if(rc<hp.size() and hp[rc]>hp[maxEl]){
                maxEl=rc;
            }
            if(maxEl !=idx){
                swap(hp[idx],hp[maxEl]);
                idx=maxEl;//this is for next iteration
            }else{
                break;
            }

        }
    }
public:
    //T-> (log(n))
    void push(int ele){
        hp.push_back(ele);
        upheapify(hp.size()-1);
    }
    //T-> (log(n))
    void pop(){
        if(empty()) return;
        swap(hp[0],hp[hp.size()-1]);
        hp.pop_back();
        if(!empty()){
            downheapify(0);
        }
    }
    //T->O(1)
    int peek(){
        if(empty()) return INT_MIN;
        return hp[0];
    }
    bool empty(){
        return this->hp.size()==0;
    }
    void display(){
        cout<<"[";
        for(int i=0;i<hp.size();i++){
            cout<<hp[i]<<" ";
        }
        cout<<"]";
    }
    //T-> O(nlogn)
    // MaxHeap(vector<int> v){
    //     hp=v;
    //     for(int i=1;i<hp.size();i++){
    //         upheapify(i);
    //     }
    // }
    //T-> O(n)
    MaxHeap(vector<int> v){
        hp=v;
        int n=hp.size();
        for(int i=n/2;i>=0;i--){
            downheapify(i);
        }
    }

};
int main(){
    vector<int> v={9,6,1,19,3,2,8,12,5};
    MaxHeap hp(v);
    hp.display();
    hp.push(100);
    hp.display();
    return 0;
}
```

you should know Timecomplexity with derivation
