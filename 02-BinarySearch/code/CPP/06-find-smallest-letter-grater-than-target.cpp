//Link: https://leetcode.com/problems/find-smallest-letter-greater-than-target/

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        //p(x)=x>k
        //FFFTTT
        //First T
        int n=letters.size();
        int l=0,h=n-1,mid;
        while(l<h){
            mid=l+(h-l)/2;
            if(letters[mid]>target){
                h=mid;
            }else{
                l=mid+1;
            }
            
        }
        return letters[l]>target?letters[l]:letters[0];
        
    }
};