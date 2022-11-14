#include <stdio.h>
#define MAX 10

//BUBBLESORT
//RICERCA BINARIA - array ordinato

int riempiArray(int array[]);
void stampaArray(int array[],int len);
void bubblesort(int array[], int len);
int binarySearch(int array[], int len, int v);

int main(int argc, const char * argv[]) {
    int array[MAX];
    int r, val, len;
    
    do{
        printf("MENU\n");
        printf("1) Inserisci array\n");
        printf("2) Ordina array (BUBBLESORT)\n");
        printf("3) Ricerca Binaria\n");
        printf("4) ESCI\n");
        scanf("%d", &r);
        
        switch(r){
            case 1:
                len = riempiArray(array);
                stampaArray(array, len);
                break;
            case 2:
                bubblesort(array, len);
                stampaArray(array, len);
                break;
            case 3:
                bubblesort(array, len);
                printf("Inserisci il valore da cercare: ");
                scanf("%d",&val);
                if (binarySearch(array, len, val)!=-1)
                    printf("Il valore è stato trovato\n");
                break;
            case 4:
                printf("ARRIVEDERCI\n\n");
                break;
            default:
                printf("Operazione non consentita\n\n");
                break;
        }
    }while(r!=4);
    return 0;
    
}

int riempiArray(int array[]){
    int i;
    int len;
    
    printf("Quanti valori vuoi inserire: ");
    scanf("%d",&len);
    for (i=0; i<len; i++){
        scanf("%d", &array[i]);
    }
    return len;
}

void stampaArray(int array[], int len){
    int i;
    for (i=0; i<len; i++)
        printf("%d ",*(array+i));
    printf("\n");
}

void bubblesortNonOttimizzato(int array[], int len){
    int i, j;
    int temp;
    
    for (i=0; i<len-1; i++){
        for (j=0; j<len-1; j++){
            if (array[j]>array[j+1]){
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

void bubblesort(int array[], int len){
    int i, j;
    int temp;
    int swap;
    
    for (i=0, swap = 1; ((i<len-1) && (swap == 1)); i++, swap = 1){
        for (j=0; j<len-1; j++){
            if (array[j]>array[j+1]){
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
                swap = 0;
            }
        }
    }
}

int binarySearch(int array[], int len, int v){
    int inizio = 0;
    int fine = len-1;
    int medio;
    
    while(inizio<=fine){
        medio = inizio + (fine-inizio)/2;
        if (array[medio]==v)
            return medio;
        if (array[medio]<v)
            inizio = medio+1;
        else
            fine = medio-1;
    }
    return -1;
}
         
         
