#include<bits/stdc++.h>
using namespace std;

int main(){
    cout<<"Enter dimensions of first matrix\t";
    int m,n,u,v;
    cin>>m>>n;
    vector<vector<int>>v1(m,vector<int>(n));
    cout<<"Enter elements of matrix\n";
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            cin>>v1[i][j];

    cout<<"\nEnter dimensions of second matrix\t";
    cin>>u>>v;
    vector<vector<int>>v2(u,vector<int>(v));
    cout<<"Enter elements of matrix\n";
    for(int i=0;i<u;i++)
        for(int j=0;j<v;j++)
            cin>>v2[i][j];
    if(n!=u){
        cout<<"Matrix Cant be multiplied!!";
        return 0;
    }
    vector<vector<int>>v3(m,vector<int>(v,0));

    for(int i=0;i<m;i++){
        for(int j=0;j<v;j++){
            for(int k=0;k<n;k++){
                v3[i][j]+=(v1[i][k]*v2[k][j]);
            }
        }
    }
    cout<<"Resultant matrix:\n";
    for(int i=0;i<m;i++){
        for(int j=0;j<v;j++){
            cout<<v3[i][j]<<" ";
        }
        cout<<endl;
    }
}
