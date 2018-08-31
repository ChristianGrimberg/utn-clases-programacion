#include <stdio_ext.h>
#include <stdlib.h>

static int getInt(int* number); /**< Prototipo de funcion privada interno al source */
static int getFloat(float* decimal);

int utn_getInt(int* pNumero, int reintentos, int minimo, int maximo, char* mensaje, char* error)
{
    int edadAux;
    int retorno = -1;

    if(maximo > minimo && reintentos > 0)
    {
        for(; reintentos > 0; reintentos--)
        {
            printf(mensaje);
            if(getInt(&edadAux) == 0 && edadAux >= minimo && edadAux <= maximo)
            {
                *pNumero = edadAux;
                retorno = 0;
                break;
            }
            else
            {
                /**< Funcion extendida en stdio_ext.h para limpiar el buffer de entrada */
                __fpurge(stdin);
                printf(error);
            }
        }

        if(reintentos == 0)
            printf("Cantidad de intentos superada.");
    }

    return retorno;
}

int utn_getFloat(float* pNumero, int reintentos, float minimo, float maximo, char* mensaje, char* error)
{
    int retorno = -1;
    float floatAux;

    if(maximo > minimo && reintentos > 0)
    {
        for(; reintentos > 0; reintentos--)
        {
            printf(mensaje);
            if(getFloat(&floatAux) == 0 && floatAux >= minimo && floatAux <= maximo)
            {
                *pNumero = floatAux;
                retorno = 0;
                break;
            }
            else
            {
                /**< Funcion extendida en stdio_ext.h para limpiar el buffer de entrada */
                __fpurge(stdin);
                printf(error);
            }
        }

        if(reintentos == 0)
            printf("Cantidad de intentos superada.");
    }

    return retorno;
}

/**< Implementacion de funcion privada */
static int getInt(int* number)
{
    int returnValue = -1;
    int numberAux;

    if(scanf("%d", &numberAux) == 1)
    {
        *number = numberAux;
        returnValue = 0;
    }
    else
        __fpurge(stdin);

    return returnValue;
}

static int getFloat(float* decimal)
{
    int returnValue = -1;
    float numberAux;

    if(scanf("%f", &numberAux) == 1)
    {
        *decimal = numberAux;
        returnValue = 0;
    }
    else
        __fpurge(stdin);

    return returnValue;
}