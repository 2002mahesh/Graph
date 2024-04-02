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

   void shortestPath(map<int,vector<int>>&adjList,int src,int desc)
   {
    map<int,bool>visited;
    map<int,int>parent;
    queue<int>q;
    q.push(src);
    parent[src]=-1;
    visited[src]=true;
     
     while(!q.empty())
     {
         int front=q.front();
         
         q.pop();
    for(auto neigh:adjList[front])
    {
          if(!visited[neigh])
          {
          q.push(neigh);
          parent[neigh]=front;
          visited[neigh]=true;
          
          }
    }
     }

     vector<int>ans;

     while(desc!=-1)
     {
        ans.push_back(desc);
        desc=parent[desc];
     }

     reverse(ans.begin(),ans.end());

     for(auto a:ans)
     cout<<a<<" ";

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


  shortestPath(adjList,0,3);
 

 
}