
			////////////////////////////////////////////////
			////										////
			////	 Luis Alejandro Oseguera Osorto		////
			////	  Programación Estructurada II		////
			////			 Proyecto Final				////
			////		# Cuenta: 0801199807935			////
			////										////
			////////////////////////////////////////////////

#include <stdio.h>
#include <windows.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>
#include <iostream>

#define Filas 10
#define Columnas 10

int Indice_1, Indice_2;

void Pantalla_seguridad();
void Menu();
void Juego_dos_personas();
void Juego_aleatorio();
void Histograma(int, int, int);
void Histograma_dos_jugadores(int, int, int);
char Regresar_menu();
int Ganador(char[][3]);
int Perdedor(char[][3]);

/*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*/

main()
	{
		srand(time(NULL));
		
		system("title Proyecto de Programacion Estructurada II");
		system("mode con: cols=55 lines=22");
		
		Pantalla_seguridad();
		
		return 0;
	}

/*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*/

void Pantalla_seguridad()
	{
		int Correcto=0, Intentos_usuario=3, Intentos_contrasena=3, Contador_contrasena=0, Indice_contrasena=0;
		char Usuario_ingresado[Columnas], Usuario[Filas][Columnas]={{"KATTIA"},{"JULISSA"}},
			 Contrasena_ingresada[Columnas], Contrasena[Filas][Columnas]={{"AITTAK"},{"ASSILUJ"}};
		
		printf("\n\t         PANTALLA DE SEGURIDAD \n\t         ******** ** ********* \n\t");
		
		do
			{
				system("color 1b");
				
				printf("\n\t  > Ingrese el usuario: ");
				scanf("%s", &Usuario_ingresado);
				
				Correcto = strcmp(Usuario_ingresado, Usuario[0]);
				
				if(Correcto != 0)
					Correcto = strcmp(Usuario_ingresado, Usuario[1]);
				
				if(Correcto != 0)
					{
						printf("\a\n    %cERROR! Usuario no valido. Le quedan %d intentos. \n", 173,Intentos_usuario);
						Intentos_usuario--;
						
						system("color 40");
						Sleep(500);
						system("color 1b");
					}
				
				if(Intentos_usuario < 0)
					{
						system("cls");
						system("color 40");
						printf("\n   Ha excedido los tres intentos, %csistema bloqueado! \n", 173);
						exit (-1);
					}
			}
		while(Correcto != 0);
		
		Correcto = 0;
		
		do
			{
				system("color 1b");
				
				Indice_contrasena = 0;
				
				printf("\n\t  > Ingrese la contrase%ca: ", 164);
				
				while(Contrasena_ingresada[Indice_contrasena] != 13)
					{
						Contrasena_ingresada[Indice_contrasena] = getch();
						
						if(Contrasena_ingresada[Indice_contrasena] > 32 && Indice_contrasena < 20)
							{
								putchar('*');
								Indice_contrasena++;
							}
						
						else if(Contrasena_ingresada[Indice_contrasena] == 8 && Indice_contrasena > 0)
							{
								putchar(8);
								putchar(' ');
								putchar(8);
								Indice_contrasena--;
							}
					}
				
				Contrasena_ingresada[Indice_contrasena] = '\0';
				
				Correcto = strcmp(Contrasena_ingresada, Contrasena[0]);
				
				if(Correcto != 0)
					Correcto = strcmp(Contrasena_ingresada, Contrasena[1]);
				
				if(Correcto != 0)
					{
						printf("\a\n\n  %cERROR! Contrase%ca incorrecta. Le quedan %d intentos. \n", 173, 164, Intentos_contrasena);
						Intentos_contrasena--;
						
						system("color 40");
						Sleep(500);
						system("color 1b");
					}
				
				if(Intentos_contrasena < 0)
					{
						system("cls");
						system("color 40");
						
						printf("\n   Ha excedido los tres intentos, %csistema bloqueado! \n", 173);
						exit (-1);
					}				
			}
		while(Correcto != 0);
		
		system("cls");
		
		Menu();
	}

