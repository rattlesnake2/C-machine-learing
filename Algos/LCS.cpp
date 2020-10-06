#include<bits/stdc++.h>
using namespace std;
#define uset unordered_set<string>
#define vec vector<vector<vector<char>>>

void generate(string &s1, vec&dir,int i,int j, string s,uset&set){
    if(i==0||j==0){
        reverse(s.begin(),s.end());
        set.insert(s);
        return;
    }
    for(int q=0;q<dir[i][j].size();q++){
        if(dir[i][j][q]=='u')
            generate(s1,dir,i-1,j,s,set);
        else if(dir[i][j][q]=='l')
            generate(s1,dir,i,j-1,s,set);
        else 
            generate(s1,dir,i-1,j-1,s+s1[i-1],set);
    }

}

int main(){
    string s1,s2;
    cout<<"Enter two strings\n";
    cin>>s1>>s2;
    int m=s1.size(),n=s2.size();
    vector<vector<int>>dp(m+1,vector<int>(n+1));
    vec dir(m+1,vector<vector<char>>(n+1,vector<char>()));
    for(int i=0;i<=m;i++){
        dp[i][0]=0;
        dir[i][0].push_back('o');
    }
    for(int i=0;i<=n;i++){
        dp[0][i]=0;
        dir[0][i].push_back('o');
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
                dir[i][j].push_back('d');
            }
            else{
                if(dp[i-1][j]==dp[i][j-1]){
                    dp[i][j]=dp[i-1][j];
                    dir[i][j].push_back('u');
                    dir[i][j].push_back('l');
                }
                else if(dp[i-1][j]>dp[i][j-1]){
                    dp[i][j]=dp[i-1][j];
                    dir[i][j].push_back('u');
                }
                else{
                    dp[i][j]=dp[i][j-1];
                    dir[i][j].push_back('l');
                }
                
            }
        }
    }
    cout<<"Length of Longest Common Subsequence: "<<dp[m][n]<<endl<<endl;
    
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    uset set;
    for(int i=0;i<=m;i++)
        for(int j=0;j<=n;j++)
            generate(s1,dir,i,j,"",set);
    
    cout<<"\nCommon Subsequences\n";
    for(auto s:set)
        if(s.length()!=dp[m][n])
            cout<<s<<" ";
    cout<<endl;
    for(auto s:set)
        if(s.length()==dp[m][n])
            cout<<s<<" ";

}