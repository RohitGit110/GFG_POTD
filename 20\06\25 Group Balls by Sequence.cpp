// PROBLME NAME Group Balls by Sequence
// TOPIC HASMPA+ARRAY

class Solution {
  public:
    bool validgroup(vector<int> &arr, int k) {
        // code here
        
        if(arr.size()%k!=0)
        {
            return false;
        }
        sort(arr.begin(),arr.end());
        
        unordered_map<int,int>m;
        
        for(int i=0;i<arr.size();i++)
        {
            m[arr[i]]++;
        }
       for(int i=0;i<arr.size();i++)
       {
           if(m[arr[i]]==0)
           {
               continue;
           }
           for(int j=0;j<k;j++)
           {
               if(m[arr[i]+j]==0)
               {
                   return false;
               }
               m[arr[i]+j]--;
           }
       }
       return true;
    }
};
