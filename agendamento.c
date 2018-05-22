//
// Created by bruno on 19/05/18.
//

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "agendamento.h"
#include "pacientes.h"

struct agendamento{

    int codigo_agendamento, codigo_paciente;
    char nome_paciente[30], area_atendimento[40], data_consulta[15];


};


Agenda *criar_Agendamento(int codigo_agendamento, int codigo_paciente, char nome_paciente[], char area_atendimento[], char data_consulta[]){

    Agenda *agenda = (Agenda*) malloc(sizeof(Agenda));

    agenda->codigo_agendamento = codigo_agendamento + 1;

    agenda->codigo_paciente = codigo_paciente;

    strcpy(agenda->nome_paciente, nome_paciente);

    strcpy(agenda->area_atendimento, area_atendimento);

    strcpy(agenda->data_consulta, data_consulta);

    return agenda;


}

void cancelar_agendamento(Agenda *ag[], int *qtd_agendamentos){

    if(*qtd_agendamentos == 0){
        printf("Não existe agendamentos.\n");
    }else{


        *qtd_agendamentos-=1;
        for(int i = 0; i < *qtd_agendamentos; i++){
            ag[i] = ag[i + 1];
        }printf("Agendamento cancelado.\n");
        return;

    }printf("Não foi possivel cancelar o agendamento!\n");


}

void listar_agendamentos(Agenda *ag[], int qtd_agendamentos){

    for (int i = 0; i < qtd_agendamentos; ++i) {
        printf("\n\nAgendamento %d\n", i + 1);
        printf("Codigo do agendamento: %d\n", ag[i]->codigo_agendamento);
        printf("Codigo do paciente: %d\n", ag[i]->codigo_paciente);
        printf("Nome do paciente: %s\n", ag[i]->nome_paciente);
        printf("Area de atendimento: %s\n", ag[i]->area_atendimento);
        printf("Data da consulta: %s\n", ag[i]->data_consulta);
    }

}

void pedir_Dados_Ag(int *cod_paciente, char a_atendimento[], char data[]){


    printf("Digite o codigo do paciente: ");
    scanf("%d", cod_paciente);

    printf("Digite a area do atendimento: ");
    scanf(" %[^\n]", a_atendimento);

    printf("Digite a data da consulta: ");
    scanf(" %[^\n]", data);


}








