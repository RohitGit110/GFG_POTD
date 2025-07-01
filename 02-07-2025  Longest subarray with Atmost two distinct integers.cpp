// Problem Name Longest subarray with Atmost two distinct integers
// Topic    Array + Sliding Window
class Solution {
  public:
    int totalElements(vector<int> &nums) {
        // code here
        unordered_map<int,int>m;
    int start=0;
    int end=0;
    int maximum=INT_MIN;
    while(end<nums.size())
    {
        m[nums[end]]++;
        while(m.size()>2)
        {
            m[nums[start]]--;
            if(m[nums[start]]==0)
            {
                m.erase(nums[start]);
            }
            start++;
        }
        maximum=max(maximum,end-start+1);
        end++;
    }
    return maximum;
    }
};
