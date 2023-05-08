#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
#include <conio.h>

#define MAX 80
#define ARCHIVO_USUARIOS "usuarios.dat"
#define TECLA_ENTER 13
#define TECLA_BACKSPACE 8
#define LONGITUD 5
#define MAX_INTENTOS 3

/* Estructura de cuentas de usuario */
struct usuario {
	char nombre[MAX];
	char password[MAX];
};
typedef struct usuario Usuario;



/* Funciones que manipulan el archivo de usuarios */
char insertarUsuario(Usuario usuario);
char existeUsuario(char nombreUsuario[], Usuario *usuario);
Usuario *obtenerUsuarios(int *);
char logear(char nombreUsuario[], char password[]);

int leerLinea(char *cad, int n);
void leerClave(char *password);

char linea[MAX];

//funciones
void leerficherodatos(char[]);//solo valen para leer los ficheros con estructura %s %f %f %f %f
void escribirficherodatos(char []);//solo valen para escribir los ficheros con estructura %s %f %f %f %f


int banner(){
	printf("--------------------------------------------------*\n");
	char banner[]={"----{ KUNFONT }------{ KUNFONT }-----{ KUNFONT }----"};
	unsigned short longitud, indice, espacio, repite, resto;

	//A CONTINUACION SE PROGRAMA EL BANNER
 
	longitud=strlen(banner);
	for (repite=1; repite<=2; repite++) /* repite el proceso 3 veces */
	{
		// *** IMPRIME EN ORDEN DE IZQUIERDA A DERECHA Y LUEGO DESPLAZA *** 
		for(resto=0; resto<=longitud; resto++) // para caracteres restantes a imprimir 
		{	for (indice=0; indice<=longitud-1-resto; indice++) // seleccion de indices evitando restantes 
			{
				printf("%c", banner[indice]); // imprime indice 
				if (!resto) usleep(1250); // demora el proceso 
			}
			for(espacio=1; espacio<=longitud-resto-1; espacio++)
				printf("\b"); // retrocede 
 
			if (resto) usleep(1750); // demora el proceso 
			printf("\b "); // borra el caracter actual 
		}
 
		for(espacio=1; espacio<=longitud; espacio++) // borra todos los caracteres presentados 
			printf("\b\b ");
		printf("\b"); // se coloca al inicio del desplegado
	}
	printf("----{ KUNFONT }------{  KUNFONT  }-----{  KUNFONT  }----\n");
	printf("----------------------------------------------------*-\n");
	
}

//INTRODUCIMOS LA FUNCIÓN DE UN BANNER FIJO 

int banner_fijo(){
	printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
	printf("*-*-*-*-*-*-*-*-*-*-{ KUNFONT }-*-*-*-*-*-*-*-*-*-{ KUNFONT }-*-*-*-*-*-*-*-*-*{ KUNFONT }-*-*-*-*-*-*\n");
	printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
	
}

//Introducimos una funcion que ofrece informacion

void normativa(){
			printf("\n");
			printf("\n");
	    	printf("NORMATIVA LEGAL DE LA PAGINA:\n");
	        printf("Para consultar los datos de la red de aguas del distrito madrileño seleccionado, debes regristrarte o iniciar sesion si ya tienes una cuenta.\n");
			printf("Los datos recogidos en la pagina proceden de la red publica de aguas del canal de Isabel II de Madrid, ofrecida por el ayuntamiento de la capital.\n");
		    printf("Para cualquier duda acerca del acceso a la web o del uso de los datos de la misma puede escribir al correo de nuestro equipo de marketing:/n jorge.escobar@alumnos.upm.es n");
		    printf("Respetando la Ley mencionada anteriormente, los datos introducidos por los usuarios de la pagina seran tratados de manera interna y no se difundiran /n de ninguna manera, siendo utilizados tan solo para labores de control de la consulta del sistema y sus datos.\n");
			printf("\n");
			printf("Gracias por su atencion, si posee alguna duda puede llamar al telefono del equipo tecnico: 666 46 52 88\n ");
			printf("\n");
			printf("\n");
	
}

//Introducimos otra funcion que ofrece informacion

void aguascaracteristicasdefiniciones(){
			printf("\n");
			printf("\n");
	    	printf("CARACTERISTICAS ESTUDIADAS\n");
	        printf("PH\n");
			printf("TURBIDEZ\n");
		    printf("COLIFORME n");
		    printf("Conductividad\n");
			printf("\n");
			printf("Gracias por su atencion, si posee alguna duda puede llamar al telefono del equipo tecnico informativo: 644 24 06 08\n ");
			printf("\n");
			printf("\n");
	
}

//CREAMOS LA FUNCION QUE PERMITE AÑADIR UN NUEVO USUARIO


