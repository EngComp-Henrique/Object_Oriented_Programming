#ifndef BANK_H
#define BANK_H

#include "../include/Pessoa.h"
#include "../include/PessoaJuridica.h"
#include "../include/PessoaFisica.h"

#include "../include/Conta.h"
#include "../include/ContaComum.h"
#include "../include/ContaLimite.h"
#include "../include/ContaPoupanca.h"


#include "../include/InexistentAccountError.h"
#include "../include/InsufficientFundError.h"

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <ctime>

class Bank : public PessoaJuridica
{
	private:
		vector<Pessoa*> holders;
		vector<Conta*> accounts;
		const char* sep_bank =  (const char*) "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*";
		bool checkDataBase();
		bool readData();
		bool saveData();
		bool validateAccount(string);
	public:
		Bank(string address, string phone, string email, string newCNPJ, 
			string newBN, string newTN) : PessoaJuridica(address, phone, email, newCNPJ, newBN, newTN) {
				readData();
			}
		~Bank();
		bool login(string);
		void listHolderAccounts(string);
		void listAccount();
		bool createAccount(Pessoa* , Conta*);
		bool query(string);
		bool updateAccount(string);
		bool deleteAccount(string);
		bool deposit(string, double);
		bool withdraw(string, double);
		bool valid_transfer(string, string, double);
		void lookBalance(string);
		void lookExtract(string);
};
#endif