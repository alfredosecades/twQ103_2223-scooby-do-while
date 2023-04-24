#include<stdio.h>
#include<string.h>

int main(){
	int opcionMenu;
	do{
	
	printf("BIENVENIDO\n¿QUE DESEA HACER?\n1.REGISTRAR NUEVO FICHERO\n2.REVISAR FICHEROS SUBIDOS\n3.INSTRUCCIONES Y AYUDA\n4.SALIR\n");
	scanf("%d",&opcionMenu);
	switch (opcionMenu){

	    case 1:
	    	printf("HAS ELEGIDO REGISTRAR UN NUEVO FICHERO\n");
	    	break;
	    case 2:
	    	printf("HAS ELEGIDO REVISAR FICHEROS SUBIDOS\n");
	    	FILE * fentrada;
						fentrada = fopen("FICHEROS SUBIDOS.txt", "r");
						    if(fentrada == NULL){
							    printf("Error en la apertura del fichero\n");
			return 0;
		}
	    	break;
	    case 3 :
	    	printf("HAS ELEGIDO INSTRUCCIONES Y AYUDA\n");
	    	break;
	    case 4:
	    	printf("HASTA PRONTO\n");
	    	break;
        }
	    	

    }while(opcionMenu!=4);
  
  
  return 0;
}
