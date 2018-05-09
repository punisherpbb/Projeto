//
// Created by bruno on 04/05/18.
//

#include "aluno.h"

struct aluno{

    char *nome, *cpf, *curso, *matricula;

};


Aluno *cadastrar_Aluno(char *nome, char *cpf, char *curso, char *mat){


    Aluno *aluno = (Aluno*) malloc(sizeof(Aluno));

    aluno->nome = nome;
    aluno->matricula = mat;
    aluno->curso = curso;
    aluno->cpf = cpf;

    return aluno;

}

void salvar_Aluno(Aluno *p, FILE *file){


    fwrite(p, sizeof(p), 1, file);
    fclose(file);


}

void imprimir_Alunos(Aluno *p){

    FILE *f;

    f = fopen("//home//bruno//Projeto//ArqsMain//dados.dat", "rb");

    rewind(f);
    while(fread(&p, sizeof(Aluno), 1, f) == EOF){
        printf("NOME DO ALUNO: %s\n", p->nome);
        printf("CPF DO ALUNO: %s\n", p->cpf);
        printf("CURSO: %s\n", p->curso);
        printf("MATRICULA DO ALUNO: %s\n", p->matricula);
    }



    fclose(f);




}










