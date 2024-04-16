#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;
template <typename T>
class Graph{
    public:
    unordered_map<T, list<T>> adjList;
    void addEdge(T u, T v, bool direction){
        //direction=0->undirected graph
        //direction=1->directed graph
        //create an edge from u to v
        adjList[u].push_back(v);
        if(direction==0){
            //undirected edge
            //create an edge from v to u
            adjList[v].push_back(u);
        }
    }
    void printAdjacencyList(){
        for(auto node: adjList){
            cout<<node.first<<"->";
            for(auto neighbour:node.second){
                 cout<<neighbour<<" ";
            }
            cout<<endl;
        }
    }
    void bfs(int src,unordered_map<int, bool>& visited){
        queue<int> q;
        q.push(src);
        visited[src]=true;

        while(!q.empty()){
            int frontNode=q.front();
            q.pop();
            cout<<frontNode<<", ";
            //insert neighours
            for(auto neighour: adjList[frontNode]){
                if(!visited[neighbour]){
                    q.push(neighbour);
                    visited[neighbour]=true;
                }
            }
        }
    }
    bool chackCyclicUsingBfs(int src,unordered_map<int,bool>& visited){
        queue<int> q;
        unordered_map<int,int>parent;
        q.push(src);
        visited[src]=true;
        parent[src]=-1;

        while(!q.empty()){
            int frontNode=q.front();
            q.pop();
            for(auto nbr: adjList[frontNode]){
                if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr]=true;
                    parent[nbr]=frontNode;
                }
                else {
                    //already visited
                    if(frontNode!=parent[nbr]){
                        //cycle present
                        return true;
                    }
                }
            }
        }
        return false;
    }
    bool CheckCyclicUsingDfs(int Src,unordered_map<int,bool>& visited){
           visited[src]=true;

           for(auto nbr:adjList[src]){
            if(!visited[nbr]){
                bool checkAgekaAns=checkCyclicDfs(nbr,visited,src);
                if(checkAgekaAns==true)
                return true;
            }
            if(visited[nbr] && !=parent){
                //cyclic present
                return true;
            }
           }
           return false;
    }


};
/*unordered_map<int, list<pair<int,int>>> adjList;
    void addEdge(int u, int v, int weight, bool direction){
        //direction=0->undirected graph
        //direction=1->directed graph
        //create an edge from u to v
        adjList[u].push_back({v,weight});
        if(direction==0){
            //undirected edge
            //create an edge from v to u
            adjList[v].push_back({u,weight});
        }
    }
    void printAdjacencyList(){
        for(auto node: adjList){
            cout<<node.first<<"->";
            for(auto neighbour:node.second){
                cout<<"{"<<neighbour.first<<","<<neighbour.second<<"},";
            }
            cout<<endl;
        }
    }
};*/
int main(){
    Graph<int> g;
    int n=5;
    g.addEdge(0,1,0);
    g.addEdge(1,3,0);
    g.addEdge(0,2,0);
    g.addEdge(2,4,0);


    g.printAdjacencyList();
    cout<<endl;


    bool ans=false;
    unordered_map<int,bool>visited;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            ans=g.chackCyclicUsingBfs(i,visited);
            if(ans==true)
            break;
        }
    }
    if(ans==true)
    cout<<" cycle is present"<<endl;
    else
      cout<<"cycle absent"<<endl;
    

    bool ansDfs=false;
    unordered_map<int,bool>visitedDfs;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            ansDfs=g.CheckCyclicUsingDfs(i,visitedDfs);
            if(ansDfs==true)
            break;
        }
    }
    if(ansDfs==true)
    cout<<" cycle is present"<<endl;
    else
      cout<<"cycle absent"<<endl;
    
    
   // Graph<char> g;
   // g.addEdge('a','b',0);
   // g.addEdge('b', 'c',0);
   // g.addEdge('a','c',0);
    //g.printAdjacencyList();
    //directed input
   // g.addEdge(0,1,1);
    //g.addEdge(1,2,1);
    //g.addEdge(0,2,1);
    //cout<<endl;
    //g.printAdjacencyList();


  //directed input
  //g.addEdge(srcNode, destNode, weight, direction);
  // g.addEdge(0,1,5,1);
  // g.addEdge(1,2,8,1);
  // g.addEdge(0,2,6,1);
  // cout << endl;
  // g.printAdjacencyList();




     //undirected edge input
   // g.addEdge(0,1,0);
    //g.addEdge(1,2,0);
    //g.addEdge(0,2,0);
    //cout<<endl;
    //g.printAdjacencyList();
   // int n;
    //cout<<" Enter the number of nodes:"<<endl;
    //cin>>n;

    //int e;
    //cout<<"Enter the number of edge:"<<endl;
    //cin>>e;
    //undirected graph
}

