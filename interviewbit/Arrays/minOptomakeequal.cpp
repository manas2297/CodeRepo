/*
Given a matrix of integers A of size N x M and an integer B.
 In a single operation, B can be added to or subtracted from any element of the matrix. Find and return the minimum number of operations required to make all the elements of the matrix equal and if it impossible return -1 instead.
 NOTE: Rows are numbered from top to bottom and columns are numbered from left to right.  
*/
int Solution::solve(vector<vector<int> > &A, int k) {
    int n = A.size();
    int m = A[0].size();
    
    vector<int>a(n*m,0);
    long long y = (INT_MAX/k)*k;
    int mod = (y+A[0][0])%k;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            a[i*m+j] = A[i][j];
            if((A[i][j]+y)%k!=mod)
                return -1;
        }
    }
    sort(a.begin(),a.end());
    int median = a[(n*m)/2];
    int minOp = 0;
    for(int i=0;i<n*m;i++){
        minOp+=abs(a[i]-median)/k;
    }
    if((n*m)%2==0){
        int med2 = a[(n*m)/2];
        int minOp2=0;
        for(int i=0;i<n*m;i++){
            minOp2 += abs(a[i]-med2)/k;
        }
        minOp = min(minOp,minOp2);
    }
    return minOp;
}
