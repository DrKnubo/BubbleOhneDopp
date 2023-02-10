// BubbleOhneDopp.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include <ctime>

using namespace std;

int main()
{
	srand(time(0));  // Zufall zufallisieren

	int array1[20] = { 0 };  //Platz für 20 Boxen
	int zwischenspeicher = 0;  //Platz zum sortieren und Plaetze tauschen
	int max = 19;  //Markiert die letzte Box beim sortieren 
	
	int boxnr = 0;		//Zufallsnr fuer die Boxen
	int m = 1;
	int n = 0;
	array1[0] = rand() % 90 + 1; //erste Box kann nicht doppelt sein muss aber zum vergleich existieren	

	do {                        // generiere 19 weiter Boxen bis keine doppelten mehr vorkommen
		boxnr = rand() % 90 + 1;
		n = (m - 1);
		do {
			if (array1[n] != boxnr) {   //wenn Box Nr ungleich dann weiter vergleichen..
				n--;
			}
			else
			{
				boxnr = rand() % 90 + 1;
			}
		} while (n >= 0);
		array1[m] = boxnr;
		m++;
	} while (m < 20);

	// unsortiert ausgeben

	for (int x = 0; x < 20; x++) {
		cout << "Unsortierte Box Nr: " << (x+1) << " : " << array1[x] << endl;
	}

	// sortieren 
	do {
		for (int x = 0; x < 19; x++) {
			int y = x + 1;
			while (y <= max) {
				if (array1[x] > array1[y]) {
					zwischenspeicher = array1[x];
					array1[x] = array1[y];
					array1[y] = zwischenspeicher;
					y++;
					x++;
				}
				else {
					y++;
					x++;
				}
			}
		}max--;
	} while (max > 0);

	cout << "Sortiert: " << endl;

	for (int x = 0; x < 20; x++) {		
		cout << array1[x] << ", ";
	}
	return 0;
}




















// Programm ausführen: STRG+F5 oder Menüeintrag "Debuggen" > "Starten ohne Debuggen starten"
// Programm debuggen: F5 oder "Debuggen" > Menü "Debuggen starten"

// Tipps für den Einstieg: 
//   1. Verwenden Sie das Projektmappen-Explorer-Fenster zum Hinzufügen/Verwalten von Dateien.
//   2. Verwenden Sie das Team Explorer-Fenster zum Herstellen einer Verbindung mit der Quellcodeverwaltung.
//   3. Verwenden Sie das Ausgabefenster, um die Buildausgabe und andere Nachrichten anzuzeigen.
//   4. Verwenden Sie das Fenster "Fehlerliste", um Fehler anzuzeigen.
//   5. Wechseln Sie zu "Projekt" > "Neues Element hinzufügen", um neue Codedateien zu erstellen, bzw. zu "Projekt" > "Vorhandenes Element hinzufügen", um dem Projekt vorhandene Codedateien hinzuzufügen.
//   6. Um dieses Projekt später erneut zu öffnen, wechseln Sie zu "Datei" > "Öffnen" > "Projekt", und wählen Sie die SLN-Datei aus.
