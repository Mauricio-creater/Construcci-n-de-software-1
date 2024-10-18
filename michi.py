#Autor: Ordoñez Silva, Junior
#////Juego Tic-Tac-Toe/////
import time #Contiene la funcion time.sleep()
import random #Contiene la funcion random.randint()
from os import system #Contiene la funcion system, me permite modificar la consola
system("color 02")
Tablero=[[' ',' ',' '],[' ',' ',' '],[' ',' ',' ']]
#Tablero=[[' ']*3]*3 #Asi se crean arrays multidimensionales
end=[False,False] # Result"X", Result2"O""
def imprimir_puntaje():
    with open("python/Score.txt") as puntaje:
        lista_p=puntaje.readlines()
    punt=list(lista_p[0])
    print("Jugador 1 \"X\": ",punt[0]," punto(s)")
    print("Jugador 2 \"O\": ",lista_p[1]," punto(s)")
Puntuacion_global=["",""]
def Leer_Puntajes():
    with open("python/Score.txt") as archivo:
        lista=list(archivo.readlines())
        Puntuacion_global[0]=str(lista[0])
        Puntuacion_global[1]=str(lista[1])
    """
    archivo=open("banner.txt")
    print(archivo.read())
    archivo.close
    """
Leer_Puntajes()
def modificar_dato(a):
    with open("python/Score.txt","r+") as arch:
        arch.write(f"{a[0]}\n{a[1]}")
def Salir(): #Esta funcion me sirve para terminar el programa
   system("cls")
   system("Color 0f")
   exit(0)
def Celebration(): #Funcion que se activa cuando alguien gana
    system("Color 1f")
    time.sleep(0.5)
    system("Color 2f")
    time.sleep(0.5)
    system("Color 3f")
    time.sleep(0.5)
    system("Color 4f")
    time.sleep(0.5)
    system("Color 5f")
    time.sleep(0.5)
    system("Color 6f")
    time.sleep(0.5)
    system("Color 7f")
    time.sleep(0.5)
    system("Color 8f")
    time.sleep(0.5)
    system("Color 9f")
    time.sleep(0.5)
    system("Color af")
    time.sleep(0.5)
    system("Color bf")
    time.sleep(0.5)
    system("Color cf")
    time.sleep(0.5)
    system("Color df")
    time.sleep(0.5)
    system("Color ef")
    time.sleep(0.5)
    system("Color f0")
    time.sleep(0.5)
def tablero(): #Funcion que me es util para imprimir el tablero de michi en pantalla
    print("          0       1       2      X")
    print("      +-------+-------+-------+")
    print("      |       |       |       |")
    print(f"  0   |   {Tablero[0][0]}   |   {Tablero[0][1]}   |   {Tablero[0][2]}   |")
    print("      |       |       |       |")
    print("      +-------+-------+-------+")
    print("      |       |       |       |")
    print(f"  1   |   {Tablero[1][0]}   |   {Tablero[1][1]}   |   {Tablero[1][2]}   |")
    print("      |       |       |       |")
    print("      +-------+-------+-------+")
    print("      |       |       |       |")
    print(f"  2   |   {Tablero[2][0]}   |   {Tablero[2][1]}   |   {Tablero[2][2]}   |")
    print("      |       |       |       |")
    print("      +-------+-------+-------+")
    print("  Y ")
