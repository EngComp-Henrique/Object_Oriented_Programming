#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include "../include/Bank.h"

#include <string>
using std::string;
using std::to_string;

#include <fstream>
using std::ifstream;
using std::ofstream;

#include <list>
using std::list;

#include <sstream>
using std::stringstream;

Bank::~Bank()
{
    saveData();
    for (auto* a: accounts)
        delete a;
    for (auto* h: holders)   
        delete h;
}

void Bank::listHolderAccounts(string accNumber)
{
    if (accounts.size() == 0)
        cout << "Não há contas no banco.";
    if (validateAccount(accNumber))
    {
        for (auto* a: accounts)
        {
            ContaComum* cc = dynamic_cast<ContaComum*>(a);
            ContaLimite* cl = dynamic_cast<ContaLimite*>(a);
            if (cc) {
                if (cc->getAccountNumber() == accNumber) {
                    cc->extrato();
                    cout << sep_bank << endl;
                }
            } else if (cl) {
                if (cl->getAccountNumber() == accNumber) {
                    cl->extrato();
                    cout << sep_bank << endl;
                }
            } else {
                ContaPoupanca* cp = dynamic_cast<ContaPoupanca*>(a);
                if (cp->getAccountNumber() == accNumber) {
                    cp->extrato();
                    cout << sep_bank << endl;
                }
            }
        }
    }
}

void Bank::listAccount()
{
    if (accounts.size() == 0)
        cout << "Não há contas no banco.";
    cout << endl;
    for (Conta* a: accounts)
    {
        ContaComum* cc = dynamic_cast<ContaComum*>(a);
        ContaLimite* cl = dynamic_cast<ContaLimite*>(a);
        if (cc) {
            cc->extrato();
        } else if (cl) {
            cl->extrato();
        } else {
            ContaPoupanca* cp = dynamic_cast<ContaPoupanca*>(a);
            cp->extrato();
        }
        cout << sep_bank << endl;
        cout << endl;
    }
}

bool Bank::validateAccount(string search)
{
    for (auto& i: holders) {
        if (i->getName() == search)
            return true;
    }

    for (auto& j: accounts) {
        if (j->getAccountNumber() == search)
            return true;
    }
    throw InexistentAccountError();
}

bool Bank::createAccount(Pessoa* p, Conta* c) 
{
    bool shouldIadd = true;
    for (auto& h: holders) {
        if (h->getName() == p->getName()) {
            shouldIadd = false;
            break;
        }
    }
    if (shouldIadd)
        holders.push_back(p);
    accounts.push_back(c);
    return true;
}

