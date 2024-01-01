### Priority Queue

1. Heap

- Heap : Heap is a hierarchy based data structure. It is a binary tree.
- It is not a regular binary tree but instead it is a complete binary tree.
- It stores the elements such that priority of parent is always higher than priority of children.

2. Complete binary tree

- It is a special binary tree in which all the elements uptill the 2nd last level are full and the last level fills all the elements left to right as tight as possible without leaving a spot.
- Heieght of complete binary tree: 2^0+2^1+.....2^(h-1)=n
- Height of complete binary tree = `2^h =n+1 => h=log2(n+1) = log(n)`
- `h=log(n)`
- For perfect binary tree or for complete binary tree 2^(h-1)=(n+1)/2 => the last level has almost half of the total nodes = no of leaf nodes

- We want a heap where bigger element has higher priority. (Max heap)
- We want a heap where smaller element has higher priority. (Min heap)

3. Max heap

- Binary Tree
- Complete Binary Tree
- Priority of parent > Priority of child

4. Array form

- if parent index is i

- left child index = 2\*i + 1
- right child index = 2\*i + 2

parent index = floor((childIndex-1)/2)

5. Time complexity

- upheapify : from child to parent to satisfy heap across one particular branch (perculate up)
  insertion : O(log(n))

maxheap.cpp

```cpp
#include <bits/stdc++.h>
using namespace std;

class MaxHeap{
    vector<int> hp;
public:
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

    void push(int ele){
        hp.push_back(ele);
        upheapify(hp.size()-1);
    }
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
};
int main(){
    MaxHeap hp;
    hp.push(3);
    hp.push(4);
    hp.push(11);
    hp.push(9);
    hp.push(14);
    hp.push(-1);
    hp.push(30);
    hp.push(44);
    hp.push(50);
    hp.display();
    return 0;
}
```

2. Minheap.cpp

```cpp

// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

class MaxHeap{
vector<int> hp;
public:
//ci--> child index, pi-> parent index
void upheapify(int ci){
while(ci>0){
int pi = (ci-1)/2;
if(hp[pi]>hp[ci]){
swap(hp[pi],hp[ci]);
ci=pi;
}else{
break;
}
}
}

    void push(int ele){
        hp.push_back(ele);
        upheapify(hp.size()-1);
    }
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

};
int main(){
MaxHeap hp;
hp.push(3);
hp.push(4);
hp.push(11);
hp.push(9);
hp.push(14);
hp.push(-1);
hp.push(30);
hp.push(44);
hp.push(50);
hp.display();
return 0;
}

```

Down heapify: for deleting the highest priority node
from parent to child

- Delete max priority ele

delete top node in maxHeap

```cpp
// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

class MaxHeap{
    vector<int> hp;
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
    // T-> O(logn)
    void push(int ele){
        hp.push_back(ele);
        upheapify(hp.size()-1);
    }
    //T-> O(logn)
    void pop(){
        if(empty()) return;
        swap(hp[0],hp[hp.size()-1]);
        hp.pop_back();
        if(!empty()){
            downheapify(0);
        }
    }
    //T-> O(1)
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
};
int main(){
    MaxHeap hp;
    hp.push(3);
    hp.push(4);
    hp.push(11);
    hp.push(9);
    hp.push(14);
    hp.push(-1);
    hp.push(30);
    hp.push(44);
    hp.push(50);
    hp.display();
    hp.pop();
    hp.display();
    return 0;
}
```
