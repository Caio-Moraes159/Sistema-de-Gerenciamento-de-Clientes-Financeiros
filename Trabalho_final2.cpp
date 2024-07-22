#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

//dados das parcelas
struct parcelas_emprestimo 
{
    double valor_da_parcela;
    string paga_ou_nao;
    string data_do_pagamento;
    string data_do_vencimento;
};

// dados dos clientes
struct dados_clientes
{
    string nome_do_cliente;
    string cpf;
    string endereco;
    string data_de_nascimento;
    string data_do_emprestimo;
    double valor_total_do_emprestimo;
    int num_parcelas;
    struct parcelas_emprestimo informacoes_sobre_emprestimo[12];
};

//controle de clientes
struct organizador_cliente
{
    int n;
};
//controle de parcelas
struct organizador_parcela
{
    int n[10];
};

//protótipo da função de escolhas da interface
int fun_escolha(int escolha, int n);

//função que mostra a interface
void fun_interface(int *escolha){
    int escolha_teste;
    system("cls");
    cout << endl
         << " 1. Cadastrar cliente" << endl
         << " 2. Visualizar as informacoes de um cliente" << endl
         << " 3. Editar as informacoes de um cliente" << endl
         << " 4. Cadastrar parcela paga" << endl
         << " 5. Cadastrar emprestimo" << endl
         << " 6. Excluir cliente" << endl
         << " 7. SAIR" << endl
         << endl
         << "-O que deseja? ";
    cin >> escolha_teste;
    *escolha = escolha_teste;
    cout << endl;
}

//função para cadastrar os clientes - 1
void cadas_client(dados_clientes cliente[], int n, organizador_cliente org_cliente[])
{    
    system("cls");
    string outro_cliente;
    int i = 0;

    while (org_cliente[i].n == 1)
    {
        i++;
    }  

    for (i; i < n; i++)
    {
    cout <<  "------------------------CLIENTE "<< i+1 << "------------------------" << endl;
 
    cout << "Nome do cliente: ";
    cin.ignore();
    getline(cin, cliente[i].nome_do_cliente);

    cout << "CPF: ";
    cin >> cliente[i].cpf;

    cout << "Endereco: ";
    cin.ignore();
    getline(cin, cliente[i].endereco);

    cout << "Data de nascimento(DD/MM/AAAA): ";
    cin >> cliente[i].data_de_nascimento; 

    cout << "Data do emprestimo(DD/MM/AAAA): ";
    cin >> cliente[i].data_do_emprestimo;

    cout << "Valor total do emprestimo: ";
    cin >> cliente[i].valor_total_do_emprestimo;

    cout << "Em quantas parcelas: ";
    cin >> cliente[i].num_parcelas;
    
    int valor_parcela = cliente[i].valor_total_do_emprestimo/cliente[i].num_parcelas;

    for (int parcelas = 0; parcelas < cliente[i].num_parcelas; parcelas++)
    {   
        cliente[i].informacoes_sobre_emprestimo[parcelas].valor_da_parcela = valor_parcela;
    }

    string n = "4";
    string ano = "3";
    string dia = "30";
    int dia_int = 0;
    for (int parcelas = 0; parcelas < cliente[i].num_parcelas; parcelas++)
    {
        cliente[i].informacoes_sobre_emprestimo[parcelas].paga_ou_nao = "NAO";
        cliente[i].informacoes_sobre_emprestimo[parcelas].data_do_vencimento = dia + "/" + n + "/202" + ano;
        int mes_int = stoi(n);
        mes_int += 1;

        if (mes_int == 2)
        {
            dia_int = 28;
            dia = to_string(dia_int);
        } 
        else
        {
            dia_int = 30;
            dia = to_string(dia_int);
        };

        if (mes_int >12)
        {
            mes_int = 1;
            int ano_int = stoi(ano);
            ano_int += 1;
            ano = to_string(ano_int);           
        }
        n = to_string(mes_int); 
    }

    cout << "---------------------------------------------------------" << endl 
     << "Deseja criar outro cliente (sim ou nao)? ";
    cin >> outro_cliente;   

    org_cliente[i].n = 1;
    
        if (outro_cliente != "sim")
        {
            return; 
        }

        system("cls");
    }
}