void menuRegistrarUsuario() {
	Usuario usuario;
	char nombreUsuario[MAX];
	char respuesta[MAX];
	char repite = 1;
	
	do {
		system("cls");
		printf("\n\t\t\tREGISTRAR USUARIO\n");
		printf("\t\t\t=================\n");
		printf("\n\tIngrese nombre de usuario: ");
		leerLinea(linea, MAX);
		sscanf(linea, "%s", nombreUsuario);

		/* Se verifica que el nombre de usuario no exista */
		if (!existeUsuario(nombreUsuario, &usuario)) {
			strcpy(usuario.nombre, nombreUsuario);

			printf("\tIngrese la clave: ");
			leerLinea(usuario.password, MAX);

			/* Se inserta el usuario en el archivo de usuarios */
			if (insertarUsuario(usuario)) {
				printf("\n\t Los datos fueron registrados satisfactoriamente!\n");

			} else {
				printf("\n\tOcurrio un error al registrar el usuario\n");
				printf("\nInténtelo mas tarde\n");
			}
		} else {
			printf("\n\tEl usuario \"%s\" ya ha sido registrado previamente\n", usuario.nombre);
			printf("\tNo puede registrar dos usuarios con el mismo nombre de usuario.\n");
		}

		printf("\n\tDesea seguir registrando usuarios? [S/N]: ");
		leerLinea(respuesta, MAX);
 
		if (!(strcmp(respuesta, "S") == 0 || strcmp(respuesta, "s") == 0)) {
			repite = 0;
		}

	} while (repite == 1);
}

//CREAMOS LA FUNCION QUE DEJA VER LOS USUARIOS REGISTRADOS

void menuListarUsuarios() {
	int numeroUsuarios;
	Usuario *usuarios;
	int i;

	system("cls");
	usuarios = obtenerUsuarios(&numeroUsuarios); /* Retorna un vector dinámico de usuarios */

	if (numeroUsuarios == 0) {
		printf("\n\tNo existe ningun usuario registrado!\n");

	} else {
		printf("\n\t\t    ==> LISTADO DE PERSONAS REGISTRADAS <==\n");
		printf(" ------------------------------------------------------------------------------\n");
		printf("%10s%25s%25s\n", "#", "NOMBRE", "CONTRASEÑA");
		printf(" ------------------------------------------------------------------------------\n");

		/* Se recorre el vector dinámico de productos */
		for (i = 0; i < numeroUsuarios; i++) {
			printf("%10d%25s%25s\n", (i + 1), usuarios[i].nombre, usuarios[i].password);
		}
		printf(" ------------------------------------------------------------------------------\n");
	}

	// Se libera la memoria asignada al vector dinámico
	free(usuarios);
	usuarios = NULL;
	getchar();
}



//Introducimos la funcion que controla el menu

void menuIniciarSesion() {
	
	
	char nombreUsuario[MAX];
	char password[MAX];
	int intento = 0;
	int loginExitoso = 0;

	do {
		system("cls");
		printf("\n\t\t\tINGRESAR AL SISTEMA\n");
		printf("\t\t\t===================\n");

		printf("\n\t\tUSUARIO: ");
		leerLinea(linea, MAX);
		sscanf(linea, "%s", nombreUsuario);

		printf("\t\tCLAVE: ");
		leerClave(password);
		
		if (logear(nombreUsuario, password)) {
			loginExitoso = 1;
		} else {
			printf("\n\n\t\tUsuario y/o password incorrectos");
			intento++;
			getchar();
		}
	} while (intento < MAX_INTENTOS && loginExitoso == 0);

	if (loginExitoso == 1) {
		menuSistema();
		
	} else {
		printf("\n\tHa sobrepasado el numero maximo de intentos permitidos\n");
		getchar();
	}
}


/* Retorna 1 si se registró el usuario en el archivo correctamente */
char insertarUsuario(Usuario usuario){
	FILE *archivo;
	char insercion = 0;

	/* Abre el archivo en modo de añadidura, para agregar datos al final. Si no existe es creado*/
	archivo = fopen(ARCHIVO_USUARIOS, "ab");

	if (archivo == NULL) {
		insercion = 0;

	} else {
		/* Registra el struct usuario en el archivo */
		fwrite(&usuario, sizeof(usuario), 1, archivo);
		insercion = 1;

		/* Cierra el archivo */
		fclose(archivo);
	}

	return insercion;
}