bool Bank::updateAccount(string nome_titular) {
    if (validateAccount(nome_titular)) {
        string a_name, a_phone, a_email, a_addr;
        cout << "Digite um nome: ";
        getline(cin, a_name);
        cout << "Digite um número de celular (formato XXXX-XXXX): ";
        getline(cin, a_phone);
        cout << "Digite um email: ";
        getline(cin, a_email);
        cout << "Digite um endereço: ";
        getline(cin, a_addr);
        Pessoa* aux = nullptr;
        string a_trn;
        for (auto* h: holders) {
            PessoaFisica* pf = dynamic_cast<PessoaFisica*>(h);
            if (pf) {
                if (pf->getName() == nome_titular) {
                    pf->setName(a_name);
                    pf->setAdd(a_addr);
                    pf->setEmail(a_email);
                    pf->setPhone(a_phone);
                    aux = pf;
                    break;
                }
            } else {
                PessoaJuridica* pj = dynamic_cast<PessoaJuridica*>(h);
                if (pj) {
                    if (pj->getName() == nome_titular) {
                        cout << "Digite o nome empresarial: ";
                        getline(cin, a_trn);
                        pj->setName(a_name);
                        pj->setAdd(a_addr);
                        pj->setEmail(a_email);
                        pj->setPhone(a_phone);
                        pj->setTradeName(a_trn);
                        aux = pj;
                        break;
                    }
                }
            }
        }
        for (auto* a: accounts) {
            ContaComum* cc = dynamic_cast<ContaComum*>(a);
            ContaLimite* cl = dynamic_cast<ContaLimite*>(a);
            if (cc) {
                if (cc->getAccountHolder()->getName() == nome_titular) {
                    cc->getAccountHolder()->setName(a_name);
                    cc->getAccountHolder()->setAdd(a_addr);
                    cc->getAccountHolder()->setEmail(a_email);
                    cc->getAccountHolder()->setPhone(a_phone);
                    PessoaJuridica* aux_pj = dynamic_cast<PessoaJuridica*>(cc->getAccountHolder());
                    if (aux_pj) {
                        aux_pj->setTradeName(a_trn);
                    }
                }
            } else if (cl) {
                if (cl->getAccountHolder()->getName() == nome_titular) {
                    cl->getAccountHolder()->setName(a_name);
                    cl->getAccountHolder()->setAdd(a_addr);
                    cl->getAccountHolder()->setEmail(a_email);
                    cl->getAccountHolder()->setPhone(a_phone);
                    PessoaJuridica* aux_pj = dynamic_cast<PessoaJuridica*>(cl->getAccountHolder());
                    if (aux_pj) {
                        aux_pj->setTradeName(a_trn);
                    }
                }
            } else {
                ContaPoupanca* cp = dynamic_cast<ContaPoupanca*>(a);
                if (cp->getAccountHolder()->getName() == nome_titular) {
                    cp->getAccountHolder()->setName(a_name);
                    cp->getAccountHolder()->setAdd(a_addr);
                    cp->getAccountHolder()->setEmail(a_email);
                    cp->getAccountHolder()->setPhone(a_phone);
                    PessoaJuridica* aux_pj = dynamic_cast<PessoaJuridica*>(cp->getAccountHolder());
                    if (aux_pj) {
                        aux_pj->setTradeName(a_trn);
                    }
                }
            }
        }
        cout << endl;
        return true;
    }
    throw InexistentAccountError();
}

bool Bank::deleteAccount(string accNumber)
{
    if (validateAccount(accNumber))
    {
        int pos = 0;
        for (auto& k: accounts)
        {
            if (k->getAccountNumber() == accNumber)
                break;
            pos++;
        }
        for (int i = pos; i < accounts.size() - 1; i++)
        {
            auto aux = accounts[i];
            accounts[i] = accounts[i + 1];
            accounts[i + 1] = aux;
        }
        accounts.pop_back();
        return true;
    } 
    throw InexistentAccountError();
}

bool Bank::query(string accNumber)
{
    if (validateAccount(accNumber))
    {
        for (auto* i: accounts)
        {
            if (i->getAccountNumber() == accNumber)
            {
                ContaComum* cc = dynamic_cast<ContaComum*>(i);
                ContaLimite* cl = dynamic_cast<ContaLimite*>(i);
                if (cc) {
                    cc->extrato();
                }
                else if (cl) {
                    cl->extrato();
                }
                else {
                    ContaPoupanca* cp = dynamic_cast<ContaPoupanca*>(i);
                    cp->extrato();
                }
                return true;
            }
        }
    } 
    throw InexistentAccountError();
}

bool Bank::deposit(string accNumber, double v)
{
    if (v < 0)
        throw WrongDataError();
    if (validateAccount(accNumber)) {
        for (auto* a: accounts)
        {
            if (a->getAccountNumber() == accNumber) {
                ContaComum* cc = dynamic_cast<ContaComum*>(a);
                ContaLimite* cl = dynamic_cast<ContaLimite*>(a);
                if (cc) {
                    *cc << v;
                    return true;
                } else if (cl) {
                    *cl << v;
                    return true;
                } else {
                    ContaPoupanca* cp = dynamic_cast<ContaPoupanca*>(a);
                    *cp << v;
                    return true;
                }
            }
        }
    } 
    throw InexistentAccountError();
}

bool Bank::withdraw(string accNumber, double v)
{
    if (v < 0)
        throw WrongDataError();
    if (validateAccount(accNumber)) {
        for (auto* a: accounts)
        {
            if (a->getAccountNumber() == accNumber) {
                ContaComum* cc = dynamic_cast<ContaComum*>(a);
                ContaLimite* cl = dynamic_cast<ContaLimite*>(a);
                if (cc) {
                    *cc >> v;
                    return true;
                } else if (cl) {
                    *cl >> v;
                    return true;
                } else {
                    ContaPoupanca* cp = dynamic_cast<ContaPoupanca*>(a);
                    *cp >> v;
                    return true;
                }
            }
        }
    } 
    throw InexistentAccountError();
}

