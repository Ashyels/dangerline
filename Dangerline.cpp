#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <ctype.h>
#define panjang 600

#define BLACK           0
#define DARK_BLUE       1
#define GREEN           2
#define TURQUOISE       3
#define DARK_RED        4
#define PURPLE          5
#define FOREST_GREEN    6
#define LIGHT_GRAY      7
#define GRAY            8
#define BLUE            9
#define LIGHT_GREEN    10
#define LIGHT_BLUE     11
#define RED            12
#define PINK           13
#define YELLOW         14
#define WHITE          15
#define STDALERT      140
#define STDHEADER     143
#define STDBACKGROUND 159

void colors(int color);
void wait( float second);					
void loading();
void loading_2();								
void loading_3();								
void header();								
void gotoxy(int x, int y);
void main_menu();
void menu_indo();
void menu_english();
void menu_indo();
void howtoplay_indo();
void credit_indo();
void exit_indo();

void arena(int *petak1_x, int *petak1_y, int *petak2_x, int *petak2_y, int *bentuk4, int *bentuk1);
void arena_merah(int *petak1_x, int *petak1_y, int *petak2_x, int *petak2_y, int *bentuk4, int *bentuk1);
void arena_hijau(int *finish_x, int *finish_y, int *petak1_x, int *petak1_y, int *petak2_x, int *petak2_y, int *bentuk4, int *bentuk1);
void letak(int *finish_x, int *finish_y, int *monster5_x, int *monster5_y, int *monster6_x, int *monster6_y, int *obat1_x, int *obat1_y, int *obat2_x, int *obat2_y, int *monster1_x, int *monster1_y, int *monster2_x, int *monster2_y, int *monster3_x, int *monster3_y, int *petak1_x, int *petak1_y, int *petak2_x, int *petak2_y);
void judgement1 (int *finish_x, int *finish_y, int *monster5_x, int *monster5_y, int *monster6_x, int *monster6_y, int *obat1_x, int *obat1_y, int *obat2_x, int *obat2_y, int *monster1_x, int *monster1_y, int *monster2_x, int *monster2_y, int *monster3_x, int *monster3_y, int *petak1_x, int *petak1_y, int *petak2_x, int *petak2_y, int *nyawa1, int *nyawa2);
void judgement2 (int *finish_x, int *finish_y, int *monster5_x, int *monster5_y, int *monster6_x, int *monster6_y, int *obat1_x, int *obat1_y, int *obat2_x, int *obat2_y, int *monster1_x, int *monster1_y, int *monster2_x, int *monster2_y, int *monster3_x, int *monster3_y, int *petak1_x, int *petak1_y, int *petak2_x, int *petak2_y, int *nyawa1, int *nyawa2);
void utama();


int bahasa(int pilihan);
int jumlah_pemain_english(int x);

int main()
{

main_menu();

}
//#####################################################################################################################################################
//==========================================================================================
void header()
{
	printf("\n\n");
	colors(RED);
	printf("\tษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป\n");
    printf("\tบ                                                             บ\n");
    printf("\tบ                       - DANGERLINE -                        บ\n");
    printf("\tบ                                                             บ\n");
    printf("\tศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ\n");
}

//==========================================================================================
void loading()
{
	system("color 0");
	int i;
	char Loading[] = "Seribu Lentera Production                   ";
	for(i=0; i<37; i++){
		gotoxy(26+i,10);
		printf("%c", Loading[i]);
		wait(0.15);
	}
}


//==========================================================================================
void loading_2()
{
	colors(LIGHT_BLUE);
	int i;
	char Loading[] = "Loading..              ";
	for(i=0; i<20; i++){
		gotoxy(34+i,12);
		printf("%c", Loading[i]);
		wait(0.1);
	}
}

//==========================================================================================
void loading_3()
{
	system("cls");
	colors(YELLOW);
	int i;
	char Loading[] = "Terimakasih! Semoga Harimu Menyenangkan :)     ";
	for(i=0; i<50; i++){
		gotoxy(20+i,10);
		printf("%c", Loading[i]);
		wait(0.15);
	}
	system("cls");

	FILE *aturanmain;
	char aturan[panjang];
	
	printf("\n\n");
	aturanmain = fopen("exit_indo.txt", "rt");
	
	while((fgets(aturan, panjang, aturanmain)) != NULL)
	printf("%s\r", aturan);
	
	fclose(aturanmain);
	printf("\n\n");

	gotoxy(28,17);
	printf("(Press any key to exit)");
	printf("\n");
	colors(BLACK);
}

//==========================================================================================
void gotoxy(int x, int y)
{											 // Modul gotoxy dari http://erwintsuki.blogspot.com/2012/02/pernahkan-anda-gagal-menggunakan-fungsi.html
	HANDLE hConsoleOutput;  
	COORD dwCursorPosition;  
	dwCursorPosition.X = x;  
	dwCursorPosition.Y = y;  
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);  
	SetConsoleCursorPosition(hConsoleOutput,dwCursorPosition);   
}

//==========================================================================================================
void wait ( float seconds )
{ 											// Modul wait dari http://www.programmingsimplified.com/c/dos.h/delay
	clock_t endwait;
	endwait = clock () + seconds * CLOCKS_PER_SEC ;
	while (clock() < endwait) {}
}

//====================================================================================================
void main_menu()
{
	int pilihan = 1;
	
	loading();
	pilihan = bahasa(pilihan);
	if(pilihan == 1)
	{
		menu_indo();	
	}
	else if(pilihan == 2)
	{
		menu_english();
	}
}

//====================================================================================================
void colors(int color)
{ 
	HANDLE hConsole; 
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}

