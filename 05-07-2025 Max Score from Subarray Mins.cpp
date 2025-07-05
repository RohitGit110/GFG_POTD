// Problem Name 05-07-2025 Max Score from Subarray Mins.cpp
// Topic Array 
// This question is Mark as Nedium but very tough when i thought using sliding window 

class Solution {
  public:
    int maxSum(vector<int> &arr) {   
      int value=INT_MIN;
      for(int i=1;i<arr.size();i++)
      {
          value=max(value,arr[i-1]+arr[i]);
      }
      return value;
        
    }
};