/* Retorna 1 si existe el nombre de usuario. Retorna el usuario buscado si existe */
char existeUsuario(char nombreUsuario[], Usuario* usuario){
	FILE *archivo;
	char existe;

	/* Abre el archivo en modo de lectura */
	archivo = fopen(ARCHIVO_USUARIOS, "rb");

	if (archivo == NULL) {
		existe = 0;

	} else {
		existe = 0;

		/* Lee secuencialmente del archivo de usuarios */
		fread(&(*usuario), sizeof(*usuario), 1, archivo);
		while (!feof(archivo)) {
			if (strcmp((*usuario).nombre, nombreUsuario) == 0) {
				/* Encuentra un usuario del archivo con el nombre de usuario buscado */
				existe = 1;
				break;
			}

			fread(&(*usuario), sizeof(*usuario), 1, archivo);
		}

		/* Cierra el archivo*/
		fclose(archivo);
	}

	return existe;
}

Usuario *obtenerUsuarios(int *n) {
	FILE *archivo;
	Usuario usuario;
	Usuario *usuarios; /* Vector dinámico de usuarios */
	int i;

	/* Abre el archivo en modo lectura */
	archivo = fopen(ARCHIVO_USUARIOS, "rb");
 
	if (archivo == NULL) { /* Si no se pudo abrir el archivo, el valor de archivo es NULL */
		*n = 0; /* No se pudo abrir. Se considera n = 0 */
		usuarios = NULL;
 
	} else {
 
		fseek(archivo, 0, SEEK_END); /* Posiciona el cursor al final del archivo */
		*n = ftell(archivo) / sizeof(Usuario); /* # de usuarios almacenados en el archivo. (# de registros) */
		usuarios = (Usuario *)malloc((*n) * sizeof(Usuario)); /* Se asigna memoria para todos los usuarios almacenados en el archivo */
 
		/* Se recorre el archivo secuencialmente */
		fseek(archivo, 0, SEEK_SET); /* Posiciona el cursor al principio del archivo */
		fread(&usuario, sizeof(usuario), 1, archivo);
		i = 0;
		while (!feof(archivo)) {
			usuarios[i++] = usuario;
			fread(&usuario, sizeof(usuario), 1, archivo);
		}
 
		/* Cierra el archivo */
		fclose(archivo);
	}
 
	return usuarios;
}

/* Retorna 1 o 0 si el usuario y password son correctos para un usuario en particular */
char logear(char nombreUsuario[], char password[]) {
	FILE *archivo;
	char logeoExitoso;
	Usuario usuario;

	/* Abre el archivo en modo de lectura */
	archivo = fopen(ARCHIVO_USUARIOS, "rb");

	if (archivo == NULL) {
		logeoExitoso = 0;

	} else {
		logeoExitoso = 0;

		/* Lee secuencialmente del archivo de usuarios */
		fread(&usuario, sizeof(usuario), 1, archivo);
		while (!feof(archivo)) {
			if (strcmp(usuario.nombre, nombreUsuario) == 0 && strcmp(usuario.password, password) == 0) {
				/* Encuentra un usuario del archivo con el nombre de usuario y password buscado */
				logeoExitoso = 1;
				break;
			}

			fread(&usuario, sizeof(usuario), 1, archivo);
		}

		/* Cierra el archivo*/
		fclose(archivo);
	}

	return logeoExitoso;
}
	
int leerLinea(char *cad, int n)
{
	int i, c;

	/* 1 COMPROBACIÓN DE DATOS INICIALES EN EL BUFFER */
	c = getchar();
	if (c == EOF) {
		cad[0] = '\0';
		return 0;
	}

	if (c == '\n') {
		i = 0;
	} else {
		cad[0] = c;
		i = 1;
	}

	/* 2. LECTURA DE LA CADENA */
	for (; i < n - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
		cad[i] = c;
	}
	cad[i] = '\0';

	/*3. LIMPIEZA DEL BUFFER */ 
	if (c != '\n' && c != EOF) /* es un caracter */
		while ((c = getchar()) != '\n' && c != EOF);
 
	return 1;
}

void leerClave(char *password) {
	char caracter;
	int i = 0;

	while (caracter = getch()) {
		if (caracter == TECLA_ENTER) {
			password[i] = '\0';
			break;
			
		} else if (caracter == TECLA_BACKSPACE) {
			if (i > 0) {
				i--;
				printf("\b \b");
			}
			
		} else {
			if (i < MAX) {
				printf("*");
				password[i] = caracter;
				i++;
			}
		}
	}
}


