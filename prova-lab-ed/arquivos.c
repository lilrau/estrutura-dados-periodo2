#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int nd, carga;
    char disciplina[15];
    FILE *fp;
    fp = fopen("entrada.txt ", "a");
    if(fp==NULL) {
        printf('erro\n');
        exit(1); // aborta o programa
    }
    printf("\nQuantas disciplinas serão gravadas: ");
    scanf("%d", &nd);
    for(int i=0; i<nd; i++) {
        printf("\nInforme a disciplina: ");
        scanf("%s", &disciplina);
        printf("\nInforme a carga horaria: ");
        scanf("%d", &carga);
        fprintf(fp, "%s %d\n", disciplina, carga);
    }
    fclose(fp);
    fp = fopen("entrada.txt", "r");
    while(!feof(fp)) {
        fscanf(fp, "%s %d", &disciplina, &carga);
        if(!feof(fp)) {
            printf("\n%s %d", disciplina, carga);
        }
    }
    fclose(fp);
    return 0;
}
