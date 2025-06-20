// Sistema de vendas de loja de roupas.
// NOME DOS ALUNOS INTEGRANTES:
// a) Gustavo Pereira Fernandes Souto, matrícula 1240111496
// b) João Victor da Silva Guimarães, matrícula 1240107989
// c) Lucas Cabral Cândido Vasconcelos, matrícula 1230211250
// d) Moisés Fernandes da Silva, matrícula 1240110677

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>

#define NOME_DO_ARQUIVO "loja_roupa.dat"
#define STRING_MAX 50
#define ITENS_MAX 20
#define MSG_ERR_AO_ABRIR_ARQ "\nErro na abertura do arquivo!\n"

FILE *arquivo;

typedef struct {
    char codigo[STRING_MAX];
    char nome[STRING_MAX];
    char marca[STRING_MAX];
    int quantidadeVendida;
    float precoUnitario;
} Item;

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct {
    long id;
    Data data;
    Item itens[ITENS_MAX];
    int totalDeItens;
    int totalDeUnidades;
    float total;
} Venda;

long criarIdDaVenda(Data data) {
    srand(time(NULL));
    return (data.ano - 2000) * 100000 + data.mes * 1000 + (rand() % 999);
}

float calcularDesconto(float valor, int unidades) {
    return unidades >= 3 ? valor * 0.90 : valor;
}

Venda criarVenda(void) {
    Venda venda;
    Data data;
    Item itens[ITENS_MAX];

    int i = 0, j;

    printf("Digite a data 'dia-mes-ano': ");
    scanf("%d-%d-%d", &data.dia, &data.mes, &data.ano);

    while(1) {
        printf("Digite o código do item para registrar, ou 'fim' para sair: ");
        scanf(" %[^\n]", itens[i].codigo);

        if (strcmp(itens[i].codigo, "fim") != 0) {
            printf("Digite o nome: ");
            scanf(" %[^\n]", itens[i].nome);
            printf("Digite a marca: ");
            scanf(" %[^\n]", itens[i].marca);
            printf("Digite a quantidade vendida: ");
            scanf("%d", &itens[i].quantidadeVendida);
            printf("Digite o preco unitário: ");
            scanf("%f", &itens[i].precoUnitario);
            i++;
        } else {
            break;
        }
    }

    venda.data = data;
    venda.totalDeItens = 0;
    venda.totalDeUnidades = 0;
    venda.total = 0;

    for(j = 0; j < i; j++) {
        venda.itens[j] = itens[j];
        venda.totalDeItens++;
        venda.totalDeUnidades += itens[j].quantidadeVendida;
        venda.total += itens[j].quantidadeVendida * itens[j].precoUnitario;
    }

    return venda;
}

void imprimirVenda(Venda venda) {
    printf("\nDia: %d-%d-%d, id: %lu\n", venda.data.dia, venda.data.mes, venda.data.ano, venda.id);

    printf("Itens:\n");
    for(int i = 0; i < venda.totalDeItens; i++) {
        printf("  --- %d ---\n", i + 1);
        printf("  Código: %s\n", venda.itens[i].codigo);
        printf("  Nome: %s\n", venda.itens[i].nome);
        printf("  Marca: %s\n", venda.itens[i].marca);
        printf("  Quantidade vendida: %d\n", venda.itens[i].quantidadeVendida);
        printf("  Preco unitário: %.2f\n", venda.itens[i].precoUnitario);
    }

    printf("Total de itens: %d\n", venda.totalDeItens);
    printf("Total de unidades: %d\n", venda.totalDeUnidades);
    printf("Total: %.2f\n", venda.total);
}

void lerTodasVendas(void) {
    arquivo = fopen(NOME_DO_ARQUIVO, "rb");

    if (arquivo == NULL) {
        printf(MSG_ERR_AO_ABRIR_ARQ);
        exit(1);
    }

    Venda venda;

    while(fread(&venda, sizeof(Venda), 1, arquivo) == 1) {
        imprimirVenda(venda);
    }

    fclose(arquivo);
}

