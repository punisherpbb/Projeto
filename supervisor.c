//
// Created by bruno on 19/05/18.
//

#include "supervisor.h"
#include "pacientes.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct supervisor{

    int cod_professor;
    char nome[30], curso[40];

};


Supervisor *cadastrar_Supervisor(int codigo, char nome[], char curso[]){

    Supervisor *sup = (Supervisor*) malloc(sizeof(Supervisor));

    sup->cod_professor = codigo;
    strcpy(sup->nome, nome);
    strcpy(sup->curso, curso);

    return sup;

}


void remover_Supervisor(Supervisor *sup[], int *qtd_supervisores, int aux){

    char c;
    printf("Excluindo o supervisor %s\n\n", sup[aux]->nome);
    printf("Tem certeza que deseja excluir o supervisor %s? [S - sim, N - Não]: ", sup[aux]->nome);
    scanf(" %c", &c);
    if(c == 'S'){
        *qtd_supervisores-=1;
        for(int i = 0; i < *qtd_supervisores; i++){
            sup[i] = sup[i + 1];
        }printf("Supervisor excluido!\n");
    }else{
        printf("O supervisor não foi excluido!\n");
    }


}
void editar_Supervisor(Supervisor *sup[], int codigo, char nome[], char curso[], int aux){

    strcpy(sup[aux]->nome, nome);
    strcpy(sup[aux]->curso, curso);
    sup[aux]->cod_professor = codigo;


}

int verificar_cod_S(Supervisor *sup[], int qtd_supervisores){

    int codigo;

    if(qtd_supervisores == 0){
        printf("Não existe supervisores cadastrados!\n");
    }else{

        printf("Digite o codigo do supervisor: ");
        scanf("%d", &codigo);

        for(int i = 0; i < qtd_supervisores; i++){
            if(sup[i]->cod_professor == codigo){
                return i;
            }
        }printf("Esse supervisor não existe!\n");
        return -1;

    }

}

void listar_Supervisores(Supervisor *sup[], int qtd_supervisores) {

    if (qtd_supervisores == 0) {
        printf("Não existe supervisores cadastrados!\n");
    } else {

        for (int i = 0; i < qtd_supervisores; i++) {

            printf("Supervisor %d\n", i + 1);
            printf("Nome: %s\n", sup[i]->nome);
            printf("Curso: %s\n", sup[i]->curso);
            printf("Codigo: %d\n", sup[i]->cod_professor);


        }

    }
}

void menu_Supervisor(){

    printf("\n\n############################################\n");
    printf("############## MENU DO SUPERVISOR ############\n");
    printf("############################################\n\n");
    printf("1 - ADICIONAR\n");
    printf("2 - REMOVER\n");
    printf("3 - EDITAR\n");
    printf("4 - LISTAR\n");
    printf("5 - SAIR\n");
    printf("OPÇÃO: ");


}

void pedir_Dados_S(int *codigo, char nome[], char curso[]){

    printf("Digite o codigo do supervisor: ");
    scanf(" %d", codigo);

    printf("Digite o nome do supervisor: ");
    scanf(" %[^\n]", nome);

    printf("Digite o curso do supervisor: ");
    scanf(" %[^\n]", curso);

}


