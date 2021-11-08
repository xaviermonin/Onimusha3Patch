// Injector.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "Injector.h"

int main()
{
	Injector oniInjector = Injector("oni3.exe");
	oniInjector.RunAndInject("onipatch.dll");

	return 0;
}
