//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    
    bool isPossible(int A[],int N, int M, int soln){
        int c=1;
        int pageSum=0;
        for(int i=0;i<N;i++){
            if(A[i]>soln){
                return false;
            }
            else if(pageSum + A[i] > soln){
                c++;
                pageSum=A[i];
            if(c>M){
                return false;
            }
            }
            else{
                pageSum+=A[i];
            }
        }
        return true;
    }
    int findPages(int A[], int N, int M) 
    {
        if(M>N) return -1;
        int s=0;
        int sum=0;
        int e=accumulate(A,A+N,sum);
        int ans=-1;
        while(s<=e){
            int mid=(s+e)/2;
            if(isPossible(A,N,M,mid)){
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
            mid=(s+e)/2;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends