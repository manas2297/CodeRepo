/*
Question: 
Given an array, 
find the nearest smaller element G[i] 
for every element A[i] in the array such that the element has 
an index smaller than i.
*/

vector<int> Solution::prevSmaller(vector<int> &A) {
    stack<int>count;
    vector<int>res(A.size());
    int currMin = A[0];
    for(int i=0;i<A.size();i++){
        while(!count.empty()){
            if(count.top()>=A[i]){
                count.pop();
            }
            else{
                break;
            }
        }
        if(count.size()==0){
            res[i] = -1;
        }else{
            res[i] = count.top();
        }
        count.push(A[i]);
    }
    return res;
}
