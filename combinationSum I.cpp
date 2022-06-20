void helper(int i,vector<int> arr, int n, int k,vector<vector<int>>&ans, vector<int >&subsets){
    if(i==n){
        if(k==0){
        ans.push_back(subsets);
        }
        return;
    }
    subsets.push_back(arr[i]);
    helper(i+1,arr,n,k-arr[i],ans,subsets);
    
    subsets.pop_back();
    
     helper(i+1,arr,n,k,ans,subsets);
    
}


vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    vector<vector<int>>ans;
    vector<int >subsets;
    helper(0,arr,n,k,ans,subsets);
    return ans;
}