int contarVendasPorData(Data data) {
    arquivo = fopen(NOME_DO_ARQUIVO, "rb");

    if (arquivo == NULL) {
        printf(MSG_ERR_AO_ABRIR_ARQ);
        exit(1);
    }

    Venda venda;
    int contador = 0;

    while(fread(&venda, sizeof(Venda), 1, arquivo) == 1) {
        if (venda.data.dia == data.dia && venda.data.mes == data.mes && venda.data.ano == data.ano) {
            contador++;
        }
    }

    fclose(arquivo);

    return contador;
}

int contarItensPorData(Data data) {
    arquivo = fopen(NOME_DO_ARQUIVO, "rb");

    if (arquivo == NULL) {
        printf(MSG_ERR_AO_ABRIR_ARQ);
        exit(1);
    }

    Venda venda;
    int contador = 0;

    while(fread(&venda, sizeof(Venda), 1, arquivo) == 1) {
        if (venda.data.dia == data.dia && venda.data.mes == data.mes && venda.data.ano == data.ano) {
            contador += venda.totalDeItens;
        }
    }

    fclose(arquivo);

    return contador;
}

void boobleSort(Venda vendas[], int len) {
  int i, j;
  Venda temp;

  for(i = 0; i < len; i++) {
    for(j = 1; j < (len - i); j++) {
      if(vendas[j - 1].total < vendas[j].total) {
        temp = vendas[j - 1];
        vendas[j - 1] = vendas[j];
        vendas[j] = temp;
      }
    }
  }
}

void buscarVendaPorData(Data data) {
    int i = 0;
    int totalDeVendasDiarias = contarVendasPorData(data);
    Venda vendasDiarias[totalDeVendasDiarias];
    Venda venda;

    arquivo = fopen(NOME_DO_ARQUIVO, "rb");

    if (arquivo == NULL) {
        printf(MSG_ERR_AO_ABRIR_ARQ);
        exit(1);
    }

    rewind(arquivo);

    while(fread(&venda, sizeof(Venda), 1, arquivo) == 1) {
        if (venda.data.dia == data.dia && venda.data.mes == data.mes && venda.data.ano == data.ano) {
            vendasDiarias[i] = venda;
            i++;
        }
    }

    if (i >= 1) {
        boobleSort(vendasDiarias, totalDeVendasDiarias);

        for(int j = 0; j < totalDeVendasDiarias; j++) {
            imprimirVenda(vendasDiarias[j]);
        }
    } else {
        printf("\nNenhuma venda encontrada no dia informado!\n");
    }

    fclose(arquivo);
}

void registrarVenda(void) {
    arquivo = fopen(NOME_DO_ARQUIVO, "ab");

    if (arquivo == NULL) {
        printf(MSG_ERR_AO_ABRIR_ARQ);
        exit(1);
    }

    Venda venda = criarVenda();
    venda.id = criarIdDaVenda(venda.data);
    venda.total = calcularDesconto(venda.total, venda.totalDeUnidades);

    fwrite(&venda, sizeof(Venda), 1, arquivo);

    fclose(arquivo);

    buscarVendaPorData(venda.data);
}

