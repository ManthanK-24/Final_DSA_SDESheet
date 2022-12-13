//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int merge(long long arr[], long long tmp[], int l,int m,int r)
    {
        int i = l;
        int j = m;
        int k = l;
        long long int invcnt = 0;
        while(i<m && j<=r)
        {
            if(arr[i]<=arr[j])
            {
                tmp[k++] = arr[i++];
            }
            else
            {
                invcnt += m-i;
                tmp[k++] = arr[j++];
            }
        }
        while(i<m)tmp[k++] =arr[i++];
        while(j<=r)tmp[k++] = arr[j++];
        for(int x=l;x<=r;x++)arr[x] = tmp[x];
        return invcnt;
        
    }
    long long int mergeSort(long long arr[], long long tmp[],int l,int r)
    {
        if(l>=r)return 0;
        long long int invcnt = 0;
        int mid = l + (r-l)/2;
        invcnt += mergeSort(arr,tmp,l,mid);
        invcnt += mergeSort(arr,tmp,mid+1,r);
        invcnt += merge(arr,tmp,l,mid+1,r);
        return invcnt;
    }
    long long int inversionCount(long long arr[], long long n)
    {
        // Your Code Here
        long long tmp[n+1];
        return mergeSort(arr,tmp,0,n-1);
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends