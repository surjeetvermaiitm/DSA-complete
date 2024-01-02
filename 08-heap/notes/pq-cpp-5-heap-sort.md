### Heap sort

same as selecton sort only diff is finding min ele from unsorted arr using heap in place of linear search

selection sort -> O(n^2)
heap sort -> O(nlogn)

- In heap sort, we replace the ineffecient linear search sub routine of selection sort with a heap. Heap can give minimum element and then remove it in logn time.

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
    void downheapify(int idx,int bound){
        while(idx<hp.size()){
            int lc=2*idx+1;
            int rc=2*idx+2;
            if(lc>=bound) break;//idx-> leaf
            int maxEl = idx;
            if(hp[lc]>hp[maxEl]){
                maxEl=lc;
            }
            if(rc<bound and hp[rc]>hp[maxEl]){
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
        i--;
        if(!empty()){
            downheapify(0,i);
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
        for(int j=0;j<hp.size();j++){
            cout<<hp[j]<<" ";
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
        i=n;
        for(int j=n/2;j>=0;j--){
            downheapify(j,i);
        }
    }
    vector<int> heapsort(){
        int sz=hp.size();
        while(sz>0){
            int el=0;
            swap(hp[el],hp[i]);
            i--;
            sz--;
            downheapify(0,i);
        }
        // for(int j=0;j<hp.size();j++){
        //     cout<<hp[j]<<" ";
        // }
        return hp;

    }

};

vector<int> heapsort(vector<int> &v){
    MaxHeap hp(v);
    return hp.heapsort();
}
int main(){
    vector<int> v={9,6,1,19,3,2,8,12,5};
    MaxHeap hp(v);
    hp.display();
    vector<int> ans=heapsort(v);
    for(int j=0;j<ans.size();j++){
            cout<<ans[j]<<" ";
        }
    return 0;
}
```
