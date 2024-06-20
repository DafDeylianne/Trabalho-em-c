#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Aqui a gente podemos fazer a Definição dos limites máximos de pacientes, médicos e consultas
#define MAX_PACIENTES 100
#define MAX_MEDICOS 50
#define MAX_CONSULTAS 200

// Aqui temos uma estrutura que armazena informações dos pacientes
typedef struct {
    char nome[50];
    int idade;
    char endereco[100];
    char telefone[15];
    char estado[3]; 
} Paciente;

// Aqui temos uma estrutura que armazena as informações dos médicos
typedef struct {
    char nome[50];
    char especialidade[50];
    char crm[20];
    char telefone[15];
    char tipoServico[50]; // campo para tipo de serviço do médico
} Medico;

// Aqui temos uma estrutura que armazena informações das consultas
typedef struct {
    int dia, mes, ano;
    int hora, minuto;
    char nomePaciente[50];
    char nomeMedico[50];
    float valor; // campo para valor da consulta
} Consulta;

// Arrays para armazenar os registros de pacientes, médicos e consultas
Paciente pacientes[MAX_PACIENTES];
Medico medicos[MAX_MEDICOS];
Consulta consultas[MAX_CONSULTAS];

// Contadores para rastrear o número de pacientes, médicos e consultas registrados
int contadorPacientes = 0;
int contadorMedicos = 0;
int contadorConsultas = 0;

// Função para adicionar um novo paciente
void adicionarPaciente() {
    // Verifica se o limite de pacientes foi atingido
    if(contadorPacientes >= MAX_PACIENTES) {
        printf("Limite de pacientes atingido.\n");
        return;
    }
    Paciente p;
    // Recebe as informações do paciente
    printf("Nome do Paciente: ");
    scanf(" %[^\n]", p.nome);
    printf("Idade: ");
    scanf("%d", &p.idade);
    printf("Endereço: ");
    scanf(" %[^\n]", p.endereco);
    printf("Telefone: ");
    scanf(" %[^\n]", p.telefone);
    printf("Estado: ");
    scanf(" %[^\n]", p.estado);
    // a gente adiciona o paciente ao array e incrementa o contador
    pacientes[contadorPacientes++] = p;
    printf("Paciente adicionado com sucesso!\n");
}

// Função para adicionar um novo médico
void adicionarMedico() {
    // Verifica se o limite de médicos foi atingido
    if(contadorMedicos >= MAX_MEDICOS) {
        printf("Limite de médicos atingido.\n");
        return;
    }
    Medico m;
    // Recebe as informações do médico
    printf("Nome do Médico: ");
    scanf(" %[^\n]", m.nome);
    printf("Especialidade: ");
    scanf(" %[^\n]", m.especialidade);
    printf("CRM: ");
    scanf(" %[^\n]", m.crm);
    printf("Telefone: ");
    scanf(" %[^\n]", m.telefone);
    printf("Tipo de Serviço: ");
    scanf(" %[^\n]", m.tipoServico);
    // a gente adiciona o médico ao array e incrementa o contador
    medicos[contadorMedicos++] = m;
    printf("Médico adicionado com sucesso!\n");
}

// Função para agendar uma nova consulta
void agendarConsulta() {
    // Verifica se o limite de consultas foi atingido
    if(contadorConsultas >= MAX_CONSULTAS) {
        printf("Limite de consultas atingido.\n");
        return;
    }
    Consulta c;
    // Recebe as informações da consulta
    printf("Data da Consulta (DD MM AAAA): ");
    scanf("%d %d %d", &c.dia, &c.mes, &c.ano);
    printf("Hora da Consulta (HH MM): ");
    scanf("%d %d", &c.hora, &c.minuto);
    printf("Nome do Paciente: ");
    scanf(" %[^\n]", c.nomePaciente);
    printf("Nome do Médico: ");
    scanf(" %[^\n]", c.nomeMedico);
    printf("Valor da Consulta: ");
    scanf("%f", &c.valor);
    // Adiciona a consulta ao array e incrementa o contador
    consultas[contadorConsultas++] = c;
    printf("Consulta agendada com sucesso!\n");
}

// aqui temos a função para listar todos os tipos de serviços
void listarTiposServicos() {
    printf("Tipos de Serviços:\n");
    // neste ponto ele percorre o array de médicos e imprime os tipos de serviços
    for(int i = 0; i < contadorMedicos; i++) {
        printf("%s\n", medicos[i].tipoServico);
    }
}

// Função para listar todos os clientes cadastrados
void listarClientes() {
    printf("Clientes:\n");
    // neste ponto ele percorre o array de pacientes e imprime as informações
    for(int i = 0; i < contadorPacientes; i++) {
        printf("Nome: %s, Estado: %s\n", pacientes[i].nome, pacientes[i].estado);
    }
}

// Função para listar todos os médicos cadastrados
void listarMedicos() {
    printf("Médicos:\n");
    // Percorre o array de médicos e imprime as informações
    for(int i = 0; i < contadorMedicos; i++) {
        printf("Nome: %s, Tipo de Serviço: %s\n", medicos[i].nome, medicos[i].tipoServico);
    }
}

// Função para listar clientes de um determinado estado
void listarClientesPorEstado(char* estado) {
    printf("Clientes do estado %s:\n", estado);
    // Percorre o array de pacientes e imprime os que são do estado especificado
    for(int i = 0; i < contadorPacientes; i++) {
        if(strcmp(pacientes[i].estado, estado) == 0) {
            printf("%s\n", pacientes[i].nome);
        }
    }
}

