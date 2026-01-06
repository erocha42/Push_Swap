#!/bin/bash

# Vérification des arguments
if [ -z "$1" ]; then
    echo "Usage: ./tester.sh <nombre_elements> [nombre_tests]"
    echo "Exemple: ./tester.sh 100 20"
    exit 1
fi

STACK_SIZE=$1
LOOPS=${2:-10} # Par défaut, fait 10 tests si le 2ème argument n'est pas donné
PUSH_SWAP="./push_swap" # Chemin vers ton exécutable

if [ ! -f "$PUSH_SWAP" ]; then
    echo "Erreur : L'exécutable $PUSH_SWAP est introuvable."
    exit 1
fi

total_moves=0
echo "Test de $PUSH_SWAP avec une stack de $STACK_SIZE éléments sur $LOOPS essais..."
echo "------------------------------------------------"

for ((i=1; i<=LOOPS; i++)); do
    # Génération d'une permutation aléatoire de nombres
    # Note: Utilise ruby pour la compatibilité (souvent dispo sur les Mac de 42)
    ARG=$(ruby -e "puts (1..$STACK_SIZE).to_a.shuffle.join(' ')")

    # Exécution de push_swap et comptage des lignes
    MOVES=$($PUSH_SWAP $ARG | wc -l)

    # Vérification si le checker est dispo (optionnel, pour vérifier si c'est bien trié)
    # CHECK=$($PUSH_SWAP $ARG | ./checker_linux $ARG) # Décommente si tu as le checker

    echo "Test $i: $MOVES coups"
    total_moves=$((total_moves + MOVES))
done

# Calcul de la moyenne
average=$((total_moves / LOOPS))

echo "------------------------------------------------"
echo "Moyenne sur $LOOPS tests pour $STACK_SIZE éléments : $average coups"