/*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*/

void Menu()
	{
		char Opcion, Respuesta;
		
		do
			{
				system("color 80");
				
				printf("\n\t\t    +-+ +-+ +-+ +-+");
				printf("\n\t    @-------|M|-|E|-|N|-|U|------@");
				printf("\n\t    |       +-+ +-+ +-+ +-+      |");
				printf("\n\t    | Un jugador . . . . . . [A] |");
				printf("\n\t    | Dos jugadorres . . . . [B] |");
				printf("\n\t    | Salir del juego. . . . [C] |");
				printf("\n\t    @----------------------------@");
				
				do
					{
						printf("\n\n\t      > Ingrese una opcion: ");
						scanf("%s", &Opcion);
						Opcion = toupper(Opcion);
						
						if(Opcion != 'A' && Opcion != 'B' && Opcion != 'C')
							printf("\a\n\t  %cERROR! Ingrese una opcion valida. ", 173);
					}
				while(Opcion != 'A' && Opcion != 'B' && Opcion != 'C');
				
				switch(Opcion)
					{
						case'A':
							Juego_aleatorio();
							Respuesta = Regresar_menu();
							break;
						
						case'B':
							Juego_dos_personas();
							Respuesta = Regresar_menu();
							break;
						
						default:
							exit (-1);
					}
			}
		while(Respuesta == 'S');
	}

/*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*/

