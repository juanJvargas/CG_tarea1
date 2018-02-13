/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: juan
 *
 * Created on 11 de febrero de 2018, 22:12
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int filas = 0;
int columnas = 0;
int cols = 0;
int fils = 0;

using namespace std;

/*
 * 
 */
int** leerMatriz(char *fileName) {
    FILE *fp = fopen(fileName, "r");
    if (fp == NULL) {
        exit(EXIT_FAILURE);
    }
    char linea[80];
    fgets(linea, 79, fp);
    char *token = strtok(linea, " "); //10 6
    filas = atoi(token);
    token = strtok(NULL, " ");
    columnas = atoi(token);
    int **matriz = new int*[filas];
    for (int i = 0; i < filas; i++) {
        matriz[i] = new int[columnas];
        fgets(linea, 79, fp);
        token = strtok(linea, " ");
        matriz[i][0] = atoi(token);
        for (int j = 1; j < columnas; j++) {
            token = strtok(NULL, " ");
            matriz[i][j] = atoi(token);
        }
    }
    fclose(fp);
    return matriz;
}

void imprimeMatriz(int **matriz) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
}

void guardarMatriz(char *fileName, int **matriz) {
    FILE *fp = fopen(fileName, "w");
    if (fp == NULL) {
        exit(EXIT_FAILURE);
    }
    char linea[80];
    sprintf(linea, "%d %d\n", filas, columnas);
    fputs(linea, fp);
    for (int i = 0; i < filas; i++) {
        linea[0] = '\0';
        for (int j = 0; j < columnas; j++) {
            char buffer[10];
            sprintf(buffer, "%d ", matriz[i][j]);
            strcat(linea, buffer);
        }
        int len = strlen(linea);
        linea[len - 1] = '\n';
        fputs(linea, fp);
    }
    fclose(fp);

}

int ** transponerMatriz(int **matriz) {
    int **matrizT = new int*[columnas];
    for (int i = 0; i < filas; i++) {
        matrizT[i] = new int[filas];
        for (int j = 0; j < columnas; j++) {
            matrizT[i][j] = matriz[j][i];
        }
    }

    return matrizT;
}

int operacion(int *A, int **B, int colum, int aux) {
    int respuesta = 0;
    return respuesta;
}
//filas*columnas----fils*cols

int ** productoMatriz(int **A, int **B) {
    int aux = 0;
    int **matrizAxB = new int*[filas];
    for (int i = 0; i < filas; i++) {
        matrizAxB[i] = new int[cols];
        for (int j = 0; j < cols; j++) {
            for (int k = 0; k < columnas; k++) {
                for (int l = 0; l < fils; l++) {
                    aux += A[i][l] * B[k][l];
                    printf("(%d*%d)+", A[i][l], B[k][l]);
                    
                }
                    printf("=%d\n", aux);
                    matrizAxB[i][k] = aux;
                    aux = 0;

            }


            //matrizAxB[i][j]= operacion(A[i],B,j,0);

        }


    }
    return matrizAxB;
}

int main(int argc, char** argv) {
    int **matriz1 = leerMatriz("matriz1.txt");
    cols = columnas;
    fils = filas;
    printf("Matriz A=\n");
    imprimeMatriz(matriz1);
    int **matriz1T = transponerMatriz(matriz1);
    printf("Matriz A transpuesta=\n");
    imprimeMatriz(matriz1T);
    int **matriz2 = leerMatriz("matriz2.txt");
    printf("Matriz B=\n");
    imprimeMatriz(matriz2);
    int **matriz2T = transponerMatriz(matriz2);
    printf("Matriz B transpuesta=\n");
    imprimeMatriz(matriz2T);
    if (cols = filas) {
        int** matriz1x2 = productoMatriz(matriz1, matriz2);
        printf("Matriz AxB=\n");
        imprimeMatriz(matriz1x2);
    } else {
        printf("no se puede multiplicar dado qeu las columnas de A son diferentes a las columas de B");
    }
    return 0;
}

