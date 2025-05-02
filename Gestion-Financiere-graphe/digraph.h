/* 
 * Squelette minimal pour la classe générique Digraph<T> du TP4.
 * TP4 -- Graphes orientés
 * UQAM / Département d'informatique
 * INF3105 - Structures de données et algorithmes (Hiver 2025)
 *
 *	Identification.
 *		
 *		Nom et prénom	: Louisama Adlin
 *		Code permanent	: LOUA20309509
 *
 */
 

#ifndef __DIGRAPH_H__
#define __DIGRAPH_H__

#include <set>
#include <map>
#include <tuple>
#include <assert.h>
//#include <array>
#include <vector>
//#include <deque>
//#include <forward_list>
//#include <list>
//#include <multiset>
//#include <multimap>
//#include <unordered_set>
//#include <unordered_map>
//#include <unordered_multiset>
//#include <unordered_multimap>
//#include <stack>
//#include <queue>
//#include <priority_queue>
#include <limits>

/*
 * 	Remarque.
 *	Tout parcours des structures de données "map" et "set" doit se faire dans	
 *	l'ordre croissant (pour les valeurs numériques) ou l'ordre lexicographique
 *	(pour les caractères ou chaines de caractères). C'est le parcours implémenté
 *	dans le standard C++11 avec le compilateur g++.
 *	Par conséquent, lors de la recherche de circuits, c'est le premier circuit 
 *	induit par parcours en ordre croissant qui sera considéré dans les différents
 *	tests.
 */

template <class T>
class Digraph {
	// Vous n'avez pas le droit de modifier cette interface. Aucun ajout de fonction
	// publique n'est autorisé. Aucune modification des signatures ou des types de
	// retour des déclarations fonctions publiques n'est autorisé.
	public:
		Digraph();
		Digraph(const Digraph & autre);
		~Digraph();
		Digraph<T> & operator = (const Digraph<T> & autre);
		
		/************* Fonctions pour les caractéristiques de graphe *************/
		// Retourne le nombre de sommets du graphe courant.
		int sommets() const;
		// Retourne le nombre d'arcs du graphe courant.
		int arcs() const;
		// Retourne "true" si "u" est un sommet du graphe courant. "false" si 
		// non.
		bool sommet(T u) const;
		// Retourne "true" si "(u,v)" est un arc du graphe courant. "false" si
		// non.
		bool arc(T u, T v) const;

		/***************************** Modificateurs *****************************/
		// Insère le sommet "u" si le graphe ne le contient pas. Ne fait rien
		// si le graphe contient déjà le sommet "u".
		void inserer(T u);

		// Créé un arc entre les sommets "u" et "v" avec le poids "emprunt", 
		// si le graphe ne contient pas l'arc "(u, v)". Ne fait rien si le
		// graphe contient déjà un arc "(u,v)".
		// Si l'arc doit être créé faut s'assurer que,
		// 	- "u" doit être différent de "v",
		// 	- "emprunt" doit être strictement positif,
		// 		- faut arrêter l'exécution avec la fonction "assert" si les 
		// 		deux conditions plus haut ne sont pas satisfaites,
		// 	- si l'arc "(u,v)" existe déjà, peu importe la valeur de "emprunt",
		//	rien ne	sera fait par la fonction inserer.
		// 	- si l'un ou les deux sommets "u" et "v" n'existent pas dans
		// 	le graphe, ils seront crées.
		void inserer(T u, T v, double emprunt);
		
		// Supprime le sommet "u" et tous les arcs qui lui sont incidents.
		void supprimer(T u);
		
		// Supprime l'arc "(u, v)"
		void supprimer(T u, T v);
		
		/*********************** Fonctions financières ***********************/
		// Retourne le montant total que doit rembourser le sommet "u".
		double dette(T u) const;
					
		// Retourne le montant total des remboursements que doit recevoir 
		// le sommet "u".
		double pret(T u) const;
		
		// Réduit les dettes circulaires du sommet "s". Voir plus d'explications
		// et un exemple dans l'énoncé.
		void reduire(T s);


		/******************************** Bonus *******************************/	
		
