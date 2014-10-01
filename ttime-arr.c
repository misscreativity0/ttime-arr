/* 
Programm um Dauer von Übertragungen zu messen,
z.B. in Filezilla, Downloads im Browser, etc.

Code-Abfolge:
1. Benutzereingabe + Auslesung derer
* - Eingabe von Geschwindigkeit(en)
*  - Eingabe von Größe(n) der Warteschlange(n)
2. Berechnung
3. Ausgabe des Ergebnis (in h, min, sek?)

*/



#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>


#define COUNT 7*2


char enter;

int ttime; // Downloadzeit (Ergebnis)
float queue ;
char unitq [10];
float speed;
char units [10];

//string und wert
char* sw [COUNT]=
{
	"B", "1",
	"kB", "1000",
	"KiB", "1024",
	"MB", "1000000",
	"MiB", "1048576",
	"GB", "1000000000",
	"GiB", "1073741824"
};
					



void input()
{

	printf("\nVerfügbare Einheiten: ");
	
	int i;
	for(i=0; i<COUNT; i+=2) 
	{
		printf("%s", sw[i]);
		if (i<COUNT-2) printf(", ");
	}
	
	printf("\n\n");
	
	printf("Bitte gebe die Größe der Warteschlange an: ");
	scanf("%f %s", &queue, unitq);
	printf("\n");

	printf("Bitte Downloadgeschwindigkeit eingeben: ");
	scanf("%f %s", &speed, units);
	printf("\n");
	
}

int uti (char* unit)
{
	int i;
	
	for(i=0; i<COUNT; i+=2)
	{if(strcmp(unit, sw[i]) == 0) return atoi(sw[i+1]);}


	printf("\nFehler bei der Eingabe der Einheit!\n");
	input();
	exit(1);
	
}


int calc ()
{
		
	queue=queue*uti(unitq);
	speed=speed*uti(units);
			
		 
	ttime=queue/speed; // in Sek.
			
	//Berechnung der Dauer
			
	// Ausgabe in hh:min:ss
	printf("Dauer: %02i:%02i:%02i hh:mm:ss\n", ttime/3600, (ttime/60)%60, ttime %60);
	printf("\n");	

	return ttime;
	
}



int main ()
{
	
	printf("\n Ist genug Zeit, um Tee zu trinken? \n");
	printf("\n-----------------------------------\n");
	
	input();
	
	
	printf("\n-----------------------------------\n");
	printf("Größe: %f %s\n", queue, unitq);
	printf("Geschwindigkeit: %f %s/s\n", speed, units);
	
	
	if(queue>0 && speed>0 ) calc();
	else printf("Awawaw... zu kleine Warteschlange oder zu niedrige Geschwindigkeit :/\n");

	return 0;
}
