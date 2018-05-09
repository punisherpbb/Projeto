//
// Created by bruno on 04/05/18.
//

#ifndef PROJETO_ALUNO_H
#define PROJETO_ALUNO_H


#include <malloc.h>

typedef struct aluno Aluno;

Aluno *cadastrar_Aluno(char *nome, char *cpf, char *curso, char *mat);

void salvar_Aluno(Aluno *p, FILE *file);


void imprimir_Alunos(Aluno *p);

#endif //PROJETO_ALUNO_H
