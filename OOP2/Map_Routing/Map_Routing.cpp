#include <bits/stdc++.h>
#define MAX_DISTANCE 1000000
using namespace std;

const int N=100;

class DirectedEdge{
    private:
        int v;
        int w;
        double weight;
    public:
        DirectedEdge(){};
        DirectedEdge(int v, int w, double weight){
            this->v = v;
            this->w = w;
            this->weight = weight;
        }
        double weight(){
            return weight;
        }
        int from(){
            return v;
        }
        int to(){
            return w;
        }
        void show(){
            cout<<v<<"->"<<w<<" "<<weight<<endl;
        }
};

typedef struct BagNode{
    DirectedEdge e;
    struct BagNode *next;
}Bag;

class EdgeWeightedDigragh{
    private:
        int V;
        int E;
        Bag *adj[N];
    public:
        EdgeWeightedDigragh(){};
        EdgeWeightedDigragh(int V){
            this->V = V;
            this->E = 0;
            for(int v = 0; v < V; v++){
                adj[v]->next = NULL;
            }
        }
        int Vcount(){
            return V;
        }
        int Ecount(){
            return E;
        }
        void addEdge(DirectedEdge e){
            for(int i = 0; i < V; i++){
                if(i == e.from()) {
                    Bag *tmp;
                    for(tmp = adj[i]; tmp->next!=0; tmp = tmp->next){
                    }
                    Bag *p = new Bag;
                    p->next = NULL;
                    p->e = e;
                    tmp->next = p;
                    E++;
                }
                break;
            }
        }
};

typedef struct DISTANCE{
    int v;
    double dist;
}Dist;

struct cmp{
    bool operator()(Dist a, Dist b){
        return a.dist < b.dist;
    }
};

class DijkstraSP{
    private:
        DirectedEdge edgeTo[N];
        Dist distTo[N];
        priority_queue<Dist, vector<Dist>, less<double>> pq;
    public:
        DijkstraSP(EdgeWeightedDigragh G, int s){
            for(int v = 0; v < G.Vcount(); v++){
                distTo[v].v=v;
                distTo[v].dist=MAX_DISTANCE;
            }
            distTo[s].dist = 0.0;
            pq.push(distTo[s]);
              
        }

};