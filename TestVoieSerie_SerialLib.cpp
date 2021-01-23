// Exemple d'utilisation de la voie série avec serialib
// Ecriture sur un une voie série
// O. Dartois - Janvier 2021

#include <iostream>
#include <string>
#include <thread>

#include "serialib.h"

int main()
{

    // Instanciation d'un objet de la classe serialib
    serialib serial;

    // Nom du port COM à ouvrir
    const std::string portCOM("COM3");

    // Ouverture du port série à la vitesse spécifié
    char erreur = serial.Open(portCOM.c_str(), 115200);

    // Si pb à l'ouverture du port série, on sort avec un message
    if (erreur != 1) {
        std::cout << "Ouverture du port serie KO !" << std::endl;
        return 0;
    }
    
    std::cout << "Ouverture du port serie OK" << std::endl;

    // Envoie des caractères ASCII de 32 à 128
    for (int c = 32; c < 128; c++)
    {
        // Ecriture d'un caractère sur le port série
        serial.WriteChar(c);
        // Pause de 1 seconde
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }

    // Fermeture du port série
    serial.Close();

    return 0;
}
