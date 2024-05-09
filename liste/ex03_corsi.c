#include <stdio.h>

struct corso{
	char denom[20];
	char cognome[15];
	int iscritti;
};

int main(){
	struct corso finfo = {"finfo", "Casadei", 150};
	struct corso lab_info = {"labinfo", "Francia", 40};
	struct corso analisi = {"analisi", "Comi", 150};
	
	double media_iscritti = (finfo.iscritti + lab_info.iscritti + analisi.iscritti) / 3;

	if(finfo.iscritti >= media_iscritti)
		printf("Nome corso: %s, Cognome docente: %s\n", finfo.denom, finfo.cognome);
	if(lab_info.iscritti >= media_iscritti)
		printf("Nome corso: %s, Cognome docente: %s\n", lab_info.denom, lab_info.cognome);
	if(analisi.iscritti >= media_iscritti)
		printf("Nome corso: %s, Cognome docente: %s\n", analisi.denom, analisi.cognome);
	return 0;
}