		// Créé un sous-graphe du graphe courant induit par les sommets du 
		// set "S".
		// Un "sous-graphe induit" par les sommets de "S" est un sous-graphe 
		// formé par les sommets de "S" et TOUS les arcs "e=(u,v)" du graphe 
		// courant tel que "u" et "v" sont TOUS deux des sommets de "S".
		//	- Il faut que tous les sommets listés dans "S" soient des
		//	sommets du graphe courant. Faut arrêter l'exécution avec la 
		//	fonction "assert" dans le cas contraire.
		Digraph<T> cooperative(std::set<T> & S) const;
	
		// De même, retourne le montant total que doivent rembourser tous 
		// les sommets du sous-graphe "SG" envers les autres sommets dans 
		// le reste du graphe courant. Attention, on ne comptabilise pas 
		// les dettes internes à "SG", on comptabilise que les dettes d'un 
		// sommet externe à "SG" vers un sommet interne de "SG".
		double dette(const Digraph<T> & SG) const;

		// De même, retourne le montant total des remboursements que doivent
		// recevoir tous les sommets du sous-graphe "SG" de la part des 
		// autres sommets dans le reste du graphe courant. Attention, on ne 
		// comptabilise pas les remboursements internes à "SG", on 
		// comptabilise que les remboursements d'un sommet interne de "SG" 
		// vers un sommet externe à "SG".
		double pret(const Digraph<T> & SG) const;

		// Réduit les dettes circulaires d'un sous-graphe "SG". Voir plus 
		// d'explications et un exemple dans l'énoncé.
		void reduire(const Digraph<T> & SG);
	
	// Vous n'avez pas le droit de modifier le type de l'attribut "graphe".
	// Vous n'avez pas le droit d'ajouter d'autres attributs privés.		
	private:
		// Par défaut, le "map" et le "set" sont parcourus en ordre croissant, 
		// ils sont ordonnés (standard C++11).
		std::map<T,std::set<std::tuple<T,double>>> graphe;
		
		// Vous pouvez ajouter toutes les fonctions privées que vous estimez
		// nécessaire.

        // Retourne le poids de l'arc entre deux sommets, ou -1 s'il n'existe pas.
        // Sert pour calculer les dettes et reduire les circuits.
        double trouverPoidArc(const T& u, const T& v) const;

        // Trouve un circuit commençant et finissant au meme sommet.
		bool trouverCircuit(T s, std::vector<T>& circuit);

        // Trouver un circuit depuis un sommet donne.
        // Marque les sommets visites pour eviter trop de boucles.
		bool trouverCircuitDepuis(T courant, T depart, std::vector<T>& chemin, std::set<T>& visites);
		
        // Reduit tous les arcs d'un circuit donne en fonction de la plus petite dette.
        // Utilise des iterateurs pour modifier le graphe efficacement.
        void reduireCircuit(const std::vector<T>& circuit);

        // Trouve un chemin qui quitte la cooperative et y revient.
        // Sert à reduire les dettes dans une cooperative de sommets.
        bool trouverCheminCooperative(T courant, const std::set<T>& coop, 
                                    std::vector<T>& chemin, std::set<T>& visites, 
                                    T& arrivee);

        // Reduit toutes les dettes sur un chemin donne en fonction d'une dette minimale.
        // Supprime ou met à jour les arcs entre les sommets du chemin.
        void reduireChemin(const std::vector<T>& chemin, double dette_minimale);

        // Calcule la dette minimale entre tous les arcs d'un chemin.
        // Sert à determiner combien on peut reduire sur tout un circuit.
        double trouverDetteMinimale(const std::vector<T>& chemin) const;

        // Gere la mise a jour speciale d'arcs entre un depart et une arrivee.
        // Utilise apres la reduction d'un chemin pour ajuster les relations entre sommets.
        void traiterArcSpecial(const T& depart, const T& arrivee, double dette_minimale);

};

// À compléter

template <class T>
Digraph<T>::Digraph() {}

template <class T>
Digraph<T>::~Digraph() {}

template <class T>
Digraph<T>::Digraph(const Digraph<T>& autre) {
    graphe = autre.graphe;
}

template <class T>
Digraph<T>& Digraph<T>::operator=(const Digraph<T>& autre) {
    if (this != &autre) graphe = autre.graphe;
    return *this;
}

/************* Fonctions pour les caractéristiques de graphe *************/

