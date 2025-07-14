#include <iostream>
#include <string>
using namespace std;


class clinica {
    string nome;
    int CEP;
    
};

class sala {
    int numero_sala;
}

class Pessoa{
    string nome;
    string id;
    
    
};

class prontuario {
    string desenvolvimento;
    string ultima_atulizacao;
};

class laudo {
    string conclusao;
    string DSM;
    string medico;
    int CRM;
};

class apoio : public Pessoa {
    int telefone;
    string relacao;
};



class psicologo : public Pessoa {
    
};

class paciente : public Pessoa{
    string data_inicio;
    string ultima_secao;
    prontuario pront;
    laudo lau;
    apoio apo;
};


int main()
{
    std::cout<<"Hello World";

    return 0;
}
