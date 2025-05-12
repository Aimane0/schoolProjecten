#include <iostream>
#include "furniture.hpp"

using namespace std;

int main(){
    Furniture furniture1;
    furniture1.print_furniture();

    furniture1.makeMoreHipster();

    furniture1.print_furniture();
}
