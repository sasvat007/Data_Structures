#include <iostream>
#include <list>
#include <vector>

using namespace std;

class graph{
    private:
        int vertex;
        vector<list<int>> adjlist;
    public:
        graph(int ver){
            vertex=ver;
            adjlist.resize(vertex);
    }
        void insert(int,int);
        void del(int,int);
        void dis();
        bool search(int,int);
};

int main(){
    int ver;
    cout<<"Enter how many vertex:";
    cin>>ver;
    graph g1(ver);
    int u=0,v=0,loop=0;
    while (loop==0){
        int ch;
        cout<<"1.Insert\n2.Delete\n3.Display\n4.Search\n5.Exit\n";
        cout<<"Enter your choice:";
        cin>>ch;
        switch (ch){
            case 1:
                cout<<"Enter source:";
                cin>>u;
                cout<<"Enter destination:";
                cin>>v;
                g1.insert(u,v);
                break;
            case 2:
                cout<<"Enter source:";
                cin>>u;
                cout<<"Enter destination:";
                cin>>v;
                g1.del(u,v);
                break;
            case 3:
                cout<<"\n";
                g1.dis();
                cout<<"\n";
                break;
            case 4:
                cout<<"Enter the source:";
                cin>>u;
                cout<<"Enter the destination:";
                cin>>v;
                if (g1.search(u,v)){
                    cout<<"\nConnection found\n\n";
                }
                else{
                    cout<<"\nConnection not found\n\n";
                }
                break;
            case 5:
                loop=1;
                break;
            default:
                cout<<"\nInvalid Entry\n\n";
                break;
        }
    }
    
}


void graph::insert(int u,int v){
    if (u<vertex && v<vertex){
        adjlist[u].push_back(v);
        cout<<"\nEdge Added\n\n";
    }
    else{
        cout<<"\nInvalid Entry\n\n";
    }
}


void graph::dis(){
    for (int i=0;i<vertex;i++){
        cout<<i<<"->";
        for (int j:adjlist[i]){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}


void graph::del(int u,int v){
    if (u<vertex && v<vertex){
        adjlist[u].remove(v);
        cout<<"\nEdge deleted\n\n";
    }
    else{
        cout<<"\nInvalid Entry\n\n";
    }
}

bool graph::search(int u,int v){
    for (int j:adjlist[u]){
        if (j==v){
            return true;
        }
    }
    return false;
}