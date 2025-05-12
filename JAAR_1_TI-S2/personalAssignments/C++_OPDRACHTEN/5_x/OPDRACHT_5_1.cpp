// Beschrijf in één zin wat de onderstaande functie doet. 
// Probeer de code alleen te lezen en niet uit te voeren.

int ears(int n_rabbits){
    if(n_rabbits <= 1){
        return n_rabbits * 2;
    }else{
        return 2 + ears(n_rabbits-1);
    }
}

// ANTWOORD: Geeft het totale aantal oren die aanwezig zijn aan.