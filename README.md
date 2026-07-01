# TER — Analyse statique avec Frama-C / EVA
Master Informatique (FSI), Aix-Marseille Université — Encadrants : B. Monmege, L. Henry

Étude du greffon **EVA** de Frama-C (limites sur les pointeurs et l'arithmétique d'adresses)
et de sa **complémentarité avec WP**. Deux livrables : un **TP pédagogique** et un
**rapport de recherche** appuyé sur des expériences reproductibles.

## Structure (3 dossiers)

    Rapport/      le rapport et ses notes
    TP/           le TP pédagogique (énoncé, corrigé, exercices)
    Exemples/     le code qui appuie le rapport (EVA mesuré + WP prouvé)

### Rapport/
- **Rapport_EVA_WP.pdf** — le document principal (11 pages)
- Rapport_EVA_WP.tex — source LaTeX
- Notes_EVA_WP_octogones.md — notes de travail (version longue)

### TP/
- TP_enonce.pdf / TP_corrige.pdf (+ sources .tex), README.md
- exercices/ — les 9 fichiers .c (ex1 garde → ex6 requires)

### Exemples/
- **EVA/** — 8 expériences **mesurées** sur Frama-C 25 (+ lancer.sh pour tout rejouer)
- **WP/**  — 3 fichiers ACSL **prouvés** (Frama-C + Alt-Ergo 2.4.3) + README_WP.md
- **Comparaison/** — les 2 cas qui **combinent** EVA et WP sur le même programme :
  racine carrée (WP réussit là où EVA cale) et pointeur tagué (aucun des deux ne gère)

## Statut de vérification — tout est vérifié
- **EVA** : mesuré (Frama-C 25). Rejouer : `cd Exemples/EVA && sh lancer.sh`
- **WP**  : prouvé localement (Alt-Ergo 2.4.3), tous les buts Valid :

      root.c 15/15 · swap.c 14/14 · reset_array.c 15/15

## Référence principale
Manuel EVA 
Blanchard, Kosmatov, Loulergue, *A Lesson on Verification of IoT Software with Frama-C*,
HPCS 2018. https://allan-blanchard.fr/publis/bkl_hpcs_2018.pdf
