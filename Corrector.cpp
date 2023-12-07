/*****************************************************************************************************************
	UNIVERSIDAD NACIONAL AUTONOMA DE MEXICO
	FACULTAD DE ESTUDIOS SUPERIORES -ARAGON-

	Computadoras y programacion. 
	(c) Ponga su nombre y numero de cuenta aqui.
	
	Quiso decir: Programa principal de la aplicacion de la distancia de Levenstein.
	
******************************************************************************************************************/


#include "stdafx.h"
#include <string.h>
#include "corrector.h"
//Funciones publicas del proyecto
/*****************************************************************************************************************
	DICCIONARIO: Esta funcion crea el diccionario completo
	char *	szNombre				:	Nombre del archivo de donde se sacaran las palabras del diccionario	
	char	szPalabras[][TAMTOKEN]	:	Arreglo con las palabras completas del diccionario
	int		iEstadisticas[]			:	Arreglo con el numero de veces que aparecen las palabras en el diccionario
	int &	iNumElementos			:	Numero de elementos en el diccionario
******************************************************************************************************************/
void	Diccionario			(char *szNombre, char szPalabras[][TAMTOKEN], int iEstadisticas[], int &iNumElementos)
{

	FILE* fpDicc;
	char szPalabraRecib[NUMPALABRAS][TAMTOKEN];
	char szPalabraDetec[TAMTOKEN];
	int  szCaracter, i, j, FinOrd, iControl;
	fopen_s(&fpDicc, szNombre, "r");
	if (fpDicc == NULL)
		return;

	iNumElementos = 0; j = 0;
	szCaracter = fgetc(fpDicc);
	while (feof(fpDicc) == 0)
	{
		if (!((szCaracter == '\t') || (szCaracter == '\n') || (szCaracter == '\r') || (szCaracter == ' ') || (szCaracter == ')') || (szCaracter == ',') || (szCaracter == '.') || (szCaracter == ';') || (szCaracter == '(')))
		{
			szPalabraRecib[iNumElementos][j] = towlower((char)szCaracter);
			szCaracter = fgetc(fpDicc);
			j++;
		}
		else
		{
			if (j > 0)
			{
				szPalabraRecib[iNumElementos][j] = '\0';
				iEstadisticas[iNumElementos] = 1;

				if (iNumElementos > 0)
				{
					for (i = 0; i < iNumElementos; i++)
						if (strcmp(szPalabraRecib[i], szPalabraRecib[iNumElementos]) == 0)
						{
							iEstadisticas[i] = iEstadisticas[i] + 1;
							i = iNumElementos;
							iNumElementos = iNumElementos - 1;
						}
				}

				iNumElementos++;
				j = 0;
			}
			szCaracter = fgetc(fpDicc);
		}
	}
	fclose(fpDicc);

szPalabraRecib[iNumElementos][j] = '\0';
	iEstadisticas[iNumElementos] = 1;

	for (i = 0; i < iNumElementos; i++)
		if (strcmp(szPalabraRecib[i], szPalabraRecib[iNumElementos]) == 0)
		{
			iEstadisticas[i] = iEstadisticas[i] + 1;
			strcpy_s(szPalabraRecib[iNumElementos], "");
			i = iNumElementos;
		}

	for (i = 0; i < iNumElementos; i++)
	{
		FinOrd = 0;
		for (j = 0; j < iNumElementos; j++)
		{
			if (strcmp(szPalabraRecib[j + 1], szPalabraRecib[j]) < 0)
			{
				strcpy_s(szPalabraDetec, szPalabraRecib[j]);
				iControl = iEstadisticas[j];
				strcpy_s(szPalabraRecib[j], szPalabraRecib[j + 1]);
				iEstadisticas[j] = iEstadisticas[j + 1];
				strcpy_s(szPalabraRecib[j + 1], szPalabraDetec);
				iEstadisticas[j + 1] = iControl;
			}
			else
				FinOrd += 1;
		}

}




/*****************************************************************************************************************
	ListaCandidatas: Esta funcion recupera desde el diccionario las palabras validas y su peso
	Regresa las palabras ordenadas por su peso
	char	szPalabrasSugeridas[][TAMTOKEN],	//Lista de palabras clonadas
	int		iNumSugeridas,						//Lista de palabras clonadas
	char	szPalabras[][TAMTOKEN],				//Lista de palabras del diccionario
	int		iEstadisticas[],					//Lista de las frecuencias de las palabras
	int		iNumElementos,						//Numero de elementos en el diccionario
	char	szListaFinal[][TAMTOKEN],			//Lista final de palabras a sugerir
	int		iPeso[],							//Peso de las palabras en la lista final
	int &	iNumLista)							//Numero de elementos en la szListaFinal
******************************************************************************************************************/
void	ListaCandidatas		(
	char	szPalabrasSugeridas[][TAMTOKEN],	//Lista de palabras clonadas
	int		iNumSugeridas,						//Lista de palabras clonadas
	char	szPalabras[][TAMTOKEN],				//Lista de palabras del diccionario
	int		iEstadisticas[],					//Lista de las frecuencias de las palabras
	int		iNumElementos,						//Numero de elementos en el diccionario
	char	szListaFinal[][TAMTOKEN],			//Lista final de palabras a sugerir
	int		iPeso[],							//Peso de las palabras en la lista final
	int &	iNumLista)							//Numero de elementos en la szListaFinal
{

	//Sustituya estas lineas por su c digo
	strcpy(szListaFinal[0], szPalabrasSugeridas[ 0] ); //la palabra candidata
	iPeso[0] = iEstadisticas[0];			// el peso de la palabra candidata
	
	iNumLista = 1;							//Una sola palabra candidata
}




/*****************************************************************************************************************
	ClonaPalabras: toma una palabra y obtiene todas las combinaciones y permutaciones requeridas por el metodo
	char *	szPalabraLeida,						// Palabra a clonar
	char	szPalabrasSugeridas[][TAMTOKEN], 	//Lista de palabras clonadas
	int &	iNumSugeridas)						//Numero de elementos en la lista
******************************************************************************************************************/
void	ClonaPalabras(
	char *	szPalabraLeida,						// Palabra a clonar
	char	szPalabrasSugeridas[][TAMTOKEN], 	//Lista de palabras clonadas
	int &	iNumSugeridas)						//Numero de elementos en la lista
{
	//Sustituya estas lineas por su c digo
	strcpy(szPalabrasSugeridas[0], szPalabraLeida); //lo que sea que se capture, es sugerencia
	iNumSugeridas = 1;							//Una sola palabra sugerida
}
