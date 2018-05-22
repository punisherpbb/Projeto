//
// Created by bruno on 15/05/18.
//

#include "pacientes.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

struct paciente {

    int cod_paciente, cpf;
    char nome[30], endereco[40], idade[10];

};

Paciente *cadastrar_Paciente(int cod, char idade[], int cpf, char nome[], char end[]){

    Paciente *paciente = (Paciente*) malloc(sizeof(Paciente));

    paciente->cod_paciente = cod;
    strcpy(paciente->idade, idade);
    paciente->cpf = cpf;
    strcpy(paciente->nome, nome);
    strcpy(paciente->endereco, end);

    return paciente;

}


void listar_Pacientes(Paciente *p[], int qtd_pacientes){

    if(qtd_pacientes == 0){

        printf("Não existe pacientes cadastrados");
    }else{

        for(int i = 0; i < qtd_pacientes; i++){
            printf("\nPaciente %d\n", i + 1);
            printf("NOME: %s\n", p[i]->nome);
            printf("Codigo: %d\n", p[i]->cod_paciente);
            printf("Idade: %s\n", p[i]->idade);
            printf("CPF: %d\n", p[i]->cpf);
            printf("Endereço: %s\n", p[i]->endereco);
            printf("\n");
        }

    }

}

void remover_Paciente(Paciente *p[], int codigo, int *qtd_pacientes){

    char c;
    printf("Tem certeza que deseja excluir o paciente %s? [S - Sim, N - Não]: ", p[codigo]->nome);
    scanf(" %c", &c);
    toupper(c);

    if(c == 'S') {
        *qtd_pacientes-=1;
        for (int i = 0; i < *qtd_pacientes; i++) {
            p[i] = p[i + 1];
        }
        printf("Paciente Excluindo!\n");
    }else{
        printf("Paciente não foi excluindo\n");
    }

}

void pedir_Dados_P(char nome[], char end[], char idade[], int *cod, int *cpf){

    printf("Digite o nome do paciente: ");
    scanf(" %[^\n]", nome);

    printf("Digite o codigo do paciente: ");
    scanf("%d", cod);

    printf("Digite a idade do Paciente: ");
    scanf(" %[^\n]", idade);

    printf("Digite o CPF: ");
    scanf("%d", cpf);

    printf("Digite o endereço do paciente: ");
    scanf(" %[^\n]", end);


}

void menu_Paciente(){

    printf("\n\n############################################\n");
    printf("############## MENU DO PACIENTE ############\n");
    printf("############################################\n\n");
    printf("1 - ADICIONAR\n");
    printf("2 - REMOVER\n");
    printf("3 - EDITAR\n");
    printf("4 - LISTAR\n");
    printf("5 - SAIR\n");
    printf("OPÇÃO: ");


}

int verificar_cod_P(Paciente *p[], int x){

        int cod, i;
        printf("Digite o codigo do paciente a ser editado/excluido: ");
        scanf("%d", &cod);

        for(i = 0; i < x; i++){
            if(p[i]->cod_paciente == cod){
                printf("Editando aluno/excluindo: %s\n", p[i]->nome);
                return i;
            }
        }
        printf("Esse codigo nao existe!");
        return -1;

}

void editar_Paciente(Paciente *p[], char nome[], char end[], char idade[], int cod, int cpf, int aux){

    strcpy(p[aux]->nome, nome);
    strcpy(p[aux]->endereco, end);
    strcpy(p[aux]->idade, idade);
    p[aux]->cod_paciente = cod;
    p[aux]->cpf = cpf;


}

int procurar_Paciente(Paciente *p[], char nome[], int *codigo, int qtd_pacientes){

    for(int i = 0; i < qtd_pacientes; i++){

        if(p[i]->cod_paciente == *codigo){
            strcpy(p[i]->nome, nome);
            return 1;
        }
    }printf("Esse paciente não está cadastrado!\n");
    return 0;


}