bool Bank::valid_transfer(string source, string destiny, double v) {
    if (validateAccount(source) && validateAccount(destiny)) {
        bool could_transfer = false;
        string source_name, destiny_name;
        time_t t;
        struct tm* info;
        time(&t);
        info = localtime(&t);
        int transaction_day = info->tm_mday;
        int transaction_month = info->tm_mon + 1;
        int transaction_year = info->tm_year + 1900;
        int transaction_hour = info->tm_hour;
        int transaction_min = info->tm_min;
        Conta* aux = nullptr;
        for (auto* a: accounts) {
            if (a->getAccountNumber() == source) {
                if (a->getBalance() - v >= 0) {
                    source_name = a->getAccountHolder()->getName();
                    *a >> v;
                    aux = a;
                    could_transfer = true;
                }
                break;
            }
        }
        if (!could_transfer)
            throw InsufficientFund();
        for (auto* b: accounts) {
            if (b->getAccountNumber() == destiny) {
                destiny_name = b->getAccountHolder()->getName();
                *b << v;
                string description_tranfer_d = "Transferência bancárias: " + destiny_name + " <- " + source_name;
                Transacoes newTransaction_d(transaction_day, transaction_month, transaction_year, transaction_hour, 
                transaction_min, description_tranfer_d, v);
                b->addTransaction(newTransaction_d);
                break;
            }
        }
        string description_tranfer_s = "Transferência bancárias: " + source_name + " -> " + destiny_name;
        Transacoes newTransaction_s(transaction_day, transaction_month, transaction_year, transaction_hour, 
        transaction_min, description_tranfer_s, v);
        aux->addTransaction(newTransaction_s);
        return true;
    }
    throw InexistentAccountError();
}

void Bank::lookBalance(string accNumber)
{
    if (validateAccount(accNumber))
    {
        for (auto& a: accounts)
        {
            if (a->getAccountNumber() == accNumber)
            {
                cout << "Valor atual na conta (R$): " << a->getBalance() << endl;
                break;
            }
        }
    }
}

void Bank::lookExtract(string accNumber)
{
    if (validateAccount(accNumber))
    {
        for (auto* a: accounts)
        {
            if (a->getAccountNumber() == accNumber)
            {
                ContaComum* cc = dynamic_cast<ContaComum*>(a);
                ContaLimite* cl = dynamic_cast<ContaLimite*>(a);
                if (cc) {
                    cc->extrato();
                    break;
                } else if (cl) {
                    cl->extrato();
                    break;
                } else {
                    ContaPoupanca* cp = dynamic_cast<ContaPoupanca*>(a);
                    cp->extrato();
                    break;
                }
            }
        }
    }
}

bool Bank::login(string accNumber)
{
    for (auto& j: accounts)
    {
        if (j->getAccountNumber() == accNumber)
            return true;
    }
    return false;
}

