#include <iostream>
#include <string>
#include <vector>
using namespace std;


class sala {
	int numero_sala;
	public:
	    void def_num(int numero_sala){
	        this-> numero_sala = numero_sala;
	    }
	    void print_sala(){
	        cout << numero_sala;
	    }
};

class Pessoa {
    public:
    	string nome;
    	int id;
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
    int CRP;
    sala sala_de_atendimento;
    public:
        void cadastro_psi(string nome, int id){
    	    this->nome = nome;
    	    this->id = id;
    	}
    	

};

class paciente : public Pessoa {
	string data_inicio;
	string ultima_secao;
	prontuario pront;
	laudo lau;
	apoio apo;
};

class clinica {
	string nome;
	string local;
	int CEP;
	string dono;
	vector<sala> salas_clinica;
	vector<psicologo> psi_clinica;
public:
	void cadastrarNome(string nome) {
		this->nome = nome;
	}
	void cadastrarLocal(string local) {
		this->local = local;
	}
	void cadastrarCep(int CEP) {
		this->CEP = CEP;
	}
	void cadastrarDono(string dono) {
		this->dono = dono;
	}
	void printarClinica() {
		cout << "Nome da clínica: " << nome << endl;
		cout << "Edenreço da clínica: " << local << endl;
		cout << "CEP da clínica: " << CEP << endl;
		cout << "Dono da clínica: " << dono << endl;
	}
	void add_psi(string nome, int id){
	    psicologo new_psi;
	    new_psi.cadastro_psi(nome, id);
	    psi_clinica.push_back(new_psi);
	}
	void print_psi(){
	    for (int i = 0; i < psi_clinica.size(); i++){
	        cout << "Nome:" << psi_clinica[i].nome << endl;
	        cout << "Id:" << psi_clinica[i].id << endl;
	    }
	} 
    void add_sala(int quant_sala){
        for (int i = 0; i < quant_sala; i ++){
            cout << "Informe o numero da sala " << i + 1 << ": ";
            int numero;
            cin >> numero;
            sala new_sala;
            new_sala.def_num(numero);
            salas_clinica.push_back(new_sala);
        }
    }
    void informe_sala(){
        for(int i = 0; i < salas_clinica.size(); i ++){
            cout << "Sala numéro: ";
            salas_clinica[i].print_sala();
            cout << endl;
        }
    }
};



int main()
{
	clinica um;
	//Parte 1 - Cadastro da clínica a ideia é que depois coloquemos um predefinido pra não ter que cadastrar sempre
	
	cout << "Bem-vindo ao sistema de gerenciamento !\nPrimenramente vamos cadastrar sua clínica" << endl;
	cout << "Informe o nome da clínica: ";
	string nome_clinica;
	cin.ignore();
	getline(cin, nome_clinica);
	um.cadastrarNome(nome_clinica);
	
	cout << "Informe o endereço: ";
	string endereco_clinica;
	cin.ignore();
	getline(cin, endereco_clinica);
	um.cadastrarLocal(endereco_clinica);
	
	cout << "Informe o CEP: ";
	int cep_clinica;
	cin >> cep_clinica;
	um.cadastrarCep(cep_clinica);
	
	cout << "Informe o nome do dono: ";
	string nome_dono;
    cin.ignore();
    getline(cin, nome_dono);
	um.cadastrarDono(nome_dono);
	
    cout << "Está na hora de cadastrar as salas de sua clínica !" << endl << "Informe quantas salas tem sua clínica: ";
    int num_sala;
    cin >> num_sala;
    um.add_sala(num_sala);
    um.informe_sala();
    
    //Parte 2 - Funcionamento para o cliente/Psicologo podendo cadasatrar varias informações 



	return 0;
}
