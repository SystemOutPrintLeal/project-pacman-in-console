#include <stdio.h>
#include <stdlib.h>
#include "mapa.h"


int isDirection(char direction)
{
    return  direction == 'a' ||
            direction == 'w' ||
            direction == 's' ||
            direction == 'd';
}

int isEmpty(MAP* m, int x, int y)
{
    return m->matriz[x][y] == '.';
}


int isValid(MAP* m, int x, int y)
{
    if(x >= m->lines) return 0;
    if(y >= m->columns) return 0;

    return 1;
}

void runInMap(MAP* m, int origin_x, int origin_y, int destiny_x, int destiny_y)
{
    //char character = m->matriz[origin_x][origin_y];
    m->matriz[destiny_x][destiny_y] = '@';
    m->matriz[origin_x][origin_y] = '.';
}

void searchMap(MAP* m, POSICAO* p, char c)
{
    for (int i=0 ; i<m->lines; i++ )
    {   
        for(int j=0; j<m->columns;j++)
        {
            if(m->matriz[i][j] == c)
            {
              p->x = i;
              p->y = j;
              break;  
            }
        }
    }
}

void readMap(MAP* m)
{
    FILE* f;
    f = fopen("mapa.txt","r");
    if(f == 0)
    {
        printf("Error to open 'mapa.txt'");
        exit(1);
    }
    printf("Sucess to read\n");
    fscanf(f, " %d %d",&(m->lines),&(m->columns));
    printf("map.lines:%d  map.columns:%d\n",m->lines,m->columns);

    /*
    Dinamic map
    */
    allocMap(m);
    for (int i=0 ; i<5 ; i++)
    {
        fscanf(f, "%s" , m->matriz[i]);
    } 
    fclose(f);
    
}

void allocMap(MAP* m)
{
    m->matriz = malloc(sizeof(char*) * m->lines);
    for(int i=0; i < m->lines; i++)
    {
        m->matriz[i] = malloc(sizeof(char) * (m->columns+1));
    }
    printf("Sucess to alloc\n");
}

void freeMap(MAP* m)
{
    /*Limpando memoria*/
    for(int i=0; i<m->lines; i++)
    {
        free(m->matriz[i]);
    } 
    free(m->matriz);
}


void printMap(MAP* m)
{
    for (int i=0 ; i<5 ; i++)
    {
        printf("%s\n" , m->matriz[i]);
    }
}