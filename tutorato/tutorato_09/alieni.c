#include <stdio.h>
#include <string.h>

typedef struct coppia {
	char lettera;
	char codificato[4];//dimensione array??
} coppia;

int main() {
	int nLettere = 0;
	int i = 0;
	int j;
	char triplaCorrente[4];// variabile temporanea per la lettura delle triplette, perchè 4??
	char messaggio[50]; //variabile temporanea in cui leggo le righe del file messaggi .txt
	char s[2];
	FILE *fp;//dichiarazione puntatore a file
	coppia lettere[26];

	fp=fopen("corrispondenze.txt","rt");//apertura file corrispondenze.txt

    //messaggio di errore in caso di apertura non corretta del file
	if (fp == NULL) {
		printf("Impossibile aprire il file corrispondenze.txt\n");
		return -1;
	}

    //lettura da file di testo corrispondenze.txt e creazione del vettore
    while(fscanf(fp," %c %s",&lettere[nLettere].lettera, lettere[nLettere].codificato)>0){
        printf("%c %s\n", lettere[nLettere].lettera, lettere[nLettere].codificato);
        nLettere++;
    }

    fclose(fp);

	fp= fopen("messaggi.txt","rt");//apertura file messaggi.txt

	if (fp == NULL) {
		printf("Impossibile aprire il file messaggi.txt\n");
		return -1;
	}

    //leggo una riga per volta poi individuo le triplette e cerco nell'array di strutture a quale lettera corrispondono
    while(fscanf(fp, "%s", messaggio)>0){
        i=0;

        while(messaggio[i]!= '\0'){
            triplaCorrente[0]=messaggio[i];
            triplaCorrente[1]=messaggio[i+1];
            triplaCorrente[2]=messaggio[i+2];
            triplaCorrente[3]='\0';

            for(j=0;j<nLettere;j++){
                if(strcmp(triplaCorrente, lettere[j].codificato)==0){
                    printf("%c", lettere[j].lettera);
					i=i+3;
                	break;
                }
            }                

        }

		printf("\n");

    }

    fclose(fp);

	printf("Inserire il messaggio da codificare: ");
	scanf("%s", messaggio);

	// codifico il messaggio
	printf("Codificato: ");
	i = 0;
	while (messaggio[i] != '\0') {
		for (j = 0; j < nLettere; j++) {
			if (lettere[j].lettera == messaggio[i]) {
				printf("%s", lettere[j].codificato);
				break;
			}
		}
		i++;
	}
	printf("\n");

	return 0;
}
