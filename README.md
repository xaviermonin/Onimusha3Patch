# Onimusha3Patch

1. Patch Onmimusha 3 to allow any screen resolution.
2. Fix the Configure input menu (see Configure input patch directory).

## How to use
1. Compile solution
2. Copy OniInjector.exe and OniPatch.dll to Onimusha 3 directory.
3. Run OniInjector.exe

## How it works
OniInjector.exe injects OniPatch.dll into the game (oni3.exe).

OniPatch.dll hooks DirectX 9 and CreateWindowExW to force the resolution size.

## Screens

Onimusha in 1920x1080
![image](https://user-images.githubusercontent.com/5740369/140754099-15c1f44c-f68f-49d5-8951-a847b1b9cb0c.png)

Configure input
![image](https://user-images.githubusercontent.com/5740369/140755030-882cac2b-89f0-4b14-8c95-096da3573139.png)
