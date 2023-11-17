class Cliente{
    double cash;

public:
    Cliente();
    void menu();
    void action(int);
    void checkBalance();
    void deposit();
    void withdraw();

    double getCash();
    void setCash(double);
};
