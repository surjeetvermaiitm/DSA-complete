### Q1. Rabbits in Forest

Link: https://leetcode.com/problems/rabbits-in-forest/description/

```CPP
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
```

Approach 2

```cpp
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
```

```py
class Solution:
    def numRabbits(self, answers: List[int]) -> int:
        # dt={}
        # for n in answers:
        #     dt[n]=1+dt.get(n,0)
        # ans=0
        # for k,v in dt.items():
        #     if k==0:
        #         ans+=v
        #     else:
        #         if v%(k+1)==0:
        #             ans+=(k+1)*(v//(k+1))
        #         else:
        #             ans+=(k+1)*(v//(k+1))+(k+1)
        #     print(ans)
        # return ans
        answers.sort()
        n=len(answers)
        count=0
        i=0
        while i<n:
            count+=answers[i]+1
            temp=answers[i]+1
            while (i<n-1) and (answers[i]==answers[i+1]) and (temp>1):
                temp-=1
                i+=1
            else:
                i+=1
        return count
        # dt={}
        # for n in answers:
        #     dt[n]=1+dt.get(n,0)
        # ans=0
        # for k,v in dt.items():
        #     ans+=(k+1)*(ceil(v/(k+1)))
        # return ans
```

### Q2. Meeting room 2 lintcode

Link: https://aaronice.gitbook.io/lintcode/sweep-line/meeting-rooms-ii
//similar to merge sort

```CPP
class Solution{
    int minMeetingRooms(vector<vector<int>> &intervals){
        vector<int> start,ending;
        for(auto el:intervals){
            start.push_back(el[0]);
            ending.push_bacl(el[1]);

        }
        sort(start.begin(),start.end());
        sort(ending.begin(),ending.end());
        int ans=0;
        int rooms=0;
        int i=0,j=0;

        while(i<start.size() and j<ending.size()){
            if(start[i]<ending[j]){
                //a meeting room started
                rooms++;
                ans=max(ans,room);
                i++;
            }else if(start[i]>ending[j]){
                // a meeting is ending
                rooms--;
                j++;
            }else{
                i++;
                j++;
            }
        }
        return ans;
    }

}

```

Note : for meeting room 1 return ans==1

### Qn3. Merge Interval

Link: https://leetcode.com/problems/merge-intervals/description/

```cpp

```
