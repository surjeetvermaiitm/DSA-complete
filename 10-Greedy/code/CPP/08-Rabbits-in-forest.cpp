// Link:https://leetcode.com/problems/rabbits-in-forest/description/

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> freq;
        for(auto n:answers){
            freq[n]++;
        }
        int ans=0;
        for(auto p:freq){
            int k=p.first;
            int v=p.second;
            cout<<k<<v<<endl;
            ans += (k+1)*(ceil(v*1.0/(k+1)));
        }
        return ans;
    }
};

//approach 2
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> freq;
        // for(auto n:answers){
        //     freq[n]++;
        // }
        // int ans=0;
        // for(auto p:freq){
        //     int k=p.first;
        //     int v=p.second;
        //     ans += (k+1)*(ceil(v*1.0/(k+1)));
        // }
        // return ans;

        int res=0;
        for(int i=0;i<answers.size();i++){
            if(!freq[answers[i]+1]){
                res += answers[i]+1;
                if(answers[i]==0) continue;
                freq[answers[i]+1]=1;
            }else{
                int key=answers[i]+1;
                freq[key]++;
                int val=freq[key];
                if(key==val){
                    freq.erase(key);
                }
            }
        }
        return res;
    }
};