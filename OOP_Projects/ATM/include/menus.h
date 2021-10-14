#ifndef MENU
#define MENU

#include <iostream>
using std::cout;
using std::endl;
using std::left;
using std::right;

class Menu
{
    private:
        const char* sep_main = (const char*) "==============================================";
    public:
        Menu() {};

        void boas_vindas() {
            cout << sep_main << endl;
            cout << "||               C PLUS BANK                ||" << endl;
            cout << "||  Simplesmente o banco do entretenimento  ||" << endl;
        }

        void menu_visao() {
            cout << "Bem-vindo GERENTE" << endl;
            cout << "Selecione uma opção:" << endl;
            cout << "1- Entrar como CORRENTISTA" << endl;
            cout << "2- Entrar como GERENTE" << endl;
            cout << "3- Encerrar operação" << endl;
            cout << "Operação: ";
        }

        void menu_correntista() {
            cout << "Operações:" << endl;
            cout << "1- Depositar" << endl;
            cout << "2- Retirar" << endl;
            cout << "3- Transferir" << endl;
            cout << "4- Ver saldo atual" << endl;
            cout << "5- Ver extrato" << endl;
            cout << "6- Sair" << endl;
            cout << "Operação: ";
        }

        void menu_gerente() {
            cout << "Operações:" << endl;
            cout << "1- Abrir conta" << endl;
            cout << "2- Consultar conta" << endl;
            cout << "3- Atualizar conta" << endl;
            cout << "4- Fechar conta" << endl;
            cout << "5- Listar todas as contas" << endl;
            cout << "6- Listar contas de um correntista" << endl;
            cout << "7- Sair" << endl;
            cout << "Operação: ";
        }

        void tipo_contas() {
            cout << "Digite o tipo de conta: " << endl;
            cout << "1- Conta Comum" << endl;
            cout << "2- Conta Limite" << endl;
            cout << "3- Conta poupança" << endl;
            cout << "Operação: ";
        }

        void separador() {
            cout << sep_main << endl;
        }

        void despedida() {
            cout << "" << endl;
        }
};

#endif