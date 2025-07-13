#include <iostream>
#include <string>
using namespace std;

class Pessoa{
    string nome;
    string id;
    
    
};

class paciente : public Pessoa{
    string data_inicio;
    string ultima_secao;
};

class psicologo : public Pessoa {
    
};

class clinica {
    
};

class prontuario {
    
};

int main()
{
    std::cout<<"Hello World";

    return 0;
}
