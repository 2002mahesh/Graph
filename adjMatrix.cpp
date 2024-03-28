#include <iostream>
#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> adjMatrix(int n,int e, vector<vector<int>>edges)
{
  vector<vector<int>>adj(n,vector<int>(n,0));

  for(int i=0;i<e;i++)
    {
      adj[edges[i][0]][edges[i][1]]=1;
      adj[edges[i][1]][edges[i][0]]=1;
    }

  return adj;
}

int main() {
 int n;
  cout<<"Enter the Number of nodes:";
  cin>>n;

  int e;
  cout<<"Enter the Number of Edges:";
  cin>>e;

  vector<vector<int>>edges;

  for(int i=0;i<e;i++)
    {
      int u,v;
      cin>>u>>v;

      edges.push_back({u,v});
    }

  vector<vector<int>>adj=adjMatrix(n,e,edges);

  for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
        cout<<adj[i][j]<<" ";

      cout<<endl;

      
    }
}