//TALLER SEMANA 11
//AGUIRRE REMIGIO-MACÍAS ISSAC-HIDALGO MATEO
//LIBRERIAS
#include <stdio.h>  
#include <string.h>
#include <time.h>
#include <stdlib.h>
//CONSTANTES
#define maxLibros 10
//VARIABLES GLOBALES
int numLibros = 0;
int opcion;
//ESTRUCTURAS  
struct Libro{
    int Id;
    char Titulo[100];
    char Autor[50];
    int Año;
    char Estado [10];

};
struct Libro biblioteca[maxLibros];
//FUNCIONES
int idRandom(){
    return (rand() % (9999 - 1000 + 1) + 1000);
}
void limpiarBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
int idUnico(int id) {
    for (int i = 0; i < numLibros; i++) {
        if (biblioteca[i].Id == id)
            return 0;
    }
    return 1;
}
void registrarLibro() {
int cantidad;

    printf("Cuantos libros desea registrar? (maximo %d): ", maxLibros - numLibros);
    while (scanf("%d", &cantidad) != 1 || cantidad < 1 || cantidad > (maxLibros - numLibros)) {
        limpiarBuffer();
        printf("Cantidad invalida. Intente nuevamente: ");
    }
    limpiarBuffer();

for (int i = 0; i < cantidad; i++) {
        printf("\n--- Libro %d ---\n", i + 1);
biblioteca[numLibros].Id = idRandom();

printf("ID del libro: %d\n",biblioteca[numLibros].Id);


printf("Ingrese el titulo del libro (Maximo 100 caracteres): ");
    fgets(biblioteca[numLibros].Titulo, 100, stdin);
    biblioteca[numLibros].Titulo[strcspn(biblioteca[numLibros].Titulo, "\n")] = 0;


printf("Ingrese el autor del libro (Maximo 50 caracteres): ");
    fgets(biblioteca[numLibros].Autor, 50, stdin);
    biblioteca[numLibros].Autor[strcspn(biblioteca[numLibros].Autor,"\n")] = 0;


printf("Ingrese el anio de publicacion: ");
    while (scanf("%d", &biblioteca[numLibros].Año) != 1) {
        limpiarBuffer();
        printf("Anio invalido. Ingrese nuevamente: ");
    }
    limpiarBuffer();


strcpy(biblioteca[numLibros].Estado, "Disponible");

numLibros ++;
}
}
void mostrarLibros() {
    if (numLibros == 0) {
        printf("No hay libros en la biblioteca.\n");
        goto E;
    }

    printf("\n%-5s %-30s %-20s %-10s %-12s\n", "ID", "Titulo", "Autor", "Anio", "Estado");
    printf("-----------------------------------------------------------------------------\n");
    for (int i = 0; i < numLibros; i++) {
        printf("%-5d %-30s %-20s %-10d %-12s\n",
            biblioteca[i].Id, biblioteca[i].Titulo,biblioteca[i].Autor, biblioteca[i].Año,biblioteca[i].Estado);
    }
    E:;
}
void mostrarIdLibros() {
    if (numLibros == 0) {
        printf("No hay libros en la biblioteca.\n");
        goto E;
    }
    printf("\n%-5s %-30s\n", "ID", "Titulo");
    printf("-----------------------------------------------------------------------------\n");
    for (int i = 0; i < numLibros; i++) {
        printf("%-5d %-30s\n",
            biblioteca[i].Id, biblioteca[i].Titulo);
    }
    E:;
}
void buscarLibro() {
    mostrarIdLibros();
    if (numLibros!=0){
    int id, i;
        printf("Ingrese el ID: ");
        scanf("%d", &id);
        limpiarBuffer();

        for (i = 0; i < numLibros; i++) {
            if (biblioteca[i].Id == id) {
                printf("\nLibro encontrado:\n");
                printf("ID: %d\n", biblioteca[i].Id);
                printf("Titulo: %s\n", biblioteca[i].Titulo);
                printf("Autor: %s\n", biblioteca[i].Autor);
                printf("Anio: %d\n", biblioteca[i].Año);
                printf("Estado: %s\n", biblioteca[i].Estado);
                goto A;
            }
        }

        printf("Libro no encontrado.\n");
        goto A;
    }

A:;
    
}
void actualizarEstado() {
    int id;
    printf("Ingrese el ID del libro: ");
    scanf("%d", &id);

    for (int i = 0; i < numLibros; i++) {
        if (biblioteca[i].Id == id) {
            if (strcmp(biblioteca[i].Estado, "Disponible") == 0)
                strcpy(biblioteca[i].Estado, "Prestado");
            else
                strcpy(biblioteca[i].Estado, "Disponible");

            printf("El libro esta: %s\n", biblioteca[i].Estado);
            goto C;
        }
    }
    printf("Libro no encontrado.\n");

    C:;
}
void eliminarLibro() {
    int id;
    printf("Ingrese el ID del libro a eliminar: ");
    scanf("%d", &id);

    for (int i = 0; i < numLibros; i++) {
        if (biblioteca[i].Id == id) {
            for (int j = i; j < numLibros - 1; j++) {
                biblioteca[j] = biblioteca[j + 1];
            }
            numLibros--;
            printf("Libro eliminado\n");
            goto D;
        }
    }
    printf("Libro no encontrado.\n");

    D:;
}
