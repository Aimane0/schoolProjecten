#include <iostream>
#include <chrono>

// Basisstructuur met een virtuele foo() functie
class Base {
public:
    virtual bool hasFoo()=0;

    virtual void foo() {
        std::cout << "Base::foo() - should never be called" << std::endl;
    }
};

// Classes om te testen, waarbij een class foo() heeft en de andere niet
class WithFoo : public Base {
public:
    bool hasFoo() override {
        return true;
    }

    void foo() override {
        //std::cout << "WithFoo::foo()" << std::endl;
    }
};

// No foo() function in this class
class WithoutFoo : public Base {
public:
    bool hasFoo() override {
        return false;
    }
};

// Functie die foo() aanroept als het object een foo() methode heeft
void callFooIfExists(Base& obj) {
    if (obj.hasFoo()) {
        // Als de cast succesvol is, dan wijst obs naar een WithFoo object en heeft het object een foo() methode
        obj.foo();
    } else {
        // Anders heeft het object geen foo() methode
        //std::cout << "No foo() method available." << std::endl;
    }
}

int main() {
    WithFoo a;
    WithoutFoo b;

    // Begin van tijdsmeting!
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < 100000; i++)
    {
        callFooIfExists(a); // Dit zou "WithFoo::foo()" moeten afdrukken
        callFooIfExists(b); // Dit zou "No foo() method available." moeten afdrukken
    }

    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<float> duration = end - start;
    std::cout << "Gemeten tijd " << duration.count();

    return 0;
}