void Juego_aleatorio()
	{
		int Contador_ganadas=0, Contador_perdidas=0, Contador_empate=0;
		char Respuesta;
		
		do
			{
				int Fila_ingresada=0, Columna_ingresada=0, Fila_aleatoria=0, Columna_aleatoria=0, Seguir=0, Mensaje_ganador=0, Contador_veces=0;
				char Posicion_principal[3][3];
				
				system("cls");
				system("color 3f");
				
				for(Indice_1=0; Indice_1 < 3; Indice_1++)
					{
						for(Indice_2=0; Indice_2 < 3; Indice_2++)
							{
								Posicion_principal[Indice_1][Indice_2] = '_';
							}
					}
				
				do
					{
						printf("\n\t\t %c%cA JUGAR!! \n\t  (Recuerda que eres la 'X') \n", 173, 173);
						
						printf("\n\t\t    1  2  3 <- Columnas \n\t\t    _  _  _ \n       Filas -> ");
						
						for(Indice_1=0; Indice_1 < 3; Indice_1++)
							{
								printf("%d  ", Indice_1+1);
								
								for(Indice_2=0; Indice_2 < 3; Indice_2++)
									{
										printf("|%c|", Posicion_principal[Indice_1][Indice_2]);
									}
								
								printf("\n\t\t");
							}
						
						Contador_veces++;
						
						do
							{
								do
									{
										Fila_ingresada = 0;
										
										printf("\n\tIngrese un numero para la fila: ");
										scanf("%d", &Fila_ingresada);
										Fila_ingresada--;
										
										if(Fila_ingresada < 0 || Fila_ingresada > 2)
											{
												printf("\a\n  %cERROR! Ingrese un numero entre uno (1) y tres (3). \n", 173);
												fflush(stdin);
											}
									}
								while(Fila_ingresada < 0 || Fila_ingresada > 2);
								
								do
									{
										Columna_ingresada = 0;
										
										printf("\n\tIngrese un numero para la columna: ");
										scanf("%d", &Columna_ingresada);
										Columna_ingresada--;
										
										if(Columna_ingresada < 0 || Columna_ingresada > 2)
											{
												printf("\a\n  %cERROR! Ingrese un numero entre uno (1) y tres (3). \n", 173);
												fflush(stdin);
											}
									}
								while(Columna_ingresada < 0 || Columna_ingresada > 2);
								
								if(Posicion_principal[Fila_ingresada][Columna_ingresada] == 'X' || Posicion_principal[Fila_ingresada][Columna_ingresada] == 'O')
									printf("\a\n     %cERROR! La fila %d y comlumna %d ya esta ocupada. \n     Ingrese otros valores. \n", 173, Fila_ingresada+1, Columna_ingresada+1);
							}
						while(Posicion_principal[Fila_ingresada][Columna_ingresada] == 'X' || Posicion_principal[Fila_ingresada][Columna_ingresada] == 'O');
						
						Posicion_principal[Fila_ingresada][Columna_ingresada] = 'X';
						
						if(Ganador(Posicion_principal) >= 1)
							{
								Contador_ganadas++;
								Mensaje_ganador++;
							}
						
						if(Mensaje_ganador == 0 && Contador_veces > 4)
							{
								Contador_empate++;
								Mensaje_ganador = -999;
							}
						
						if(Mensaje_ganador == 0)
							{
								do
									{
										Fila_aleatoria = rand()%3;
										Columna_aleatoria = rand()%3;
									}
								while(Posicion_principal[Fila_aleatoria][Columna_aleatoria] == 'X' || Posicion_principal[Fila_aleatoria][Columna_aleatoria] == 'O');
								
								Posicion_principal[Fila_aleatoria][Columna_aleatoria] = 'O';
								
								if(Perdedor(Posicion_principal) >= 1)
									{
										Contador_perdidas++;
										Mensaje_ganador--;
									}
							}
						
						system("cls");
						
						Seguir = Mensaje_ganador;
					}
				while(Seguir == 0);
				
				if(Mensaje_ganador == -999 && Contador_veces > 4)
					Mensaje_ganador = 0;
				
				if(Mensaje_ganador > 0)
					{
						system("color 70");
						
						printf("\n\t\t %c%cGANASTEEE!!\n\n", 173, 173);
					}
					else if(Mensaje_ganador < 0)
						{
							system("color 07");
							
							printf("\n\t\t PERDISTE...\n\n");
						}
						else if(Mensaje_ganador == 0)
							{
								system("color 07");
								
								printf("\n\t\t EMPATE... \n\n");
							}
				
				printf("\n\t\t    1  2  3 <- Columnas \n\t\t    _  _  _ \n       Filas -> ");
				
				for(Indice_1=0; Indice_1 < 3; Indice_1++)
					{
						printf("%d  ", Indice_1+1);
						
						for(Indice_2=0; Indice_2 < 3; Indice_2++)
							{
								printf("|%c|", Posicion_principal[Indice_1][Indice_2]);
							}
						
						printf("\n\t\t");
					}
				
				do
					{
						printf("\n\t%cDesea jugar otra partida? [S/N]: ", 168);
						scanf("%s", &Respuesta);
						Respuesta = toupper(Respuesta);
						
						if(Respuesta != 'S' && Respuesta != 'N')
							printf("\a\n\t%cERROR! Ingrese una opcion valida. \n", 173);
					}
				while(Respuesta != 'S' && Respuesta != 'N');
			}
		while(Respuesta == 'S');
		
		
		Histograma(Contador_ganadas, Contador_perdidas, Contador_empate);
	}

/*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*/

