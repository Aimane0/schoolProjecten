#include <iostream>

template <typename T>
class Pair
{
public:
    T first;
    T second;

    Pair(T a, T b) : first(a), second(b) {}

    T getFirst()
    {
        return first;
    };

    T getSecond()
    {
        return second;
    };

    void setFirst(T x){
        first = x;
    };

    void setSecond(T x){
        second = x;
    };
};

template <typename T>
void swapValues(Pair<T> &pair){ // GEBRUIK VAN & REFERENCE, OMDAT JE ANDERS EEN LOKALE KOPIE MAAKT DIE JE VERANDERT EN DAT WIL JE NIET DOEN
                                // DE REFERENCE ZORGT ER VOOR DAT JE DE MEE GEGEVEN VARIABEL IN DE PARAMETER DIRECT AANPAST, IN PLAATS VAN EEN LOKALE KOPIE IN DE FUNCTIE!
    T tempFirst = pair.getFirst();
    T tempSecond = pair.getSecond();

    pair.setFirst(tempSecond);
    pair.setSecond(tempFirst);
}

int main() {
    Pair<float> myPair(42.5, 22.5);

    std::cout << "First: " << myPair.getFirst() << std::endl;
    std::cout << "Second: " << myPair.getSecond() <<std::endl;

    myPair.setFirst(99.55);
    myPair.setSecond(533.68383);

    std::cout << "First: " << myPair.getFirst() << std::endl;
    std::cout << "Second: " << myPair.getSecond() <<std::endl;

    swapValues(myPair);

    std::cout << "First: " << myPair.getFirst() << std::endl;
    std::cout << "Second: " << myPair.getSecond() <<std::endl;
}