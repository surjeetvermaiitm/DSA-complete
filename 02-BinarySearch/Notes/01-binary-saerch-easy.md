#### Q1. Binary Search

Link:https://leetcode.com/problems/binary-search/

```CPP
class Solution {
public:
    int search(vector<int>& nums, int target) {
        //p(x)=x>k
        //FFFTT
        //last F
        int n=nums.size();
        int l=0;
        int h=n-1;
        int mid;
        while(l<h){
            mid=l+(h-l+1)/2;
            if(nums[mid]>target){
                h=mid-1;
            }else{
                l=mid;
            }
        }
        return nums[l]==target?l:-1;
    }
};
```

#### Q2. Search Insert Position

Link: https://leetcode.com/problems/search-insert-position/description/

```CPP
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        //P(X)=x<k
        //TTFF
        //First F
        int n=nums.size();
        int l=0;
        int h=n-1;
        int mid;
        while(l<h){
            mid=l+(h-l)/2;
            if(nums[mid]<target){
                l=mid+1;
            }else{
                h=mid;
            }
        }
        return nums[n-1]<target?n:l;

    }
};

```

#### Qn3. Search 2d matrix

Link: https://leetcode.com/problems/search-a-2d-matrix/

```CPP
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //p(x)=x>=k;
        //FFTT
        //first T
        int m=matrix.size();
        int n=matrix[0].size();
        if(m==0 || n==0) return false;
        int l=0;
        int h=m*n-1;
        int mid;
        while(l<h){
            mid=l+(h-l)/2;
            int i=mid/n;
            int j=mid%n;
            if(matrix[i][j]>=target){
                h=mid;
            }else{
                l=mid+1;
            }
        }
        return matrix[l/n][l%n]==target;

    }
};
```

#### Qn 4. Sqrt X

Link:
https://leetcode.com/problems/sqrtx/description/

```CPP
class Solution {
public:
    int mySqrt(int x) {
        // p(x)=x*x<=k
        //TTTFFF
        //Last T
        int l=1,h=x/2,mid;
        if(x<2) return x;
        while(l<h){
            mid=l+(h-l+1)/2;
            if(mid<=x/mid){
                l=mid;
            }else{
                h=mid-1;
            }
        }
        return l;

    }
};
```

#### Qn 5. First bad version

Link: https://leetcode.com/problems/first-bad-version/description/

```CPP
class Solution {
public:
    int firstBadVersion(int n) {
        //FFFTTT
        //First T
        int l=1,h=n,mid;
        while(l<h){
            mid=l+(h-l)/2;
            if(isBadVersion(mid)){
                h=mid;
            }else{
                l=mid+1;
            }
        }
        return l;

    }
};
```

#### Qn 6. Find smallest letter greater than target

Link: https://leetcode.com/problems/find-smallest-letter-greater-than-target/

```CPP
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
```

#### Qn 7. Find minimum in rotated sorted array

Link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/

```CPP
class Solution {
public:
    int findMin(vector<int>& nums) {
        //P(x)=x>arr[n-1]
        //TTTFFF
        //First F

        int n=nums.size();
        int l=0,h=n-1,mid;
        while(l<h){
            mid=l+(h-l)/2;
            if(nums[mid]>nums[n-1]){
                l=mid+1;
            }else{
                h=mid;
            }
        }
        return nums[l];

    }
};

```

#### Q8. Arranging coins

Link: https://leetcode.com/problems/arranging-coins/

```CPP
class Solution {
public:
    int arrangeCoins(int n) {
        //p(x)=x*(x+1)/2 <=n
        //TTTFFF
        //Last T
        long long int l=1,h=n-1,mid;
        while(l<h){
            mid=l+(h-l+1)/2;
            if(mid*(mid+1)/2<=n){
                l=mid;
            }else{
                h=mid-1;
            }
        }

        return l;

    }
};
```

#### Qn 9.