def Comprobacion(a): #Funcion que comprueba si alguno de los jugadores hizo 3 en raya, recibe como paremetro el Tablero de michi original
    Result=[0,0]
    Result2=[0,0]
    for b in range(0,3,1):
        if Result[0]==3 or Result[1]==3:
            end[0]=True
        elif Result2[0]==3 or Result2[1]==3:
            end[1]=True
        Result[0]=0
        Result[1]=0
        Result2[0]=0
        Result2[1]=0
        for c in range(0,3,1):
            if a[c][b]=="X":
                Result[0]+=1 #a[c][b]=="X"
            if a[b][c]=="X":
                Result[1]+=1
            if a[c][b]=="O":
                Result2[0]+=1
            if a[b][c]=="O":
                Result2[1]+=1
    Result[0]=0
    Result[1]=0
    Result2[0]=0
    Result2[1]=0
    c=0
    for b in range(0,3,1):
        if a[c][b]=="X":
            Result[0]+=1
        if a[c][b]=="O":
            Result2[0]+=1
        c+=1
    if Result[0]==3:
        end[0]=True
    if Result2[0]==3:
        end[1]=True
    Result[0]=0
    Result2[0]=0
    x=2
    for b in range(0,3,1):
        if a[b][x]=="X":
            Result[0]+=1
        if a[b][x]=="O":
            Result2[0]+=1
        x-=1
    if Result[0]==3:
        end[0]=True
    if Result2[0]==3:
        end[1]=True
    Result[0]=0
    Result2[0]=0
    cont=0
    for z in range(0,3,1):
        for b in range(0,3,1):
            if a[z][b]=="X" or a[z][b]=="O":
                cont+=1
    
    #Estas son opciones por si alguien gana, se coloco aqui para ahorrar codigo
    if end[0]==True:
        print("-------------------------Ganador Jugador 1 \"X\"------------------------------")
        print("Resultado:")
        tablero()
        nuevo=list(Puntuacion_global[0])
        temp=int(nuevo[0])
        temp+=1
        Puntuacion_global[0]=str(temp)
        modificar_dato(Puntuacion_global)
        Celebration()
        imprimir_puntaje()
        Menu_continuar()
    elif end[1]==True:
        print("-------------------------Ganador Jugador 2 \"O\"------------------------------")
        print("Resultado:")
        tablero()
        temp2=int(Puntuacion_global[1])
        temp2+=1
        Puntuacion_global[1]=str(temp2)
        modificar_dato(Puntuacion_global)
        Celebration()
        imprimir_puntaje()
        Menu_continuar()
    elif (not end[0] and not end[1]) and cont==9:
        print("-------------------------Empate Tecnico------------------------------")
        print("Resultado:")
        tablero()
        time.sleep(3)
        imprimir_puntaje()
        Menu_continuar()
def Menu_continuar(): #Permite al jugador escojer entre seguir jugando o no
    print("Continuar?")
    print("(1) Si")
    print("(2) No")
    option=int(input("Ingrese una opcion: "))
    while option>2 or option<1:
        option=int(input("Intente nuevamente: "))
    if option==2:
        system("Color 0f")
        system("cls")
        print("\n \n \n \n \n \n \n \n \n")
        print("-------------------------------Gracias por jugar!!!----------------------------------")
        Celebration()
        Salir()
    else:
        system("Color 0f")
        time.sleep(1)
        system("cls")
def main_menu(): #Se encarga de imprimir el menu de modos de juego
    print("-------------------------------------------------MICHI PYTHON------------------------------------------------------")
    print("Modo de juego:")
    print("(1) Cooperativo")
    print("(2) PvE (Siempre empiezas tu)")
    print("(3) Maquina vs Maquina (Debes escojer el jugador que comienza)")
    print("\n///////////////////////////////Tabla de puntaje/////////////////////////////")
    imprimir_puntaje()
    print("\n \n \n \n \n \n \n ")
    print("(4) Salir")
def select_character():#Se encarga de mostrar el menu de seleccion de jugador
    print("------------------------------ESCOJE AL JUGADOR--------------------------------------------")
    print("Quien comienza?:")
    print("(1) Jugador 1 \"X\"")
    print("(2) Jugador 2 \"O\"")
    print("\n \n \n \n \n \n \n \n \n \n \n \n ")
def Variable_puntaje():
    puntaje_J=["",""]
    with open("python/Score.txt") as puntaje:
        arr=puntaje.readlines()
        puntaje_J[0]=str(arr[0])
        puntaje_J[1]=str(arr[1])
    return puntaje_J
