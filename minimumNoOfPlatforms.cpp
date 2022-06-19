int calculateMinPatforms(int at[], int dt[], int n) {
    // Write your code here.
    int count =1,i=1,ans=1,j=0;
    
    sort(at,at+n);
    sort(dt,dt+n);
    while(i<n && j<n)
    {
        if(at[i]<=dt[j])
        {
            count++;
            i++;
        }
        else
        {
            count--;
            j++;
        }
        ans = max(ans,count);
        
    }
    return ans;
    
    
    
    
}
