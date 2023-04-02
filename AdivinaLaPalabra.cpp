#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{   
    char *lista[]={"gato","perro","murcielago","hormiga","leon","aguila","elefante","ballena","canguro","pantera"};
    char Palabra[100], PalabraVacia[100], letra;
    
    //Escoger una palabra al azar
    srand(time(NULL));
    short j= rand() % 10;
    system("cls");
    printf("%d \n", j);
    strcpy (Palabra,lista[j]); //copiar la palabra a otra variable 
    printf("%s \n", Palabra);
    short c= strlen(Palabra);  

    printf("ADIVINA LA PALABRA \n");  

    for (short i = 0; i < c; i++)
    {
        PalabraVacia[i]='-';
        //printf("%c", PalabraVacia[i]);
    }

    short espacios=c;
    short intentos=5, aciertos=0;
    do
    {
        system("cls");
        printf("La palabra oculta es %s \n", Palabra);
        printf("Palabra oculta: %s \n", PalabraVacia);
        printf("intentos restantes: %i \n", intentos);
        printf("Los espacios que quedan son %i \n", espacios);
        printf("Ingresa una letra: ");
        letra= getchar();

        for (short j = 0; j < c; j++)
        {
            if (letra == Palabra[j])
            {
                aciertos++;
                espacios = espacios -1;
                PalabraVacia[j]=letra;
            }   
        }

        if (aciertos == 0)
        {
            intentos--;           
        }

        if (intentos == 0)
        {
            break;
        }
        

        if (espacios == 0)
        {
            break;
        }
        
    } while (intentos > 1);

    if (intentos == 0)
    {
        system("cls");
        printf("Lo siento, has perdido \n");
        printf("La palabra oculta era %s \n", Palabra);
    }

    else if (espacios == 0)
    {   
        system("cls");
        printf("Felicitaciones, has ganado \n");
        printf("La palabra oculta era %s \n", Palabra);
    }
}