void Juego_dos_personas()
	{
		int Contador_ganadas=0, Contador_perdidas=0, Contador_empate=0;
		char Respuesta;
		
		do
			{
				int Fila_ingresada=0, Columna_ingresada=0, Fila_aleatoria=0, Columna_aleatoria=0, Seguir=0, Mensaje_ganador=0, Contador_veces=0;
				char Posicion_principal[3][3];
				
				system("cls");
				
				for(Indice_1=0; Indice_1 < 3; Indice_1++)
					{
						for(Indice_2=0; Indice_2 < 3; Indice_2++)
							{
								Posicion_principal[Indice_1][Indice_2] = '_';
							}
					}
				
				do
					{
						system("color 09");
						
						printf("\n\t\t %c%cA  JUGAR!! \n\t        (Turno de  'X') \n", 173, 173);
						
						printf("\n\t\t    1  2  3 <- Columnas \n\t\t    _  _  _ \n       Filas -> ");
						
						for(Indice_1=0; Indice_1 < 3; Indice_1++)
							{
								printf("%d  ", Indice_1+1);
								
								for(Indice_2=0; Indice_2 < 3; Indice_2++)
									{
										printf("|%c|", Posicion_principal[Indice_1][Indice_2]);
									}
								
								printf("\n\t\t");
							}
					
						Contador_veces++;
						
						do
							{
								do
									{
										Fila_ingresada = 0;
										
										printf("\n\tIngrese un numero para la fila: ");
										scanf("%d", &Fila_ingresada);
										Fila_ingresada--;
										
										if(Fila_ingresada < 0 || Fila_ingresada > 2)
											{
												printf("\a\n  %cERROR! Ingrese un numero entre uno (1) y tres (3). \n", 173);
												fflush(stdin);
											}
									}
								while(Fila_ingresada < 0 || Fila_ingresada > 2);
								
								do
									{
										Columna_ingresada = 0;
										
										printf("\n\tIngrese un numero para la columna: ");
										scanf("%d", &Columna_ingresada);
										Columna_ingresada--;
										
										if(Columna_ingresada < 0 || Columna_ingresada > 2)
											{
												printf("\a\n  %cERROR! Ingrese un numero entre uno (1) y tres (3). \n", 173);
												fflush(stdin);
											}
									}
								while(Columna_ingresada < 0 || Columna_ingresada > 2);
								
								if(Posicion_principal[Fila_ingresada][Columna_ingresada] == 'X' || Posicion_principal[Fila_ingresada][Columna_ingresada] == 'O')
									printf("\a\n     %cERROR! La fila %d y comlumna %d ya esta ocupada. \n     Ingrese otros valores. \n", 173, Fila_ingresada+1, Columna_ingresada+1);
							}
						while(Posicion_principal[Fila_ingresada][Columna_ingresada] == 'X' || Posicion_principal[Fila_ingresada][Columna_ingresada] == 'O');
						
						Posicion_principal[Fila_ingresada][Columna_ingresada] = 'X';
						
						if(Ganador(Posicion_principal) >= 1)
							{
								Contador_ganadas++;
								Mensaje_ganador++;
							}
						
						if(Mensaje_ganador == 0 && Contador_veces > 4)
							{
								Contador_empate++;
								Mensaje_ganador = -999;
							}
						
						system("cls");
						system("color 0c");
						
						if(Mensaje_ganador == 0)
							{
								printf("\n\t\t %c%cA  JUGAR!! \n\t        (Turno de 'O') \n", 173, 173);
								
								printf("\n\t\t    1  2  3 <- Columnas \n\t\t    _  _  _ \n       Filas -> ");
								
								for(Indice_1=0; Indice_1 < 3; Indice_1++)
									{
										printf("%d  ", Indice_1+1);
										
										for(Indice_2=0; Indice_2 < 3; Indice_2++)
											{
												printf("|%c|", Posicion_principal[Indice_1][Indice_2]);
											}
										
										printf("\n\t\t");
									}
								
								do
									{
										do
											{
												Fila_ingresada = 0;
												
												printf("\n\tIngrese un numero para la fila: ");
												scanf("%d", &Fila_ingresada);
												Fila_ingresada--;
												
												if(Fila_ingresada < 0 || Fila_ingresada > 2)
													printf("\a\n\t%cERROR! Ingrese un numero entre uno (1) y tres (3). \n", 173);
											}
										while(Fila_ingresada < 0 || Fila_ingresada > 2);
										
										do
											{
												Columna_ingresada = 0;
												
												printf("\n\tIngrese un numero para la columna: ");
												scanf("%d", &Columna_ingresada);
												Columna_ingresada--;
												
												if(Columna_ingresada < 0 || Columna_ingresada > 2)
													printf("\a\n\t%cERROR! Ingrese un numero entre uno (1) y tres (3). \n", 173);
											}
										while(Columna_ingresada < 0 || Columna_ingresada > 2);
										
										if(Posicion_principal[Fila_ingresada][Columna_ingresada] == 'X' || Posicion_principal[Fila_ingresada][Columna_ingresada] == 'O')
											printf("\a\n     %cERROR! La fila %d y comlumna %d ya esta ocupada. \n     Ingrese otros valores. \n", 173, Fila_ingresada+1, Columna_ingresada+1);
									}
								while(Posicion_principal[Fila_ingresada][Columna_ingresada] == 'X' || Posicion_principal[Fila_ingresada][Columna_ingresada] == 'O');
								
								Posicion_principal[Fila_ingresada][Columna_ingresada] = 'O';
								
								if(Perdedor(Posicion_principal) >= 1)
									{
										Contador_perdidas++;
										Mensaje_ganador--;
									}
							}
						
						system("cls");
						
						Seguir = Mensaje_ganador;
					}
				while(Seguir == 0);
				
				if(Mensaje_ganador == -999 && Contador_veces > 4)
					Mensaje_ganador = 0;
				
				if(Mensaje_ganador > 0)
					{
						system("color 9f");
						
						printf("\n\t\t %c'X' GANADOOOR! \n\n", 173);
					}
					else if(Mensaje_ganador < 0)
						{
							system("color cf");
							
							printf("\n\t\t %c'O' GANADOOOR! \n\n", 173);
						}
						else if(Mensaje_ganador == 0)
							{
								system("color 07");
								
								printf("\n\t\t EMPATE... \n\n");
							}
				
				printf("\n\t\t    1  2  3 <- Columnas \n\t\t    _  _  _ \n       Filas -> ");
				
				for(Indice_1=0; Indice_1 < 3; Indice_1++)
					{
						printf("%d  ", Indice_1+1);
						
						for(Indice_2=0; Indice_2 < 3; Indice_2++)
							{
								printf("|%c|", Posicion_principal[Indice_1][Indice_2]);
							}
						
						printf("\n\t\t");
					}
				
				do
					{
						printf("\n\t%cDesea jugar otra partida? [S/N]: ", 168);
						scanf("%s", &Respuesta);
						Respuesta = toupper(Respuesta);
						
						if(Respuesta != 'S' && Respuesta != 'N')
							printf("\a\n\t%cERROR! Ingrese una opcion valida. \n", 173);
					}
				while(Respuesta != 'S' && Respuesta != 'N');
			}
		while(Respuesta == 'S');
		
		Histograma_dos_jugadores(Contador_ganadas, Contador_perdidas, Contador_empate);
	}

