// Problem Name Check if frequencies can be equal
// Topic  HashMap + Aray

class Solution {
  public:
    bool sameFreq(string& s) {
         vector<int>ans(26,0);   // In question clearly give all character into lowercase English Later 

      // Mapping 
    for(int i=0;i<s.size();i++)
    {
        ans[s[i]-'a']++;
    }
    int one_char=-1;
    for(int i=0;i<ans.size();i++)   // take one value reason if in array if all value is so no need to change simply return the true
    {
       if(ans[i]>0)
       {
           one_char=ans[i];
           break;
       }
    }
    int k=0;
    for( k=0;k<ans.size();k++)    // check if all array value count is same so simply return the true  // dry run     aababb 
    {
        if(ans[k]==0)
        {
            continue;
        }
        if( ans[k]!=one_char)
        {
            break;
        }
    }
    if(k==ans.size())
    {
        return true;
    }
    
    int i=0;
    for( i=0;i<ans.size();i++)  // main logic 
    {
        if(ans[i]==0)    // ans[i]==0 skip 
        {
            continue;
        }
        vector<int>temp(ans.begin(),ans.end());    // agar nhi then all value past in temp and all time decrese one value and check if one time all elements are same then return true; 
                                                   // other return false;
        temp[i]--;
        int value=-1;
        bool flag=false;
        int j=0;
        for( j=0;j<temp.size();j++)
        {
            if(temp[j]==0)
            {
                continue;
            }
            if(temp[j]>0 && flag==false)
            {
                value=temp[j];
                flag=true;
            }
            
            if(temp[j]>0 && temp[j]==value && flag==true)
            {
                value=temp[j];
            }
            else
            {
                break;
            }
        }
        if(j==temp.size())
        {
            return true;
            
        }
        
    }
    return false;
        
    }
};
