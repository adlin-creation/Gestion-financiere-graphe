/* 
 * Tests pour la classe générique Digraph<T> du TP4.
 * TP4 -- Graphes orientés
 * UQAM / Département d'informatique
 * INF3105 - Structures de données et algorithmes (Hiver 2025)
 */
 
#include "digraph.h"
#include <iostream>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"

int main() {
	int erreur = 0, som = 15, arr = 34;
	Digraph<std::string> graphe;
        std::string vertices [] = {"BIC","BMO","BNP","ATB","BEA","AXA","NBG",
                "BOC","RBC","BOA","LCL","BNS","CIC","BNC", "ING"};
        std::string arcs [] = {"NBG","LCL","NBG","AXA","LCL","RBC","LCL","BOA",
                "LCL","BNS","BNS","BOA","BNS","BIC","BNS","CIC","CIC","LCL",
                "CIC","ING","ATB","CIC","ATB","BIC", "ATB","BNP","ING","ATB",
                "ING","BNC","BNC","NBG","BNC","BEA","BOC","NBG","BOC","AXA",
                "BNP","BMO","BNP","BEA","BIC","BMO","BIC","BNP","BMO","BOA",
                "BMO","NBG","BMO","AXA","BOA","RBC","BOA","NBG","RBC","NBG",
                "BEA","AXA","BEA","BOC","BEA","ING","BEA","ATB","AXA","BNP"};
        double emprunts [] = {5320,1500,4420,3900,8010,6370,5320,2313,5500,4200,
                7622,1700,3050,1700,1302,4710,4500,1740,2200,4000,5000,3012,3220,
                2410,3240,3440,5100,7400,3800,1100,3900,9390,2100,9200};
	for(int i = 0, j = 0; i < arr && j < 2 * arr; i++, j += 2)
		graphe.inserer(arcs[j], arcs[j + 1], emprunts[i]);
	if(graphe.sommets() != som) {
		std::cerr << RED << "ECHEC - I" << RESET << std::endl;
		erreur++;
	}
	if(graphe.arcs() != arr) {
		std::cerr << RED << "ECHEC - II" << RESET << std::endl;
		erreur++;
	}
	std::set<std::string> S({"BIC", "BMO", "BNP", "BEA", "AXA", "ATB"});
	Digraph<std::string> sous_graphe = graphe.cooperative(S);
	if(sous_graphe.sommets() != 6) {
		std::cerr << RED << "ECHEC - III" << RESET << std::endl;
		erreur++;
	}
	if(sous_graphe.arcs() != 10) {
		std::cerr << RED << "ECHEC - IV" << RESET << std::endl;
		erreur++;
	}
	int old_erreur = erreur;
	for(std::set<std::string>::iterator i = S.begin(); i != S.end(); ++i)
		if(!sous_graphe.sommet(*i))
			erreur++;
	if(old_erreur != erreur) {
		std::cerr << RED << "ECHEC - V" << RESET << std::endl;
		erreur++;
	}
	if(!sous_graphe.arc("ATB", "BIC") ||
			!sous_graphe.arc("ATB", "BNP") ||
			!sous_graphe.arc("AXA", "BNP") ||
			!sous_graphe.arc("BEA", "ATB") ||
			!sous_graphe.arc("BEA", "AXA") ||
			!sous_graphe.arc("BIC", "BMO") ||
			!sous_graphe.arc("BIC", "BNP") ||
			!sous_graphe.arc("BMO", "AXA") ||
			!sous_graphe.arc("BNP", "BEA") ||
			!sous_graphe.arc("BNP", "BMO")) {
		std::cerr << RED << "ECHEC - VI" << RESET << std::endl;
		erreur++;
	}
	if(sous_graphe.arc("NBG", "AXA") ||
			sous_graphe.arc("BOC", "AXA") ||
			sous_graphe.arc("BMO", "BOA") ||
			sous_graphe.arc("BMO", "NBG") ||
			sous_graphe.arc("BNS", "BIC") ||
			sous_graphe.arc("ATB", "CIC") ||
			sous_graphe.arc("ING", "ATB") ||
			sous_graphe.arc("BEA", "ING") ||
			sous_graphe.arc("BNC", "BEA") ||
			sous_graphe.arc("BEA", "BOC")) {
		std::cerr << RED << "ECHEC - VII" << RESET << std::endl;
		erreur++;
	}
	graphe.supprimer("BNP");
	if(sous_graphe.sommets() != 6 || sous_graphe.arcs() != 10) {
		std::cerr << RED << "ECHEC - VIII" << RESET << std::endl;
		erreur++;
	}
	sous_graphe.supprimer("BMO", "AXA");	
	sous_graphe.supprimer("BMO", "AXA");	
	if(graphe.sommets() != som - 1 || graphe.arcs() != arr - 5) {
		std::cerr << RED << "ECHEC - IX" << RESET << std::endl;
		erreur++;
	}
	std::set<std::string> T({"LCL"});
	sous_graphe = graphe.cooperative(T);
	if(sous_graphe.sommets() != 1) {
		std::cerr << RED << "ECHEC - X" << RESET << std::endl;
		erreur++;
	}
	if(sous_graphe.arcs() != 0) {
		std::cerr << RED << "ECHEC - XI" << RESET << std::endl;
		erreur++;
	}
	T.insert("NBG");
	sous_graphe = graphe.cooperative(T);
	if(sous_graphe.sommets() != 2) {
		std::cerr << RED << "ECHEC - XII" << RESET << std::endl;
		erreur++;
	}
	if(sous_graphe.arcs() != 1 || !sous_graphe.arc("NBG", "LCL")) {
		std::cerr << RED << "ECHEC - XIII" << RESET << std::endl;
		erreur++;
	}
	T.insert("ING");
	sous_graphe = graphe.cooperative(T);
	if(sous_graphe.sommets() != 3) {
		std::cerr << RED << "ECHEC - XIV" << RESET << std::endl;
		erreur++;
	}
	if(sous_graphe.arcs() != 1 || !sous_graphe.arc("NBG", "LCL")) {
		std::cerr << RED << "ECHEC - XV" << RESET << std::endl;
		erreur++;
	}
	Digraph<int> digraph;
	std::set<int> N;
	for(int i = 10; i < 1000; i += 10) {
		N.insert(i);
		for(int j = 1; j < 10; j++) {
			digraph.inserer(i, i + j, 3105.3173);
			digraph.inserer(i, i - j, 3173.3105);
		}
	}
	Digraph<int> subgraph = digraph.cooperative(N);
	if(subgraph.sommets() != 99 || subgraph.arcs() != 0) {
		std::cerr << RED << "ECHEC - XVI" << RESET << std::endl;
		erreur++;
	}
	for(int i = 10; i < 1000; i += 10) 
		N.insert(i + 1);
	subgraph = digraph.cooperative(N);
	if(subgraph.sommets() != 99 * 2 || subgraph.arcs() != 99 + 98) {
		std::cerr << RED << "ECHEC - XVII" << RESET << std::endl;
		erreur++;
	}	
	N.insert(9);
	subgraph = digraph.cooperative(N);
	if(subgraph.sommets() != 99 * 2 + 1 || subgraph.arcs() != 99 + 98 + 1) {
		std::cerr << RED << "ECHEC - XVIII" << RESET << std::endl;
		erreur++;
	}	
	if(erreur == 0)
		std::cout << GREEN << "\t==> OK" << RESET << std::endl;
	return erreur;
}
