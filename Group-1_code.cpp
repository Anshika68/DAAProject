#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > g;
bool visit[10001];
int i,j;
vector<int> dominant(int v,int e)
{
   vector<int> Set;
   //Take any edge e graph connecting the vertices i.e.; X and Y.
   for(i=0;i<v;i++)
   {
      if(!visit[i])
      {
         Set.push_back(i); //Add vertex
         visit[i]=true;
         for(j=0;j<(int)g[i].size();j++)
         {
            if(!visit[g[i][j]])
            {
               visit[g[i][j]]=true;
               break;
            }
         }
      }
   }
   return Set;
}
int main() {
   int v,e,a,b;
   cout<<"Enter number of vertices:";
   cin>>v;
   cout<<"Enter number of Edges:";
   cin>>e;
   g.resize(v);
   memset(visit,0,sizeof(visit)); //set all index value of an array as 0
   for(i=0;i<e;i++)
   {
      cout<<"Enter the end-points of edge "<<i+1<<" : ";
      cin>>a>>b;
      a--; b--;
      g[a].push_back(b);
      g[b].push_back(a);
   }
   vector<int> Set = dominant(v,e);
   cout<<"The Dominant Set is:\n";
   for(i=0;i<(int)Set.size();i++)
      cout<<Set[i]+1<<" ";
   return 0;
}
