# Environnement de compilation
CXX=g++ 
C11=--std=c++11

# Liste des fichiers sources
SRC_DIG= $(wildcard *_digraph.cpp)
SRC_BON= $(wildcard *_bonus.cpp)

# Liste des exécutables correspondants
EXEC_DIG= $(SRC_DIG:.cpp=)
EXEC_BON= $(SRC_BON:.cpp=)

# Tout compilé et exécuté
all: $(EXEC_DIG) $(EXEC_BON)

# Régle de compilation pour garder les mêmes noms sans le .cpp
%: %.cpp
	$(CXX) $(C11) -o $@ $< 

# Cible pour rouler les tests de la classe Digraph et de la réduction
digraph: $(EXEC_DIG)
	@for exec in $(EXEC_DIG); do \
		if [ $$exec = "07_digraph" ]; then \
			./$$exec complete complete_reduction; \
		elif [ $$exec = "08_digraph" ]; then \
			./$$exec tutte_graph tutte_dettes-prets_sommet; \
		elif [ $$exec = "09_digraph" ]; then \
			./$$exec regular_graph regular_dettes-prets_sommet; \
		elif [ $$exec = "10_digraph" ]; then \
			./$$exec dorogovtsev_graph dorogovtsev_dettes-prets_sommet; \
		else \
			./$$exec; \
                fi \
	done

# Cible pour rouler les tests de la réduction de groupe (bonus)
bonus: $(EXEC_BON)
	@for exec in $(EXEC_BON); do \
		if [ $$exec = "02_digraph_bonus" ]; then \
			./$$exec complete complete_reduction_sg; \
		elif [ $$exec = "06_digraph_bonus" ]; then \
			./$$exec tutte_graph tutte_dettes-prets_sommet tutte_sg_1 tutte_sg_2; \
		elif [ $$exec = "07_digraph_bonus" ]; then \
			./$$exec regular_graph regular_dettes-prets_sommet regular_sg_1 regular_sg_2; \
		elif [ $$exec = "08_digraph_bonus" ]; then \
			./$$exec dorogovtsev_graph dorogovtsev_dettes-prets_sommet dorogovtsev_sg_1 dorogovtsev_sg_2; \
		else \
			./$$exec; \
		fi \
	done

# Supprimer les exécutables
clean:
	rm -f $(EXEC_DIG)
	rm -f $(EXEC_BON)
