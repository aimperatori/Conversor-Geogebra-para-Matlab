/*
 ============================================================================
 Name        : Convercao.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	setbuf(stdin, NULL);

	FILE *ent, *sai;
	int i;

	if ((ent = fopen("C:\\converte.txt", "r")) == NULL) {
		printf("Arquivo converte não pode ser aberto\n");
		exit(1);
	}
	if ((sai = fopen("C:\\resultado.txt", "w")) == NULL) {
		printf("Arquivo resultado não pode ser aberto\n");
		exit(1);
	}

	char x[50];
	char y[50];

	strcpy(x,"A = [");

	char c;
	while((c=fgetc(ent))!=EOF) {
		//putchar(c);
		if(c=='(') {
			do {
				c = fgetc(ent);
				x[strlen(x)+1] = '\0';
				if (c==',') {
					x[strlen(x)] = ',';
					break;
				}
				x[strlen(x)] = c;
				putchar(c); // mostra
			} while(1);
		}

	}
	for(i=5;x[i]!=',';i++) {
		x[strlen(x)+1] = '\0';
		x[strlen(x)] = x[i];
	}
	printf("\n%s\n", x);
//	fprintf(sai,x);
	fclose(ent);

	ent = fopen("C:\\converte.txt", "r");
	strcpy(y,";");

	while((c=fgetc(ent))!=EOF) {
		//putchar(c);
		if(c==',') {
			c = fgetc(ent);
			putchar(c);
			do {
				c = fgetc(ent);
				y[strlen(y)+1] = '\0';
				if (c==')') {
					y[strlen(y)] = ',';
					break;
				}
				y[strlen(y)] = c;
				putchar(c); // mostra
			} while(1);
		}
	}
	for(i=1;y[i]!=',';i++) {
		y[strlen(y)+1] = '\0';
		y[strlen(y)] = y[i];
	}
	y[strlen(y)+1] = '\0';
	y[strlen(y)] = ']';

	printf("\n%s", y);
	fclose(ent);

	fprintf(sai,x);
	fprintf(sai,y);
	fprintf(sai,"\n");
	fprintf(sai,"fill(A(1,:), A(2,:),'g')\n");
	fprintf(sai,"A=M*A;\n");
	fprintf(sai,"fill(A(1,:), A(2,:),'g')\n");
	fprintf(sai,x);
	fprintf(sai,y);
	fprintf(sai,"\n");
	fprintf(sai,"A=N*A;\n");
	fprintf(sai,"fill(A(1,:), A(2,:),'g')\n");
	fprintf(sai,x);
	fprintf(sai,y);
	fprintf(sai,"\n");
	fprintf(sai,"A=O*A;\n");
	fprintf(sai,"fill(A(1,:), A(2,:),'g')\n");





	return EXIT_SUCCESS;
}
