#include "funciones.h"
void main() {
    srand(time(NULL)); 
    do {
        printf("-----------------------------------------------------------------------------\n");
        printf("------------------------------ Menu Biblioteca ------------------------------\n");
        printf("-----------------------------------------------------------------------------\n");
        printf("|   1. Registrar libro\n");
        printf("|   2. Mostrar todos los libros\n");
        printf("|   3. Buscar libro\n");
        printf("|   4. Actualizar estado de libro\n");
        printf("|   5. Eliminar libro\n");
        printf("|   6. Salir\n");
        printf("-----------------------------------------------------------------------------\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        limpiarBuffer();

        switch (opcion) {
            case 1: registrarLibro(); 
            break;
            case 2: mostrarLibros(); 
            break;
            case 3: buscarLibro(); 
            break;
            case 4: actualizarEstado(); 
            break;
            case 5: eliminarLibro(); 
            break;
            case 6: 
            printf("-----------------------------------------------------------------------------\n");
            printf("-----------------------------Salida correctamente----------------------------\n"); 
            printf("-----------------------------------------------------------------------------\n");
            break;
            default: 
            printf("-----------------------------------------------------------------------------\n");
            printf("---------------------Opcion invalida. Intente nuevamente---------------------\n");
            printf("-----------------------------------------------------------------------------\n");
        }
    } while (opcion != 6);

}