void estatisticasDiarias(void) {
    Data data;

    printf("Digite a data 'dia-mes-ano': ");
    scanf("%d-%d-%d", &data.dia, &data.mes, &data.ano);

    int totalDeItensDiarios = contarItensPorData(data);

    arquivo = fopen(NOME_DO_ARQUIVO, "rb");

    if (arquivo == NULL) {
        printf(MSG_ERR_AO_ABRIR_ARQ);
        exit(1);
    }

    Venda venda;
    Item itensDiarios[totalDeItensDiarios];
    float faturamentoDiario = 0;
    int quantidadeDeVendas = 0;
    int i = 0;

    while(fread(&venda, sizeof(Venda), 1, arquivo) == 1) {
        if (venda.data.dia == data.dia && venda.data.mes == data.mes && venda.data.ano == data.ano) {
            quantidadeDeVendas++;
            faturamentoDiario += venda.total;

            for(int j = 0; j < venda.totalDeItens; j++) {
                itensDiarios[i] = venda.itens[j];
                i++;
            }
        }
    }

    Item itensSomados[totalDeItensDiarios];

    for(int j = 0; j < totalDeItensDiarios; j++) {
        strcpy(itensSomados[j].codigo, itensDiarios[j].codigo);
        strcpy(itensSomados[j].marca, itensDiarios[j].marca);
        strcpy(itensSomados[j].nome, itensDiarios[j].nome);
        itensSomados[j].precoUnitario = itensDiarios[j].precoUnitario;
        itensSomados[j].quantidadeVendida = 0;

        for(int k = 0; k < totalDeItensDiarios; k++) {
            if(strcmp(itensSomados[j].codigo, itensDiarios[k].codigo) == 0) {
                itensSomados[j].quantidadeVendida += itensDiarios[k].quantidadeVendida;
            }
        }
    }

    Item itemMaisVendido = { "inválido", "inválido", "inválido", 0, 0 };
    Item itemMenosVendido = { "inválido", "inválido", "inválido", 0, 0 };

    if(totalDeItensDiarios > 0) {
        itemMaisVendido = itensSomados[0];
        itemMenosVendido = itensSomados[0];
    }

    for(int j = 1; j < totalDeItensDiarios; j++) {
        if(itemMaisVendido.quantidadeVendida < itensSomados[j].quantidadeVendida) {
            itemMaisVendido = itensSomados[j];
        }
        if(itemMenosVendido.quantidadeVendida > itensSomados[j].quantidadeVendida) {
            itemMenosVendido = itensSomados[j];
        }
    }

    printf("\nEstatísticas diárias ");
    printf("%d-%d-%d\n", data.dia, data.mes, data.ano);
    printf("Faturamento diário: %.2f\n", faturamentoDiario);
    printf("Quantidade de vendas: %d\n", quantidadeDeVendas);

    printf("Item mais vendido:\n");
    printf("  Código: %s\n", itemMaisVendido.codigo);
    printf("  Nome: %s\n", itemMaisVendido.nome);
    printf("  Marca: %s\n", itemMaisVendido.marca);
    printf("  Quantidade vendida: %d\n", itemMaisVendido.quantidadeVendida);
    printf("  Preco unitário: %.2f\n", itemMaisVendido.precoUnitario);

    printf("Item menos vendido:\n");
    printf("  Código: %s\n", itemMenosVendido.codigo);
    printf("  Nome: %s\n", itemMenosVendido.nome);
    printf("  Marca: %s\n", itemMenosVendido.marca);
    printf("  Quantidade vendida: %d\n", itemMenosVendido.quantidadeVendida);
    printf("  Preco unitário: %.2f\n", itemMenosVendido.precoUnitario);

    fclose(arquivo);
}

void consultarVendaPorData(void) {
    Data data;

    printf("Digite a data 'dia-mes-ano': ");
    scanf("%d-%d-%d", &data.dia, &data.mes, &data.ano);

    buscarVendaPorData(data);
}

void consultarVendaPorId(void) {
    arquivo = fopen(NOME_DO_ARQUIVO, "rb");

    if (arquivo == NULL) {
        printf(MSG_ERR_AO_ABRIR_ARQ);
        exit(1);
    }

    long idVenda;
    Venda venda;
    int encontrado = 0;

    printf("Digite o id da venda: ");
    scanf("%lu", &idVenda);

    rewind(arquivo);

    while(fread(&venda, sizeof(Venda), 1, arquivo) == 1) {
        if (venda.id == idVenda) {
            imprimirVenda(venda);
            encontrado = 1;
            break;
        }
    }

    if (encontrado == 0) {
        printf("\nNenhuma venda encontrada com o id informado!\n");
    }

    fclose(arquivo);
}

