#include <stdio.h>
#include "aluno.h"


int main(){

    FILE *file;

    file = fopen("//home//bruno//Projeto//ArqsMain//dados.dat", "ab");

    if(file == NULL){
        printf("ERROR\n");
    }


    char nome[21], cpf[15], curso[40], matricula[10];
    Aluno *aluno;

    printf("Digite o nome do aluno: ");
    fgets(nome, 21, stdin);

    printf("Digite o CPF do aluno: ");
    fgets(cpf, 15, stdin);

    printf("Digite o curso: ");
    fgets(curso, 40, stdin);

    printf("Digite a matricula do aluno: ");
    fgets(matricula, 10, stdin);


    aluno = cadastrar_Aluno(nome, cpf, curso, matricula);
    imprimir_Alunos(aluno);

    salvar_Aluno(aluno, file);



    return 0;
}