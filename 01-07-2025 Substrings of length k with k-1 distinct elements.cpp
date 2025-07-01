// Problem Name Substrings of length k with k-1 distinct elements
// Topic  Sliding Window 
class Solution {
  public:
    int substrCount(string &s, int k) {
     
    int first=0;   // set first into index 0;
    int second=0; // set second into index 0;
    vector<int>temp(26,0);
    int count=0;
    while(second<s.size())
    {
        temp[s[second]-'a']++;   // count the value temp; 
        int value=0;
        if(second-first+1>=k)
        {
          
            for(int j=0;j<temp.size();j++)
            {
                if(temp[j]>0)
                {
                    value++;
                }
                
                
            }
             if(value==k-1)
        {
            count++;
        }
            temp[s[first]-'a']--;
            first++;
        }
       
     
        second++;
    }
    return count;
        
    }
};
