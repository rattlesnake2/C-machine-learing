#include<bits/stdc++.h>
using namespace std;

void print(int s,int e,int n,vector<vector<int>>&brac,char &name){
    if(s<0||e>n||s>=e)
        return;
    if((e-s)==1){
        cout<<name++;
        return;
    }
    if((e-s)==2){
        cout<<'('<<name++;
        cout<<name++<<')';
        return;
    }
    cout<<'(';
    print(s,brac[s][e],n,brac,name);
    print(brac[s][e],e,n,brac,name);
    cout<<')';
}
long multiply(vector<int>&v,int s,int e,vector<vector<long>>&dp,vector<vector<int>>&brac){
    if(s<0||s>=e||(abs(s-e)==1)){
        return 0;
    }
    if(s==(e-2)){
        return  dp[s][e]=v[s]*v[s+1]*v[e];
    }
    if(dp[s][e]==-1){
        long minCost=INT_MAX;
        for(int r=s+1;r<e;r++){
            long cost=v[s]*v[r]*v[e]+multiply(v,s,r,dp,brac)+multiply(v,r,e,dp,brac);
            if(cost<minCost){
                minCost=cost;
                brac[s][e]=r;
            }
        }
        dp[s][e]=minCost;
    }
    return dp[s][e];
}

int main(){

    int n;
    cout<<"Enter the number of matrices: ";
    cin>>n;
    vector<int>v(n+1);
    cout<<"Enter the  dimensions\n";
    for(int i=0;i<n+1;i++)
        cin>>v[i];
    vector<vector<long>>dp(n+1,vector<long>(n+1,-1));
    vector<vector<int>>brac(n+1,vector<int>(n+1,-1));
    multiply(v,0,n,dp,brac);
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            cout<<dp[i][j]<<"     ";
        }
        cout<<endl;
    }
    char name='A';
    cout<<endl;
    print(0,n,n+1,brac,name);
    cout<<"\nOptimal Cost: "<<dp[0][n]<<endl<<endl;
}