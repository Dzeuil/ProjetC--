#include "graph.hpp"

int main() {
    Graph g;
    g.add_vertices(0);
    g.add_vertices(1);
    g.add_vertices(2);
    g.add_edge(0, 1, 0.2);
    g.add_edge(0, 2, 0.3);
    g.add_edge(1, 0, 3.2);
    g.add_edge(1, 2, 7.3);
    g.printvector();
    g.printgraphviz2();
    g.dfs();
    //g.shortestPath(0);
    g.printShortestPath(0);
    return 0;
}