/*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*/

int Ganador(char Posicion[3][3])
	{
		int Indice_filas=0, Indice_columnas=0, Seguir=0;
				
		if(Posicion[0][0] == 'X' && Posicion[0][1] == 'X' && Posicion[0][2] == 'X')
			Seguir++;
			else if(Posicion[1][0] == 'X' && Posicion[1][1] == 'X' && Posicion[1][2] == 'X')
				Seguir++;
				else if(Posicion[2][0] == 'X' && Posicion[2][1] == 'X' && Posicion[2][2] == 'X')
					Seguir++;
					else if(Posicion[0][0] == 'X' && Posicion[1][0] == 'X' && Posicion[2][0] == 'X')
						Seguir++;
						else if(Posicion[0][1] == 'X' && Posicion[1][1] == 'X' && Posicion[2][1] == 'X')
							Seguir++;
							else if(Posicion[0][2] == 'X' && Posicion[1][2] == 'X' && Posicion[2][2] == 'X')
								Seguir++;
								else if(Posicion[0][0] == 'X' && Posicion[1][1] == 'X' && Posicion[2][2] == 'X')
									Seguir++;
									else if(Posicion[0][2] == 'X' && Posicion[1][1] == 'X' && Posicion[2][0] == 'X')
										Seguir++;
		
		return Seguir;
	}

