#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED



#endif // UTN_H_INCLUDED
int utn_getNumeroInt (int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int utn_getNumeroFloat (float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);
int utn_getNombreOApellido(char* pResultado, char* mensaje, char* mensajeError,int minCaractres,int maxCaracteres, int reintentos);
int utn_getAlfanumerico(char* pResultado, char* mensaje, char* mensajeError,int minCaracteres,int maxCaracteres, int reintentos);
int utn_getString(char* pResultado, char* mensaje, char* mensajeError,int minCaractres,int maxCaracteres, int reintentos);
int utn_getFecha(int* dia, int* mes, int* anio);
int esStringLetrasSinEspacio(char* cadena);
int esStringConEspacio(char* cadena);
