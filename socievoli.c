#include <stdio.h>
#define MAX 10

//https://github.com/Informatica-Alippi-Perego/

int sommaDivisori(int n);

/*
int main(int argc, const char * argv[]) {

    int read;
    int old;
    int n=0;
    
    do{
        scanf("%d",&read);
        if (read<0)
            break;
        n++;
        if (n<2)
            printf("Non hai inserito abbastanza numeri per il confronto\n");
        else{
            if (sommaDivisori(old) == read)
                printf("La catena fin ora inserita è di numeri socievoli\n");
            else{
                printf("La catena non è di numeri socievoli");
                read = -1;
            }
            
        }
        old = read;
        
    }while(read>=0);
    
    return 0;
    
}
*/
int main(int argc, const char * argv[]) {
    int len,i;
    int valori[100];
    int socievoli = 1;
    
    printf("Quanto è grande il gruppo di numeri? ");
    scanf("%d",&len);
    printf("Inserisci i numeri:\n");
    for(i=0; i<len;i++)
        scanf("%d",&valori[i]);
    
    for(i=0; ((i<len) && (socievoli==1));i++){
        if (i==len-1){
            if (sommaDivisori(valori[i]) != valori[0])
                socievoli = 0;
        }
        else{
            if (sommaDivisori(valori[i]) != valori[i+1])
                socievoli = 0;
        }
    }
    // ho finito di scorrere e non ho trovati problemi -> socievoli = 1
    if (socievoli==1)
        printf("Il gruppo è di numeri socievoli\n");
    else
        printf("Il gruppo NON è di numeri socievoli\n");
    
    return 0;
}

int sommaDivisori(int n){
    int somma;
    int i;
    
    for (i=1, somma = 0; i<n; i++){
        if (n%i == 0)
            somma = somma + i;
    }
    return somma;
}
