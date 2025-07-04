// Problem Name Subarrays With At Most K Distinct Integers
// Topic    Sliding+Window
class Solution {
  public:
    int countAtMostK(vector<int> &nums, int k) {
        // code here
         unordered_map<int,int>m;
     
     int first=0;
     int second=0;
     int count=0;
     while(second<nums.size())
     {
         m[nums[second]]++;
         while(m.size()>k)
         {
             m[nums[first]]--;
             if(m[nums[first]]==0)
             {
                 m.erase(nums[first]);
                 
             }
             first++;
         }
         count+=second-first+1;
         second++;
     }
     return count;
    }
};
