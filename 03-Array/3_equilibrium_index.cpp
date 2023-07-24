// Author: Surjeet Kumar Verma
// Link: https://practice.geeksforgeeks.org/problems/equilibrium-index-of-an-array/1?page=10&category%5B%5D=Arrays&sortBy=submissions&utm_source=youtube_practice_channel&utm_medium=collab_fraz_gfgytdescription&utm_campaign=geekweekdsalive

/* You are required to complete this method*/
int findEquilibrium(int A[], int n)
{
  //Your code here
  int sum=0;
  for(int i=0;i<n;i++){
      sum+=A[i];
  }
  int leftsum=0,rightsum=sum;
  for(int i=0;i<n;i++){
      rightsum=rightsum-A[i];
      if(leftsum==rightsum){
          return i;
      }
      leftsum+=A[i];
  }
  return -1;
}