#include<stdio.h>
#include<string.h>



int main(){
	int opcionMenu;
	char orden;
	char nombrefic[20], nombrefichero[20];
	char texto[100]; 
	float ph, conductividad, turbidez, coliformes;
    char nfuentes[10]; 
		  
	do{
	
	printf("BIENVENIDO\n¿QUE DESEA HACER?\n1.REGISTRAR NUEVO FICHERO\n2.REVISAR FICHEROS SUBIDOS\n3.INSTRUCCIONES Y AYUDA\n4.SALIR\n");
	scanf("%d",&opcionMenu);
	switch (opcionMenu){

	    case 1:
	    	
	    	printf("introduce como quieres llamar al archivo fichero\n");
		  scanf("%s", nombrefic);
		  
		    FILE *fsalida;
	        fsalida = fopen(nombrefic, "w");
        	if (fsalida == NULL) {
	    	    printf("Error, no puede crear el fichero.\n");
	        	return 0;	
	        }
        	printf("que desea introducir\n");
        	fflush(stdin);
	        fgets(texto, 100, stdin);	
	        fclose(fsalida);
            printf("Se ha escrito el archivo correctamente.\n");
            break;
             
         
	    case 2:
	    	printf("HAS ELEGIDO REVISAR FICHEROS SUBIDOS\n");
	    	printf("introduce el nombre del fichero que quiere mirar\n");
	    	scanf("%s",nombrefichero);
	    	FILE * fentrada2;
			fentrada2 = fopen(nombrefichero, "r");
						if(fentrada2 == NULL){
							printf("Error en la apertura del fichero\n");
							return 1;
						}
		    printf("El archivo se abrio correctamente\n");
	
						while	(fscanf(fentrada2,"%s %f %f %f %f", &nfuentes, &ph, &conductividad, &turbidez, &coliformes)!=EOF){
						
						     
							printf("%s\t %2.f %2.f %2.f %2.f\n", nfuentes, ph, conductividad, turbidez, coliformes);
							fflush(stdin);
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
