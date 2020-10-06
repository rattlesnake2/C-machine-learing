#include<bits/stdc++.h>
using namespace std;

struct Item { 
	float weight; 
	int value; 
}; 

struct Node { 
	int level;
	float cost, bound, cap; 
	vector<int>res;
	Node(){}
	Node(int l,float c,float b,float cp,vector<int>vec){
		level=l;
		cost=c;
		bound=b;
		cap=cp;
		res=vec;
	}
}; 


void boundAndCost(vector<int>&path,int n, float capacity, vector<Item>&v,float &bound,float &cost) { 
	int i=0;
	while(i<n && capacity>=(path[i]*v[i].weight)){
		bound+=path[i]*v[i].value;
		cost+=path[i]*v[i].value;
		capacity-=(path[i]*v[i].weight);
		i++;
	}
	bound=0-bound;
	cost=0-cost;
	if(i==n)
		return;
	cost-=((capacity/v[i].weight)*v[i].value*path[i]);
} 

void knapsack(float capacity, vector<Item>v , int n) 
{ 
	sort(v.begin(), v.end(), [](Item a, Item b){
		return (a.value / a.weight) > (b.value / b.weight); 
	}); 

	queue<Node>q;
	vector<int>path(v.size(),1);
	float startBound=0,startCost=0;
	boundAndCost(path,n,capacity,v,startBound,startCost);

	Node startNode(-1,startCost,startBound,capacity,path);
	Node answer;
	q.push(startNode);

	while(q.size()){

		auto temp=q.front();
		q.pop();
		if(temp.bound<=startBound){
			startBound=temp.bound;
			answer=temp;
		}
		if(temp.level==(n-1)||temp.cost>startBound)
			continue;
		
		auto vec=temp.res;
		float b=0,c=0;
		if(temp.cap>v[temp.level+1].weight){
			boundAndCost(vec,n,capacity,v,b,c);
			Node left(temp.level+1,c,b,temp.cap-v[temp.level+1].weight,vec);
			q.push(left);
		}
		b=c=0;
		vec[temp.level+1]=0;
		boundAndCost(vec,n,capacity,v,b,c);
		Node right(temp.level+1,c,b,temp.cap,vec);
		q.push(right);
	}
	cout<<endl<<"Optimal Solution: "<<-answer.bound<<endl;
	cout<<"Optimal Selection: ";
	for(auto x:answer.res)
			cout<<x<<" ";
	cout<<endl<<endl;
	cout<<"Items Selected: ";
	for(int i=0;i<answer.res.size();i++)
		if(answer.res[i]==1)
			cout<<"("<<v[i].weight<<","<<v[i].value<<");";
	cout<<endl<<endl; 
} 

int main() 
{ 
	cout<<"Enter the number of items: ";
	int n;
	cin>>n;
    vector<Item>v(n);
    cout<<"Enter the weight and value of items\n";
    for(int i=0;i<n;i++)
        cin>>v[i].weight>>v[i].value;
    cout<<"Enter capacity of knapsack: ";
    float cap;
    cin>>cap;
    knapsack(cap, v , n); 

} 
