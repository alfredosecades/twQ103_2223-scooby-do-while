#include<stdio.h>
#include<string.h>

//funciones
void leerficherodatos(char[]);
void escribirficherodatos(char []);

int main(){
	int opcionMenu;
	char nombrefic[20], nombrefichero[20],nficheros[20];
	char texto[100], salir; 
	float ph, conductividad, turbidez, coliformes;

		  
	do{
	 
	    printf("BIENVENIDO\n¿QUE DESEA HACER?\n1.REGISTRAR NUEVO FICHERO\n2.REVISAR FICHEROS SUBIDOS\n3.INSTRUCCIONES Y AYUDA\n4.SALIR\n");
	    scanf("%d",&opcionMenu);
	    switch (opcionMenu){

	    case 1:
	    	
	    	printf("introduce como quieres llamar al archivo fichero (acuerdese de acabarlo con el formato .txt)\n");
		    scanf("%s", nombrefic);
		    escribirficherodatos(nombrefic);
	        printf("comprobacion del fichero\n");
		    leerficherodatos(nombrefic);
            
            //meter en un fichero llamado listadeficheros todos los ficheros introducidos;
            
            FILE *fsalida;
	            fsalida = fopen("lista.txt","a+");
        	        if (fsalida == NULL) {
	    	            printf("Error\n");
	        	        return 0;	
	                }
            	fflush(stdin);
	    		fprintf(fsalida,"%s\n",nombrefic);
		    	fclose(fsalida);
		    printf("\n\n\n");
    
            do{ //funcion de salir cuando quieras
		        printf("Utilice s y dspues enter para volver al menu principal\n");
		        fflush(stdin);
		        scanf("%c",&salir);
		    	}while(salir=='s'&&salir=='S');
		    	if(salir=='s'&&salir=='S'){
		    			break;
				}
	    
             
         
	    case 2:
	    	//leer el fichero con los fichero que existen 
	    	printf("HAS ELEGIDO REVISAR FICHEROS SUBIDOS\n");
	    	fflush(stdin);
	    	printf("Estos son los ficheros creados\n");
	    	
	    	FILE *flista;
	        flista = fopen("lista.txt","r");
        	    if (flista == NULL) {
	    	        printf("Error\n");
	        	    return 0;	
	            }
	            fflush(stdin);
            while(fscanf(flista,"%s",nficheros)!=EOF){
							printf("%s\n",nficheros);
							fflush(stdin);
			}
			fclose(flista);
            fflush(stdin);
            
	    	//leer el fichero que quieras
	    	
	    	printf("introduce el nombre del fichero que quiere mirar\n");
	    	scanf("%s",nombrefichero);
	    	leerficherodatos(nombrefichero);
		    printf("\n\n\n");
		     do{
		        printf("Utilice s y dspues enter para volver al menu principal\n");
		        fflush(stdin);
		        scanf("%c",&salir);
		    	}while(salir=='s'&&salir=='S');
		    	if(salir=='s'&&salir=='S'){
		    			break;
				}
	    
	    case 3 :
	    	printf("HAS ELEGIDO INSTRUCCIONES Y AYUDA\n");
		    printf("\n\n\n");
		     do{
		        printf("Utilice s y dspues enter para volver al menu principal\n");
		        fflush(stdin);
		        scanf("%c",&salir);
		    	}while(salir=='s'&&salir=='S');
		    	if(salir=='s'&&salir=='S'){
		    			break;
				}
	    
	    case 4:
	    	printf("HASTA PRONTO\n");
	    	break;
        }
    
	    	

    }while(opcionMenu!=4);
  
  
  return 0;
}

void leerficherodatos(char nombrefichero[]){
	
	
	float ph, conductividad, turbidez, coliformes;
	  char nfuentes[10];
	
	 FILE *fsalida1;
	        fsalida1 = fopen(nombrefichero,"r");
        	if (fsalida1 == NULL) {
	    	    printf("Error, no puede leer el fichero.\n");
	        	
	        }
            while	(fscanf(fsalida1,"%s %f %f %f %f", nfuentes, &ph, &conductividad, &turbidez, &coliformes)!=EOF){
				
							printf("%s\t %2.f %2.f %2.f %2.f\n", nfuentes, ph, conductividad, turbidez, coliformes);
							fflush(stdin);
						}
						fclose(fsalida1);
            
            fflush(stdin);
	
}
void escribirficherodatos(char nombrefic[]){
	

	float ph, conductividad, turbidez, coliformes;
    char nfuentes[10]; 
	 FILE *fsalida;
	        fsalida = fopen(nombrefic,"a+");
        	if (fsalida == NULL) {
	    	    printf("Error, no puede crear el fichero.\n");
	        	
	        }
        	printf("que desea introducir (recuerde que es nombre de la fuente, pH, conductividad, turbidez y coliformes)\n");
        	fflush(stdin);
	        scanf("%s %f %f %f %f", nfuentes, &ph, &conductividad, &turbidez, &coliformes);
			fprintf(fsalida,"%s\t %2.f %2.f %2.f %2.f\n", nfuentes, ph, conductividad, turbidez, coliformes);
			fclose(fsalida);
}
