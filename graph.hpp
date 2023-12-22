    #include <iostream>
    #include <vector>
    #include <cmath>
    #include <fstream>
    #include <queue>
    #include "stack.hpp"

    using namespace std;

    class Edge {
        public: //private apres !!!!!!! et friend
            float val;
            int num;
        public:
            Edge(float val, int num) : val(val), num(num) {
                // this->val = val;
                // val = valu;
                // num = etatf;
            }
    };

    class Vertex {
        private:
        public:
            int num;

            vector<Edge> edges;
            
            Vertex(int num) : num(num){}
            
            void dfs (vector<Vertex>& vertices, vector<bool>& visit) {
                for (Edge& e : edges) {
                    cout << num << " -> " << e.val << " ->" << e.num << std::endl;
                    if (!visit[e.num]) {
                        visit[e.num] = true;
                        vertices[e.num].dfs(vertices,visit);
                    }
                }
            }
    };

    class Graph {
        private:
            vector<Vertex> vertice;
        public:
            bool Visited [sizeof(vertice)] = {false};
            float dist[sizeof(vertice)];
            int pred[sizeof(vertice)];

            void add_vertices(int Vertices){
                vertice.push_back(Vertex(Vertices)); // essayer sans construction de Vertex
            };

            void add_edge(int etati, int etatf, float val) {
                vertice[etati].edges.push_back(Edge(val,etatf));
            };

            void printvector() {
                for (Vertex &v : vertice) {
                    cout << v.num << ": ";
                    for (Edge &e : v.edges) {
                        cout << e.num << "("<<e.val<<") ";
                    }
                    cout << endl;
                }
            }

            void printgraphviz2() {
                string const nomFichier("graphe.dot");
                ofstream fout (nomFichier.c_str());
                if (!fout) {
                    cerr << "Erreur d'ouverture du fichier graphe.dot" << endl;
                    exit(-1);
                }
                fout << "digraph G {" << endl;
                for (Vertex &v : vertice) {
                    fout <<"\t" << v.num << " [label=\"" << v.num << "\"];" << endl;
                }
                fout << "\n";
                for (Vertex &v : vertice) {
                    for (Edge &e : v.edges) {
                        fout << "\t" << v.num << " -> " << e.num << "[label=\"" << e.val << "\"];" << endl;
                    }
                }
                fout << "}" << endl;
                fout.close();
                system("dot -Tpng graphe.dot > graph.png");
            }

            // Dijkstra algorithm
            void shortestPath(int start) {   // The set is filled with the vertex number that is being processed now
                Visited[start]=true;
                cout<<"\nLe plus court chemin de "<<start<<" vers chaque sommet est : \n";
                // A priority queue is used to get vertices in the order of their distance from source vertex.
                priority_queue<pair<float,int>, vector<pair<float,int>>, greater<pair<float,int>>> Q; // Q contains a pair of distance and vertex number
                Q.push({0,start});
                while(!Q.empty()) {
                    int u = Q.top().second;     // Pick the smallest distance vertex from Q[]
                    Q.pop();      // Remove the picked vertex from Q[]
                    for (int i = 0; i < vertice[u].edges.size(); i++) {
                        Edge& edg=vertice[u].edges[i];
                        // If not visited then mark it as visited and enqueue it
                        if (!Visited[edg.num]) {
                            Visited[edg.num] = true;
                            float w = edg.val;
                            Q.push({dist[u] + w, edg.num});
                            dist[edg.num] = dist[u] + w;
                            pred[edg.num] = u;
                        } else if (dist[u]+edg.val < dist[edg.num]) {
                            // Relaxing the edge
                            dist[edg.num] = dist[u] + edg.val;
                            pred[edg.num] = u;
                        }
                    }
                }
            }
            
            // Function to print the constructed distance array
            void printShortestPath(int st) {
                cout << "Distance from " << st << " to all other vertices are:\n";
                for (int i = 0; i < sizeof(vertice); i++)
                    cout << dist[i] << " ";
                cout << endl;
                /*
                This function prints shortest path from src to dest.
                It uses parent[] to build the path.
                */
                printPath(st);
            }

            // Print the path
            void printPath(int dest) {
                Stack s(sizeof(vertice)); // Create a stack
                int temp = dest; // Set the destination city as the last node
                while (temp != -1) { // Run till the source city is reached
                    s.push(temp); // Push the current city to the stack
                    temp = pred[temp]; // Get the predecessor of the current city
                }
                printf("\n%d",dest);
                // All cities must be printed in reverse order
                while (!s.isEmpty()) {
                    printf(" <- %d",s.pop());
                }
            }

            void dfs () {
                vector<bool> visit (vertice.size(), false);
                for (Vertex& v : vertice) {
                    if (!visit[v.num]) {
                        visit[v.num] = true;
                        v.dfs(vertice, visit);
                    }
                }
            }
    };

    /*class Matrix {
        private:
            int n,p;
            vector<vector<float>> matrix;
        public:
            Matrix(int n, int p) {
                this->n = n;
                this->p = p;
                matrix.resize(n, vector<float>(p,NAN));
            }

            void PrintMatrice() {
                for (auto i = 0; i < this->n; ++i){
                    cout << endl;
                    for (auto j = 0; j < this->p; ++j){
                        if (!isnan(matrix[i][j])){
                            cout << matrix[i][j] << " ";
                        } else {
                            cout << "NaN" << " ";
                        }
                    }
                    cout << endl;
                }
            }
            void addarrete(int n, int p, float val) {
                matrix[n][p] = val;
            }
            
            void addsommet(int s) {
                matrix.push_back(s);
            }
    };*/