#####################################################################################################
while True: #El bucle sirve para que el programa continue si el usuario lo desea 
    Tablero=[[' ',' ',' '],[' ',' ',' '],[' ',' ',' ']] #Esto limpia el tablero cunado se inicia una nueva partida
    main_menu()
    option_game=int(input("Ingrese una opcion: ")) #Seleccion de modo de juego
    system("cls")
    while option_game>4 or option_game<1:
        main_menu()
        option_game=int(input("Vuelva a intentarlo: "))
    system("cls")
    if option_game==4: #Esto es por si algun usuario selecciona la opcion "salir" en el menu de modo de juego
        Salir()
    select_character()
    StartX=True
    option_start=int(input("Ingrese una opcion: ")) #Seleccionar jugador
    system("cls")
    while option_start>2 or option_start<1:
        select_character()
        option_start=int(input("Vuelva a intentarlo: "))
        system("cls")
    if option_game==1: #Se ejecuta cuando escojemos la opcion modo "Cooperativo"
        if option_start==2: #Me sirve para saber si el jugador empezara con X u O
            StartX=False
        while(not end[0] and not end[1]):
            print("---------------------------------------------------------------------------------------")
            if StartX==True:
                print("Turno de Jugador 1  \"X\"")
            else:
                print("Turno de Jugador 2 \"O\"")
            tablero()
            print("Ingrese las coordenadas: ")
            Coord_X=int(input("Eje X:"))
            while Coord_X>2 or Coord_X<0:
                Coord_X=int(input("Intente nuevamente, Eje X: "))
            Coord_Y=int(input("Eje Y:"))
            while Coord_Y>2 or Coord_Y<0:
                Coord_Y=int(input("Intente nuevamente, Eje Y: "))
            if Tablero[Coord_Y][Coord_X]=="X" or Tablero[Coord_Y][Coord_X]=="O":
                print("Ese casillero ya esta ocupado")
                time.sleep(3)
            else:
                if StartX==True:
                    Tablero[Coord_Y][Coord_X]="X"
                else:
                    Tablero[Coord_Y][Coord_X]="O"
                StartX=not StartX
            Comprobacion(Tablero)
            system("cls")
            
        end=[False,False]
    elif option_game==2: #Se ejecuta con la opcion modo "PvE"
        if option_start==2:
            StartX=False
        while (not end[0] and not end[1]):
            if StartX==True:
                print("Turno de Jugador 1  \"X\"")
            else:
                print("Turno de Jugador 2 \"O\"")
            tablero()
            print("Ingrese las coordenadas:")
            Coord_X=int(input("Eje X: "))
            while Coord_X>2 or Coord_X<0:
                Coord_X=int(input("Intente nuevamente, Eje X: "))
            Coord_Y=int(input("Eje Y: "))
            while Coord_Y>2 or Coord_Y<0:
                Coord_Y=int(input("Intente nuevamente, Eje Y: "))
            if Tablero[Coord_Y][Coord_X]=="X" or Tablero[Coord_Y][Coord_X]=="O":
                print("Ese casillero ya esta ocupado")
                time.sleep(3)
                system("cls")
                continue
            else:
                if StartX==True:
                    Tablero[Coord_Y][Coord_X]="X"
                else:
                    Tablero[Coord_Y][Coord_X]="O"
                StartX=not StartX
                Comprobacion(Tablero)
                system("cls")
            
            #Cuando le toca a la maquina se ejecuta esto
                Coord_X=random.randint(0,2)
                Coord_Y=random.randint(0,2)
                while Tablero[Coord_Y][Coord_X]=="X" or Tablero[Coord_Y][Coord_X]=="O":
                    #Sirve para buscar casillas donde no se haya jugado todavia
                    Coord_X=random.randint(0,2)
                    Coord_Y=random.randint(0,2)
                if StartX==True:
                    Tablero[Coord_Y][Coord_X]="X"
                else:
                    Tablero[Coord_Y][Coord_X]="O"
                StartX=not StartX
                print("Jugando",end="")
                time.sleep(0.5)
                print(".",end="")
                time.sleep(0.5)
                print(".",end="")
                time.sleep(0.5)
                print(".")
                Comprobacion(Tablero)
                system("cls")
        end=[False,False]
    elif option_game==3: #Se ejecuta con el modo "Maquina vs Maquina"
        if option_start==2:
            StartX=False
        while (not end[0] and not end[1]):
            if StartX==True:
                print("Turno de Jugador 1 \"X\"")
            else:
                print("Turno de Jugador 2 \"O\"")
            tablero()
            Coord_X=random.randint(0,2)
            Coord_Y=random.randint(0,2)
            while Tablero[Coord_Y][Coord_X]=="X" or Tablero[Coord_Y][Coord_X]=="O":
                Coord_X=random.randint(0,2)
                Coord_Y=random.randint(0,2)
            if StartX==True:
                Tablero[Coord_Y][Coord_X]="X"
            else:
                Tablero[Coord_Y][Coord_X]="O"
            StartX=not StartX
            print("Jugando...")
            Comprobacion(Tablero)
            time.sleep(2)
            system("cls")
        end=[False,False]