
#include<stdio.h>
#include<string.h>

//funciones
void leerficherodatos(char[]);//solo valen para leer los ficheros con estructura %s %f %f %f %f
void escribirficherodatos(char []);//solo valen para escribir los ficheros con estructura %s %f %f %f %f
void abrirficherolista(char []);
float mediaph(char nombrefichero[]);
void ordenarconductividad(char nombrefichero[]);

int main(){
	int opcionMenu;
	char nombrefic[20], nombrefichero[20],nficheros[20];
	char texto[100], salir;
	char lista[]="lista.txt"; 
	float ph, conductividad, turbidez, coliformes;

		  
	do{
	 
	    printf("BIENVENIDO\n?QUE DESEA HACER?\n1.REGISTRAR NUEVO FICHERO\n2.REVISAR FICHEROS SUBIDOS\n3.MEDIA PH\n4.INSTRUCCIONES Y AYUDA\n5.SALIR\n");
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
	    	
	        abrirficherolista(lista);
            
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
	    	abrirficherolista(lista);
            
	    	printf("introduce el nombre del fichero que quiere mirar\n");
	    	scanf("%s",nombrefichero);
	    	mediaph(nombrefichero);
	    	break;
	    case 4 :
	    	abrirficherolista(lista);
	    	printf("introduce el nombre del fichero que quiere mirar\n");
	    	scanf("%s",nombrefichero);
	    	//ordenarconductividad(nombrefichero);
	    	break;
	    	
	    	
	    	
	    /*
	    	printf("HAS ELEGIDO INSTRUCCIONES Y AYUDA\n");
		    printf("\n\n\n");
		     do{
		        printf("Utilice s y dspues enter para volver al menu principal\n");
		        printf("Utilice s y despues enter para volver al menu principal\n");
		        printf("Bienvenido a ... \nEste programa consiste en un algoritmo para guardar los ficheros de los datdos de diferentes analisis\n");
		        printf("de agua.La opcion uno sirve para registrar nuevos ficheros con datos nuevos de experimentos nuevos.Al introducir un fichero nuevo");
		        printf("se regsitrara en un fichero con el nombre dde todos los ficheros registrados.La opcion dos sirve para leer los datos de ficheros antiguos\n");
		        fflush(stdin);
		        scanf("%c",&salir);
		    	}while(salir=='s'&&salir=='S');
		    	if(salir=='s'&&salir=='S'){
		    			break;
				}
			*/
	    
	    case 5:
	    	printf("HASTA PRONTO\n");
	    	break;
        }
    
	    	

    }while(opcionMenu!=5);
  
  
  return 0;
}

void leerficherodatos(char nombrefichero[]){
	
	
	float ph, conductividad, turbidez, coliformes;
	  char nfuentes[10];
	  char titulo[10], titulo2[10], titulo3[10], titulo4[10], titulo5[10];
	 
	 FILE *fsalida1;
	        fsalida1 = fopen(nombrefichero,"r");
        	if (fsalida1 == NULL) {
	    	    printf("Error, no puede leer el fichero.\n");
	        	
	        }
	        
	        fscanf(fsalida1,"%s %s %s %s %s",titulo, titulo2, titulo3, titulo4, titulo5);
	        printf("%s %s %s %s %s\n",titulo, titulo2, titulo3, titulo4, titulo5);  
            while	(fscanf(fsalida1,"%s %f %f %f %f", nfuentes, &ph, &conductividad, &turbidez, &coliformes)!=EOF){
				
							printf("%s %2.f %2.f %2.f %2.f\n", nfuentes, ph, conductividad, turbidez, coliformes);
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
void abrirficherolista(char []){
	char nombrefic[20], nombrefichero[20],nficheros[20];
	char texto[100], salir; 
	float ph, conductividad, turbidez, coliformes;
		
		fflush(stdin);
	    	printf("Estos son los ficheros creados\n");
	    	
	    	FILE *flista;
	        flista = fopen("lista.txt","r");
        	    if (flista == NULL) {
	    	        printf("Error\n");
	        	    	
	            }
	            fflush(stdin);
            while(fscanf(flista,"%s",nficheros)!=EOF){
							printf("%s\n",nficheros);
							fflush(stdin);
			}
			fclose(flista);
            fflush(stdin);
}
float mediaph(char nombrefichero[]){
	float ph, conductividad, turbidez, coliformes, media=0, i;
	  char nfuentes[10];
	  int contador=0;
	  char titulo[10], titulo2[10], titulo3[10], titulo4[10], titulo5[10];
	
	FILE *fsalida1;
	        fsalida1 = fopen(nombrefichero,"r");
        	if (fsalida1 == NULL) {
	    	    printf("Error, no puede leer el fichero.\n");
	        	
	        }

	        fscanf(fsalida1,"%s %s %s %s %s",titulo, titulo2, titulo3, titulo4, titulo5);
	        printf("%s %s %s %s %s\n",titulo, titulo2, titulo3, titulo4, titulo5);  
            while	(fscanf(fsalida1,"%s %f %f %f %f", nfuentes, &ph, &conductividad, &turbidez, &coliformes)!=EOF){
				
							printf("%s %2.f %2.f %2.f %2.f\n", nfuentes, ph, conductividad, turbidez, coliformes);
							fflush(stdin);
                            contador++;
                            	media+=ph;
						}
						fclose(fsalida1);
		
            
            media=media/contador;
			printf("media = %2.f\n",media);
            
            fflush(stdin);
	return media;
}
/*
void ordenarconductividad(char nombrefichero[]){
	float ph, conductividad, turbidez, coliformes, media;
	  char nfuentes[10];
	  int contador=0, i,aux;
	  int vector[50] ;
	  char titulo[10], titulo2[10], titulo3[10], titulo4[10], titulo5[10];
	
	 FILE *fsalida1;
	        fsalida1 = fopen(nombrefichero,"r");
        	if (fsalida1 == NULL) {
	    	    printf("Error, no puede leer el fichero.\n");
	        	
	        }
	        
	        fscanf(fsalida1,"%s %s %s %s %s",titulo, titulo2, titulo3, titulo4, titulo5);
	        printf("%s %s %s %s %s\n",titulo, titulo2, titulo3, titulo4, titulo5);  
            while	(fscanf(fsalida1,"%s %f %f %f %f", nfuentes, &ph, &conductividad, &turbidez, &coliformes)!=EOF){
				
							printf("%s %2.f %2.f %2.f %2.f\n", nfuentes, ph, conductividad, turbidez, coliformes);
							fflush(stdin);
							conductividad=aux;
						}
						fclose(fsalida1);
            
            fflush(stdin);
	
	
						}
					
				
*/


