#include <iostream>
#include <fstream>
#include <cstdio> // Voor std::remove
#include <string>
#include <stdint.h>

class TempFile {
private:
    std::string filename; // Naam van het tijdelijke bestand

public:
    // Constructor die een tijdelijk bestand aanmaakt
    TempFile(const std::string& prefix) {
        filename = prefix + "_file.txt";
        std::ofstream file(filename);
        if (!file) {
            std::cerr << "Kan geen tijdelijk bestand aanmaken.";
        } else {
            std::cout << "Het tijdelijke bestand is aangemaakt en klaar voor gebruik";
        }
    }

    // Destructor die het tijdelijke bestand verwijdert
    ~TempFile() {
        if (std::remove(filename.c_str()) != 0){
            std::cerr << "Er is een fout opgetreden bij het verwijderen!";
        } else {
            std::cout << "Het bestand is succesvol verwijderd!";
        }
    }

    // Verwijder copy constructor en copy assignment operator
    TempFile(const TempFile&) = delete;
    TempFile& operator=(const TempFile&) = delete;

    // Functie om naar het bestand te schrijven
    void writeData(const std::string& data) {
        std::ofstream file(filename, std::ios::app);
        if (!file){
            std::cerr <<"Er kon niet geschreven worden naar het bestand";
        } else {
            std::cout << data << std::endl;
            std::cout << "Data succesvol naar het bestand geschreven";
        }
    }

    // Functie om de naam van het bestand te krijgen
    const std::string& getFilename() const {
        return filename;
    }
};

// Hoofdprogramma om de RAII-klasse te testen
int main() {
    try {
        TempFile tempFile("example"); // Maak een tijdelijk bestand aan met prefix "example"

        tempFile.writeData("Hello, RAII!"); // Schrijf data naar het bestand
        std::cout << "Temporary file is: " << tempFile.getFilename() << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    // Het tijdelijke bestand wordt hier automatisch verwijderd door de destructor van TempFile

    return 0;
}