//Link: https://leetcode.com/problems/lexicographical-numbers/description/
//i->10*i+0,10*i+1,10*i+2.....10*i+9
// i->10*i+0,10*i+1,10*i+2.....10*i+9
// - f(i,n)=prints the number in the range i to n in lexicographical order, ifi!=0
// f(i,n)={f(10*i+0,n),f(10*i+1,n).....f(10*i+9)} or f(10*i+j,n) for all j [0,9] if i!=0
// f(i,n)={f(10*i+1,n),f(10*i+2,n).....f(10*i+9)} or f(10*i+j,n) for all j [1,9] if i==0

class Solution {
public:
vector<int> res;
    void f(int i,int n){
        if(i>n) return ;
        if(i<=n and i!=0){
            // cout<<i<<" ";
            res.push_back(i);
        }
        if(i!=0){
            for(int j=0;j<=9;j++){
                f(10*i+j,n);
            }
        }else{
           for(int j=1;j<=9;j++){
                f(10*i+j,n);
            } 
        }
        
    }
    vector<int> lexicalOrder(int n) {
        res.clear();
        f(0,n);
        return res;
    }
};
//class Solution {
public:
vector<int> res;
    void f(int i,int n){
        if(i>n) return ;
        if(i<=n and i!=0){
            // cout<<i<<" ";
            res.push_back(i);
        }
        // if(i!=0){
        //     for(int j=0;j<=9;j++){
        //         f(10*i+j,n);
        //     }
        // }else{
        //    for(int j=1;j<=9;j++){
        //         f(10*i+j,n);
        //     } 
        // }
        for(int j=(i==0)?1:0;j<=9;j++){
            f(10*i+j,n);
        }
        
    }
    vector<int> lexicalOrder(int n) {
        res.clear();
        f(0,n);
        return res;
    }
};