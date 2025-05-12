// Team Park Rangers

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

/// @brief Function that puts temperatures from a file in a vector
/// @param src_filename the file with the temperatures
/// @return the vector with the temperatures (float)
std::vector<float> tempInVector(std::string src_filename){
    std::ifstream inf(src_filename);
    std::vector<float> temps;

    // if no input file or empty input file
    if(!inf){
        std::cerr << "couldn't open input file" << "\n";
        return temps;
    }

    std::string input;

    // read input file and add to vector
    while(inf){
        std::getline(inf >> std::ws, input);
        temps.push_back(std::stof(input));
    }
    return temps;
}

int main(){
    std::vector<float> temperatures = tempInVector("temps.txt");
    for(const auto &i: temperatures) std::cout << i << "\n";
}