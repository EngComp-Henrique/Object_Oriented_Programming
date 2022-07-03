#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include "../include/PessoaFisica.h"
#include "../include/PessoaJuridica.h"

#include "../include/ContaComum.h"
#include "../include/ContaLimite.h"
#include "../include/ContaPoupanca.h"

#include "../include/Bank.h"

#include "../include/InvalidOperation.h"
#include "../include/ExceedLimitError.h"
#include "../include/InsufficientFundError.h"
#include "../include/WrongDataError.h"
#include "../include/InexistentAccountError.h"

#include "../include/menus.h"

#include <string>
using std::string;

#include <stdlib.h>

#include <chrono>
#include <thread>
using namespace std::literals::chrono_literals;

int main()
{
   int who, op;
   string acNumber;
   double amount;

   Menu menu;

   Bank c_plus_bank("C PLUS BANK", "Av. Maria João", "2102-6200", "cplusplus@py.com", "19843321000251", 
   "GUIDO Association.");

   menu.boas_vindas();
   menu.separador();

   try {
      menu.menu_visao();
      cin >> who;
      if (who < 1 || who > 3)
         throw InvalidOperation();
      if (who == 1) {
         menu.separador();
         cout << "Entrando como CORRENTISTA..." << endl;
         cout << "Digite o número da conta: ";
         cin >> acNumber;
         while (!c_plus_bank.login(acNumber)) {
            cout << "Essa conta não existe. Tente novamente: ";
            cin >> acNumber;
            menu.separador();
         }
      }
      if (who == 3) {
         menu.separador();
         return 0;
      }
   } 
   catch(InvalidOperation& e) {
      cout << e.what() << endl;
      who = 1;
      cout << "Entrando como CORRENTISTA..." << endl;
      cout << "Digite o número da conta: ";
      cin >> acNumber;
      while (!c_plus_bank.login(acNumber)) {
         cout << "Essa conta não existe. Tente novamente: ";
         cin >> acNumber;
      }
   }
   std::this_thread::sleep_for(700ms);
   system("clear");
   while (true) 
   {
      int flag;
      menu.boas_vindas();
      try {
         if (who == 1) {
            menu.separador();
            menu.menu_correntista();
            cin >> op;
            menu.separador();
            if (op < 1 || op > 6)
               throw InvalidOperation();
            if (op == 1) {
               cout << "Digite quando deseja depositar: ";
               cin >> amount;
               c_plus_bank.deposit(acNumber, amount);
            } else if (op == 2) {
               cout << "Digite quando deseja sacar: ";
               cin >> amount;
               c_plus_bank.withdraw(acNumber, amount);
            } else if (op == 3) {
               string another_count;
               double a_value;
               cout << "Digite o número da conta para qual você deseja transferir: "; cin.ignore();
               cin >> another_count;
               cout << "Quanto deseja transferir: ";
               cin >> amount;
               c_plus_bank.valid_transfer(acNumber, another_count, amount);
            } else if (op == 4) {
               c_plus_bank.lookBalance(acNumber);
            } else if (op == 5) {
               c_plus_bank.lookExtract(acNumber);
            } else {
               break;
            }
         } else {
            string a_name, a_phone, a_email, a_addr, p;
            Pessoa* pessoa = nullptr;
            Conta* conta = nullptr;
            menu.separador();
            menu.menu_gerente();
            cin >> op;
            menu.separador();
            if (op < 1 || op > 7)
               throw InvalidOperation();
            if (op == 1) {
               cout << "Digite 'pf' para pessoa física ou 'pj' para pessoa juridíca: ";
               cin >> p;
               if (p != "pf" && p != "pj")
                  throw InvalidOperation();
               cout << "Você selecionou " << ((p == "pf") ? "Pessoa Fisíca" : "Pessoa Juridíca") << endl;
               if (p == "pf") {
                  string a_cpf;
                  cout << "Digite um nome da pessoa: "; cin.ignore();
                  getline(cin, a_name);

                  cout << "Digite o CPF (sem pontuação): ";
                  getline(cin, a_cpf);

                  cout << "Digite um número de celular (formato XXXX-XXXX): ";
                  getline(cin, a_phone);

                  cout << "Digite um email: ";
                  getline(cin, a_email);

                  cout << "Digite um endereço: ";
                  getline(cin, a_addr);

                  int y;
                  cout << "Digite o ano em que nasceu: ";
                  cin >> y;
                  pessoa = new PessoaFisica(a_name, a_addr, a_phone, a_email, a_cpf, y);
               } else {
                  string a_cnpj, trn;
                  cout << "Digite um nome fantasia da empresa: "; cin.ignore();
                  getline(cin, a_name);

                  cout << "Digite o CNPJ (sem pontuação [são 14 digitos]): ";
                  getline(cin, a_cnpj);

                  cout << "Digite um número de celular (formato XXXX-XXXX): ";
                  getline(cin, a_phone);

                  cout << "Digite um email: ";
                  getline(cin, a_email);

                  cout << "Digite um endereço: ";
                  getline(cin, a_addr);

                  cout << "Digite o nome empresarial: ";
                  getline(cin, trn);

                  pessoa = new PessoaJuridica(a_name, a_addr, a_phone, a_email, a_cnpj, trn);
               }
               menu.separador();
               menu.tipo_contas();
               cin >> op;
               menu.separador();
               if (op < 1 || op > 3)
                  throw InvalidOperation();
               cout << "Tipo de conta: " << op << endl;
               if (op == 1) {
                  cout << "Digite o número da nova conta: "; cin.ignore();
                  getline(cin, acNumber);

                  cout << "Digite a quantida inicial: ";
                  cin >> amount;
                  conta = new ContaComum(acNumber, pessoa, amount);
               } else if (op == 2) {
                  int limit;
                  cout << "Digite o número da nova conta: "; cin.ignore();
                  getline(cin, acNumber);

                  cout << "Digite a quantida inicial: ";
                  cin >> amount;
                  cout << "Digite o valor do limite: ";
                  cin >> limit;
                  conta = new ContaLimite(acNumber, amount, pessoa, limit);
               } else {
                  cout << "Digite o número da nova conta: "; cin.ignore();
                  getline(cin, acNumber);

                  cout << "Digite a quantida inicial: ";
                  cin >> amount;
                  conta = new ContaPoupanca(acNumber, amount, pessoa, 10, 10, 10);
               }
               c_plus_bank.createAccount(pessoa, conta);
            } else if (op == 2) {
               cout << "Digite o número da conta que deseja consultar: ";
               cin >> acNumber;
               c_plus_bank.query(acNumber);
            } else if (op == 3) {
               cout << "Digite o nome do titular da conta: "; cin.ignore();
               getline(cin, a_name);
               c_plus_bank.updateAccount(a_name);
            } else if (op == 4) {
               cout << "Digite o número da conta: ";
               cin >> acNumber;
               c_plus_bank.deleteAccount(acNumber);
            } else if (op == 5) {
               c_plus_bank.listAccount();
            } else if (op == 6) {
               cout << "Digite o número da conta: ";
               cin >> acNumber;
               c_plus_bank.listHolderAccounts(acNumber);
            } else {
               break;
            }
         }
      }
      catch(InsufficientFund& e) {
         cout << e.what() << endl;
         std::this_thread::sleep_for(2000ms);
         system("clear");
         continue;
      }

      catch(ExceedLimit& e) {
         cout << e.what() << endl;
         std::this_thread::sleep_for(2000ms);
         system("clear");
         continue;
      } 
      
      catch(InvalidOperation& e) {
         cout << e.what() << endl;
         std::this_thread::sleep_for(2000ms);
         system("clear");
         continue;
      }

      catch(InexistentAccountError& e) {
         cout << e.what() << endl;
         std::this_thread::sleep_for(2000ms);
         system("clear");
         continue;
      }

      catch(WrongDataError& e) {
         cout << e.what() << endl;
         std::this_thread::sleep_for(2000ms);
         system("clear");
         continue;
      }
      cin.clear();
      cout << "Press Enter to continue" << endl;
      cin.ignore();
      flag = getc(stdin);
      std::this_thread::sleep_for(700ms);
      system("clear");
   }
   return 0;
}