/*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*/

int Perdedor(char Posicion[3][3])
	{
		int Indice_filas=0, Indice_columnas=0, Seguir=0;
				
		if(Posicion[0][0] == 'O' && Posicion[0][1] == 'O' && Posicion[0][2] == 'O')
			Seguir++;
			else if(Posicion[1][0] == 'O' && Posicion[1][1] == 'O' && Posicion[1][2] == 'O')
				Seguir++;
				else if(Posicion[2][0] == 'O' && Posicion[2][1] == 'O' && Posicion[2][2] == 'O')
					Seguir++;
					else if(Posicion[0][0] == 'O' && Posicion[1][0] == 'O' && Posicion[2][0] == 'O')
						Seguir++;
						else if(Posicion[0][1] == 'O' && Posicion[1][1] == 'O' && Posicion[2][1] == 'O')
							Seguir++;
							else if(Posicion[0][2] == 'O' && Posicion[1][2] == 'O' && Posicion[2][2] == 'O')
								Seguir++;
								else if(Posicion[0][0] == 'O' && Posicion[1][1] == 'O' && Posicion[2][2] == 'O')
									Seguir++;
									else if(Posicion[0][2] == 'O' && Posicion[1][1] == 'O' && Posicion[2][0] == 'O')
										Seguir++;
		
		return Seguir;
	}

/*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*/

void Histograma(int Contador_ganadas, int Contador_perdidas, int Contador_empate)
	{
		printf("\n\t\tHistograma \n\t\t**********");
		
		printf("\n\tVeces ganadas . . . . [%d]: ", Contador_ganadas);
		for(Indice_1=0; Indice_1<Contador_ganadas; Indice_1++)
			printf("*");
		
		printf("\n\tVeces perdidas. . . . [%d]: ", Contador_perdidas);
		for(Indice_1=0; Indice_1<Contador_perdidas; Indice_1++)
			printf("*");
		
		printf("\n\tVeces empatadas . . . [%d]: ", Contador_empate);
		for(Indice_1=0; Indice_1<Contador_empate; Indice_1++)
			printf("*");
		
		printf("\n");
	}

/*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*/

void Histograma_dos_jugadores(int Contador_ganadas, int Contador_perdidas, int Contador_empate)
	{
		printf("\n\t\tHistograma \n\t\t**********");
		
		printf("\n\tGanadas por 'X' . . . [%d]: ", Contador_ganadas);
		for(Indice_1=0; Indice_1<Contador_ganadas; Indice_1++)
			printf("*");
		
		printf("\n\tGanadas por 'O' . . . [%d]: ", Contador_perdidas);
		for(Indice_1=0; Indice_1<Contador_perdidas; Indice_1++)
			printf("*");
		
		printf("\n\tVeces empatadas . . . [%d]: ", Contador_empate);
		for(Indice_1=0; Indice_1<Contador_empate; Indice_1++)
			printf("*");
		
		printf("\n");
	}

/*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*/

char Regresar_menu()
	{
		char Respuesta;
		
		do
			{
				printf("\n\t%cDesea regresar al menu principal? [S/N]: ", 168);
				scanf("%s", &Respuesta);
				Respuesta = toupper(Respuesta);
				
				if(Respuesta != 'S' && Respuesta != 'N')
					printf("\n\n\tcERROR! Ingrese una opcion valida. \n", 173);
			}
		while(Respuesta != 'S' && Respuesta != 'N');
		
		system("cls");
		
		return Respuesta;
	}
