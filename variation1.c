#include <stdio.h>
#include <stdlib.h>
#define MAX 10
typedef struct
{
    int elem[MAX];
    int count;
}List;
List initialize (List L);
List insertPos (List L, int data, int position);
List deletePos (List L, int position);
int Locate (List L, int data);
List insertSorted (List L, int data);
void Display (List L);
int main (){
List L;
initialize (L);
insertPos (L, 500, 5);
};
List initialize (List L){
        int temp = 0;
    printf ("Pls insert a number:");
    for (int i = 0; i < MAX; i++)
    {
        printf ("[%d]: ", i + 1);
        scanf ("%d", &temp);
    L.elem[i] = temp;
    }
    for (int i = 0; i < MAX; i++)
    {
        printf ("%d, ", L.elem[i]);
    }
    
    L.count = 0;
    return L;
};
List insertPos (List L, int data, int position){
for (int i = MAX; i > 0; i--)
{
    L->elem(i) = L->elem(i + 1);
    
}

};