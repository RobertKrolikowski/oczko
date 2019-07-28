#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>

char talia[52];
char taliaznak[52];
char znak[4]={3,4,5,6};

//funkcja tasowania kart
void tasowanie()
{
	int i=0,t,tt;
	char pojemnik;
	for(;i < 200;i++)
	{
		t=rand() % 52;
		tt=rand() % 52;
		pojemnik = talia[t];
		talia[t] = talia[tt];
		talia[tt] = pojemnik;
		pojemnik = taliaznak[t];
		taliaznak[t] = taliaznak[tt];
		taliaznak[tt] = pojemnik;
	}
}

int main()
{

	srand(time(0));
	int numerkarty = 51,punktyG = 0,punktyK = 0,reka = 0,reka1 = 0,opcja,wynik[3]={0,0,0};
	//wynik[0]-wygrana,wynik[1]-remis,wynik[2]-przegrana

	printf("Witam w polskiej wersji gry w oczko\n\n\n");

	printf("Objasnienie:\nA-as ma zawsze 11 punktow \nnatomiast 2 asy czyli 22 punkty oznacza perskie oczko i wygrana\n\n");
	printf("J-Walet,D-Dama,K-Krol \nwszystkie wyzej wymienione karty maja po 10 punktow\n\n");
	printf("liczby natomiast maja taka wartosc jaka przedstawiaja\n(2 to 2 punkty, 6 to 6 punktow\n\n\n");
	printf("Jesli sie zapoznales z zasadami nacisnij enter\n");
	getchar();
	//wpisanie do tali kart
	for(int a = 0,z = 0,b = 0; a < 4;a++,z++,b+=13)
	{
		for(int t = 0; t < 13;t++)
		{
			talia[t+b] = 48+t;
			taliaznak[t+b] = znak[z];
			if(t == 10)
			{
			talia[t+b] = 'J';
			taliaznak[t+b] = znak[z];
			}
			if(t == 11)
			{
			talia[t+b] = 'D';
			taliaznak[t+b] = znak[z];
			}
			if(t == 12)
			{
			talia[t+b] = 'K';
			taliaznak[t+b] = znak[z];
			}
			if(t == 1)
			{
			talia[t+b] = 'A';
			taliaznak[t+b] = znak[z];
			}
		}
	}
	
	tasowanie();

	/*//wyswietlenie tali przed tasowaniem
	printf("Przed tasowaniem\n");
	for(int a=0; a < 52; a++)
	{
		printf("%c%c\n",talia[a],taliaznak[a]);
	}
	tasowanie();

	//po tasowaniu
	printf("Po tasowaniu\n");
	for(int a=0; a < 52; a++)
	{
		printf("%c%c\n",talia[a],taliaznak[a]);
	}*/
	do
	{
		do
		{
			system ("cls");
			printf("Dobrana karta to:\n");
			if(talia[numerkarty] == 48) printf("1");
			printf("%c%c\n",talia[numerkarty],taliaznak[numerkarty]);
			reka = reka + 1;
	

			//Sprawdzanie jaka to karta i dodawanie punktow dodawanie punktow
			if( (talia[numerkarty] == 48) || (talia[numerkarty] == 68) || (talia[numerkarty] == 74) || (talia[numerkarty] == 75) )
			{
				punktyG = punktyG + 10;
			}
			else if( talia[numerkarty] == 65 )
			{
				punktyG = punktyG + 11;
			}
			else
			{	//sprawdzanie kart od 2 do 9
				for(int a = 50 ;a <= talia[numerkarty];a++)
				{
					if(a == talia[numerkarty]) punktyG = punktyG + (a-48);
				}
			}
			//zmniejszenie numeru karty (odrzucenie karty)
			numerkarty--;
	
			//Jesli 2 pierwsze karty to ASY wowczas gracz wygrywa (perskie oczko)
			if ( (punktyG == 22) && (reka == 2) )
			{
				printf("Wygrales!!\nMasz perskie oczko\n");
				for(int a = reka;a > 0 ; a--)
				{
						printf("%c%c  ",talia[numerkarty + a],taliaznak[numerkarty + a]);
				}
				wynik[0] += 1;
				getchar();
				break;
			}
			printf("Twoje punkty: %d\n",punktyG);
			//sprawdzanie czy gracz ma oczko
			if(punktyG == 21)
			{
				system("cls");
				printf("Wygrales!!\nMasz oczko\n");
				printf("Twoje karty to:\n");
				for(int a = reka;a > 0 ; a--)
				{
					if(talia[numerkarty + a] == 48) printf("1");
					printf("%c%c  ",talia[numerkarty + a],taliaznak[numerkarty + a]);
				}
				wynik[0] += 1;
				getchar();		
				break;
			}
			//sprawdzanie czy punkty gracz sa wieksze niz 21
			if (punktyG > 21)
			{
				system("cls");
				printf("Przegrales!!\nMasz %d punktow\n",punktyG);
				printf("Twoje karty to:\n");
				for(int a = reka;a > 0 ; a--)
				{
					if(talia[numerkarty + a] == 48) printf("1");
					printf("%c%c  ",talia[numerkarty + a],taliaznak[numerkarty + a]);
					
				}
				wynik[2] += 1;
				printf("\n\n");
				getchar();
				break;
			}
			//Menu wyboru 
			do
			{	
				if (numerkarty != -1)
				{

					printf("\n1.Dobierz karte\n2.Wystarczy\n");
					printf("3.Pokaz ilosc punktow i moje karty\n");
					//zabespieczenie przed wprowadzeniem litery
					while (scanf("%d",&opcja) !=1 )
					{
						system("cls");
						printf("Podales litere zamiast liczbe\n");
						printf("\n1.Dobierz karte\n2.Wystarczy\n");
						printf("3.Pokaz ilosc punktow i moje karty\n");
						fflush(stdin);
					}

					if (opcja == 3)
					{
						system ("cls");
						printf("Aktualnie masz %d punktow\n",punktyG);
						printf("A twoje karty to :\n");
						for(int a = reka;a > 0 ; a--)
						{
							if(talia[numerkarty + a] == 48) printf("1");
							printf("%c%c  ",talia[numerkarty + a],taliaznak[numerkarty + a]);
						}
					}
					if( (opcja >= 4) || (opcja <=0) )
					{
						system ("cls");
						printf("Podales zla liczbe.\n");
						opcja = 3;
					}
				}
				//jesli zabraknie kart
				else
				{
					printf("\nSkonczyly sie karty\n");
					opcja = 2;
				}
			}
			while(opcja == 3); 
		}
		while(opcja == 1);
		if(punktyG < 21)
		{
			//ruch komputera
			do
			{
				if(numerkarty != -1)
				{
					reka1 = reka1 + 1;
	
					//Sprawdzanie jaka to karta i dodawanie punktow dodawanie punktow
					if( (talia[numerkarty] == 48) || (talia[numerkarty] == 68) || (talia[numerkarty] == 74) || (talia[numerkarty] == 75) )
					{
						punktyK = punktyK + 10;
					}
					else if( talia[numerkarty] == 65 )
					{
						punktyK = punktyK + 11;
					}
					else
					{	//sprawdzanie kart od 2 do 9
						for(int a = 50 ;a <= talia[numerkarty];a++)
						{
							if(a == talia[numerkarty]) punktyK = punktyK + (a-48);
						}
					}
					//zmniejszenie numeru karty (odrzucenie karty)
					numerkarty--;
				}
				else break;
			}
			while(punktyK < punktyG);

			system ("cls");
			if (numerkarty == -1) printf("Karty sie skonczyly\n");
			printf("Komputer ma %d punktow a jego karty to:\n",punktyK);
			//wyswietlenie kart komputera 
			for(int a = reka1;a > 0 ; a--)
			{
				if(talia[numerkarty + a] == 48) printf("1");
				printf("%c%c  ",talia[numerkarty + a],taliaznak[numerkarty + a]);
			}
			//wyswietlenie kart gracza
			printf("\nMasz %d punktow, a Twoje karty to:\n",punktyG);
			for(int a = reka1 + reka;a > reka1 ; a--)
			{
				if(talia[numerkarty + a] == 48) printf("1");
				printf("%c%c  ",talia[numerkarty + a],taliaznak[numerkarty + a]);
			}

			//sprawdzanie kto wygral
			if ( (punktyK >= 22) && (reka1 != 2) ) punktyK = 0;

			if(punktyG > punktyK)
			{
				printf("\nWygrales\n");
				wynik[0] += 1;
			}
			else if(punktyG < punktyK)
			{
				printf("\nPrzegrales\n");
				wynik[2] += 1;
			}
			else
			{
				printf("\nRemis\n");
				wynik[1] += 1;
			}
		}
		printf("\nWygrane\tRemisy\tPrzegrane\n");
		printf("%d\t%d\t%d\n",wynik[0],wynik[1],wynik[2]);




		do
		{
			//menu
			printf("\n1.Zagraj jeszcze raz bez tasowania\n");
			printf("2.Zagraj jeszcze i przetasuj\n");
			printf("3.Zakoncz gre\n");
			while( (scanf("%d",&opcja)) != 1)
			{
				system("cls");
				printf("Podales litere zamiast liczbe\n");
				printf("\n1.Zagraj jeszcze raz bez tasowania\n");
				printf("2.Zagraj jeszcze i przetasuj\n");
				printf("3.Zakoncz gre\n");
				fflush(stdin);
			}
			//"wyrzucenie kart z reki" i kasacja punktow
			reka = 0;
			punktyG = 0;
			punktyK = 0;
			reka1 = 0;
			if( (opcja >= 4) || (opcja <=0) )
			{
				system ("cls");
				printf("Podales zla liczbe.\n");
			}
			if(opcja == 3 ) break;
			//jesli zabraknie kart a gracz bedzie dalej chcial grac to karty zostana przetasowane
			if(numerkarty == -1)
			{
				printf("Nie ma juz kart w tali!!\n");
				printf("Karty zostana przetasowane");
				opcja = 2;
				getch();
			}
			//przetasowanie kart i nowe rozdanie
			if(opcja == 2)
			{
				tasowanie();
				numerkarty = 51;
				opcja = 1;
			}
		}
		while(opcja != 1 );
	}
	while(opcja == 1);



	getchar();
	return 0;
}
