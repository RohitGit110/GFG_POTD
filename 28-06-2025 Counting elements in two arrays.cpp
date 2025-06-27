// Problem Name Counting elements in two arrays
class Solution {
  public:
    vector<int> countLessEq(vector<int>& a, vector<int>& b) {
      sort(b.begin(), b.end());

    vector<int> ans;
    for (int i = 0; i < a.size(); i++) {
        int start = 0;
        int end = b.size();
        int index = b.size();
        while (start <= end) {
            int mid = (start + end) / 2;  // Moved inside loop
            if (b[mid] > a[i]) {
                index = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        
        ans.push_back(index);
    }
    return ans;
    }
   
};