//função para visualizar as informações do cliente criado - 2
void info_cliente(dados_clientes cliente[], int n, organizador_cliente org_cliente[])
{   
    system("cls");
    int escolha = 0;
    string outro_cliente = "sim";

    cout << "Qual cliente deseja acessar? ";
    cin >> escolha;
    escolha -= 1;

    if (org_cliente[escolha].n == 0)
    {
        cout << endl << "Nao existe esse cliente!!" << endl << endl;
        system("pause");
        return;
    }
    

    while(outro_cliente == "sim")
    {   
        cout << endl
         << "------------------------CLIENTE "<< escolha + 1 << "------------------------" << endl 
         << "Nome do cliente: " << cliente[escolha].nome_do_cliente << endl
         << "CPF: " << cliente[escolha].cpf << endl
         << "Endereco: " << cliente[escolha].endereco << endl
         << "Data de nascimento: " << cliente[escolha].data_de_nascimento << endl
         << "Data do emprestimo: " << cliente[escolha].data_do_emprestimo << endl
         << "Valor do emprestimo: " << cliente[escolha].valor_total_do_emprestimo << endl << endl
         << "------------------EMPRESTIMO ("<< cliente[escolha].num_parcelas <<" parcelas)-----------------" << endl
         << "Valor: " << cliente[escolha].informacoes_sobre_emprestimo[0].valor_da_parcela << endl
         << "Pago ou nao: " << cliente[escolha].informacoes_sobre_emprestimo[0].paga_ou_nao << endl
         << "Data do pagamento: " << cliente[escolha].informacoes_sobre_emprestimo[0].data_do_pagamento << endl
         << "Data de vencimento: " << cliente[escolha].informacoes_sobre_emprestimo[0].data_do_vencimento << endl
         << "---------------------------------------------------------" << endl << endl;
    
        cout << "Deseja acessar outro cliente?(sim ou nao) ";
        cin >> outro_cliente;

        if (outro_cliente != "sim")
        {
            return;
        }

        cout << endl << "Qual cliente? ";
        cin >> escolha;
        escolha -=1;
        system("cls");

        if (org_cliente[escolha].n == 0)
        {
            cout << endl << "Nao existe esse cliente!!" << endl << endl;
            system("pause");
            return;
        }
    }
}

//função para editar os clientes já criados - 3
void editar_info_client(dados_clientes cliente[], int n, organizador_cliente org_cliente[])
{
    system("cls");
    int escolha = 0, editar = 0;
    string outro_cliente = "sim";

    cout << "Qual cliente desseja editar? ";
    cin >> escolha;
    escolha -= 1;

    if (org_cliente[escolha].n == 0)
    {
        cout << endl << "Nao existe esse cliente!!" << endl << endl;
        system("pause");
        return;
    }

    while (outro_cliente == "sim")
    {   
        cout << endl
         << "------------------------CLIENTE "<< escolha + 1 <<"------------------------" << endl
         << "1-Nome do cliente: " << cliente[escolha].nome_do_cliente << endl
         << "2-CPF: " << cliente[escolha].cpf << endl
         << "3-Endereco: " << cliente[escolha].endereco << endl
         << "4-Data de nascimento: " << cliente[escolha].data_de_nascimento << endl
         << "5-Data do emprestimo: " << cliente[escolha].data_do_emprestimo << endl
         << "---------------------------------------------------------" << endl;
        cout << "Deseja editar qual opcao: ";
        cin >> editar;

        cout << endl;

        if (editar == 1)
        {
            cout << "Nome do cliente: ";
            cin.ignore();
            getline(cin, cliente[escolha].nome_do_cliente);     
        }

        if (editar == 2)
        {
            cout << "CPF: ";
            cin >> cliente[escolha].cpf;
        }

        if (editar == 3)
        {
            cout << "Endereco: ";
            cin.ignore();
            getline(cin, cliente[escolha].endereco);
        }

        if (editar == 4)
        {
            cout << "Data de nascimento(DD/MM/AAAA): ";
            cin >> cliente[escolha].data_de_nascimento;
        }

        if (editar == 5)
        {
            cout << "Data do emprestimo(DD/MM/AAAA): ";
            cin >> cliente[escolha].data_do_emprestimo;
        }

        cout << endl << "----------------------------------------------------------" << endl;

        cout << "Deseja editar outro campo?(sim ou nao) ";
        cin >> outro_cliente;

        if (outro_cliente != "sim")
        {
            return;
        }

        system("cls");
    }
}

