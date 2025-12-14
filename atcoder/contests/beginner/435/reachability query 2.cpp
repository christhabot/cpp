#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> connections, revConnections;
vector<bool> black, explored;
vector<int> scc;
vector<bool> sccBlack, reachable;
vector<int> order;
vector<vector<int>> sccGraph, revSccGraph;

void dfs1(int node) {
    explored[node] = true;
    for (int next : connections[node]) {
        if (!explored[next]) {
            dfs1(next);
        }
    }
    order.push_back(node);
}

void dfs2(int node, int comp) {
    scc[node] = comp;
    explored[node] = true;
    for (int next : revConnections[node]) {
        if (!explored[next]) {
            dfs2(next, comp);
        }
    }
}

void propagateBlack(int sccId) {
    if (reachable[sccId]) return;
    reachable[sccId] = true;
    for (int prev : revSccGraph[sccId]) {
        propagateBlack(prev);
    }
}

int main() 
{
    int nodes, edges, temp, temp2, amountq, op, idx;
    scanf("%d %d", &nodes, &edges);
    connections.assign(nodes, vector<int>());
    revConnections.assign(nodes, vector<int>());
    black.assign(nodes, false);
    explored.assign(nodes, false);
    scc.assign(nodes, -1);
    
    for(int i = 0; i < edges; i++)
    {
        scanf("%d %d", &temp, &temp2);
        temp--;
        temp2--;
        connections[temp].push_back(temp2);
        revConnections[temp2].push_back(temp);
    }
    
    for (int i = 0; i < nodes; i++) {
        if (!explored[i]) {
            dfs1(i);
        }
    }
    
    explored.assign(nodes, false);
    int sccCount = 0;
    for (int i = nodes - 1; i >= 0; i--) {
        int node = order[i];
        if (!explored[node]) {
            dfs2(node, sccCount);
            sccCount++;
        }
    }
    
    sccBlack.assign(sccCount, false);
    reachable.assign(sccCount, false);
    sccGraph.assign(sccCount, vector<int>());
    revSccGraph.assign(sccCount, vector<int>());
    
    set<pair<int,int>> edges_set;
    for (int i = 0; i < nodes; i++) {
        for (int next : connections[i]) {
            if (scc[i] != scc[next]) {
                if (edges_set.find({scc[i], scc[next]}) == edges_set.end()) {
                    edges_set.insert({scc[i], scc[next]});
                    sccGraph[scc[i]].push_back(scc[next]);
                    revSccGraph[scc[next]].push_back(scc[i]);
                }
            }
        }
    }
    
    scanf("%d", &amountq);
    while(amountq--)
    {
        scanf("%d %d", &op, &idx);
        idx--;
        if(op == 1)
        {
            black[idx] = true;
            int s = scc[idx];
            if (!sccBlack[s]) {
                sccBlack[s] = true;
                propagateBlack(s);
            }
        }
        else if(op == 2)
        {
            printf("%s\n", reachable[scc[idx]] ? "Yes" : "No");
        }
    }
}