template <class T>
int Digraph<T>::sommets() const {
    return graphe.size();
}

template <class T>
int Digraph<T>::arcs() const {
    int total = 0;
    for (typename std::map<T, std::set<std::tuple<T, double>>>::const_iterator iter = graphe.begin(); iter != graphe.end(); ++iter) {
        total += iter->second.size();
    }
    return total;
}

template <class T>
bool Digraph<T>::sommet(T u) const {
    return graphe.find(u) != graphe.end();
}

template <class T>
bool Digraph<T>::arc(T u, T v) const {
    typename std::map<T, std::set<std::tuple<T, double>>>::const_iterator iter_sommet = graphe.find(u);
    if (iter_sommet == graphe.end()) return false;
    for (typename std::set<std::tuple<T, double>>::const_iterator iter_arc = iter_sommet->second.begin(); iter_arc != iter_sommet->second.end(); ++iter_arc) {
        if (std::get<0>(*iter_arc) == v) return true;
    }
    return false;
}

/***************************** Modificateurs *****************************/

template <class T>
void Digraph<T>::inserer(T u) {
    if (!sommet(u)) graphe[u] = std::set<std::tuple<T, double>>();
}

template <class T>
void Digraph<T>::inserer(T u, T v, double emprunt) {
    inserer(u); inserer(v);
    std::set<std::tuple<T, double>>& connexions = graphe[u];
    for (typename std::set<std::tuple<T, double>>::iterator iter = connexions.begin(); iter != connexions.end(); ++iter) {
        if (std::get<0>(*iter) == v) connexions.erase(iter);
            break;
    }
    connexions.insert(std::make_tuple(v, emprunt));
}

template <class T>
void Digraph<T>::supprimer(T u) {
    for (auto& sommet : graphe) {
        std::set<std::tuple<T, double>>& connexions = sommet.second;
        std::set<std::tuple<T, double>> nouvelles_connexions;
        for (const auto& arc : connexions) {
            if (std::get<0>(arc) != u) nouvelles_connexions.insert(arc);
        }
        connexions = std::move(nouvelles_connexions);
    }
    graphe.erase(u);
}


template <class T>
void Digraph<T>::supprimer(T u, T v) {
    typename std::map<T, std::set<std::tuple<T, double>>>::iterator iter_sommet = graphe.find(u);
    if (iter_sommet == graphe.end()) return;
    std::set<std::tuple<T, double>>& connexions = iter_sommet->second;
    for (typename std::set<std::tuple<T, double>>::iterator iter_arc = connexions.begin(); iter_arc != connexions.end(); ++iter_arc) {
        if (std::get<0>(*iter_arc) == v) {
            connexions.erase(iter_arc);
            break;
        }
    }
}

/*********************** Fonctions financières ***********************/

template <class T>
double Digraph<T>::pret(T u) const {
    if (!sommet(u)) return 0.0;
    double total = 0.0;
    typename std::map<T, std::set<std::tuple<T, double>>>::const_iterator iter_sommet = graphe.find(u);
    if (iter_sommet == graphe.end()) return 0.0;
    const std::set<std::tuple<T, double>>& emprunts = iter_sommet->second;
    for (typename std::set<std::tuple<T, double>>::const_iterator iter_emprunt = emprunts.begin(); iter_emprunt != emprunts.end(); ++iter_emprunt) {
        total += std::get<1>(*iter_emprunt);
    }
    return total;
}

template <class T>
double Digraph<T>::dette(T u) const {
    if (!sommet(u)) return 0.0;
    double total = 0.0;
    for (typename std::map<T, std::set<std::tuple<T, double>>>::const_iterator iter_sommet = graphe.begin(); iter_sommet != graphe.end(); ++iter_sommet) {
        const std::set<std::tuple<T, double>>& emprunts = iter_sommet->second;
        for (typename std::set<std::tuple<T, double>>::const_iterator iter_emprunt = emprunts.begin(); iter_emprunt != emprunts.end(); ++iter_emprunt) {
            if (std::get<0>(*iter_emprunt) == u) total += std::get<1>(*iter_emprunt);
        }
    }
    return total;
}

