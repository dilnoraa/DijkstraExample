#include <stdio.h>
#include <stdlib.h>

void Distance(int[][5],int []);

int main()
{

    int N = 5;
    int i,j;


    int cost [5][5]=
    {
        {1000,    5,    3, 1000,    2},
        {1000, 1000,    2,    6, 1000},
        {1000,    1, 1000,    2, 1000},
        {1000, 1000, 1000, 1000, 1000},
        {1000,    6,   10,    4,    8}
    };


    for(i=0; i<5; i++)
    {
        for(j=0; j<5; j++)
            printf("%d    ",cost[i][j]);
        printf("\n");
    }

    int distances[N];
    Distance(cost, distances);
    printf("\n En kisa yolu Dikstra algoritmasi ile:\n");
    for ( i=0; i<N; ++i)
        printf("%d\n",distances[i]);
}

void Distance( int cost [5][5], int D[5])
{

    int w, v, min,i;
    int infinity=1000;
    int visited[5];

    D[0] = 0;
    for(v=1; v<5; v++)
    {
        visited[v] = 0;
        D[v] = cost[0][v];
    }

    for( i=1; i<5; ++i)
    {
        min = infinity;
        for(w=1; w<5; w++)
            if(visited[w]!=0)
                if(D[w]<min)
                {
                    v = w;
                    min = D[w];
                }

        visited[v] =1;

        for(w=1; w<5; w++)
            if(visited[w]!=0)
                if(min+cost[v][w] < D[w])
                    D[w] = min + cost[v][w];
    }
}

