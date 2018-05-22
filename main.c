#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"
#include "pacientes.h"
#include "supervisor.h"
#include "agendamento.h"

void menu_Principal(){

    printf("\n\n###########################################\n");
    printf("############# MENU PRINCIPAL ##############\n");
    printf("###########################################\n\n");
    printf("1 - OPÇÕES DE ALUNO\n");
    printf("2 - OPÇÕES DE PACIENTE\n");
    printf("3 - OPÇÕES DE SUPERVISOR\n");
    printf("4 - OPÇÕES DE AGENDAMENTO\n");
    printf("5 - SAIR\n\n");
    printf("OPÇÃO: ");
}

//Main pode ser temporario

int main(){

    //VARIAVEIS DO SISTEMA
    int op_S, op_A, op_P, op_Sup;

    //VARIAVEIS DO ALUNO
    int qtd_alunos = 0, cpf, mat, aux;

    char nome[20], curso[30];

    int *pont = &qtd_alunos, *pont1 = &mat, *pont2 = &cpf;

    //VARIAVEIS DO PACIENTE
    int qtd_paciente = 0, cod, cpf_p;

    char nome_p[30], end_P[40], idade[10];

    int *pontcpf = &cpf, *pontcod = &cod, *pontqtd_P = &qtd_paciente;


    //VARIAVEIS DO SUPERVISOR
    int qtd_supervisores = 0, cod_Sup;

    char nome_Sup[30], curso_Sup[40];

    int *pontcod_S = &cod_Sup, *pontsup = &qtd_supervisores;

    //VARIAVEIS DO AGENDAMENTO
    int cod_agendamento = 0, cod_paciente, qtd_agendamentos = 0;
    char a_atendimento[40], data[15];
    int *pont_cod_paciente = &cod_paciente;

    //VETORES DAS ESTRUTURAS
    Aluno *aluno[1000];
    Paciente *p[1000];
    Supervisor *sup[1000];
    Agenda *ag[1000];

    do {

        menu_Principal();

        scanf("%d", &op_S);

        if(op_S == 1) {

            menu_Aluno();
            scanf(" %d", &op_A);

            if (op_A == 1) {

                pedir_Dados(aluno, qtd_alunos, nome, curso, pont1, pont2);

                aluno[qtd_alunos] = adicionar_Aluno(nome, curso, mat, cpf);

                qtd_alunos++;

            } else if (op_A == 2) {

                aux = verificar_Mat(aluno, qtd_alunos);

                remover_Alunos(aluno, aux, pont);

            } else if (op_A == 3) {

                aux = verificar_Mat(aluno, qtd_alunos);

                if (aux != -1) {

                    pedir_Dados(aluno, qtd_alunos, nome, curso, pont1, pont2);

                    editar_Alunos(aluno, nome, curso, mat, cpf, aux);

                } else {

                    continue;
                }

            } else if (op_A == 4) {

                imprimir_Alunos(aluno, qtd_alunos);

            }
        }else if(op_S == 2){

            menu_Paciente();
            scanf("%d", &op_P);

            if(op_P == 1){

                pedir_Dados_P(nome_p, end_P, idade, pontcod, pontcpf);

                p[qtd_paciente] = cadastrar_Paciente(cod, idade, cpf, nome_p, end_P);

                qtd_paciente++;

            }else if(op_P == 2){

                aux = verificar_cod_P(p, qtd_paciente);

                remover_Paciente(p, aux, pontqtd_P);

            }else if (op_P == 3){

                aux = verificar_cod_P(p, qtd_paciente);

                if(aux != -1){

                    pedir_Dados_P(nome_p, end_P, idade, pontcod, pontcpf);

                    editar_Paciente(p, nome_p, end_P, idade, cod, cpf, aux);

                }else{

                    continue;
                }
            } else if(op_P == 4){

                listar_Pacientes(p, qtd_paciente);

            }

        }else if(op_S == 3){

            menu_Supervisor();
            scanf("%d", &op_Sup);

            if(op_Sup == 1){

                pedir_Dados_S(pontcod_S, nome_Sup, curso_Sup);

                sup[qtd_supervisores] = cadastrar_Supervisor(cod_Sup, nome_Sup, curso_Sup);

                qtd_supervisores++;

            }else if(op_Sup == 2){

                aux = verificar_cod_S(sup, qtd_supervisores);

                remover_Supervisor(sup, pontsup, aux);

            }else if(op_Sup == 3){

                aux = verificar_cod_S(sup, qtd_supervisores);

                if(aux != -1){

                    pedir_Dados_S(pontcod_S, nome_Sup, curso_Sup);

                    editar_Supervisor(sup, cod_Sup, nome_Sup, curso_Sup, aux);

                }else{

                    continue;

                }

            }else if(op_Sup == 4){

                listar_Supervisores(sup, qtd_supervisores);

            }

        }else if(op_S == 4){

            pedir_Dados_Ag(pont_cod_paciente, a_atendimento, data);

            if(procurar_Paciente(p, nome_p, pont_cod_paciente, qtd_paciente)) {

                ag[qtd_agendamentos] = criar_Agendamento(cod_agendamento, cod_paciente, nome_p, a_atendimento, data);

                qtd_agendamentos++;

                listar_agendamentos(ag, qtd_agendamentos);
            }
            
        }

    }while(op_S != 5);



    return 0;
}