#include <iostream>
using namespace std;

const int N= 1e3+10;
int graph[N][N];

int main() {
    int n, m;
    cout << "Enter the number of nodes (n): ";
    cin >> n;
    cout << "Enter the number of edges (m): ";
    cin >> m;

    cout << "Enter the edges (u v) one by one:\n";
    for (int i = 0; i < m; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1][v2] = 1;
        graph[v2][v1] = 1;
    }
    cout << "Adjacency Matrix:\n";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<graph[i][j]<<" ";
		}
		cout<<"\n";
	}
}
//input 3 2
//      1 0
//      2 1