//====================================================================================================
int jumlah_pemain_english(int x)
{
	system("cls");
	header();
	int pemain;
	
	colors(YELLOW);
	gotoxy(2,9);
	printf("How many Player(s):");
	gotoxy(2,10);
	printf("1. One Player");
	gotoxy(2,11);
	printf("2. Two Player");
	gotoxy(2,12);
	printf("3. Back");
	gotoxy(2,14);
	printf("Insert the Number: ");
	scanf("%i", &pemain);
	
	return pemain;
}

//====================================================================================================
int jumlah_pemain_indo(int x)
{
	system("cls");
	header();
	int pemain;
	
	colors(YELLOW);
	gotoxy(2,9);
	printf("Banyak Pemain:");
	gotoxy(2,10);
	printf("1. Satu Pemain");
	gotoxy(2,11);
	printf("2. Dua Pemain");
	gotoxy(2,12);
	printf("3. Kembali");
	gotoxy(2,14);
	printf("Masukkan Angka: ");
	scanf("%i", &pemain);
	
	return pemain;
}

//====================================================================================================
int bahasa(int x)
{
	system("cls");
	int pilihan;
	
	colors(YELLOW);
	gotoxy(24,9);
	printf("Pilih Bahasa/ Select Language:");
	gotoxy(28,11);
	printf("1. Indonesia");
	gotoxy(28,12);	
	printf("2. English");
	gotoxy(24,14);
	printf("Masukkan angka/ Insert the Number: ");
	scanf("%i", &pilihan);
	
	return pilihan;
}

//====================================================================================================
void menu_english()
{			
	system("cls");
	int menu, i, j, pemain = 1;
	
	header();
	
	colors(YELLOW);
	gotoxy(2,9);
	printf("1. Play");
	gotoxy(2,10);
	printf("2. How to Play");
	gotoxy(2,11);
	printf("3. Credit");
	gotoxy(2,12);
	printf("4. Exit");
	gotoxy(2,14);
	printf("Insert the Number: ");
	scanf("%i", &menu);
	
	switch(menu)
	{
		case 1:
		{
			system("cls");
			header();
			
			pemain = jumlah_pemain_english(pemain);
			if(pemain == 1)
			{
				system("cls");
				header();
				printf("\n\n");
					colors(YELLOW);
				printf("   Sorry there is something wrong..");
				printf("\n\n");
				getch();
				menu_english();
			}
			
			else if(pemain == 2)
			{
				system("cls");
				header();
				printf("\n\n");
					colors(YELLOW);
				printf("   Sorry there is something wrong..");
				printf("\n\n");
				getch();
				menu_english();		
			}
			
			else if(pemain == 3)
			{
				menu_english();				
			}
			
			break;
		}
		
		case 2:
		{
			system("cls");
			header();
			printf("\n\n");
				colors(YELLOW);
			printf("   Sorry there is something wrong..");
			printf("\n\n");
			getch();
			menu_english();
			break;
		}
		
		case 3:
		{
			system("cls");
			header();
			printf("\n\n");
				colors(YELLOW);
			printf("   Sorry there is something wrong..");
			printf("\n\n");
			getch();
			menu_english();
			break;
		}	
		
		case 4:
		{
			system("cls");
			header();
			printf("\n\n");
				colors(YELLOW);
			printf("   Sorry there is something wrong..");
			printf("\n\n");
			getch();
			menu_english();
			break;
		}
	}
}

//====================================================================================================
void menu_indo()
{			
	system("cls");
	loading_2();
	system("cls");
	int menu, i, j, pemain = 1;
	
	colors(LIGHT_GREEN);
	header();
	
	colors(YELLOW);
	gotoxy(2,9);
	printf("1. Main");
	gotoxy(2,10);
	printf("2. Cara Bermain");
	gotoxy(2,11);
	printf("3. Kredit");
	gotoxy(2,12);
	printf("4. Keluar");
	gotoxy(2,14);
	printf("Masukkan Angka: ");
	scanf("%i", &menu);
	
	switch(menu)
	{
		case 1:
		{
			system("cls");
			header();
			pemain = jumlah_pemain_indo(pemain);
			
			if(pemain == 1)
			{
				system("cls");
				header();
				printf("\n\n");
					colors(YELLOW);
				printf("   Mohon Maaf karena sedang dalam perbaikan..");
				printf("\n\n");
				getch();
				menu_indo();
			}
			
			else if(pemain == 2)
			{
				system("cls");
				header();
				loading_2();
				utama();						
			}
			
			else if(pemain == 3)
			{
				loading_2();
				menu_indo();				
			}
			
			break;
		}
		
		case 2:
		{
			system("cls");
			header();
			colors(YELLOW);
			howtoplay_indo();
			getch();
    		menu_indo();
			
			break;
		}
		
		case 3:
		{
			system("cls");
			header();
			colors(YELLOW);
			credit_indo();
			getch();
    		menu_indo();
			break;
		}	
		
		case 4:
		{
			system("cls");
			header();
			loading_3();
			getch();
			exit(i);
			break;
		}
	}
}

//====================================================================================================
void howtoplay_indo()
{
	FILE *aturanmain;
	char aturan[panjang];
	
	printf("\n\n");
	aturanmain = fopen("howtoplay_indo.txt", "rt");
	
	while((fgets(aturan, panjang, aturanmain)) != NULL)
	printf("%s\r", aturan);
	
	fclose(aturanmain);
	printf("\n\n");
	colors(BLACK);
}

//====================================================================================================
void credit_indo()
{
	FILE *aturanmain;
	char aturan[panjang];
	
	printf("\n\n");
	aturanmain = fopen("credit_indo.txt", "rt");
	
	while((fgets(aturan, panjang, aturanmain)) != NULL)
	printf("%s\r", aturan);
	
	fclose(aturanmain);
	printf("\n\n");
	colors(BLACK);
}

//====================================================================================================




















