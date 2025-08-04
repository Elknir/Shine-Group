# Test Technique Shine Group

Test Technique fait en 1 jour

Pour le contexte, j'ai envoyé un mail à job@shine-group.tech pour demander si le test technique était faisable sur Unreal (avec du C++ et du blueprint pour le flow) et non pas en C++ pur.
N'ayant pas eu de réponse lundi, j'ai décidé de le faire sur Unreal.
Cela me semblait plus pertinent de le faire de cette manière pour montrer mes compétences sur des points spécifiques à Unreal et pour avoir un rendu plus agréable visuellement que des commandes de console.
Ceci étant dit, n'hésitez pas à me dire si cela pose un souci et je ferais en sorte de m'adapter si possible. Pour finir, contactez-moi si vous avez d'autres demandes (comme un build) ou si vous avez des questions sur l'architecture du code.


## Architecture

Toute la partie UI est faite en Blueprint. Plus particulierement la gestion des UI qui se fait avec le plugin "CommonUI" (car je voulais en apprendre d'avantage sur ce plugin).
De même pour la geestion de sauvegarde qui se fait avec les "Games Saves Slots" etant directement intégrée avec les blueprints.

Il reste donc la logique de combat qui est fait en C++ que vous pouvez retrouver dans le ficher "FightManager.cpp" (N'oubliez pas de build avec live coding pour qu'il apparaisse)
Le "BP_FightManager" sert uniquement a envoyer des messages à l'event dispatcher du "WBP_FightMenu" et à faire les changements d'UI.

L'architecture globale est la suivante :

Level BP (fait spawn) -> WBP_ManagerUI (gère et à les socket CommonUI de) -> WBP_GameMenu (Pour sauvegarder les données ou afficher le fight) et le WBP_FightMenu (Qui communique via des event dispatchers au WBP_ManagerUI et fait spawn) -> FightManager.cpp (qui a toute la logique du combat en C++)

