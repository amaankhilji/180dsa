
void solve(string s, vector<string>&ans, int index)
{
    //Base Case
    if(index >= s.length())
    {
        ans.push_back(s);
    }
    
    for(int j = index; j < s.length(); j++)
    {
        swap(s[j], s[index]);
        
        //Recursive Call
        solve(s, ans, index+1);
        
        //BackTracking
        swap(s[j], s[index]);
    }
}


vector<string> findPermutations(string &s) {
    vector<string> ans;
    int index = 0;
    solve(s, ans, index);
    return ans;
}
