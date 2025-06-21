// PROBLEM NAME Police and Thieves
// TOPIC=  TWO POINTER + GREEDY
class Solution {
  public:
    int catchThieves(vector<char> &arr, int k) {
        int police=0;
        int theif=0;
        int n=arr.size();
        int count=0;

        for(int i=0;i<arr.size();i++)   // Pointing index of p 
        {
            if(arr[i]=='P')
            {
                police=i;
                break;
            }
        }

        for(int i=0;i<arr.size();i++)  // Pointing index of T
        {
            if(arr[i]=='T')
            {
                theif=i;
                break;
            }
        }
        if(arr[police]!='P' || arr[theif]!='T')   // when P or T is not present in array then return 0;
        {
            return 0;
        }

        while(police<n && theif<n )   // Main logic 
        {
            if(abs(police-theif)<=k)    // difference of these index is smaller then k 
            {
                count++;
                police++;
                theif++;

                
                while(police<n && arr[police]!='P')   // poiting index of P
                {
                    police++;
                }
                while(theif<n && arr[theif]!='T')    // poinging index of T
                {
                    theif++;
                }
            }
            else if(police<theif)                  // police < theif means is not in range   P P P T and k=2 if Polic  is pointing 0 index and theif  is pointing 3 index  
            {
                police++;
                while(police<n && arr[police]!='P')  //  poiting index of P
                {
                    police++;
                }
            }
            else
            {
                theif++;
                while(theif<n && arr[theif]!='T')  //  poiting index of P
                {
                    theif++;
                }
            }
        }

        return count;
    }
};
