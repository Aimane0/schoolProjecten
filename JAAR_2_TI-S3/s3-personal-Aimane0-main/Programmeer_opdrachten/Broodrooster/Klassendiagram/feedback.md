Feedback verkregen van Marius 08/01/2025

- Listener patern toevoegen tussen LichtSensor en BroodRoosterControl, omdat hier een circulaire depedency zit!

- Vergeten broodroostercontrol toe te voegen als private member bij bruinteinstellencontrol, anders kan die niets naar broodroostercontrol sturen!

- InstelKnop heet Knop en niet InstelKnop, naam aanpassen

- Solenoid en Speaker en verwarmingselement hebben elkaar publieke functies, die moet je ff omwisselen