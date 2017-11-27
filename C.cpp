#include <bits/stdc++.h>

using namespace std;

vector< vector <int> > graph(100001);
int A[100001], dist[100001];

int main(void){

	int n, m;
	cin >> n >> m;

	for(int i=1; i<=n; i++){
		cin >> A[i]; 
	}
	for(int i=0; i<m; i++){
		int aux1, aux2;
		cin >> aux1 >> aux2;
		graph[aux1].push_back(aux2);
		graph[aux2].push_back(aux1);
	}
	int conComp=0;
	long long int ans=0;
	queue<int> bfs;
	fill(dist, dist+100001, 0);
	for(int i=1; i<=n; i++){
		if(dist[i]==0){
			dist[i]=1;
			conComp++;
			int mini=A[i];
			bfs.push(i);
			while(!bfs.empty()){
				int v=bfs.front();
				bfs.pop();
				for(int j=0; j<graph[v].size(); j++){
					int next=graph[v][j];
					if(dist[next]==0){
						dist[next]=1;
						mini=min(mini, A[next]);
						bfs.push(next);
					}
				}
			}
			ans+=mini;
		}
	}
	cout << ans << "\n";


	return 0;
}