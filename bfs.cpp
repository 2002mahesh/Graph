//Undirected Graph

#include <iostream>
#include<bits/stdc++.h>

using namespace std;

map<int,vector<int>> adjlist(int n,int e, vector<vector<int>>edges)
{
  map<int,vector<int>>adjList;

  for(int i=0;i<e;i++)
    {
       adjList[edges[i][0]].push_back(edges[i][1]);
       adjList[edges[i][1]].push_back(edges[i][0]);
    }

  return adjList;
}

void BFS(int n,map<int,vector<int>> adjlist,int src)
{
    queue<int>q;
    map<int,bool>visited;
    q.push(src);
    visited[src]=true;

    while(!q.empty())
    {
        int front=q.front();
        q.pop();
        cout<<front<<" ";
        for(auto neigh:adjlist[front])
        {
            if(!visited[neigh])
            {
                visited[neigh]=true;
            q.push(neigh);
            }
        }
    }

    
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

  map<int,vector<int>>adjList=adjlist(n,e,edges);
 

 BFS(n,adjList,0);
 }