// ========================================================================================================================================================
void arena_hijau(int *finish_x, int *finish_y, int *petak1_x, int *petak1_y, int *petak2_x, int *petak2_y, int *bentuk4, int *bentuk1)
{
	int i, j, bentuk2 = 5, bentuk3 = 3;

	colors(LIGHT_GREEN);

	printf("\n\n\n");
	for(i=1; i<11; i++)
	{
		printf("\t\t\t");
		for(j=1; j<11; j++)
		{				

			if(j == *finish_x && i == *finish_y)
			{
				colors(YELLOW);
				printf("%c  ", bentuk2);
				colors(LIGHT_GREEN);
			}			

			else if(j == *petak2_x && i == *petak2_y)
			{
				colors(WHITE);
				printf("%c  ", *bentuk4);
				colors(LIGHT_GREEN);
			}
			
			else if(j == *petak1_x && i == *petak1_y)
			{
				colors(WHITE);
				printf("%c  ", *bentuk1);
				colors(LIGHT_GREEN);
			}

			else if(i == 10 && j != 10 && j != 1)
			{
				printf("%c  ", bentuk2);
			}
			
			else if(i == 1 && j != 10 && j != 1)
			{
				printf("%c  ", bentuk2);
			}
			
			else if(j == 1)
			{
				printf("%c  ", bentuk2);
			}	
			
			else if(j == 10)
			{
				printf("%c  ", bentuk2);
			}
		
			else printf("   ");
		}
		printf("\n\n");
	}
	
	printf("\n\n");
}

// ========================================================================================================================================================
void arena(int *petak1_x, int *petak1_y, int *petak2_x, int *petak2_y, int *bentuk4, int *bentuk1)
{
	int i, j, bentuk2 = 5, bentuk3 = 3;

	colors(YELLOW);

	printf("\n\n\n");
	for(i=1; i<11; i++)
	{
		printf("\t\t\t");
		for(j=1; j<11; j++)
		{				
			if(j == *petak2_x && i == *petak2_y)
			{
				colors(LIGHT_GREEN);
				printf("%c  ", *bentuk4);
				colors(YELLOW);
			}
			
			else if(j == *petak1_x && i == *petak1_y)
			{
				colors(LIGHT_BLUE);
				printf("%c  ", *bentuk1);
				colors(YELLOW);
			}
			
			else if(i == 10 && j != 10 && j != 1)
			{
				printf("%c  ", bentuk2);
			}
			
			else if(i == 1 && j != 10 && j != 1)
			{
				printf("%c  ", bentuk2);
			}
			
			else if(j == 1)
			{
				printf("%c  ", bentuk2);
			}	
			
			else if(j == 10)
			{
				printf("%c  ", bentuk2);
			}
		
			else printf("   ");
		}
		printf("\n\n");
	}
	
	printf("\n\n");
}

// ========================================================================================================================================================
void arena_merah(int *petak1_x, int *petak1_y, int *petak2_x, int *petak2_y, int *bentuk4, int *bentuk1)
{
	int i, j, bentuk2 = 5, bentuk3 = 3;

	colors(RED);

	printf("\n\n\n");
	for(i=1; i<11; i++)
	{
		printf("\t\t\t");
		for(j=1; j<11; j++)
		{				
			if(j == *petak2_x && i == *petak2_y)
			{
				printf("%c  ", *bentuk4);
			}
			
			else if(j == *petak1_x && i == *petak1_y)
			{
				printf("%c  ", *bentuk1);
			}
			
			else if(i == 10 && j != 10 && j != 1)
			{
				printf("%c  ", bentuk2);
			}
			
			else if(i == 1 && j != 10 && j != 1)
			{
				printf("%c  ", bentuk2);
			}
			
			else if(j == 1)
			{
				printf("%c  ", bentuk2);
			}	
			
			else if(j == 10)
			{
				printf("%c  ", bentuk2);
			}
		
			else printf("   ");
		}
		printf("\n\n");
	}
	
	printf("\n\n");
}

// ========================================================================================================================================================
void letak(int *finish_x, int *finish_y, int *monster5_x, int *monster5_y, int *monster6_x, int *monster6_y, int *obat1_x, int *obat1_y, int *obat2_x, int *obat2_y, int *monster1_x, int *monster1_y, int *monster2_x, int *monster2_y, int *monster3_x, int *monster3_y, int *petak1_x, int *petak1_y, int *petak2_x, int *petak2_y)
{
	awal:
	srand(time(NULL));

	*obat1_x=(rand()%8)+2;
	*obat1_y=(rand()%8)+2;

	*obat2_x=(rand()%8)+2;
	*obat2_y=(rand()%8)+2;
		
	*monster1_x=(rand()%8)+2;
	*monster1_y=(rand()%8)+2;

	*monster2_x=(rand()%8)+2;
	*monster2_y=(rand()%8)+2;

	*monster3_x=(rand()%8)+2;
	*monster3_y=(rand()%8)+2;

	*monster6_x=(rand()%8)+2;
	*monster6_y=(rand()%8)+2;

	*monster5_x=(rand()%8)+2;
	*monster5_y=(rand()%8)+2;

	if(	((*monster1_x == *obat1_x) && (*monster1_y == *obat1_y))	||
		((*monster1_x == *obat2_x) && (*monster1_y == *obat2_y))	||
		((*monster1_x == *finish_x) && (*monster1_y == *finish_y))	||
		
		((*monster2_x == *obat1_x) && (*monster2_y == *obat1_y))	||
		((*monster2_x == *obat2_x) && (*monster2_y == *obat2_y))	||
		((*monster2_x == *finish_x) && (*monster2_y == *finish_y))	||
		
		((*monster3_x == *obat1_x) && (*monster3_y == *obat1_y))	||
		((*monster3_x == *obat2_x) && (*monster3_y == *obat2_y))	||
		((*monster3_x == *finish_x) && (*monster3_y == *finish_y))	||
		
		((*monster6_x == *obat1_x) && (*monster6_y == *obat1_y))	||
		((*monster6_x == *obat2_x) && (*monster6_y == *obat2_y))	||
		((*monster6_x == *finish_x) && (*monster6_y == *finish_y))	||
		
		((*monster5_x == *obat1_x) && (*monster5_y == *obat1_y))	||
		((*monster5_x == *obat2_x) && (*monster5_y == *obat2_y))	||
		((*monster5_x == *finish_x) && (*monster5_y == *finish_y))	)
	{
		goto awal;
	}
		
/*	if(	(*petak1_x == *monster1_x && *petak1_y == *monster1_y)	||
		(*petak1_x == *monster2_x && *petak1_y == *monster2_y)	||
		(*petak1_x == *monster3_x && *petak1_y == *monster3_y)	||
		(*petak1_x == *monster4_x && *petak1_y == *monster4_y)	||
		(*petak1_x == *monster5_x && *petak1_y == *monster5_y)	||
		(*petak1_x == *obat1_x && *petak1_y == *obat1_y)		||
		(*petak1_x == *obat2_x && *petak1_y == *obat2_y)		||
		
		(*petak2_x == *monster1_x && *petak2_y == *monster1_y)	||
		(*petak2_x == *monster2_x && *petak2_y == *monster2_y)	||
		(*petak2_x == *monster3_x && *petak2_y == *monster3_y)	||
		(*petak2_x == *monster4_x && *petak2_y == *monster4_y)	||
		(*petak2_x == *monster5_x && *petak2_y == *monster5_y)	||
		(*petak2_x == *obat1_x && *petak2_y == *obat1_y)		||
		(*petak2_x == *obat2_x && *petak2_y == *obat2_y)		){
		goto awal;}*/
}

