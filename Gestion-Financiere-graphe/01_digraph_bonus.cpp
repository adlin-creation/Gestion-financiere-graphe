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

	std::set<std::string> S({"BIC", "BMO", "BNP", "BEA", "AXA", "ATB"}), BNP({"BNP"});

	for(int i = 0, j = 0; i < arr && j < 2 * arr; i++, j += 2)
		graphe.inserer(arcs[j], arcs[j + 1], emprunts[i]);
	Digraph<std::string> sous_graphe = graphe.cooperative(S);
	Digraph<std::string> clony(graphe), cloony(graphe);
	if(graphe.sommets() != som  || graphe.arcs() != arr) {
		std::cerr << RED << "ECHEC - I" << RESET << std::endl;
		erreur++;
	}
	graphe.reduire(sous_graphe);
	if(graphe.arc("BEA", "BOC") || 
		graphe.arc("BOC", "AXA") ||
		graphe.arc("NBG", "AXA") || 
		graphe.arc("ATB", "CIC") ||
		graphe.arc("ING", "ATB") || 
		graphe.arc("BNS", "BIC") ||
		graphe.arc("ING", "BNC") ||
		!graphe.arc("BEA", "BIC")) {
		std::cerr << RED << "ECHEC - II" << RESET << std::endl;
		erreur++;
	}
	if(graphe.dette("BIC") != 200 + 6320 ||
		graphe.dette("ATB") != 798 ||
		graphe.dette("BMO") != 2512 + 4000 || 
		graphe.dette("AXA") != 4800 + 3440 ||
		graphe.dette("BEA") != 5000 + 3198 ||
		graphe.dette("BOC") != 0 ||
		graphe.dette("BNC") != 0 ||
		graphe.dette("ING") != 9390 + 1198 ||
		graphe.dette("BNS") != 2690 ||
		graphe.dette("NBG") != 4710 + 40 + 2740 + 7400 + 3800 ||
		graphe.dette("LCL") != 4620 + 880 ||
		graphe.dette("CIC") != 2313) {
		std::cerr << RED << "ECHEC - III" << RESET << std::endl;
		erreur++;
	}
	if(graphe.pret("BIC") != 3220 + 2512 ||
		graphe.pret("ATB") != 6320 + 3050 ||
		graphe.pret("BMO") != 3440 + 2740 + 2410 || 
		graphe.pret("BEA") != 4800 + 798 + 9390 + 200 ||
		graphe.pret("BOC") != 40 ||
		graphe.pret("BNC") != 4710 + 3198||
		graphe.pret("ING") != 0 ||
		graphe.pret("BNS") != 2313 + 6370 ||
		graphe.pret("NBG") != 4620 ||
		graphe.pret("LCL") != 4420 + 3900 + 2690 ||
		graphe.pret("CIC") != 880 + 1198) {
		std::cerr << RED << "ECHEC - IV" << RESET << std::endl;
		erreur++;
	}
	sous_graphe = clony.cooperative(BNP);
	clony.reduire(sous_graphe);
	cloony.reduire("BNP");
	if(clony.arc("BNP", "BMO") ||
		clony.arc("BNP", "BEA") ||
		clony.arc("NBG", "AXA") ||
		clony.arc("BEA", "AXA") ||
		clony.arc("ATB", "BIC") ||
		clony.arc("BEA", "ATB") ||
		clony.arc("BMO", "AXA")) {
		std::cerr << RED << "ECHEC - V" << RESET << std::endl;
		erreur++;
	}
	if(clony.dette("BNP") != cloony.dette("BNP") ||
		clony.pret("BNP") != cloony.pret("BNP") ||
		clony.dette("BNP") != 1360 + 2650 + 2460 ||
		clony.pret("BNP") != 0 ||
		clony.dette("AXA") != 400 ||
		clony.pret("AXA") != 1360 ||
		clony.dette("BEA") != 4500 ||
		clony.pret("BEA") != 2100 + 9390 ||
		cloony.dette("BNP") != 1360 + 2650 + 2460 ||
		cloony.pret("BNP") != 0 ||
		cloony.dette("AXA") != 400 ||
		cloony.pret("AXA") != 1360 ||
		cloony.dette("BEA") != 4500 ||
		cloony.pret("BEA") != 2100 + 9390) {
		std::cerr << RED << "ECHEC - VI" << RESET << std::endl;
		erreur++;
	}
	Digraph<std::string> obi_one, obi_two;
	std::set<std::string> a({"A"}), b({"B"});
	obi_one.inserer("A", "B", 3105);
	obi_one.inserer("B", "A", 3105);
	obi_two.inserer("A", "B", 3105);
	obi_two.inserer("B", "A", 3105);
	Digraph<std::string> A = obi_one.cooperative(a);
	Digraph<std::string> B = obi_one.cooperative(b);
	obi_one.reduire(A);
	if(obi_one.sommets() != 2 || obi_one.arcs() != 0) {
		std::cerr << RED << "ECHEC - VII" << RESET << std::endl;
		erreur++;
	}
	obi_two.reduire(B);
	if(obi_one.sommets() != 2 || obi_one.arcs() != 0) {
		std::cerr << RED << "ECHEC - VIII" << RESET << std::endl;
		erreur++;
	}
	Digraph<int> grogu;
	std::set<int> W;
	for(int i = 0; i < 10000; i++)
		grogu.inserer(i, i + 1, (i + 1)*(i + 1));
	for(int i = 0; i < 10000; i += 1000)
		W.insert(i);
	Digraph<int> sub = grogu.cooperative(W);
	grogu.reduire(sub);
	if(grogu.arcs() != 10000) {
		std::cerr << RED << "ECHEC - IX" << RESET << std::endl;
		erreur++;
	}
	Digraph<int> clone(grogu), cloone(grogu);
	clone.inserer(10000, -2, 3105);
	clone.inserer(-1, -2, 0.5);
	clone.inserer(-1, 0, 0.5);
	cloone.inserer(10000, -2, 0.5);
	cloone.inserer(-1, 0, 0.5);
	W.clear();
	W.insert(-2);
	W.insert(-1);
	W.insert(0);
	sub = clone.cooperative(W);
	clone.reduire(sub);
	sub = cloone.cooperative(W);
	cloone.reduire(sub);
	if(clone.arcs() != 10003 ||
		clone.arc(0, 1)) {
		std::cerr << RED << "ECHEC - X" << RESET << std::endl;
		erreur++;
	}
	if(clone.dette(sub) != 3105 - 1 ||
		clone.pret(sub) != 0) {
		std::cerr << RED << "ECHEC - XI" << RESET << std::endl;
		erreur++;
	}
	if(cloone.arcs() != 10002 ||
		cloone.arc(10000, - 2)) {
		std::cerr << RED << "ECHEC - XII" << RESET << std::endl;
		erreur++;
	}
	if(cloone.dette(sub) != 0 ||
		cloone.pret(sub) != 0.5) {
		std::cerr << RED << "ECHEC - XIII" << RESET << std::endl;
		erreur++;
	}
	Digraph<int> yoda;
	for(int j = 0; j < 10; j++) {
		yoda.inserer(0, j * 100 + 1, 3105);
		for(int i = 1; i < 100; i++)
			yoda.inserer((j * 100) + i, (j * 100) + i + 1, 3105);
		yoda.inserer(j * 100 + 100, 0, 3105);
	}
	if(yoda.sommets() != 1001 || yoda.arcs() != 1010) {
		std::cerr << RED << "ECHEC - XIV" << RESET << std::endl;
		erreur++;
	}
	Digraph<int> luke(yoda), leia(yoda), obi(yoda);
	W.clear();
	W.insert(7);
	W.insert(107);
	W.insert(207);
	sub = yoda.cooperative(W);
	luke.reduire(sub);
	if(luke.sommets() != 1001 || luke.arcs() != 707) {
		std::cerr << RED << "ECHEC - XV" << RESET << std::endl;
		erreur++;
	}
	W.insert(8);
	W.insert(108);
	W.insert(208);
	sub = yoda.cooperative(W);
	leia.reduire(sub);
	if(leia.sommets() != 1001 || leia.arcs() != 707) {
		std::cerr << RED << "ECHEC - XVI" << RESET << std::endl;
		erreur++;
	}
	W.insert(0);
	sub = yoda.cooperative(W);
	obi.reduire(sub);
	if(obi.sommets() != 1001 || obi.arcs() != 9) {
		std::cerr << RED << "ECHEC - XVII" << RESET << std::endl;
		erreur++;
	}
	if(erreur == 0)
		std::cout << GREEN << "\t==> OK" << RESET << std::endl;
	return erreur;
}
