// Hoe vaak wordt de onderstaande code uitgevoerd als a=900 en b=280?

int findGCD(int a,int b){
    if(a == b){
        return a;
    }
    else if(a>b){
        return findGCD(a-b,b);
    }else{
        return findGCD(a,b-a);
    }
}

// antwoord: 
// a - b in de eerste return geeft een nieuwe a
// b - a in de tweede return geeft een nieuwe b
// 1: 900 - 280 = 620
// 2: 620 - 280 = 340
// 3: 340 - 280 = 60
// 4: b is nu groter dan a dus nu is het 280 - 60 = 220
// b is nu 220 en a blijft 60
// 5: 220 - 60 = 160
// 6: 160 - 60 = 100
// 7: 100 - 60 = 40
// a is nu 60 en b is nu 40
// 8: 60 - 40 = 20
// b is nu 40 en a is nu 20
// 9: 40 - 20 = 20
// a en b zijn nu allebei 20
// 10: voor de laatste returned die 20 want a == b