//Função para editar as parcelas dos clientes cadastrados - 4
void editar_parcela(dados_clientes cliente[], int n, organizador_parcela org_parcela[], organizador_cliente org_cliente[])
{
    system("cls");
    int parcela, escolha = 0, soma_parcelas = 0;
    string paga = "nao";
 
    cout << "Qual emprestimo desseja editar? ";
    cin >> escolha;
    escolha -= 1;

    if (org_cliente[escolha].n == 0)
    {
        cout << endl << "Nao existe esse cliente!!" << endl << endl;
        system("pause");
        return;
    }    

    for (int i = 0; i < cliente[escolha].num_parcelas; i++)
    {
        soma_parcelas += cliente[escolha].informacoes_sobre_emprestimo[i].valor_da_parcela;
    }

    if (soma_parcelas == 0)
    {
        cout << endl << "Todas as parcelas foram pagas!!" << endl << endl;
        system("pause");
        return;
    }
    
    cout << endl
    << "-------------------VALOR DO EMPRESTIMO-------------------" << endl
    << "Valor do emprestimo: " << cliente[escolha].valor_total_do_emprestimo << endl
    << "Quantidade de parcelas: " << cliente[escolha].num_parcelas << endl << endl;

    for(int i = 0; i < cliente[escolha].num_parcelas; i++){
        cout << "-----------------------"<< i + 1<<" PARCELA-------------------------" << endl
        << "Valor da parcela: " << cliente[escolha].informacoes_sobre_emprestimo[i].valor_da_parcela << endl
        << "Pago ou nao: " << cliente[escolha].informacoes_sobre_emprestimo[i].paga_ou_nao << endl
        << "Data do pagamento: " << cliente[escolha].informacoes_sobre_emprestimo[i].data_do_pagamento << endl
        << "Data do vencimento: " << cliente[escolha].informacoes_sobre_emprestimo[i].data_do_vencimento << endl
        << "----------------------------------------------------------" << endl << endl;
    }

    cout << "Deseja pagar a ultima parcela em aberto (sim ou nao)? ";
    cin >> paga;
    int i = 0;

    while (org_parcela[escolha].n[i] == 1)
    {
        i++;
    }  

    if (paga == "sim")
    {
        cliente[escolha].informacoes_sobre_emprestimo[i].paga_ou_nao = "PAGA";
        cliente[escolha].informacoes_sobre_emprestimo[i].valor_da_parcela = 0;
        cout << endl << "Qual a data do pagamento(dia de hoje): ";
        cin >> cliente[escolha].informacoes_sobre_emprestimo[i].data_do_pagamento;
        org_parcela[escolha].n[i] = 1;

        system("cls");

        cout << "Parcela "<< i + 1 <<" paga com suceeso!" << endl << endl; 

        for(int i = 0; i < cliente[escolha].num_parcelas; i++){
            cout << "-----------------------"<< i + 1 <<" PARCELA------------------------" << endl
            << "Valor da parcela: " << cliente[escolha].informacoes_sobre_emprestimo[i].valor_da_parcela << endl
            << "Pago ou nao: " << cliente[escolha].informacoes_sobre_emprestimo[i].paga_ou_nao << endl
            << "Data do pagamento: " << cliente[escolha].informacoes_sobre_emprestimo[i].data_do_pagamento << endl
            << "Data do vencimento: " << cliente[escolha].informacoes_sobre_emprestimo[i].data_do_vencimento << endl
            << "----------------------------------------------------------" << endl << endl;
        }
    }
    system("pause");
    return;
}

