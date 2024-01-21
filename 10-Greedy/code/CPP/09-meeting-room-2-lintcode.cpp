//Link: https://aaronice.gitbook.io/lintcode/sweep-line/meeting-rooms-ii

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

// for meeting room 1 return ans==1