// Função para listar prestadores de serviço de um determinado tipo
void listarPrestadoresPorTipo(char* tipo) {
    printf("Prestadores de serviço do tipo %s:\n", tipo);
    // Percorre o array de médicos e imprime os que fornecem o tipo de serviço especificado
    for(int i = 0; i < contadorMedicos; i++) {
        if(strcmp(medicos[i].tipoServico, tipo) == 0) {
            printf("%s\n", medicos[i].nome);
        }
    }
}

// Função para apresentar os estados onde está registrado o serviço mais caro
void apresentarEstadosServicoMaisCaro() {
    float maxValor = 0;
    // Percorre o array de consultas para encontrar o valor máximo
    for(int i = 0; i < contadorConsultas; i++) {
        if(consultas[i].valor > maxValor) {
            maxValor = consultas[i].valor;
        }
    }

    printf("Estados onde está registrado o serviço mais caro:\n");
    // Percorre o array de consultas para encontrar os estados com o serviço mais caro
    for(int i = 0; i < contadorConsultas; i++) {
        if(consultas[i].valor == maxValor) {
            for(int j = 0; j < contadorPacientes; j++) {
                if(strcmp(consultas[i].nomePaciente, pacientes[j].nome) == 0) {
                    printf("%s\n", pacientes[j].estado);
                }
            }
        }
    }
}

// Função de comparação para ordenar consultas por valor crescente
int comparaConsultas(const void* a, const void* b) {
    Consulta* consultaA = (Consulta*)a;
    Consulta* consultaB = (Consulta*)b;
    return (consultaA->valor > consultaB->valor) - (consultaA->valor < consultaB->valor);
}

// Função para listar consultas em ordem crescente de valor
void listarConsultasPorValorCrescente() {
    // Ordena o array de consultas pelo valor
    qsort(consultas, contadorConsultas, sizeof(Consulta), comparaConsultas);
    printf("Consultas em ordem crescente de valor:\n");
    // Percorre o array de consultas e imprime as informações
    for(int i = 0; i < contadorConsultas; i++) {
        printf("Consulta %d: Valor: %.2f, Paciente: %s, Médico: %s\n", 
               i+1, consultas[i].valor, consultas[i].nomePaciente, consultas[i].nomeMedico);
    }
}

// Função de comparação para ordenar pacientes por nome crescente
int comparaPacientes(const void* a, const void* b) {
    Paciente* pacienteA = (Paciente*)a;
    Paciente* pacienteB = (Paciente*)b;
    return strcmp(pacienteA->nome, pacienteB->nome);
}

// Função para listar pacientes em ordem crescente de nome
void listarClientesPorNomeCrescente() {
    // Ordena o array de pacientes pelo nome
    qsort(pacientes, contadorPacientes, sizeof(Paciente), comparaPacientes);
    printf("Clientes em ordem crescente de nome:\n");
    // Percorre o array de pacientes e imprime as informações
    for(int i = 0; i < contadorPacientes; i++) {
        printf("%s\n", pacientes[i].nome);
    }
}

// Função que exibe o menu de operações e processa a escolha do usuário
void menu() {
    int opcao;
    char estado[3];
    char tipo[50];

    do {
        // Exibe as opções do menu
        printf("\nMenu de Operações:\n");
        printf("1. Adicionar Paciente\n");
        printf("2. Adicionar Médico\n");
        printf("3. Agendar Consulta\n");
        printf("4. Listar Tipos de Serviços\n");
        printf("5. Listar Clientes\n");
        printf("6. Listar Médicos\n");
        printf("7. Listar Clientes por Estado\n");
        printf("8. Listar Prestadores por Tipo de Serviço\n");
        printf("9. Apresentar Estados com o Serviço Mais Caro\n");
        printf("10. Listar Consultas por Valor Crescente\n");
        printf("11. Listar Clientes por Nome Crescente\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        // Processa a escolha do usuário
        switch(opcao) {
            case 1: adicionarPaciente(); break; // Chama a função para adicionar paciente
            case 2: adicionarMedico(); break; // Chama a função para adicionar médico
            case 3: agendarConsulta(); break; // Chama a função para agendar consulta
            case 4: listarTiposServicos(); break; // Chama a função para listar tipos de serviços
            case 5: listarClientes(); break; // Chama a função para listar clientes
            case 6: listarMedicos(); break; // Chama a função para listar médicos
            case 7: 
                printf("Digite o estado: ");
                scanf(" %[^\n]", estado);
                listarClientesPorEstado(estado); break; // Chama a função para listar clientes por estado
            case 8: 
                printf("Digite o tipo de serviço: ");
                scanf(" %[^\n]", tipo);
                listarPrestadoresPorTipo(tipo); break; // Chama a função para listar prestadores por tipo de serviço
            case 9: apresentarEstadosServicoMaisCaro(); break; // Chama a função para apresentar estados com o serviço mais caro
            case 10: listarConsultasPorValorCrescente(); break; // Chama a função para listar consultas por valor crescente
            case 11: listarClientesPorNomeCrescente(); break; // Chama a função para listar clientes por nome crescente
            case 0: printf("Saindo...\n"); break; // Sai do programa
            default: printf("Opção inválida. Tente novamente.\n"); // Trata opção inválida
        }
    } while(opcao != 0); // Continua exibindo o menu até que o usuário escolha sair
}

// Função principal que inicia o programa
int main() {
    menu(); // Chama a função de menu
    return 0;
}