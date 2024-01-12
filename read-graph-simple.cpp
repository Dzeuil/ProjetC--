#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

void read_graph(std::string filename)
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
        std::cout << "transition " << from << " -(" << value << ")-> " << to << std::endl;
    }
}

int main () {
    read_graph("./ex0.gr");
    return 0;
}
