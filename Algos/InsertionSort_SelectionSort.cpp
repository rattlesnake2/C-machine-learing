#include<bits/stdc++.h>
using namespace std;

void insertion(vector<int>&v,int n){
    for(int i=1;i<n;i++){
        for(int j=i-1;j>=0;j--){
            if(v[j]>v[j+1])
                swap(v[j],v[j+1]);
            else break;
        }
        for(int x:v)
            cout<<x<<" ";
        cout<<endl;
    }
}

int selection(vector<int>&v,int n){
    for(int i=0;i<n;i++){
        int minI=i;
        for(int j=i+1;j<n;j++){
            if(v[minI]>v[j])
                minI=j;
        }
        swap(v[i],v[minI]);
        for(int x:v)
            cout<<x<<" ";
        cout<<endl;
    }
}

int main(){
    int n;
    cout<<"Enter size and elements of array\n";
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    auto v1=v;
    cout<<"Selection Sort\n\n";
    selection(v,n);
    cout<<"\nInsertion Sort\n\n";
    insertion(v1,n);
    
}
