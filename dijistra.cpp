//Undirected Graph

#include <iostream>
#include<bits/stdc++.h>

using namespace std;

map<int,vector<pair<int,int>>> adjlist(int n,int e, vector<vector<int>>edges)
{
  map<int,vector<pair<int,int>>>adjList;

  for(int i=0;i<e;i++)
    {
       adjList[edges[i][0]].push_back({edges[i][1],edges[i][2]});
       
    }

  return adjList;
}

   void toposort(map<int,vector<pair<int,int>>>&adjList,map<int,bool>&visited,int src,stack<int>&s)
   {
    
       visited[src]=true;
    for(auto neigh:adjList[src])
    {
        if(!visited[neigh.first])
        {
           toposort(adjList,visited,neigh.first,s);
        }
    }

    s.push(src);
   }
vector<int> shortestPath(int n,map<int,vector<pair<int,int>>>&adjList,int src,int dest,stack<int>&s)
{
   vector<int>ans(n,INT_MAX);
   ans[src]=0;

   while(!s.empty())
   {
      int top=s.top();
      s.pop();

      for(auto neigh:adjList[top])
      {
        ans[neigh.first]=min(ans[neigh.first],ans[top]+neigh.second);
      }

   }

   return ans;
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
      int u,v,wt;
      cin>>u>>v>>wt;

      edges.push_back({u,v,wt});
    }
   stack<int>s;
   map<int,bool>visited;
   
  map<int,vector<pair<int,int>>>adjList=adjlist(n,e,edges);
  toposort(adjList,visited,0,s);

  vector<int>ans=shortestPath(n,adjList,0,3,s);


  
  cout<<"shortest path between "<<0<<" and "<<4<<"is "<<ans[4];


 
 

 
}