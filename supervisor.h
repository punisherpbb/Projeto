//
// Created by bruno on 19/05/18.
//

#ifndef PROJETO_SUPERVISOR_H
#define PROJETO_SUPERVISOR_H

typedef struct supervisor Supervisor;

void remover_Supervisor(Supervisor *sup[], int *qtd_supervisores, int aux);

Supervisor *cadastrar_Supervisor(int codigo, char nome[], char curso[]);

void editar_Supervisor(Supervisor *sup[], int codigo, char nome[], char curso[], int aux);

void listar_Supervisores(Supervisor *sup[], int qtd_supervisores);

void pedir_Dados_S(int *codigo, char nome[], char curso[]);

void menu_Supervisor();

int verificar_cod_S(Supervisor *sup[], int qtd_supervisores);


#endif //PROJETO_SUPERVISOR_H

