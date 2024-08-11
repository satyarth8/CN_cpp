#include <bits/stdc++.h>


using namespace std;
const int N= 1e3+10;
int graph[N][N];


int main() {
	int n,m;
	cin>>n>>m;
	vector <int> graph2[n];
	for(int i=0;i<m;i++)
	{
		int v1,v2;
		cin>>v1>>v2;

		graph2[v1].push_back(v2);
		graph2[v2].push_back(v1);
		// bi directional hai sara edge
	}
	for(int i=0;i<n;i++)
	{
		cout<<i;
		for(auto x:graph2[i])
		{
			cout<<" -> "<<x;
		}
		cout<<"\n";
	}

}

/* 
input
3 2
1 0
2 1
*/