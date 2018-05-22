//
// Criado por bruno em 04/05/18.
//

#ifndef PROJETO_ALUNO_H
#define PROJETO_ALUNO_H

typedef struct aluno Aluno;

Aluno *adicionar_Aluno(char nome[], char curso[], int matricula, int cpf);

void imprimir_Alunos(Aluno *aluno[], int x);

void menu_Aluno();

void editar_Alunos(Aluno *aluno[], char nome[], char curso[], int matricula, int cpf, int aluno_e);

int verificar_Mat(Aluno *aluno[], int x);

void remover_Alunos(Aluno *aluno[], int mat, int *qtd_alunos);

void pedir_Dados(Aluno *aluno[], int qtd_alunos, char nome[], char curso[], int *mat, int *cpf);

# endif  // PROJETO_ALUNO_H