void alterarVendaPorId(void) {
    arquivo = fopen(NOME_DO_ARQUIVO, "rb+");

    if (arquivo == NULL) {
        printf(MSG_ERR_AO_ABRIR_ARQ);
        exit(1);
    }

    long idVenda;
    Venda venda;
    int encontrado = 0;

    printf("Digite o id da venda: ");
    scanf("%lu", &idVenda);

    rewind(arquivo);

    while(fread(&venda, sizeof(Venda), 1, arquivo) == 1) {
        if (venda.id == idVenda) {
            imprimirVenda(venda);
            printf("\n\nVenda encontrada, insira os novos dados:\n");

            Venda vendaModificada = criarVenda();
            vendaModificada.id = idVenda;

            fseek(arquivo, -sizeof(Venda), SEEK_CUR);
            fwrite(&vendaModificada, sizeof(Venda), 1, arquivo);

            printf("Os dados foram alterados com sucesso!\n");
            encontrado = 1;
            break;
        }
    }

    if (encontrado == 0) {
        printf("\nNenhuma venda encontrada com o id informado!\n");
    }

    fclose(arquivo);
}

void deletarVendaPorId(void) {
    arquivo = fopen(NOME_DO_ARQUIVO, "rb");
    FILE *temporario = fopen("temp.bin", "wb");

    if(arquivo == NULL || temporario == NULL) {
        printf(MSG_ERR_AO_ABRIR_ARQ);
        exit(1);
    }

    long idVenda;
    Venda venda;

    printf("Digite o id da venda: ");
    scanf("%lu", &idVenda);

    rewind(arquivo);

    while(fread(&venda, sizeof(Venda), 1, arquivo) == 1) {
        if (venda.id != idVenda) {
            fwrite(&venda, sizeof(Venda), 1, temporario);
        }
    }

    fclose(arquivo);
    fclose(temporario);

    if(remove(NOME_DO_ARQUIVO) != 0) {
        printf("\nErro ao remover o arquivo original!\n");
    }

    if(rename("temp.bin", NOME_DO_ARQUIVO) != 0) {
        printf("\nErro ao remover o arquivo temporário!\n");
    }
}

int main(void) {
    setlocale(LC_ALL, "portuguese");

    int opcao;

    //system("CLS"); //windows
    system("clear"); //linux

    do {
        printf("____________________________________\n");
        printf("Sistema de vendas de loja de roupas\n\n");
        printf("Digite o número da opção desejada:\n");
        printf("1 - Registrar uma venda\n");
        printf("2 - Listar todas as vendas\n");
        printf("3 - Verificar as estatísticas diárias\n");
        printf("4 - Consultar vendas pela data\n");
        printf("5 - Consultar uma venda pelo id\n");
        printf("6 - Alterar uma venda pelo id\n");
        printf("7 - Excluir uma venda pelo id\n");
        printf("0 - Sair\n");
        printf("____________________________________\n");
        printf("Opção: ");

        if (scanf("%d", &opcao) != 1) {
            printf("Erro: Valor não numérico!\n\n");
            exit(1);
        }

        switch(opcao) {
            case 1:
                registrarVenda();
                printf("\nInclusão concluída!\n\n");
                break;
            case 2:
                lerTodasVendas();
                break;
            case 3:
                estatisticasDiarias();
                break;
            case 4:
                consultarVendaPorData();
                break;
            case 5:
                consultarVendaPorId();
                break;
            case 6:
                alterarVendaPorId();
                break;
            case 7:
                deletarVendaPorId();
                break;
            case 0:
                printf("Saindo!\n\n");
                break;
            default:
                printf("Digite uma opção válida!\n\n");
                break;
        }
    } while(opcao != 0);

    //system("PAUSE"); //windows
    getchar(); //linux

    return 0;
}