template <class T>
void Digraph<T>::reduire(T s) {
    std::vector<T> circuit;
	int limite = 1000;
    while (trouverCircuit(s, circuit) && limite-- > 0) {
        reduireCircuit(circuit);
        circuit.clear();
    }
}

/******************************** Bonus *******************************/	
template <class T>
Digraph<T> Digraph<T>::cooperative(std::set<T> & S) const {
    Digraph<T> sous_graphe;
    for (const T& u : S) {
        assert(sommet(u));
        sous_graphe.inserer(u);
    }
    for (const T& u : S) {
        auto it = graphe.find(u);
        if (it != graphe.end()) {
            for (const auto& arc : it->second) {
                T v = std::get<0>(arc);
                if (S.find(v) != S.end()) sous_graphe.inserer(u, v, std::get<1>(arc));
            }
        }
    }
    return sous_graphe;
}

template <class T>
double Digraph<T>::dette(const Digraph<T> & SG) const {
    double total = 0.0;
    for (const auto& paire : graphe) {
        T u = paire.first;
        if (!SG.sommet(u)) {
            for (const auto& arc : paire.second) {
                T v = std::get<0>(arc);
                if (SG.sommet(v)) total += std::get<1>(arc);
            }
        }
    }
    return total;
}

template <class T>
double Digraph<T>::pret(const Digraph<T> & SG) const {
    double total = 0.0;
    for (const auto& paire : SG.graphe) {
        T u = paire.first;
        auto it = graphe.find(u);
        if (it != graphe.end()) {
            for (const auto& arc : it->second) {
                T v = std::get<0>(arc);
                if (!SG.sommet(v)) total += std::get<1>(arc);
            }
        }
    }
    return total;
}

template <class T>
void Digraph<T>::reduire(const Digraph<T> & SG) {
    std::set<T> sommets_coop;
    for (const auto& paire : SG.graphe) {
        sommets_coop.insert(paire.first);
    }
    bool chemin_trouve = true;
    int limite = 1000;
    while (chemin_trouve && limite-- > 0) {
        chemin_trouve = false;
        for (const T& depart : sommets_coop) {
            std::vector<T> chemin;
            std::set<T> visites;
            T arrivee;
            if (trouverCheminCooperative(depart, sommets_coop, chemin, visites, arrivee)) {
                chemin_trouve = true;
                double dette_minimale = trouverDetteMinimale(chemin);
                reduireChemin(chemin, dette_minimale);
                traiterArcSpecial(depart, arrivee, dette_minimale);
                break;
            }
        }
    }
}


/******************************** Fonctions privees ajoutees *******************************/

template <class T>
double Digraph<T>::trouverPoidArc(const T& u, const T& v) const {
    typename std::map<T, std::set<std::tuple<T, double>>>::const_iterator iter1 = graphe.find(u);
    if (iter1 == graphe.end()) return -1.0;
    for (typename std::set<std::tuple<T, double>>::const_iterator iter2 = iter1->second.begin(); iter2 != iter1->second.end(); ++iter2) {
        if (std::get<0>(*iter2) == v)
            return std::get<1>(*iter2);
    }
    return -1.0;
}

template <class T>
bool Digraph<T>::trouverCircuitDepuis(T courant, T depart, std::vector<T>& chemin, std::set<T>& visites) {
    visites.insert(courant);
    chemin.push_back(courant);
    typename std::map<T, std::set<std::tuple<T, double>>>::const_iterator iter1 = graphe.find(courant);
    if (iter1 != graphe.end()) {
        for (typename std::set<std::tuple<T, double>>::const_iterator iter2 = iter1->second.begin(); iter2 != iter1->second.end(); ++iter2) {
            const T& sommetCible = std::get<0>(*iter2);
            if (sommetCible == depart && chemin.size() > 1) {
                chemin.push_back(depart); return true;
            }
            if (visites.find(sommetCible) == visites.end()) {
                if (trouverCircuitDepuis(sommetCible, depart, chemin, visites))
                    return true;
            }
        }
    }
    visites.erase(courant);
    chemin.pop_back();
    return false;
}

template <class T>
bool Digraph<T>::trouverCircuit(T s, std::vector<T>& circuit) {
    std::set<T> visites;
    return trouverCircuitDepuis(s, s, circuit, visites);
}