//Introducimos las funciones que nos dejan leer y escribir sobre el fichero de los usuarios


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
	
	
menuSistema(){
		
			int opcionMenu;
	char nombrefic[20], nombrefichero[20],nficheros[20];
	char texto[100], salir; 
	float ph, conductividad, turbidez, coliformes;
		
		int repite;
		repite=1;
		int farandul;
		int opcion2;	
			do{
	
	system("cls");
	banner_fijo();
	printf("\n     =========================================================================\n");
	printf("\t\t\t     BIENVENIDO A KUNFONT, TU COMPARADOR DE AGUSA DE CONFIANZA\n");
	printf("\t\t  Puede consultar y añadir: datos y fuentes del distrito de Lavapies\n");
	printf("\t\t   Elija que desea realizar\n");

	printf("     =========================================================================\n");

		printf("\n\t\tAqui va todo el contenido del sistema ;)");
	
		printf("\n\t\t[1].REGISTRAR NUEVO FICHERO CON DATOS DE FUENTES NUEVAS\n");
		printf("\t\t[2]. CONSULTAR LOS DATOS DE AGUAS DEL DISTRITO DE LAVAPIES U OTROS FICHEROS YA CREADOS\n");
			printf("\t\t  [3]. AYUDA E INSTRUCCIONES\n");
		printf("\n\t\tIngrese su opcion: [ ]\b\b");
	
		leerLinea(linea, MAX);
		sscanf(linea, "%d", &opcion2);
		farandul++;
		
		switch (opcion2) {
			case 1:
				system("cls");		
				banner_fijo();
				
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
				farandul++;
				repite=0;
				break;



			case 2:
				system("cls");		
				banner_fijo();
				
					//leer el fichero con los fichero que existen 
	    	printf("HAS ELEGIDO REVISAR LA INFORMACION DE AGUAS DE LAVAPIES\n");
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
				farandul++;
				repite=0;
				break;
				
				
			case 3 :
		    	
		    	farandul++;
		    	repite=0;
		    	system("cls");		
				banner_fijo();
				
	    		printf("HAS ELEGIDO INSTRUCCIONES Y AYUDA DENTRO\n");
		    	printf("\n\n\n");
		  	   do{
		    	    printf("Utilice s y despues enter para volver al menu principal\n");
			        printf("Bienvenido a Kunfont \nEste programa consiste en un algoritmo para guardar los ficheros de los datdos de diferentes analisis\n");
			        printf("de agua.La opcion 6 sirve para registrar nuevos ficheros con datos nuevos de experimentos nuevos.Al introducir un fichero nuevo");
		    	    printf("se regsitrara en un fichero con el nombre dde todos los ficheros registrados.La opcion 7 sirve para leer los datos de ficheros antiguos\n");
		        	fflush(stdin);
		   	     scanf("%c",&salir);
		    		}while(salir=='s'&&salir=='S');
		    		if(salir=='s'&&salir=='S'){
		   		 			break;
					}		
				
				
				
}} while (repite == 1);
	getchar();
}	




//INTRODUCIMOS LA FUNCION QUE CODIFICA EL MENU PRINCIPAL





void menuInicial() {
	
	setlocale(LC_CTYPE,"Spanish");//CODIFICAMOS EL IDIOMA A ESPAÑOL PARA PODER UTILIZAR LETRAS COMO LA Ñ DE ESPAÑA
	
	Usuario usuario;
	char repite = 1;
	int opcion = -1;
	int farandul;
	farandul=1;
	system ("color e0");//CODIFICAMOS EL COLOR: AMARILLO PARA EL FONDO Y EL NEGRO PARA LAS LETRAS

	
	do {
		system("cls");

		
		if(farandul==1){
			banner();
		}else{
		banner_fijo();
		}
				
		printf("\t\t\tMENU PRINCIPAL\n");
		printf("\n\t\t[1]. Ver usuarios registrados\n");
		printf("\t\t[2]. Registrar usuario nuevo\n");
		printf("\t\t[3]. Consultar datos de Aguas de LAVAPIES\n");
		printf("\t\t[4]. Normativa Legal de la web\n");
		printf("\t\t[5]. A cerca de los datos recogidos\n");
		printf("\t\t[0]. Salir\n");
		printf("\n\t\tIngrese su opcion: [ ]\b\b");
		leerLinea(linea, MAX);
		sscanf(linea, "%d", &opcion);
		farandul++;

		switch (opcion) {
			case 1:
				system("cls");		
				banner_fijo();
				menuListarUsuarios();
				farandul++;
				break;

			case 2:
				system("cls");		
				banner_fijo();
				menuRegistrarUsuario();
				farandul++;
				break;

			case 3:
				system("cls");		
				banner_fijo();
				menuIniciarSesion();
				farandul++;
				break;

			case 4:
				system("cls");		
				banner_fijo();
				normativa();
				system("pause");
				break;
				
			case 5:
				system("cls");		
				banner_fijo();
				aguascaracteristicasdefiniciones();
				system("pause");
				farandul++;
				break;
			
			case 0:
				system("cls");		
				banner_fijo();
				printf("HASTA PRONTO!!\n");
				repite = 0;
				break;
		}

	} while (repite == 1);
}

// CREAMOS EL PROGRAMA

int main() {
	menuInicial();
	return 0;
}
