//
// Created by bruno on 19/05/18.
//

#ifndef PROJETO_AGENDAMENTO_H
#define PROJETO_AGENDAMENTO_H

typedef struct agendamento Agenda;

void cancelar_agendamento(Agenda *ag[], int *qtd_agendamentos);

Agenda *criar_Agendamento(int codigo_agendamento, int codigo_paciente, char nome_paciente[], char area_atendimento[], char data_consulta[]);

void listar_agendamentos(Agenda *ag[], int qtd_agendamentos);

void pedir_Dados_Ag(int *cod_paciente, char a_atendimento[], char data[]);

#endif //PROJETO_AGENDAMENTO_H
