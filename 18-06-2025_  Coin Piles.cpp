// Problem link    https://www.geeksforgeeks.org/problems/coin-piles5152/1
// Name    Coin Piles



class Solution {
  public:
    int minimumCoins(vector<int>& arr, int k) {
        //CodeGenius
        int n=arr.size();
        
        sort(arr.begin(),arr.end());// sorting the array 
        
        vector<int>pre(n);  // creating prefix sum ;
        
        pre[0]=arr[0];
        
        for(int i=1;i<n;i++)
            pre[i]=pre[i-1]+arr[i];  // value copy in prefixsum
        
        int ans=INT_MAX,prev=0;
        
        for(int i=0;i<n;i++){
            if(i>0) prev=pre[i-1];  // check i>0 then copy prev other not 
            int pos=upper_bound(arr.begin()+i,arr.end(),arr[i]+k)-arr.begin();
            // upper bound return the index of those index which is greater than nums[i]+k;
            int total=pos>0?pre[n-1]-pre[pos-1] : 0;  // if pos is greater than 0 after return the value prefix ke last value or us index se phale wale index ka value 
            int allowed=(n-pos)*(arr[i]+k);  // calculate the required coins
            int extracoins = prev+total-allowed;    // add previous coins of prefix sun before this index and minus the total -allowed value 
            ans=min(ans,extracoins); // each iteration check 
        }
        return ans;
    }
};
