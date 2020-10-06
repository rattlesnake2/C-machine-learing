#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,cap;
    cout<<"Enter the number of items  ";
    cin>>n;
    cout<<"Enter n items values and weights\n";
    vector<vector<int>>v(n,vector<int>(2));
    for(int i=0;i<n;i++)
        cin>>v[i][0]>>v[i][1];
    cout<<"Enter capacity of knapsack ";
    cin>>cap;
    
    sort(v.begin(),v.end(),[](vector<int>v1,vector<int>v2){
        return (v1[0]*1.0/v1[1])>(v2[0]*1.0/v2[1]);
    });

    // for(auto r:v)
    //     cout<<r[0]<<" "<<r[1]<<endl;
    // cout<<endl;

    float maxV=0;
    int i=0;
    while(i<n && cap>0){
        if(v[i][1]<=cap){
            cap-=v[i][1];
            maxV+=v[i][0];
            cout<<"W->"<<v[i][1]<<"  V->"<<v[i][0]<<endl;
        }
        else{
            maxV+=(cap*1.0/v[i][1])*v[i][0];
            cout<<"W->"<<cap<<"  V->"<<(cap*1.0/v[i][1])*v[i][0]<<endl;
            cap=0;
        }
        i++;
    }
    cout<<"Maximum value in knapsack: "<<maxV<<endl<<endl;
    
}