 /*
  Day 96 : Possibility of finishing all courses given pre-requisites
 */
int Solution::solve(int A, vector<int> &B, vector<int> &C) {
    vector<int> adj[A+1];
    for(int i = 1;i <= A; i++) {
      adj[i].clear();
    }
    for(int i=0;i<B.size();i++){
        adj[B[i]].push_back(C[i]);
    }
    vector<int>indeg(A+1,0);
    for(int u=1;u<A+1;u++){
        // cout<<u<<"->";
        vector<int>::iterator i;
        for(i = adj[u].begin();i!=adj[u].end();i++){
            // cout<<*i<<" ";
            indeg[*i]++;
        }
        // cout<<endl;
    }
    queue<int>q;
    for(int i=1;i<A+1;i++){
        if(indeg[i]==0)
        q.push(i);
    }
    int count = 0;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(auto i = adj[x].begin();i!=adj[x].end();i++){
            indeg[*i]--;
            if(indeg[*i]==0){
                q.push(*i);
            }
        }
        count++;
    }
    // cout<<count;
    if(count!=A){
        return 0;
    }
    return 1;
    
}