// ========================================================================================================================================================
void utama()
{
	char nama1[10], nama2[10];

	system("cls");
		colors(LIGHT_BLUE);
	printf("\n\n");
	printf(" Nama Pemain kesatu: ");
	scanf("%s", &nama1);
		colors(LIGHT_GREEN);
	system("cls");
	printf("\n\n");
	printf(" Nama Pemain kedua: ");
	scanf("%s", &nama2);
		colors(WHITE);

	start1: //# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #     START   I   # # # # # # # # # # # # # # # # # # # # 

	int monster1_x, monster1_y;
	int monster2_x, monster2_y;
	int monster3_x, monster3_y;
	int monster6_x, monster6_y;
	int monster5_x, monster5_y;
	
	int finish_x, finish_y;
	
	int obat1_x, obat1_y;
	int obat2_x, obat2_y;

	int i, j, giliran=0;
	char pion;

	int petak1_x = 2, petak1_y = 2;
	int petak2_x = 9, petak2_y = 9;	
	int nyawa1 = 5, nyawa2 = 5;
	int bentuk1 = 30, bentuk2 = 5, bentuk3 = 3, bentuk4 = 30;

	srand(time(NULL));

	finish_x=(rand()%8)+2;
	finish_y=(rand()%8)+2;

	letak(&finish_x, &finish_y, &monster5_x, &monster5_y, &monster6_x, &monster6_y, &obat1_x, &obat1_y, &obat2_x, &obat2_y, &monster1_x, &monster1_y, &monster2_x, &monster2_y, &monster3_x, &monster3_y, &petak1_x, &petak1_y, &petak2_x, &petak2_y);

	start2: //# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #     START   II   # # # # # # # # # # # # # # # # # # # # 
	
	system ("cls");

		colors(LIGHT_BLUE);	
	printf("\n\n");
	printf(" %s", nama1);
	gotoxy(10,2);
	printf(": ");
	for(i=0; i<nyawa1; i++)
	{
		printf("%c ", bentuk3);
	}

		colors(LIGHT_GREEN);
	printf("\n");
	printf(" %s", nama2);
	gotoxy(10,3);
	printf(": ");
	for(i=0; i<nyawa2; i++)
	{
		printf("%c ", bentuk3);
	}

arena(&petak1_x, &petak1_y, &petak2_x, &petak2_y, &bentuk4, &bentuk1);
	
	colors(YELLOW);
	printf("\n Ronde: %d", giliran);
	colors(WHITE);

	printf("\n");
	printf("\n");
	printf(" Tekan tombol:\n");
	printf("  a (untuk ke kiri)\n");
	printf("  w (untuk ke atas)\n");
	printf("  s (untuk ke bawah)\n");
	printf("  d (untuk ke kanan)\n");
	printf(" Lalu tekan 'enter' untuk mulai melangkah");
	printf("\n");
	printf("\n");

	if(giliran % 2 == 0)
	{
		colors(LIGHT_BLUE);
		printf(" Giliran: %s", nama1);
	}
	
	else if(giliran % 2 == 1)
	{
		colors(LIGHT_GREEN);
		printf(" Giliran: %s", nama2);
	}
	
		colors(WHITE);
		
	printf("\n");
	printf("\n");	
	printf(" Langkah: ");
	scanf("%s", &pion);

	if(giliran % 2 == 0)
	{
		switch(pion)
		{
			case 'd':
			{
				petak1_x = petak1_x + 1;
				if(petak1_x > 9)
				{
					petak1_x = 9;
				}
				
				bentuk1 = 16;
				break;
			}
	
			case 'a':
			{
				petak1_x = petak1_x - 1;
				if(petak1_x < 2)
				{
					petak1_x = 2;
				}
				
				bentuk1 = 17;
				break;
			}
				
			case 's':
			{		
				petak1_y = petak1_y + 1;
				if(petak1_y > 9)
				{
					petak1_y = 9;
				}
				bentuk1 = 31;
				break;
			}

			case 'w':
			{
				petak1_y = petak1_y - 1;
				if(petak1_y < 2)
				{
					petak1_y = 2;
				}
			
				bentuk1 = 30;
				break;
			}
			
			default:
			{	
				colors(RED);
				printf("\n\n");
				printf("Maaf, giliran anda kami skip!");
				colors(WHITE);
				getch();
			}
		}

		
		if(	(petak1_x == monster1_x && petak1_y == monster1_y)	||
			(petak1_x == monster2_x && petak1_y == monster2_y)	||
			(petak1_x == monster3_x && petak1_y == monster3_y)	||
			(petak1_x == monster6_x && petak1_y == monster6_y)	||
			(petak1_x == monster5_x && petak1_y == monster5_y)	)
		{
			if(petak1_x == monster1_x && petak1_y == monster1_y)
			{
				nyawa1 = nyawa1 - 1;
			}

			else if(petak1_x == monster2_x && petak1_y == monster2_y)
			{
				nyawa1 = nyawa1 - 2;
			}

			else if(petak1_x == monster3_x && petak1_y == monster3_y)
			{
				nyawa1 = nyawa1 - 3;
			}

/*			else if(petak1_x == monster6_x && petak1_y == monster6_y)
			{
				nyawa1 = nyawa1 - 4;
			}
*/
			else if(petak1_x == monster5_x && petak1_y == monster5_y)
			{
				nyawa1 = nyawa1 - 5;
			}

			system ("cls");

				colors(RED);	
			printf("\n\n");
			printf(" %s", nama1);
			gotoxy(10,2);
			printf(": ");
			for(i=0; i<nyawa1; i++)
			{
				printf("%c ", bentuk3);
			}

				colors(LIGHT_GREEN);
			printf("\n");
			printf(" %s", nama2);
			gotoxy(10,3);
			printf(": ");
			for(i=0; i<nyawa2; i++)
			{
				printf("%c ", bentuk3);
			}

			arena_merah(&petak1_x, &petak1_y, &petak2_x, &petak2_y, &bentuk4, &bentuk1);
			judgement1(&monster6_x, &monster6_y, &monster5_x, &monster5_y, &finish_x, &finish_y, &obat1_x, &obat1_y, &obat2_x, &obat2_y, &monster1_x, &monster1_y, &monster2_x, &monster2_y, &monster3_x, &monster3_y, &petak1_x, &petak1_y, &petak2_x, &petak2_y, &nyawa1, &nyawa2);
		}

		else judgement1(&monster6_x, &monster6_y, &monster5_x, &monster5_y, &finish_x, &finish_y, &obat1_x, &obat1_y, &obat2_x, &obat2_y, &monster1_x, &monster1_y, &monster2_x, &monster2_y, &monster3_x, &monster3_y, &petak1_x, &petak1_y, &petak2_x, &petak2_y, &nyawa1, &nyawa2);

		if(petak1_x == finish_x && petak1_y == finish_y)
		{
			system ("cls");

				colors(YELLOW);	
			printf("\n\n");
			printf(" %s", nama1);
			gotoxy(10,2);
			printf(": ");
			for(i=0; i<nyawa1; i++)
			{
				printf("%c ", bentuk3);
			}

				colors(YELLOW);
			printf("\n");
			printf(" %s", nama2);
			gotoxy(10,3);
			printf(": ");
			for(i=0; i<nyawa2; i++)
			{
				printf("%c ", bentuk3);
			}
			arena_hijau(&finish_x, &finish_y, &petak1_x, &petak1_y, &petak2_x, &petak2_y, &bentuk4, &bentuk1);

			colors(YELLOW);
			printf("\n\n\t\t\t  ");
			char Loading[35] = "........Selamat!........";
			for(i=0; i<35; i++){
				printf("%c", Loading[i]);
				for(j=0; j<25000000; j++){
				j=j;
				}
			}
			printf("\n\n\t\t\t  ");
			char Loading2[35] = "Kau menemukan tanamannya";
			for(i=0; i<35; i++){
				printf("%c", Loading2[i]);
				for(j=0; j<25000000; j++){
				j=j;
				}
			}
			
			int lanjut;
			
			printf("\n\n");
			printf(" Main lagi? \n");
			printf(" 1. Ya \n");
			printf(" 2. Tidak \n");
			printf(" (Masukkan nomor) : ");
			scanf("%i", &lanjut);
			
				if(lanjut == 1)
				{
					goto start1;
				}
				else if (lanjut == 2)
				{
					menu_indo();
				}
		}
	
		if(nyawa1 <= 0)
		{
			printf("\n\n\t\t\t  ");
			colors(RED);
			char Loading[35] = ".......Game Over......";
				for(i=0; i<35; i++)
				{
					printf("%c", Loading[i]);
						for(j=0; j<25000000; j++)
						{
						j=j;
						}
				}
				
			int lanjut;
			
			colors(RED);
			printf("\n\n");
			printf(" Lanjutkan? \n");
			printf(" 1. Ya \n");
			printf(" 2. Tidak \n");
			printf(" (Masukkan nomor) : ");
			scanf("%i", &lanjut);
			
			if(lanjut == 1)
			{
				goto start1;
			}
			else if (lanjut == 2)
			{
				menu_indo();
			}
		}
	
	}
		
	else if(giliran % 2 == 1)
	{
		switch(pion)
		{
			case 'd':
			{
				petak2_x = petak2_x + 1;
				if(petak2_x > 9)
				{
					petak2_x = 9;
				}
				
				bentuk4 = 16;
				break;
			}
	
			case 'a':
			{
				petak2_x = petak2_x - 1;
				if(petak2_x < 2)
				{
					petak2_x = 2;
				}
				
				bentuk4 = 17;
				break;
			}
				
			case 's':
			{		
				petak2_y = petak2_y + 1;
				if(petak2_y > 9)
				{
					petak2_y = 9;
				}
				bentuk4 = 31;
				break;
			}

			case 'w':
			{
				petak2_y = petak2_y - 1;
				if(petak2_y < 2)
				{
					petak2_y = 2;
				}
			
				bentuk4 = 30;
				break;
			}
			
			default:
			{	
				colors(RED);
				printf("\n\n");
				printf("Maaf, giliran anda kami skip!");
				colors(WHITE);
				getch();
			}
		}

		if(	(petak2_x == monster1_x && petak2_y == monster1_y)	||
			(petak2_x == monster2_x && petak2_y == monster2_y)	||
			(petak2_x == monster3_x && petak2_y == monster3_y)	||
			(petak2_x == monster6_x && petak2_y == monster6_y)	||
			(petak2_x == monster5_x && petak2_y == monster5_y)	)
		{
			if(petak2_x == monster1_x && petak2_y == monster1_y)
			{
				nyawa2 = nyawa2 - 1;
			}

			else if(petak2_x == monster2_x && petak2_y == monster2_y)
			{
				nyawa2 = nyawa2 - 2;
			}

			else if(petak2_x == monster3_x && petak2_y == monster3_y)
			{
				nyawa2 = nyawa2 - 3;
			}

/*			else if(petak2_x == monster6_x && petak2_y == monster6_y)
			{
				nyawa2 = nyawa2 - 4;
			}
*/
			else if(petak2_x == monster5_x && petak2_y == monster5_y)
			{
				nyawa2 = nyawa2 - 5;
			}

			system ("cls");

				colors(LIGHT_BLUE);	
			printf("\n\n");
			printf(" %s", nama1);
			gotoxy(10,2);
			printf(": ");
			for(i=0; i<nyawa1; i++)
			{
				printf("%c ", bentuk3);
			}

				colors(RED);
			printf("\n");
			printf(" %s", nama2);
			gotoxy(10,3);
			printf(": ");
			for(i=0; i<nyawa2; i++)
			{
				printf("%c ", bentuk3);
			}

			arena_merah(&petak1_x, &petak1_y, &petak2_x, &petak2_y, &bentuk4, &bentuk1);
			judgement2(&monster6_x, &monster6_y, &monster5_x, &monster5_y, &finish_x, &finish_y, &obat1_x, &obat1_y, &obat2_x, &obat2_y, &monster1_x, &monster1_y, &monster2_x, &monster2_y, &monster3_x, &monster3_y, &petak1_x, &petak1_y, &petak2_x, &petak2_y, &nyawa1, &nyawa2);
		}

		else judgement2(&monster6_x, &monster6_y, &monster5_x, &monster5_y, &finish_x, &finish_y, &obat1_x, &obat1_y, &obat2_x, &obat2_y, &monster1_x, &monster1_y, &monster2_x, &monster2_y, &monster3_x, &monster3_y, &petak1_x, &petak1_y, &petak2_x, &petak2_y, &nyawa1, &nyawa2);	
	
		if(petak2_x == finish_x && petak2_y == finish_y)
		{
			system ("cls");

				colors(YELLOW);	
			printf("\n\n");
			printf(" %s", nama1);
			gotoxy(10,2);
			printf(": ");
			for(i=0; i<nyawa1; i++)
			{
				printf("%c ", bentuk3);
			}

				colors(YELLOW);
			printf("\n");
			printf(" %s", nama2);
			gotoxy(10,3);
			printf(": ");
			for(i=0; i<nyawa2; i++)
			{
				printf("%c ", bentuk3);
			}
			arena_hijau(&finish_x, &finish_y, &petak1_x, &petak1_y, &petak2_x, &petak2_y, &bentuk4, &bentuk1);

			colors(YELLOW);
			printf("\n\n\t\t\t  ");
			char Loading[35] = "........Selamat!........";
			for(i=0; i<35; i++){
				printf("%c", Loading[i]);
				for(j=0; j<25000000; j++){
				j=j;
				}
			}
			printf("\n\n\t\t\t  ");
			char Loading2[35] = "Kau menemukan tanamannya";
			for(i=0; i<35; i++){
				printf("%c", Loading2[i]);
				for(j=0; j<25000000; j++){
				j=j;
				}
			}
			
			int lanjut;
			
			printf("\n\n");
			printf(" Main lagi? \n");
			printf(" 1. Ya \n");
			printf(" 2. Tidak \n");
			printf(" (Masukkan nomor) : ");
			scanf("%i", &lanjut);
			
			if(lanjut == 1)
			{
				goto start1;
			}
			else if (lanjut == 2)
			{
				menu_indo();
			}
		}
	
		if(nyawa2 <= 0)
		{
			printf("\n\n\t\t\t  ");
			colors(RED);
			char Loading[35] = ".......Game Over......";
				for(i=0; i<35; i++)
				{
					printf("%c", Loading[i]);
						for(j=0; j<25000000; j++)
						{
						j=j;
						}
				}
				
			int lanjut;
			
			colors(RED);
			printf("\n\n");
			printf(" Lanjutkan? \n");
			printf(" 1. Ya \n");
			printf(" 2. Tidak \n");
			printf(" (Masukkan nomor) : ");
			scanf("%i", &lanjut);
			
			if(lanjut == 1)
			{
				goto start1;
			}
			else if (lanjut == 2)
			{
				menu_indo();
			}
		}
	
	}
	
	giliran++;
	
	goto start2;
}