template <class T>
void Digraph<T>::reduireCircuit(const std::vector<T>& chemin) {
    if (chemin.size() < 2) return;
    typename std::vector<T>::const_iterator iter1 = chemin.begin();
    typename std::vector<T>::const_iterator iter2 = iter1; ++iter2;
    double dette_minimale = std::numeric_limits<double>::max();
    while (iter2 != chemin.end()) {
        double poids = trouverPoidArc(*iter1, *iter2);
        if (poids < dette_minimale) dette_minimale = poids;
        ++iter1, ++iter2;
    }
    iter1 = chemin.begin();
    iter2 = iter1, ++iter2;
    while (iter2 != chemin.end()) {
        const T& u = *iter1; const T& v = *iter2;
        std::set<std::tuple<T, double>>& voisins = graphe[u];
        for (typename std::set<std::tuple<T, double>>::iterator iter = voisins.begin(); iter != voisins.end(); ) {
            if (std::get<0>(*iter) == v) {
                double ancienPoids = std::get<1>(*iter);
                iter = voisins.erase(iter);
                double nouveauPoids = ancienPoids - dette_minimale;
                if (nouveauPoids > 0) voisins.insert(std::make_tuple(v, nouveauPoids));
                break;
            } else ++iter;
        
        }
        ++iter1, ++iter2;
    }
}

template <class T>
bool Digraph<T>::trouverCheminCooperative(T courant, const std::set<T>& coop, 
                                         std::vector<T>& chemin, std::set<T>& visites, 
                                         T& arrivee) {
    visites.insert(courant);
    chemin.push_back(courant);
    auto it = graphe.find(courant);
    if (it != graphe.end()) {
        for (const auto& arc : it->second) {
            T v = std::get<0>(arc);
            if (visites.find(v) == visites.end()) {
                if (coop.find(v) == coop.end()) {
                    if (trouverCheminCooperative(v, coop, chemin, visites, arrivee)) {
                        return true;
                    }
                } else if (chemin.size() > 1) {
                    chemin.push_back(v);
                    arrivee = v;
                    return true;
                }
            }
        }
    }
    chemin.pop_back();
    visites.erase(courant);
    return false;
}

template <class T>
double Digraph<T>::trouverDetteMinimale(const std::vector<T>& chemin) const {
    double dette_minimale = std::numeric_limits<double>::max();

    for (int i = 0; i < (int)chemin.size() - 1; ++i) {
        double poids = trouverPoidArc(chemin[i], chemin[i+1]);
        if (poids < dette_minimale) {
            dette_minimale = poids;
        }
    }
    return dette_minimale;
}

template <class T>
void Digraph<T>::reduireChemin(const std::vector<T>& chemin, double dette_minimale) {
    for (int i = 0; i < (int)chemin.size() - 1; ++i) {
        const T& u = chemin[i];
        const T& v = chemin[i+1];

        auto& arcs = graphe[u];
        for (auto iter = arcs.begin(); iter != arcs.end(); ) {
            if (std::get<0>(*iter) == v) {
                double ancien_poids = std::get<1>(*iter);
                iter = arcs.erase(iter);
                double nouveau_poids = ancien_poids - dette_minimale;
                if (nouveau_poids > 0) {
                    arcs.insert(std::make_tuple(v, nouveau_poids));
                }
                break;
            } else {
                ++iter;
            }
        }
    }
}

template <class T>
void Digraph<T>::traiterArcSpecial(const T& depart, const T& arrivee, double dette_minimale) {
    if (depart != arrivee) {
        double poids_arc = trouverPoidArc(depart, arrivee);
        if (poids_arc >= 0) {
            supprimer(depart, arrivee);
            inserer(depart, arrivee, poids_arc + dette_minimale);
        } else {
            poids_arc = trouverPoidArc(arrivee, depart);
            if (poids_arc >= 0) {
                if (poids_arc > dette_minimale) {
                    supprimer(arrivee, depart);
                    inserer(arrivee, depart, poids_arc - dette_minimale);
                } else {
                    supprimer(arrivee, depart);
                    if (dette_minimale > poids_arc) {
                        inserer(depart, arrivee, dette_minimale - poids_arc);
                    }
                }
            } else {
                inserer(depart, arrivee, dette_minimale);
            }
        }
    }
}

#endif
