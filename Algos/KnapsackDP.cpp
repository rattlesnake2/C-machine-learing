#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,cap;
    cout<<"Enter the number of items  ";
    cin>>n;
    cout<<"Enter n items weight and values\n";
    vector<int>value(n),weight(n);
    for(int i=0;i<n;i++)
        cin>>value[i]>>weight[i];
    cout<<"Enter capacity of knapsack ";
    cin>>cap;
    vector<vector<int>>dp(n+1,vector<int>(cap+1));
    vector<vector<char>>dir(n+1,vector<char>(cap+1));
    for(int i=0;i<=n;i++){
        dp[i][0]=0;
        dir[i][0]='o';
    }
    for(int i=0;i<=cap;i++){
        dp[0][i]=0;
        dir[0][i]='o';
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=cap;j++){
            if(j>=weight[i-1] && (dp[i-1][j]<=(dp[i-1][j-weight[i-1]]+value[i-1]))){
                dp[i][j]=dp[i-1][j-weight[i-1]]+value[i-1];
                dir[i][j]='d';
            }
            else{
                dp[i][j]=dp[i-1][j];
                dir[i][j]='u';
            }
        }
    }
    cout<<"Maximum value in knapsack: "<<dp[n][cap]<<endl<<endl;
    
    for(int i=0;i<=n;i++){
        for(int j=0;j<=cap;j++){
            cout<<dp[i][j]<<"|"<<dir[i][j]<<"      ";
        }
        cout<<endl;
    }

    int i=n,j=cap;
    while(i>0&&j>0){
        if(dir[i][j]=='d'){
            cout<<"W->"<<weight[i-1]<<"  V->"<<value[i-1]<<endl;
            j-=weight[i-1];
        }
        i--;
    }
}