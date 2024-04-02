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

 vector<int> DijistraAlgo(int src,int n,map<int,vector<pair<int,int>>>&adjList)
 {
    vector<int>dist(n,INT_MAX);
    dist[src]=0;
    set<pair<int,int>>s;
     s.insert({0,src});

     while(!s.empty())
     {
        pair<int,int>front=*s.begin();
        s.erase(*s.begin());
        int dis=front.first;
        int node=front.second;

        for(auto neigh:adjList[node])
        {
            if(dist[neigh.first]==INT_MAX)
            {
                dist[neigh.first]=dis+neigh.second;
                s.insert({dist[neigh.first],neigh.first});
            }
            else
            {
                if(dist[neigh.first]>dis+neigh.second)
                {
                    s.erase({dist[neigh.first],neigh.first});
                    dist[neigh.first]=dis+neigh.second;

                }
                
            }
        }
     }


     return dist;

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
   
   
  map<int,vector<pair<int,int>>>adjList=adjlist(n,e,edges);
  
  vector<int> ans=DijistraAlgo(6,6,adjList);

  for(int i=0;i<6;i++)
  cout<<i<<"->"<<ans[i]<<endl;

 
 

 
}