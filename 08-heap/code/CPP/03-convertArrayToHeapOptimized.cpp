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