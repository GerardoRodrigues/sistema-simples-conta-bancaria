#include "Cabecalho/Cliente.h"
#include <iostream>
using namespace std;

Cliente::Cliente(){
    cash = 0;
    menu();
}

void Cliente::menu(){
    setlocale(LC_ALL, "portuguese");
    int option = 0;

    do{
        cout << "0. Sair" << endl;
        cout << "1. Checar saldo" << endl;
        cout << "2. Depositar dinheiro" << endl;
        cout << "3. Sacar dinheiro" << endl;
        cout << "Qual operacao deseja fazer ? "; cin >> option;
        cout << endl;

        action(option);

    }while(option);
}

void Cliente::action(int option){
    switch (option)
    {
    case 0:
        cout << "Fechando sistema" << endl;
        break;
    case 1:
        checkBalance();
        break;
    case 2:
        deposit();
        break;
    case 3:
        withdraw();
        break;
    default:
        cout << "Operacao invalida" << endl;
        break;
    }
}

void Cliente::checkBalance(){
    cout << endl << "Seu saldo bancario eh: " << getCash() << "R$" << endl;
}

void Cliente::deposit(){
    double deposit;

    cout << "Qual valor deseja depositar ? "; cin >> deposit;

    if(deposit > 0){
        cash += deposit;
        cout << endl << "Deposito realizado com sucesso!" << endl;
        checkBalance();
        cout << endl;
    } else{
        cout << endl << "Valor invalido!" << endl;
    }
}

void Cliente::withdraw(){
    double withdraw;

    cout << "Qual valor deseja sacar ? "; cin >> withdraw;

    if(cash >= withdraw && withdraw > 0){
        cout << endl << "Saque realizado com sucesso!" << endl;
        cash -= withdraw;
        checkBalance();
        cout << endl;
    }else{
        cout << endl << "Saldo insuficiente para saque!" << endl;
    }
}

double Cliente::getCash()
{
    return cash;
}

void Cliente::setCash(double cash){
    this->cash = cash;
}
