# pipex - 42 School Project

## 📋 Description
pipex est un projet système du tronc commun à 42 qui reproduit le comportement des pipes shell en C. Ce projet explore la gestion des processus, les tubes (pipes) et la redirection des flux standards dans un environnement UNIX.

## 🎯 Objectifs
- Comprendre le mécanisme des pipes et des tubes
- Maîtriser la création et gestion des processus avec fork()
- Implémenter la redirection des entrées/sorties
- Gérer l'exécution de commandes shell en C

## 🛠️ Technologies Utilisées

### 🔧 Système
- **Pipes UNIX** - Communication inter-processus
- **Fork et Execve** - Création et exécution de processus
- **Redirections de flux** - dup2 et gestion des descripteurs
- **Gestion des chemins** - Accès aux exécutables système

## 🚀 Installation et Utilisation

### 📋 Compilation
```bash
git clone [URL-du-repository]
cd pipex
make
⚙️ Utilisation
bash
# Format équivalent à : < file1 cmd1 | cmd2 > file2
./pipex file1 cmd1 cmd2 file2

# Exemple concret
./pipex input.txt "grep hello" "wc -l" output.txt
```

📊 Fonctionnalités Implémentées
🔄 Gestion des Processus
Création de pipes - pipe() pour la communication

Forking - Création de processus enfants

Exécution de commandes - execve() avec gestion des paths

Attente des processus - waitpid() pour la synchronisation

📁 Gestion des Fichiers
Ouverture de fichiers - Gestion des entrées/sorties

Redirection des flux - dup2() pour les pipes

Gestion des erreurs - Fermeture propre des descripteurs

🛡️ Fonctions Principales
pipex - Fonction principale orchestrant l'exécution

execute_command - Exécution d'une commande dans un processus

find_path - Recherche du chemin absolu des exécutables

split_command - Parsing des commandes et arguments

💡 Compétences Développées
Programmation système UNIX

Gestion des processus et du multitâche

Communication inter-processus via pipes

Redirection des flux d'entrée/sortie

Parsing de commandes shell

Gestion des chemins d'exécution

Gestion robuste des erreurs système

🎯 Comportement Reproduit
Le projet reproduit exactement le comportement de :

bash
# Commande shell équivalente
< input.txt cmd1 | cmd2 > output.txt
📝 Cas d'Usage
bash
# Compter le nombre de lignes contenant "error" dans un log
./pipex app.log "grep error" "wc -l" result.txt

# Trier et dédoublonner des données
./pipex data.txt "sort" "uniq" sorted_data.txt

📁 Structure du Projet
```
text
pipex/
├── src/           # Code source
├── inc/           # Fichiers d'en-tête
├── Makefile       # Système de compilation
└── README.md      # Documentation
```
Ce projet est fondamental pour comprendre le fonctionnement interne des shells UNIX et ouvre la voie vers des concepts plus avancés de programmation système.
