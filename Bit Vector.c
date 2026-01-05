#include <stdio.h>
#include <stdbool.h>
#define MAX 10
void initialize (int bitvector[], int N){
    for (int i = 0; i < N; i++){
        bitvector[i] = 0;
    }
}

void insert (int bitvector[], int x){
    bitvector[x] = 1;
}

void removeElem (int bitvector[], int x){
    bitvector[x] = 0;
}

bool contains (int bitvector[], int x){
    if (bitvector[x] == 1){
        return true;
    }else{
        return false;
    }
}

void Union (int A[], int B[], int C[], int N){
    for (int i = 0; i < N; i++){
        C[i] = A[i] | B[i];
    }
} 
void Intersection (int A[], int B[], int C[], int N){
    for (int i = 0; i < N; i++){
        C[i] = A[i] & B[i];
    }
} 
void Difference (int A[], int B[], int C[], int N){
    for (int i = 0; i < N; i++){
        if (A[i] == 1 && B[i] == 0){
            C[i] = 1;
        }
        else{
            C[i] = 0;
        }
    }
}

void printSet(int bitvector[], int N) {
    printf("{ ");
    for (int i = 0; i < N; i++) {
        if (bitvector[i] == 1) {
            printf("%d ", i);
        }
    }
    printf("}\n");
}

int main() {
    int A[MAX], B[MAX], C[MAX];

    /* Initialize sets */
    initialize(A, MAX);
    initialize(B, MAX);
    initialize(C, MAX);

    /* Insert elements */
    insert(A, 1);
    insert(A, 3);
    insert(A, 5);

    insert(B, 3);
    insert(B, 4);
    insert(B, 5);

    printf("Set A: ");
    printSet(A, MAX);

    printf("Set B: ");
    printSet(B, MAX);

    /* Membership test */
    printf("Contains 3 in A? %s\n", contains(A, 3) ? "Yes" : "No");
    printf("Contains 4 in A? %s\n", contains(A, 4) ? "Yes" : "No");

    /* Union */
    Union(A, B, C, MAX);
    printf("A ∪ B: ");
    printSet(C, MAX);

    /* Intersection */
    Intersection(A, B, C, MAX);
    printf("A ∩ B: ");
    printSet(C, MAX);

    /* Difference */
    Difference(A, B, C, MAX);
    printf("A - B: ");
    printSet(C, MAX);

    return 0;
}