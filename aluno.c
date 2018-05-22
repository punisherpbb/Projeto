//
// Created by bruno on 04/05/18.
//


#include "aluno.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


struct aluno {

    int matricula, cpf;
    char nome[30], curso[30];

};


Aluno *adicionar_Aluno(char nome[], char curso[], int matricula, int cpf){

    Aluno *aluno = (Aluno*) malloc(sizeof(Aluno));

    strcpy(aluno->nome, nome);
    strcpy(aluno->curso, curso);
    aluno->matricula = matricula;
    aluno->cpf = cpf;

    return aluno;

}

void imprimir_Alunos(Aluno *aluno[], int x) {

    if(x == 0){
        printf("Não existe alunos cadastrados!");
    }else{

        for (int i = 0; i < x; i++) {

            printf("\nAluno %d\n", i + 1);
            printf("NOME: %s\n", aluno[i]->nome);
            printf("CURSO: %s\n", aluno[i]->curso);
            printf("Matricula: %d\n", aluno[i]->matricula);
            printf("CPF: %d\n", aluno[i]->cpf);
            printf("\n");

        }

    }
}

//Esta função é temporaria
void menu_Aluno(){

    printf("\n\n############################################\n");
    printf("############## MENU DO ALUNO ###############\n");
    printf("############################################\n\n");
    printf("1 - ADICIONAR\n");
    printf("2 - REMOVER\n");
    printf("3 - EDITAR\n");
    printf("4 - LISTAR\n");
    printf("5 - SAIR\n\n");
    printf("OPÇÃO: ");
}

void pedir_Dados(Aluno *aluno[], int qtd_alunos, char nome[], char curso[], int *mat, int *cpf) {


    printf("Digite a matricula do aluno: ");
    scanf(" %d", mat);

    printf("Digite o nome do aluno: ");
    scanf(" %[^\n]", nome);

    printf("Digite o cpf do aluno: ");
    scanf(" %d", cpf);

    printf("Digite o curso do aluno: ");
    scanf(" %[^\n]", curso);


}


int verificar_Mat(Aluno *aluno[], int x){

    int mat;

    if(x == 0){
        printf("Não existe alunos cadastrados!\n");
    }else {


        printf("Digite a matricula do aluno a ser editado/excluido: ");
        scanf("%d", &mat);

        for (int i = 0; i < x; i++) {
            if (aluno[i]->matricula == mat) {
                printf("Editando aluno/excluindo: %s\n", aluno[i]->nome);
                return i;
            }
        }
        printf("Essa matricula nao existe!");
        return -1;
    }
}

void editar_Alunos(Aluno *aluno[], char nome[], char curso[], int matricula, int cpf, int aluno_e){


    strcpy(aluno[aluno_e]->nome, nome);
    aluno[aluno_e]->matricula = matricula;
    strcpy(aluno[aluno_e]->curso, curso);
    aluno[aluno_e]->cpf = cpf;


}

void remover_Alunos(Aluno *aluno[], int mat, int *qtd_alunos){

    char c;

    printf("Tem certeza que deseja excluir o aluno %s [S - Sim, N - Não]: ", aluno[mat]->nome);
    scanf(" %c", &c);
    toupper(c);
    if (c == 'S') {

        *qtd_alunos -= 1;
        for (int i = 0; i < *qtd_alunos; i++) {
            aluno[i] = aluno[i + 1];
        }printf("Aluno Excluido");

    }else {
        printf("O aluno não foi excluido!\n");
    }
}

