#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <queue>
#include "stack.hpp"
#include <sstream>
#include <string>

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

         Matrix (const std::string& filename);

        void PrintMatrice(ostream& os = cout) const {
            for (auto i = 0; i < this->n; ++i){
                os << endl;
                for (auto j = 0; j < this->p; ++j){
                    if (!isnan(matrix[i][j])){
                        os << matrix[i][j] << "\t";
                    } else {
                        os << "NaN" << "\t";
                    }
                }
                os << endl;
            }
        }

        void addarrete(int n, int p, float val) {
            matrix[n][p] = val;
        }
            
        /*void addsommet(int s) {
            matrix.push_back(vector<float>(s, NAN));
        }*/

        Matrix PCC () {
            Matrix A = *this;
            //parcourir la diagonale et mettre 0 dedans
            for (int k = 0; k < this->n; k++) {
                A.matrix[k][k] = 0;
            }
            // On remplace les NAN par des Infini
            for(int i = 0; i < this->n; i++) {
                for(int j = 0; j < this->p; j++){
                    if(isnan(A.matrix[i][j])) {
                        A.matrix[i][j] = INFINITY;
                    }
                }
            }
            for (int k = 0; k < this->n; k++) {
                for(int i = 0; i < this->n; i++) {
                    for(int j = 0; j < this->p; j++){
                        if(A.matrix[i][j] > A.matrix[i][k] + A.matrix[k][j]){
                            A.matrix[i][j] = A.matrix[i][k] + A.matrix[k][j];
                        }
                    }
                }
            }
            return A;
        }
};
// Virtual pour avoir une liaision dinamique
// throw / try - catch : pour les exceptions.


Matrix::Matrix (const std::string& filename)
{
    // La première ligne du fichier filename contient le nombre de sommets.
    // Les autres lignes contiennent les transitions entre les sommets du graphe.
    // Une transition est un triplet: from to value
    //     où from est le sommet de départ (un entier)
    //        to est le sommet d'arrivée   (un entier)
    //        value est la valeur réelle de la transition entre from et to.

    // On ouvre le fichier en lecture.
    std::ifstream input_file(filename);

    // Si il y a eu un problème lors de l'ouverture du fichier:
    if (!input_file.is_open())
    {
        // là on affiche simplement un message et on sort de la fonction
        std::cout << "Cannot open file " << filename << std::endl;
        return; // on termine la fonction
    }

    // On va lire le fichier ligne par ligne en mettant chaque ligne dans une std::string.
    std::string line;

    // On lit la première ligne du fichier qui doit contenir le nombre de sommets du graphe.
    // Si il n'y a pas de lignes dans le fichier getline retourne false et on lance une exception.
    if (!getline(input_file, line))
    {
        std::cout << "File " << filename << " is empty" << std::endl;
        return; // on termine la fonction
    }
    // La std::string line contient un entier.
    // On va transformer la string en un entier (fonction std::stoi string to integer)
    // et mettre l'entier dans la variable nb_vertices
    int nb_vertices = 0;
    // là je considère que la traduction s'est bien passée
    nb_vertices = std::stoi(line);
    this->n = nb_vertices;
    this->p = nb_vertices;
    matrix.resize(n, vector<float>(p,NAN));
    // On lit toutes les lignes du fichier: quand il n'y en aura plus, getline retournera false.
    // On lit la ligne et on met son contenu dans la variable line.
    while (getline(input_file, line))
    {
        // Dans line, on sait qu'on a deux int et un double.
        // Pour extraire ces trois nombres, on initialise sur cette string, un objet de type istringstream.
        // Dans lequel on va pouvoir lire avec, l'opérateur >>, nos 3 nombres.
        std::istringstream iss(line);
        int from, to;
        double value;
        iss >> from >> to >> value;
        // On met la transition dans le graphe.
        matrix[from][to] = value;
    }
}

ostream& operator<< (ostream& os, const Matrix& m) {
    m.PrintMatrice(os);
    return os;
}