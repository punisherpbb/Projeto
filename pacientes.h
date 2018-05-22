//
// Created by bruno on 15/05/18.
//

#ifndef PROJETO_PACIENTES_H
#define PROJETO_PACIENTES_H


typedef struct paciente Paciente;

Paciente *cadastrar_Paciente(int cod, char idade[], int cpf, char nome[], char end[]);

void pedir_Dados_P(char nome[], char end[], char idade[], int *cod, int *cpf);

void listar_Pacientes(Paciente *p[], int qtd_pacientes);

int verificar_cod_P(Paciente *p[], int x);

void menu_Paciente();

void remover_Paciente(Paciente *p[], int codigo, int *qtd_pacientes);

void editar_Paciente(Paciente *p[], char nome[], char end[], char idade[], int cod, int cpf, int aux);

int procurar_Paciente(Paciente *p[], char nome[], int *codigo, int qtd_pacientes);

#endif //PROJETO_PACIENTES_H
