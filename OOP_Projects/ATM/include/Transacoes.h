#ifndef TRANSACOES_H
#define TRANSACOES_H

#include <string>
using std::string;

class Transacoes {
private:
    int t_day, t_month, t_year, t_hours, t_minutes;
    string description;
    double amount;
public:
    Transacoes(int d, int m, int a, int hours, int minutes, string des, double v) : 
    t_day(d), t_month(m), t_year(a), t_hours(hours), t_minutes(minutes), amount(v) {
        description = des;
    };
    Transacoes() { };
    int get_Tday() const {return t_day;}
    int get_Tmonth() const {return t_month;}
    int get_Tyear() const {return t_year;}
    int get_Tmin() const {return t_minutes;}
    int get_Thour() const {return t_hours;}
    string getDescription() const {return description;}
    double getAmount() const {return amount;}
};


#endif