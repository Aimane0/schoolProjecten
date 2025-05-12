prijs=133
print('Prijs van het geselecteerde artikel in eurocenten:'+' '+str(prijs))
betaald_bedrag=eval(input('Aantal eurocenten waarmee u heeft betaald: '))
print('U heeft betaald met'+' '+str(betaald_bedrag)+' '+'eurocenten.')


wisselgeld=betaald_bedrag-prijs
print('U krijgt'+' '+str(wisselgeld)+' '+'eurocenten terug.')


if int(wisselgeld) >= int(50):
    print('U krijgt'+' '+str(wisselgeld//50)+', '+'50 eurocent munten')
    wisselgeld2=(wisselgeld%50)
else:
    wisselgeld2=(wisselgeld%50)
    print('U krijgt 0, 50 eurocent munten')
if int(wisselgeld2) >= 20:
    print('U krijgt' + ' ' + str(wisselgeld2 // 20) + ', ' + '20 eurocent munten')
    wisselgeld3=(wisselgeld2%20)
else:
    wisselgeld3=(wisselgeld2%20)
    print('U krijgt 0, 20 eurocent munten')
if int(wisselgeld3) >= 10:
    print('U krijgt' + ' ' + str(wisselgeld3 // 10) + ', ' + '10 eurocent munten')
    wisselgeld4=(wisselgeld3%10)
else:
    wisselgeld4=(wisselgeld3%10)
    print('U krijgt 0, 10 eurocent munten')
if int(wisselgeld4) >= 5:
    print('U krijgt' + ' ' + str(wisselgeld4 // 5) + ', ' + '5 eurocent munten')
    wisselgeld5=(wisselgeld4%5)
else:
    wisselgeld5=(wisselgeld4%5)
    print('U krijgt 0, 5 eurocent munten')
if int(wisselgeld5) >= 2:
    print('U krijgt' + ' ' + str(wisselgeld5 // 2) + ', ' + '2 eurocent munten')
    wisselgeld6=(wisselgeld5%2)
else:
    wisselgeld6=(wisselgeld5%2)
    print('U krijgt 0, 2 eurocent munten')
if int(wisselgeld6) >= 1:
    print('U krijgt' + ' ' + str(wisselgeld6 // 1) + ', ' + '1 eurocent munten')
else:
    print('U krijgt 0, 1 eurocent munten')