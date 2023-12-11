#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>

using namespace std;

class Edge {
    private:
    public:
        float val;
        int num;
        Edge(float valu, int etatf) {
            val = valu;
            num = etatf;
        };
};

class Vertex {
    private:
    public:
        int num;
        vector<Edge> edges;
        Vertex(int numb) {
            num = numb;
        };
};

class Graph {
    private:
        vector<Vertex> vertice;
    public:
        bool Visited [sizeof(vertice)] = {false};

        void add_vertices(int Vertices){
            vertice.push_back(Vertex(Vertices));
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
                fout << v.num << " [label=\"" << v.num << "\"];" << endl;
            }

            for (Vertex &v : vertice) {
                for (Edge &e : v.edges) {
                    fout << "\t" << v.num << " -> " << e.num << "[label=\"" << e.val << "\"];" << endl;
                }
            }
            fout << "}" << endl;
            fout.close();
            system("dot -Tpng graphe.dot > graph.png");
        }
        
        Vertex& get_vertex(int num) {
            for(Vertex &vertex : vertice) {
                if(vertex.num == num) {
                    return vertex;
                }
            }
        }

        void deep_search (Vertex vertice) {
            cout << vertice.num << endl;
            for(Edge &e : vertice.edges) {
                Vertex &prochain = get_vertex(e.num);
                if(!Visited[prochain.num]){
                    Visited[prochain.num]=true;
                    deep_search(prochain);
                }
            }
        };
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