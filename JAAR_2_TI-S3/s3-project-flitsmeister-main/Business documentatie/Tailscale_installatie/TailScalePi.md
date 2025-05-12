# Een handleiding voor de installatie van Tailscale op een Raspberry Pi

### Zorg dat jij eerst Tailscale op je eigen apparaat hebt geinstalleerd

1. Breng een SSH verbinding met je PI tot stand via Powershell / Terminal

2. Voeg de volgende Tailscale pakketten toe:
``` 
curl -fsSL https://pkgs.tailscale.com/stable/ubuntu/noble.noarmor.gpg | sudo tee /usr/share/keyrings/tailscale-archive-keyring.gpg >/dev/null
curl -fsSL https://pkgs.tailscale.com/stable/ubuntu/noble.tailscale-keyring.list | sudo tee /etc/apt/sources.list.d/tailscale.list
```

3. Installeer Tailscale
``` 
sudo apt-get update
sudo apt-get install tailscale
``` 

4. Verbind je machine met Tailscale
``` 
sudo tailscale up
```

Nu krijg je een link in de terminal, als je deze linkt plakt in je browser kan je inloggen en zorgen dat de Pi op jouw net komt te staan

5. Done! Je kan het IP adres van je device zo vinden
``` 
tailscale ip -4
```