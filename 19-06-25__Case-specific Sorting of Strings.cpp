class Solution {
  public:
    string caseSort(string& s) {
        // code here
          
      string l; // create l for storing l case letter ;
      
      string u; // create u for storing upper case letter ;
      
      // line 11 to 21 . If element is lower case than store in lowe case 
      // or upper case 
      for(int i=0;i<s.size();i++)
      {
          if(isupper(s[i]))
          {
              u+=s[i];
          }
          else
          {
              l+=s[i];
          }
      }
      
      sort(l.begin(),l.end());  
      sort(u.begin(),u.end());
     int first=0;
     int second=0;
     // using two pointer 
     for(int i=0;i<s.size();i++)
     {
         if(isupper(s[i]) && first<u.size())
         {
             s[i]=u[first];
             first++;
         }
         else if(islower(s[i]) && second<l.size())
         {
             s[i]=l[second];
             second++;
         }
     }
     return s;
    }
};
