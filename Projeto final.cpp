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
	public:
	    void print_prontuario(){
	        cout << "Ultima atualização: " << ultima_atulizacao << endl;
	        cout << "Prontuario: " << endl << desenvolvimento << endl;
	    }
	    void att(){
	        int escolha = 0;
	        while(escolha != 3){
	            cout << "Ações:" << endl << "1 - Ver prontuario" << endl << "2 - Atualizar Prontuario" << endl << "3 - Voltar";	  
	            cin >> escolha;
	            if(escolha == 1){
	                print_prontuario();
	            } else if(escolha == 2){
	                cout << "Informe a data de hoje: ";
	                cin.ignore();
	                getline(cin, ultima_atulizacao);
	                cout << "Escreva as atualizações: " << endl;
	                cin.ignore();
	                string att;
	                getline(cin, att);
	                desenvolvimento = desenvolvimento + "\n" + "\n" + ultima_atulizacao + "\n" + att;
	            }
	        }
	    }
};

class laudo {
	string conclusao;
	string DSM;
	string medico;
	int CRM;
	public:
	    void print_laudo(){
	        cout << "Médico resposável: " << medico << "(CRM: " << CRM << ")" << endl;
	        cout << "DSM: " << DSM << endl << conclusao << endl;
	    }
};

class apoio : public Pessoa {
	int telefone;
	string relacao;
	public:
	    void print_apoio(){
	        cout << "Nome: " << nome << endl << "Relação: " << relacao << endl << "Telefone: " << telefone << endl; 
	    }
};

class paciente : public Pessoa {
	string data_inicio;
	string ultima_secao;
	int idade;
	prontuario pront;
	laudo lau;
	vector<apoio> apo;
	public:
	    void func(){
	        int escolha = 0;
	        while(escolha != 5){
	            cout << "Ações:" << endl;
	            cout << "1 - Informações" << endl <<"2 - Prontuario" << endl << "3 - Informações de Laudo" << endl << "4 - Consultar rede de apoio" << endl << "5 - Voltar";	     
	            cin >> escolha;
	            if (escolha == 1){
	                cout << "Nome: " << nome << endl << "Idade: " << idade << endl << "Primeira seção: " << data_inicio << endl << "Ultima seção cadastada: " << ultima_secao << endl;
	            } else if (escolha == 2){
	                pront.att();
	            } else if (escolha == 3){
	                lau.print_laudo();
	            }
	            else if(escolha == 4) {
	                for (int i = 0; i < apo.size(); i ++){
	                    apo[i].print_apoio();
	                }
	            }
	        }

	    }
};

class psicologo : public Pessoa {
    int CRP;
    sala sala_de_atendimento;
    vector<paciente> clientes;
    public:
        void cadastro_psi(string nome, int id){
    	    this->nome = nome;
    	    this->id = id;
    	}
    	void print_CRP(){
    	    cout << CRP << endl;
    	}
    	void list_clientes(){
    	    cout << "Clientes: ";
    	    for(int i = 0; i < clientes.size(); i ++){
    	        cout <<clientes[i].nome << endl;
    	    }
    	}
    	
    	void procurar_cliente(string nome_cliente){
    	    for(int i = 0; i < clientes.size(); i++){
    	        if(clientes[i].nome == nome_cliente){
    	            clientes[i].func();
    	            break;
    	        }
    	    }
    	    cout << "Cliente não encontrado" << endl;
    	}
    	
    	void gestao(){
    	    cout << "Bem-vindo " << nome << "!" << endl ;
    	    int escolha = 0;
    	    while(escolha != 5){
    	        cout << "O que deseja fazer ?!" << endl;
    	        cout << "1 - Listar pacientes" << endl << "2 - Procurar paciente" << endl << "3 - Adcionar paciente" << endl << "4 - Remover pacientes" << endl << "5 - Sair" << endl;
    	        if (escolha == 1){
    	            list_clientes();
    	        } else if (escolha == 2){
    	            cout << "Informe o nome do cliente: ";
    	            string nome_cliente;
    	            cin.ignore();
                    getline(cin, nome_cliente);
    	            procurar_cliente(nome_cliente);
    	        }
    	    }
    	}
    	

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
	void print_nome(){
	    cout << nome;
	}
	void add_psi(string nome, int id){
	    psicologo new_psi;
	    new_psi.cadastro_psi(nome, id);
	    psi_clinica.push_back(new_psi);
	}
	void print_psi(){
	    cout << "Psicologos da clínica:" << endl;
	    for (int i = 0; i < psi_clinica.size(); i++){
	        cout << "Nome:" << psi_clinica[i].nome << endl;
	        cout << "CRP:";
	        psi_clinica[i].print_CRP();
	    }
	}
	void login_psi(string nome_psicolgo){
	    for (int i = 0; i < psi_clinica.size(); i ++){
	        if(psi_clinica[i].nome == nome_psicolgo){
	            psi_clinica[i].gestao();
	            break;
	        } 
	    }
	    cout << "Nome não encontrado!" << endl;
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
    

    int escolha_1 = 0;
    
    while (escolha_1 != 4){
        cout << "Sistema da clínica ";
        um.print_nome(); 
        cout << "!" << endl << "Qual ação deseja realizar ?" << endl;
        cout << "1 - Informações" << endl << "2 - Sou psicologo" << endl << "3 - Sou cliente" << endl << "4 - Sou administrador" << endl << "5 - Sair" << endl;   
        cin >> escolha_1;
        if(escolha_1 == 1){
            cout << "Informações:" << endl << "1 - Endereço" << endl << "2 - Psicologos da clínica" << endl;
            int escolha_2 = 0;
            cin >> escolha_2;
            if (escolha_2 == 1){
                um.printarClinica();
            } else if (escolha_2 == 2){
                um.print_psi();
            }
        } else if(escolha_1 == 2){
            cout << "Qual ação você deseja realizar ?" << endl << "1 - Já sou cadastrado" << endl << "2 - Me cadastrar" << endl << "3 - Desejo cancelar meu cadastro" << endl;
            int escolha_3 = 0;
            cin >> escolha_3;
            //aplica um while
            if (escolha_3 == 1){
                cout << "Informe o seu nome: ";
                string nome_psi;
                cin.ignore();
	            getline(cin, nome_psi);
	            um.login_psi(nome_psi);
            }
        }
    }


	return 0;
}
