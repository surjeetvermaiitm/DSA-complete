//Link: https://leetcode.com/problems/boats-to-save-people/
//approach 1
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
       
    
        sort(people.begin(),people.end());
        
        int i = 0, j = people.size() - 1,cnt = 0;
        
        while(i <= j)
        {   
           
            if(people[i] + people[j] <= limit)
            {
                ++i;
                --j;
            }

            else
                --j;
            
            ++cnt; 
        }
        
        return cnt;
        
    }
	
};
//
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
       
    
        sort(people.begin(),people.end());
        
        int i = 0, j = people.size() - 1,boat = 0;
        
        while(i <= j){   
            if(people[i] + people[j] <= limit){
                i++;
                j--;
            }
            else{
                j--;
            }
            boat++;
        }
        return boat; 
    }
	
};