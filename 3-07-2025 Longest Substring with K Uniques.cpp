// Problem Name Longest Substring with K Uniques
// Topic  Array + sliding Window
class Solution {
  public:
    int longestKSubstr(string &s, int k) {
       int maximum = -1;
       int start = 0;
       int end = 0;
       unordered_map<char, int> m;
       
       while (end < s.size()) {
           m[s[end]]++;

           while (m.size() > k) {
               m[s[start]]--;
               if (m[s[start]] == 0) {
                   m.erase(s[start]);
               }
               start++;
           }

           if (m.size() == k) {
               maximum = max(maximum, end - start + 1);
           }

           end++;
       }
       
       return maximum;
    }
};
