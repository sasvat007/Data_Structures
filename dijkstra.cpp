#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

class graph{
    private:
        int v;
        vector<vector<pair<int,int>>> adjlist;
    public:
        graph(int ver){
            v=ver;
            adjlist.resize(v);
        }
        void addedge(int,int,int);
        void display();
        void dijkstra(int);
};

int main(){
    int vertex;
    cout<<"Enter how many vertex:";
    cin>>vertex;
    graph g1(vertex);
    int src=0,des=0,wei=0,loop=0;
    while (loop==0){
        int ch;
        cout<<"1.Add edges\n2.Display\n3.Dijkstra\n4.Exit\n";
        cout<<"Enter your choice:";
        cin>>ch;
        switch(ch){
            case 1:
                cout<<"Enter source:";
                cin>>src;
                cout<<"Enter destination:";
                cin>>des;
                cout<<"Enter weight:";
                cin>>wei;
                g1.addedge(src,des,wei);
                break;
            case 2:
                g1.display();
                break;
            case 3:
                cout<<"Enter source:";
                cin>>src;
                g1.dijkstra(src);
                break;
            case 4:
                loop=1;
                break;
            default:
                cout<<"\nInvalid Entry\n\n";
                break;
        }
    }

}


void graph::addedge(int src,int des,int wei){
    if (src<v && des<v){
        adjlist[src].push_back({des,wei});
        //adjlist[des].push_back({src,wei});
    }
    else{
        cout<<"\nInvalid Entry\n\n";
    }
}

void graph::display(){
    for (int i=0;i<v;i++){
        cout<<i<<"->";
        for (const auto& edge: adjlist[i]){
            cout << "(" << edge.first << ", weight=" << edge.second << ") ";
        }
        cout<<endl;
    }
}

void graph::dijkstra(int src){
    vector<int> dist(v,INT_MAX);
    dist[src]=0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; //min heap
    pq.push({0,src});
    
    while(!pq.empty()){
        int u=pq.top().second;
        pq.pop();
        for (const auto& edge: adjlist[u]){
            int vert=edge.first;
            int w=edge.second;
            if (dist[vert]>dist[u]+w){
                dist[vert]=dist[u]+w;
                pq.push({dist[vert],vert});
            }
        }
    }
    for (int i=0;i<v;i++){
        if (dist[i]==INT_MAX){
            cout<<"INF";
        }
        else{
            cout<<dist[i];
        }
        cout<<"\n";
    }
}