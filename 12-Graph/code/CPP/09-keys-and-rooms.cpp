//Link: https://leetcode.com/problems/keys-and-rooms/description/

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int> visited;
        queue<int> q;
        q.push(0);
        visited.insert(0);
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            for(int nbr:rooms[curr]){
                if(visited.count(nbr)==0){
                    q.push(nbr);
                    visited.insert(nbr);
                }
            }
            
        }
        return visited.size()==rooms.size();
        
    }
};