// ========================================================================================================================================================
void judgement2 (int *finish_x, int *finish_y, int *monster5_x, int *monster5_y, int *monster6_x, int *monster6_y, int *obat1_x, int *obat1_y, int *obat2_x, int *obat2_y, int *monster1_x, int *monster1_y, int *monster2_x, int *monster2_y, int *monster3_x, int *monster3_y, int *petak1_x, int *petak1_y, int *petak2_x, int *petak2_y, int *nyawa1, int *nyawa2)
{
	int i,j;

	if(*petak2_x == *monster1_x && *petak2_y == *monster1_y){
		printf("\n\n\t\t\t  ");
		colors(GREEN);
		char Loading[35] = "......Ranjau Hijau......";
		for(i=0; i<35; i++){
			printf("%c", Loading[i]);
				for(j=0; j<25000000; j++){
					j=j;
				}
		}
		letak(&*finish_x, &*finish_y, &*monster5_x, &*monster5_y, &*monster6_x, &*monster6_y, &*obat1_x, &*obat1_y, &*obat2_x, &*obat2_y, &*monster1_x, &*monster1_y, &*monster2_x, &*monster2_y, &*monster3_x, &*monster3_y, &*petak1_x, &*petak1_y, &*petak2_x, &*petak2_y);
	}

	else if(*petak2_x == *monster2_x && *petak2_y == *monster2_y)
	{
		printf("\n\n\t\t\t  ");
		colors(BLUE);
		char Loading[35] = "......Ranjau Biru.......";
		for(i=0; i<35; i++){
			printf("%c", Loading[i]);
				for(j=0; j<25000000; j++){
					j=j;
				}
		}
		letak(&*finish_x, &*finish_y, &*monster5_x, &*monster5_y, &*monster6_x, &*monster6_y, &*obat1_x, &*obat1_y, &*obat2_x, &*obat2_y, &*monster1_x, &*monster1_y, &*monster2_x, &*monster2_y, &*monster3_x, &*monster3_y, &*petak1_x, &*petak1_y, &*petak2_x, &*petak2_y);
	}

	else if(*petak2_x == *monster3_x && *petak2_y == *monster3_y){
		printf("\n\n\t\t\t  ");
		colors(RED);
		char Loading[35] = "......Ranjau Merah......";
		for(i=0; i<35; i++){
			printf("%c", Loading[i]);
				for(j=0; j<25000000; j++){
					j=j;
				}
		}
		letak(&*finish_x, &*finish_y, &*monster5_x, &*monster5_y, &*monster6_x, &*monster6_y, &*obat1_x, &*obat1_y, &*obat2_x, &*obat2_y, &*monster1_x, &*monster1_y, &*monster2_x, &*monster2_y, &*monster3_x, &*monster3_y, &*petak1_x, &*petak1_y, &*petak2_x, &*petak2_y);
	}

/*
	else if(*petak2_x == *monster6_x && *petak2_y == *monster6_y)
	{
		printf("\n\n\t\t\t  ");
		colors(RED);
		char Loading[35] = "......Ranjau Merah......";
		for(i=0; i<35; i++){
			printf("%c", Loading[i]);
				for(j=0; j<25000000; j++){
					j=j;
				}
		}
	}
*/
	else if(*petak2_x == *monster5_x && *petak2_y == *monster5_y)
	{
		printf("\n\n\t\t\t  ");
		colors(PURPLE);
		char Loading[35] = "......Ranjau Ungu......";
		for(i=0; i<35; i++){
			printf("%c", Loading[i]);
				for(j=0; j<25000000; j++){
					j=j;
				}
		}
		letak(&*finish_x, &*finish_y, &*monster5_x, &*monster5_y, &*monster6_x, &*monster6_y, &*obat1_x, &*obat1_y, &*obat2_x, &*obat2_y, &*monster1_x, &*monster1_y, &*monster2_x, &*monster2_y, &*monster3_x, &*monster3_y, &*petak1_x, &*petak1_y, &*petak2_x, &*petak2_y);
	}
/*
	if(*petak2_x == *obat1_x && *petak2_y == *obat1_y)
	{
		*nyawa2 = *nyawa2 + 1;
		colors(LIGHT_GREEN);		
		printf("\n\n\t\t\t  ");
		char Loading[35] = "...Aku Menemukan Obat...";
		for(i=0; i<35; i++)
		{
			printf("%c", Loading[i]);
			for(j=0; j<25000000; j++)
			{
			j=j;
			}
		}
		colors(WHITE);	
		obat1_x = 0;
		obat1_y = 0;	
	}
*/
 	if(*petak2_x == *obat2_x && *petak2_y == *obat2_y)
	 {
		*nyawa2 = *nyawa2 + 1;
		colors(LIGHT_GREEN);		
		printf("\n\n\t\t\t  ");
		char Loading[35] = "...Aku Menemukan Obat...";
		for(i=0; i<35; i++)
		{
			printf("%c", Loading[i]);
			for(j=0; j<25000000; j++)
			{
			j=j;
			}
		}
		colors(WHITE);		
		letak(&*finish_x, &*finish_y, &*monster5_x, &*monster5_y, &*monster6_x, &*monster6_y, &*obat1_x, &*obat1_y, &*obat2_x, &*obat2_y, &*monster1_x, &*monster1_y, &*monster2_x, &*monster2_y, &*monster3_x, &*monster3_y, &*petak1_x, &*petak1_y, &*petak2_x, &*petak2_y);
	}
	
	if(			(*petak2_x != *finish_x) && (*petak2_y != *finish_y) &&
				((*petak2_x - *finish_x) < 2 && (*petak2_x - *finish_x) > -2) &&
				((*petak2_y - *finish_y) < 2 && (*petak2_y - *finish_y) > -2) )
	{
		colors(YELLOW);
		printf("\n\n\t\t\t  ");
		char Loading[35] = "Tanamannya di sekitar sini";
		for(i=0; i<35; i++){
			printf("%c", Loading[i]);
			for(j=0; j<25000000; j++){
			j=j;
			}
		}
		colors(WHITE);
	}
}

