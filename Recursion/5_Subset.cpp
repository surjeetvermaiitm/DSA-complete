// Author: Surjeet Kumar Verma 
// Link: https://leetcode.com/problems/subsets/

/* At any stage of our Recursion, we will have 2 choices only -
a) Pick the i-th Element
b) Don't Pick the i-th Elemenent

As all our elements are Unique, our Subsets generated will be Unique as well
*/

class Solution {
private :

void helper(int i , vector<int> &subSet , vector<int> &nums , vector<vector<int>> &ans)
{
    // Our base case will hit when our i pointer reaches the end of given array nums[]

    if(i == nums.size() )
    {
        ans.push_back(subSet) ;
        return ;
    }

    // We pick i-th Element

    subSet.push_back(nums[i]) ;

    // We ask recursion to do rest of the task
    helper(i + 1 , subSet , nums , ans) ;

    // Backtrack and Undo the change we have done

    subSet.pop_back() ;

    // We don't pick the i-th element

    helper(i + 1 , subSet , nums , ans) ;

    return ;
}

public:
    vector<vector<int>> subsets(vector<int>& nums) {

    vector<vector<int>> ans ;
    vector<int> subSet ;

    helper(0 , subSet , nums , ans) ;

    return ans ;
}
};

/*
Time Complexity : O(2^N)
Space Complexity : O(N)
*/

//approach 2
class Solution {
public:
    vector<vector<int>> helper(vector<int> &v,int i){
        if(i>=v.size()){
            return {{}};
        }
        
        vector<vector<int>> partial_ans=helper(v,i+1);
        
        vector<vector<int>> ans;
        
        for(vector<int> x:partial_ans){
            ans.push_back(x);
        }
        for(vector<int> x:partial_ans){
            x.push_back(v[i]);
            ans.push_back(x);
        }
        return ans;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        return helper(nums,0);
    }
};
/*
Time Complexity : O(2^N)
Space Complexity : O(N)
*/
