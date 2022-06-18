int removeDuplicates(vector<int> &a, int n) {
    int ct=1;
	for(int i=1;i<n;i++){
        if(a[i]!=a[i-1]){
            ct++;
        }
    }
    return ct;
}