// ========================================================================================================================================================
void judgement1 (int *finish_x, int *finish_y, int *monster5_x, int *monster5_y, int *monster6_x, int *monster6_y, int *obat1_x, int *obat1_y, int *obat2_x, int *obat2_y, int *monster1_x, int *monster1_y, int *monster2_x, int *monster2_y, int *monster3_x, int *monster3_y, int *petak1_x, int *petak1_y, int *petak2_x, int *petak2_y, int *nyawa1, int *nyawa2)
{
	int i,j;
	
	if(*petak1_x == *monster1_x && *petak1_y == *monster1_y){
		printf("\n\n\t\t\t  ");
		colors(GREEN);
		char Loading[35] = ".....Ranjau Hijau......";
		for(i=0; i<35; i++){
			printf("%c", Loading[i]);
				for(j=0; j<25000000; j++){
					j=j;
				}
		}
		letak(&*finish_x, &*finish_y, &*monster5_x, &*monster5_y, &*monster6_x, &*monster6_y, &*obat1_x, &*obat1_y, &*obat2_x, &*obat2_y, &*monster1_x, &*monster1_y, &*monster2_x, &*monster2_y, &*monster3_x, &*monster3_y, &*petak1_x, &*petak1_y, &*petak2_x, &*petak2_y);
	}

	else if(*petak1_x == *monster2_x && *petak1_y == *monster2_y)
	{
		printf("\n\n\t\t\t  ");
		colors(BLUE);
		char Loading[35] = "......Ranjau Biru......";
		for(i=0; i<35; i++){
			printf("%c", Loading[i]);
				for(j=0; j<25000000; j++){
					j=j;
				}
		}
		letak(&*finish_x, &*finish_y, &*monster5_x, &*monster5_y, &*monster6_x, &*monster6_y, &*obat1_x, &*obat1_y, &*obat2_x, &*obat2_y, &*monster1_x, &*monster1_y, &*monster2_x, &*monster2_y, &*monster3_x, &*monster3_y, &*petak1_x, &*petak1_y, &*petak2_x, &*petak2_y);
	}

	else if(*petak1_x == *monster3_x && *petak1_y == *monster3_y){
		printf("\n\n\t\t\t  ");
		colors(RED);
		char Loading[35] = "......Ranjau Merah.....";
		for(i=0; i<35; i++){
			printf("%c", Loading[i]);
				for(j=0; j<25000000; j++){
					j=j;
				}
		}
		letak(&*finish_x, &*finish_y, &*monster5_x, &*monster5_y, &*monster6_x, &*monster6_y, &*obat1_x, &*obat1_y, &*obat2_x, &*obat2_y, &*monster1_x, &*monster1_y, &*monster2_x, &*monster2_y, &*monster3_x, &*monster3_y, &*petak1_x, &*petak1_y, &*petak2_x, &*petak2_y);
	}
/*
	else if(*petak1_x == *monster6_x && *petak1_y == *monster6_y)
	{
		printf("\n\n\t\t\t  ");
		colors(RED);
		char Loading[35] = "......Ranjau Merah......";
		for(i=0; i<35; i++){
			printf("%c", Loading[i]);
				for(j=0; j<25000000; j++){
					j=j;
				}
		}
	}
*/
	else if(*petak1_x == *monster5_x && *petak1_y == *monster5_y)
	{
		printf("\n\n\t\t\t  ");
		colors(PURPLE);
		char Loading[35] = "......Ranjau Ungu......";
		for(i=0; i<35; i++){
			printf("%c", Loading[i]);
				for(j=0; j<25000000; j++){
					j=j;
				}
		}
		letak(&*finish_x, &*finish_y, &*monster5_x, &*monster5_y, &*monster6_x, &*monster6_y, &*obat1_x, &*obat1_y, &*obat2_x, &*obat2_y, &*monster1_x, &*monster1_y, &*monster2_x, &*monster2_y, &*monster3_x, &*monster3_y, &*petak1_x, &*petak1_y, &*petak2_x, &*petak2_y);
	}
/*	
	if(*petak1_x == *obat1_x && *petak1_y == *obat1_y){
		*nyawa1 = *nyawa1 + 1;
		colors(LIGHT_GREEN);		
		printf("\n\n\t\t\t  ");
		char Loading[35] = "...Aku Menemukan Obat...";
		for(i=0; i<35; i++){
			printf("%c", Loading[i]);
			for(j=0; j<25000000; j++){
			j=j;
			}
		}
		colors(WHITE);	
		obat1_x = 0;
		obat1_y = 0;	
	}
*/	
 	if(*petak1_x == *obat2_x && *petak1_y == *obat2_y)
	 {
		*nyawa1 = *nyawa1 + 1;
		colors(LIGHT_GREEN);		
		printf("\n\n\t\t\t  ");
		char Loading[35] = "...Aku Menemukan Obat...";
		for(i=0; i<35; i++){
			printf("%c", Loading[i]);
			for(j=0; j<25000000; j++){
			j=j;
			}
		}
		colors(WHITE);		
		letak(&*finish_x, &*finish_y, &*monster5_x, &*monster5_y, &*monster6_x, &*monster6_y, &*obat1_x, &*obat1_y, &*obat2_x, &*obat2_y, &*monster1_x, &*monster1_y, &*monster2_x, &*monster2_y, &*monster3_x, &*monster3_y, &*petak1_x, &*petak1_y, &*petak2_x, &*petak2_y);
	}

	if(			(*petak1_x != *finish_x) && (*petak1_y != *finish_y) &&
				((*petak1_x - *finish_x) < 2 && (*petak1_x - *finish_x) > -2) &&
				((*petak1_y - *finish_y) < 2 && (*petak1_y - *finish_y) > -2) )
	{
		colors(YELLOW);
		printf("\n\n\t\t\t  ");
		char Loading[35] = "Tanamannya di sekitar sini";
		for(i=0; i<35; i++){
			printf("%c", Loading[i]);
			for(j=0; j<25000000; j++){
			j=j;
			}
		}
		colors(WHITE);
	}
}

