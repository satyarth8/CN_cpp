#include <bits/stdc++.h>


using namespace std;
const int N= 1e3+10;

vector<int> g[N];

bool vis[N]; //visited

void dfs(int vertex)
{
	cout<<vertex<<endl;
	//Take action on vertex after entering the vertex
	vis[vertex]=true;
	for(int child:g[vertex])
	{
		cout<<"Par "<<vertex<<" ,child "<<child<<endl;
		//take action on child before entering child node
		if(vis[child]) continue;
		dfs(child);
		//Take action on child after exiting child node
	}

	//Take action on vertex before exiting the vertex
}

int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int v1,v2;
		cin>>v1>>v2;
		g[v1].push_back(v2);
		g[v2].push_back(v1);
	}
	dfs(0);
}

// input 

/*
3 2
1 0
2 1 */
