## Including custom messages on Arduino using VSCode

1. Make sure that the folder containing your custom messages is in your catkin_ws
2. Build your workspace using `catkin_make`
3. Launch `roscore`
4. Run `rosrun rosserial_arduino make_libraries.py "path_to_the_library_destination"` (for VSCode, it's your project's "lib" folder)
5. Within VSCode, add `#include <name_of_the_folder_containing_your_msg/custom_msg_file.h>`

##### Inclure les messages custom sur Arduino avec VSCode:

1. Cloner le git contenant le message custom dans catkin_ws
2. Faire `catkin_make`
3. Lancer `roscore`
5. Lancer `rosrun rosserial_arduino make_libraries.py "chemin_de_l'endroit_où_mettre_la_librairie"` (pour VSCode, c'est le répertoire "lib" du projet)
6. Dans VSCode, ajouter `#include <nom_du_répertoire_contenant_le_message/nom_du_fichier_de_message.h>`
