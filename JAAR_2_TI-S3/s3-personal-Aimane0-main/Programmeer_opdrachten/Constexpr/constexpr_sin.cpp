#include <iostream>
#include <array>
#include <cmath>
#include <chrono>

// Constante voor pi
constexpr double pi = 3.14159265358979323846;

// Functie om graden naar radialen om te zetten
constexpr double degreesToRadians(int degrees) {
    return degrees * (pi / 180.0);
}

// Eigen constexpr sinus functie met behulp van de Taylor-reeks
constexpr double constexprSin(double x) {
    double term = x;
    double result = x;
    constexpr int iterations = 10; // Aantal termen voor de Taylor-reeks
    
    // De Taylorreeks van een sinus is:
    // sin(x) = x - x^3/3! + x^5/5! - x^7/7! + ...

    // NB: onderstaande code is een optimalisatie: elke 
    // term wordt berekend met behulp van de vorige term, waardoor
    // er minder vermenigvuldigingen nodig zijn
    for (int i = 1; i < iterations; ++i) {
        term *= -x * x / ((2 * i) * (2 * i + 1));
        result += term;
    }

    return result;
}

// Eigen constexpr cosinusfunctie
constexpr double constexprCos(double x) {
    double term = 1.0; 
    double result = term;
    constexpr int iterations = 10;

    for (int i = 1; i < iterations; ++i) {
        term *= -x * x / ((2 * i - 1) * (2 * i));
        result += term;
    }
    return result;
}

constexpr std::array<double, 360> generateSinTable() {
    std::array<double, 360> sinTable{};
    for (int i = 0; i < 360; ++i) {
        sinTable[i] = constexprSin(degreesToRadians(i));
    }
    return sinTable;
}

constexpr std::array<double, 360> generateCosTable() {
    std::array<double, 360> cosTable{};
    for (int i = 0; i < 360; ++i) {
        cosTable[i] = constexprCos(degreesToRadians(i));
    }
    return cosTable;
}

// Sinustabel gegenereerd tijdens compile-tijd
constexpr auto sinTable = generateSinTable();
constexpr auto cosTable = generateCosTable();

// Functie om de sinuswaarde te krijgen voor een gegeven graad
double sinDegrees(int degrees) {
    return sinTable[degrees];
}

double cosDegrees(int degrees) {
    return cosTable[degrees];
}

void calculateMaxError(double& maxSinError, double& maxCosError) {
    maxSinError = 0.0;
    maxCosError = 0.0;
    for (int i = 0; i < 360; ++i) {
        double sinError = std::abs(std::sin(degreesToRadians(i)) - sinDegrees(i));
        double cosError = std::abs(std::cos(degreesToRadians(i)) - cosDegrees(i));
        maxSinError = std::max(maxSinError, sinError);
        maxCosError = std::max(maxCosError, cosError);
    }
}

int main() {
    
    double maxSinError, maxCosError;
    calculateMaxError(maxSinError, maxCosError);
    std::cout << "Maximale fout tussen sin(x) en sinDegrees(x): " << maxSinError << '\n';
    std::cout << "Maximale fout tussen cos(x) en cosDegrees(x): " << maxCosError << '\n';

    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 1'000'000; ++i) {
        sinDegrees(i % 360); 
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "Tijd voor sinDegrees: "
              << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()
              << " microseconden\n";

    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 1'000'000; ++i) {
        cosDegrees(i % 360); 
    }
    end = std::chrono::high_resolution_clock::now();
    std::cout << "Tijd voor cosDegrees: "
              << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()
              << " microseconden\n";

    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 1'000'000; ++i) {
        std::sin(degreesToRadians(i % 360));

    end = std::chrono::high_resolution_clock::now();
    std::cout << "Tijd voor std::sin: "
              << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()
              << " microseconden\n";

    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 1'000'000; ++i) {
        std::cos(degreesToRadians(i % 360));
    }
    end = std::chrono::high_resolution_clock::now();
    std::cout << "Tijd voor std::cos: "
              << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()
              << " microseconden\n";

    return 0;
}
}