//Função para excluir os clientes - 6
void excluir_client(dados_clientes cliente[], int n, organizador_cliente org_cliente[])
{
    system("cls");
    int excluir = 0;
    string loop = "sim";

    cout << "Qual cliente deseja excluir? ";
    cin >> excluir;
    excluir -= 1;

    if (org_cliente[excluir].n == 0)
    {
        cout << endl << "Nao existe esse cliente!!" << endl << endl;
        system("pause");
        return;
    }

    cliente[excluir].nome_do_cliente = "";
    cliente[excluir].cpf = "";
    cliente[excluir].endereco = "";
    cliente[excluir].data_de_nascimento = "";
    cliente[excluir].data_do_emprestimo = "";
    cliente[excluir].valor_total_do_emprestimo = 0;
    cliente[excluir].num_parcelas = 0;

    for (int i = 0; i < cliente[excluir].num_parcelas; i++)
    {
        cliente[excluir].informacoes_sobre_emprestimo[i].valor_da_parcela = 0;
        cliente[excluir].informacoes_sobre_emprestimo[i].paga_ou_nao = "";
        cliente[excluir].informacoes_sobre_emprestimo[i].data_do_pagamento = "";
        cliente[excluir].informacoes_sobre_emprestimo[i].data_do_vencimento = "";
    }
    cout << endl << "Cliente excluido com suceesso!!" << endl << endl;
    
    org_cliente[excluir].n = 0;
    system("pause");
    return;
}

//função para cadastrar um novo emprestimo - 5
void cadas_emprestimo(dados_clientes cliente[], int n)
{
    int escolha = 0, soma_parcelas = 0;
    system("cls");

    cout << "Deseja cadastar um emprestimo em qual cliente? ";
    cin >> escolha;
    escolha -= 1;

    for (int i = 0; i < cliente[escolha].num_parcelas; i++)
    {
        soma_parcelas += cliente[escolha].informacoes_sobre_emprestimo[i].valor_da_parcela;
    }

    if (soma_parcelas == 0)
    {
        cout << endl << "Qual o valor do emprestimo: ";
        cin >> cliente[escolha].valor_total_do_emprestimo;

        cliente[escolha].num_parcelas = 0;
        cout << "Em quantas parcelas: ";
        cin >> cliente[escolha].num_parcelas;

        int valor_parcela = cliente[escolha].valor_total_do_emprestimo/cliente[escolha].num_parcelas;

        for (int parcelas = 0; parcelas < cliente[escolha].num_parcelas; parcelas++)
        {   
            cliente[escolha].informacoes_sobre_emprestimo[parcelas].valor_da_parcela = valor_parcela;
        }

        string n = "4";
        string ano = "3";
        string dia = "30";
        int dia_int = 0;

        for (int parcelas = 0; parcelas < cliente[escolha].num_parcelas; parcelas++)
        {
            cliente[escolha].informacoes_sobre_emprestimo[parcelas].paga_ou_nao = "NAO";
            cliente[escolha].informacoes_sobre_emprestimo[parcelas].data_do_vencimento = dia + "/" + n + "/202" + ano;
            int mes_int = stoi(n);
            mes_int += 1;

            if (mes_int == 2)
            {   
                dia_int = 28;
                dia = to_string(dia_int);
            } 
            else
            {
                dia_int = 30;
                dia = to_string(dia_int);
            };

            if (mes_int >12)
            {
                mes_int = 1;
                int ano_int = stoi(ano);
                ano_int += 1;
                ano = to_string(ano_int);           
            }
            n = to_string(mes_int); 
        }
    }
    else
    {
        cout << endl << "ja existe um emprestimo ativo!" << endl << endl;
        system("pause");
    }
}

