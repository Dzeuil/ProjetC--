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

        void print(){
            cout << sizeof(vertice) << endl;
        }
          
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

class Matrix {
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
            matrix.push_back(vector<float>(s, NAN));
        }

        void PCC () {
            Matrix matrik(this->n,this->p);
            for (int k = 0; k < this->n; k++) {
                for(int i = 0; i < this->n; i++) {
                    for(int j = 0; j < this->p; j++){
                        if(!isnan(matrix[i][j]) && !isnan(matrix[k][j]) && !isnan(matrix[i][k])){   // On vérifie que une transition existe bien dans tout les cas testé.
                            if(matrix[i][j] > matrix[i][k] + matrix[k][j]){
                                matrik[i][j] = matrix[i][k] + matrix[k][j];
                            }
                        }
                    }
                }
            }
        }
};
// Virtual pour avoir une liaision dinamique
// throw / try - catch : pour les exceptions.