bool Bank::saveData() 
{
    ofstream out("../database/data.dat", std::ios::out);
    if (!out)
        return false;
    for (auto* h: holders) {
        string line;
        PessoaFisica* pf = dynamic_cast<PessoaFisica*>(h);
        string titular;
        if (pf) {
            titular = pf->getName();
            line = "pf|" + pf->getName() + '|' + pf->getAddress() + '|' + pf->getPhone() + '|' + pf->getEmail() + '|' + pf->getCPF() + '|' + to_string(pf->getByear());
            out << line << endl;
        } else {
            PessoaJuridica* pj = dynamic_cast<PessoaJuridica*>(h);
            titular = pj->getName();
            line = "pj|" + pj->getName() + '|' + pj->getAddress() + '|' + pj->getPhone() + '|'+ pj->getEmail() + '|' + pj->getCNPJ() + '|' + pj->getTradeName();
            out << line << endl;
        }
        for (auto* a: accounts) {
            string line_2;
            ContaComum* cc = dynamic_cast<ContaComum*>(a);
            ContaLimite* cl = dynamic_cast<ContaLimite*>(a);
            if (cc) {
                if (cc->getAccountHolder()->getName() == titular) {
                    line_2 = "cc|" + cc->getAccountNumber() + '|' + to_string(cc->getBalance());
                    out << line_2 << endl;
                    auto tr = cc->getTransactions();
                    string line_3;
                    for (auto t: tr) {
                        line_3 = "tr|" + to_string(t.get_Tday()) + '|' + to_string(t.get_Tmonth()) + '|' + to_string(t.get_Tyear()) + '|' + to_string(t.get_Thour()) + '|' + to_string(t.get_Tmin()) + '|' +  t.getDescription() + '|' + to_string(t.getAmount());
                        out << line_3 << endl;
                    }
                }
            } else if (cl) {
                if (cl->getAccountHolder()->getName() == titular) {
                    line_2 = "cl|" + cl->getAccountNumber() + '|' + to_string(cl->getBalance()) + '|' + to_string(cl->getLimit());
                    out << line_2 << endl;
                    auto tr = cl->getTransactions();
                    string line_3;
                    for (auto t: tr) {
                        line_3 = "tr|" + to_string(t.get_Tday()) + '|' + to_string(t.get_Tmonth()) + '|' + to_string(t.get_Tyear()) + '|' + to_string(t.get_Thour()) + '|' + to_string(t.get_Tmin()) + '|' +  t.getDescription() + '|' + to_string(t.getAmount());
                        out << line_3 << endl;
                    }
                }
            } else {
                ContaPoupanca* cp = dynamic_cast<ContaPoupanca*>(a);
                if (cp->getAccountHolder()->getName() == titular) {
                    line_2 = "cp|" + cp->getAccountNumber() + '|' + to_string(cp->getBalance()) + '|' + to_string(cp->getBday()) + '|' + to_string(cp->getBmonth()) + '|' + to_string(cp->getByear());
                    out << line_2 << endl;
                    auto tr = cp->getTransactions();
                    string line_3;
                    for (auto t: tr) {
                        line_3 = "tr|" + to_string(t.get_Tday()) + '|' + to_string(t.get_Tmonth()) + '|' + to_string(t.get_Tyear()) + '|' + to_string(t.get_Thour()) + '|' + to_string(t.get_Tmin()) + '|' +  t.getDescription() + '|' + to_string(t.getAmount());
                        out << line_3 << endl;
                    }
                }
            }
        }
    }
    out.close();
    return true;
}

bool Bank::readData() {
    ifstream in("../database/data.dat", std::ios::in);
    if (!in) {
        in.close();
        in.open("../database/data.dat");
        in.close();
    } else {
        string line;
        list<string> lines;
        while (!in.eof()) {
            getline(in, line);
            if (line == "")
                break;
            lines.push_back(line);
        }

        string info;
        string current_person;
        Pessoa* p = nullptr;
        Conta* c = nullptr;
        for (string a_line: lines) {
            vector<string> map_info;
            stringstream X(a_line);
            while (getline(X, info, '|')) {
                map_info.push_back(info);
            }
            if (map_info[0] == "pf") {
                p = new PessoaFisica(map_info[1], map_info[2], map_info[3], map_info[4], map_info[5], std::stoi(map_info[6]));
            } else if (map_info[0] == "pj") {
                p = new PessoaJuridica(map_info[1], map_info[2], map_info[3], map_info[4], map_info[5], map_info[6]);
            } else if (map_info[0] == "cc") {
                c = new ContaComum(map_info[1], p, std::stod(map_info[2]));
                createAccount(p, c);
            } else if (map_info[0] == "cl") {
                c = new ContaLimite(map_info[1], std::stod(map_info[2]), p, std::stod(map_info[3]));
                createAccount(p, c);
            } else if (map_info[0] == "cp") {
                c = new ContaPoupanca(map_info[1], std::stod(map_info[2]), p, std::stoi(map_info[3]), std::stoi(map_info[4]),
                std::stoi(map_info[5]));
                createAccount(p, c);
            } else {
                Transacoes t(std::stoi(map_info[1]), std::stoi(map_info[2]), std::stoi(map_info[3]), std::stoi(map_info[4]), 
                std::stoi(map_info[5]), map_info[6], std::stod(map_info[7]));
                c->addTransaction(t);
            }
        }
    }
    return true;
}