//função para escolher qual opção da interface deseja acessar
void fun_escolha(int escolha, int n, dados_clientes cliente[], organizador_cliente org_cliente[], organizador_parcela org_parcela[])
{   
    bool loop = true;

    while(loop = true){
        fun_interface(&escolha);
        if (escolha<1 || escolha>7)
        {
            cout << "Nao existe essa opcao, escolha outra!! " << endl; 
            system("pause");
        }

        if (escolha == 1)
        {   
            cadas_client(cliente, n, org_cliente);
        }

        if (escolha == 2)
        {   
            if (org_cliente[0].n == 1 || org_cliente[1].n == 1 || org_cliente[2].n == 1 || org_cliente[3].n == 1 || org_cliente[4].n == 1 || org_cliente[5].n == 1 || org_cliente[6].n == 1 || org_cliente[7].n == 1 || org_cliente[8].n == 1 || org_cliente[9].n == 1)
            {
                info_cliente(cliente, n, org_cliente);
            } 
            else 
            {
                cout << "Nao existe nenhum cliente cadastrado!" << endl;
                system("pause");
            }
        }

        if (escolha == 3)
        {
            if (org_cliente[0].n == 1 || org_cliente[1].n == 1 || org_cliente[2].n == 1 || org_cliente[3].n == 1 || org_cliente[4].n == 1 || org_cliente[5].n == 1 || org_cliente[6].n == 1 || org_cliente[7].n == 1 || org_cliente[8].n == 1 || org_cliente[9].n == 1)
            {
                editar_info_client(cliente, n, org_cliente);
            } 
            else 
            {
                cout << "Nao existe nenhum cliente cadastrado!" << endl;
                system("pause");
            }
        }

        if (escolha == 4)
        {   
            if (org_cliente[0].n == 1 || org_cliente[1].n == 1 || org_cliente[2].n == 1 || org_cliente[3].n == 1 || org_cliente[4].n == 1 || org_cliente[5].n == 1 || org_cliente[6].n == 1 || org_cliente[7].n == 1 || org_cliente[8].n == 1 || org_cliente[9].n == 1)
            {
                editar_parcela(cliente, n, org_parcela, org_cliente);
            } 
            else 
            {
                cout << "Nao existe nenhum cliente cadastrado!" << endl;
                system("pause");
            }
        }

        if (escolha == 5)
        {
            if (org_cliente[0].n == 1 || org_cliente[1].n == 1 || org_cliente[2].n == 1 || org_cliente[3].n == 1 || org_cliente[4].n == 1 || org_cliente[5].n == 1 || org_cliente[6].n == 1 || org_cliente[7].n == 1 || org_cliente[8].n == 1 || org_cliente[9].n == 1)
            {
                cadas_emprestimo(cliente, n);
            } 
            else 
            {
                cout << "Nao existe nenhum cliente cadastrado!" << endl;
                system("pause");
            }
        }

        if (escolha == 6)
        {
            if (org_cliente[0].n == 1 || org_cliente[1].n == 1 || org_cliente[2].n == 1 || org_cliente[3].n == 1 || org_cliente[4].n == 1 || org_cliente[5].n == 1 || org_cliente[6].n == 1 || org_cliente[7].n == 1 || org_cliente[8].n == 1 || org_cliente[9].n == 1)
            {
                excluir_client(cliente, n, org_cliente);
            } 
            else 
            {
                cout << "Nao existe nenhum cliente cadastrado!" << endl;
                system("pause");
            }
        }

        //Ao escolher essa opção,ela finaliza o While e encerra o programa
        if (escolha == 7) 
        {
            return;
        }
    }
}

//inicio do int main
int main()
{
    int escolha = 0, n = 10;
    bool loop = true;
    struct dados_clientes cliente[10];
    struct organizador_cliente org_cliente[10] = {0,0,0,0,0,0,0,0,0,0};
    struct organizador_parcela org_parcela[12] = {0,0,0,0,0,0,0,0,0,0,0,0};

    fun_escolha(escolha, n, cliente, org_cliente, org_parcela);
    // comando para encerrar o programa 
    exit(0);

    return 0;
    // final do int main
}
