#include <iostream>
#include <string>
#include <vector>
using namespace std;


class sala {
	int disponibilidade = 0;
	public:
	    int numero_sala;
	    void def_num(int numero_sala){
	        this-> numero_sala = numero_sala;
	    }
	    void print_sala(){
	        if(disponibilidade == 0){
	            cout << numero_sala;
	        }
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
	                string att;
	                getline(cin, att);
	                desenvolvimento = desenvolvimento + "\n" + "\n" + ultima_atulizacao + "\n" + att;
	            }
	        }
	    }
	    void att_primeira(string primeira_secao, string primeira_data){
	        desenvolvimento = primeira_data + "\n" + primeira_secao; 
	        
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
	    void setMedico(string medico, int CRM){
	        this->medico = medico;
	        this-> CRM = CRM;
	    }
	    void setConclusao(string conclusao, string DSM){
	        this->conclusao = conclusao;
	        this->DSM = DSM;
	    }
};

class apoio : public Pessoa {
	public:
    	int telefone;
    	string relacao;	
    	void set_dados(int telefone, string relacao){
    	    this->telefone = telefone;
    	    this->relacao = relacao;
    	}
	    void print_apoio(){
	        cout << "Nome: " << nome << endl << "Relação: " << relacao << endl << "Telefone: " << telefone << endl; 
	    }
};

class paciente : public Pessoa {
	string data_inicio;
	string ultima_secao;
	prontuario pront;
	laudo lau;
	vector<apoio> apo;
	public:
	    int idade;
	    void addApo(string nome_apoio, int telefone, string relacao){
	        apoio new_apoio;
	        new_apoio.nome = nome_apoio;
	        new_apoio.set_dados(telefone, relacao);
	        apo.push_back(new_apoio);
	    }
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
	  void setData_inicio(string data_inicio){
	      this->data_inicio = data_inicio;
	  }
	  void setData_atual(string ultima_secao){
	      this->ultima_secao = ultima_secao;
	  }
	  void setLauMedico(string medico, int CRM){
	      lau.setMedico(medico, CRM);
	  }
	  void setLauConclusao(string conclusao, string DSM){
	      lau.setConclusao(conclusao, DSM);
	  }
	  void prontAttPrimeira(string primeira_secao, string primeira_data){
	      pront.att_primeira(primeira_secao, primeira_data);
	  }
};

class psicologo : public Pessoa {
    int CRP;
    sala sala_de_atendimento;
    vector<paciente> clientes;
    public:
        void setSala(sala sala_de_atendimento){
            this->sala_de_atendimento = sala_de_atendimento;
        }
        void cadastro_psi(string nome, int CRP){
    	    this->nome = nome;
    	    this->CRP = CRP;
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
    	        cout << "1 - Listar pacientes" << endl << "2 - Procurar cliente" << endl << "3 - Adcionar cliente" << endl << "4 - Remover cliente" << endl << "5 - Sair" << endl;
    	        cin >> escolha;
    	        if (escolha == 1){
    	            list_clientes();
    	        } else if (escolha == 2){
    	            cout << "Informe o nome do cliente: ";
    	            string nome_cliente;
    	            cin.ignore();
                    getline(cin, nome_cliente);
    	            procurar_cliente(nome_cliente);
    	        } else if (escolha == 3){
    	            paciente novo_cliente;
    	            cout << "Informe o nome do novo cliente: ";
    	            cin.ignore();
    	            getline(cin, novo_cliente.nome);
    	            cout << "Informe a idade do cliente: ";
    	            cin >> novo_cliente.idade;
    	            cout << "Informe a data da primeira seção: ";
    	            cin.ignore();
    	            string data_cliente;
    	            getline(cin, data_cliente);
    	            novo_cliente.setData_inicio(data_cliente);
    	            novo_cliente.setData_atual(data_cliente);
    	            cout << "O cliente tem algum laudo ? (S/n)";
    	            char escolha;
    	            cin.ignore();
    	            escolha = getchar();
    	            if(escolha == 'S'){
    	                cout << "Informe o nome do médico que deu o laudo: ";
    	                cin.ignore();
    	                string dados_laudo;
    	                getline(cin, dados_laudo);
    	                int CRM;
    	                cout << "Informe o CRM do médico: ";
    	                cin >> CRM;
    	                novo_cliente.setLauMedico(dados_laudo, CRM);
    	                cout << "Informe a conclusão médica: ";
    	                cin.ignore();
    	                getline(cin, dados_laudo);
    	                cout << "Informe o código do DSM: ";
    	                string DSM;
    	                cin.ignore();
    	                getline(cin, DSM);
    	                novo_cliente.setLauConclusao(dados_laudo, DSM);
    	            }
    	           cout << "Informe o prontuario da primeira seção: ";
    	           string laudo_inicio;
    	           getline(cin, laudo_inicio);
    	           novo_cliente.prontAttPrimeira(laudo_inicio,data_cliente);
    	           cout << "Informe o nome de uma pessoa para rede de apoio: ";
    	           string nome_apoio;
    	           getline(cin, nome_apoio);
    	           cout << "Informe a relação do requerido com o cliente: ";
    	           string relacao_apoio;
    	           getline(cin, relacao_apoio);
    	           cout << "Informe o telefone do requerido: ";
    	           int telefone_apoio;
    	           cin >> telefone_apoio;
    	           novo_cliente.addApo(nome_apoio, telefone_apoio, relacao_apoio);
    	           clientes.push_back(novo_cliente);
    	           cout << "Cliente cadastado";
    	        }
    	        else if(escolha == 4){
    	            cout << "Informe o nome do cliente: ";
    	            string cliente_delet;
    	            cin.ignore();
    	            getline(cin, cliente_delet);
    	            for (int i = 0; i < clientes.size(); i ++){
    	                int achou = 0;
    	                if (cliente_delet == clientes[i].nome){
    	                    int tam_aux = clientes.size() - 1;
    	                    paciente cliente_aux;
    	                    cliente_aux = clientes[i];
    	                    clientes[i] = clientes[tam_aux];
    	                    clientes[tam_aux] = cliente_aux;
    	                    clientes.pop_back();
    	                    achou = 1;
    	                }
    	                if(achou = 1){
    	                    cout << "Cliente removido !!" << endl;
    	                } else {
    	                    cout << "Cliente não encontrado" << endl;
    	                }
    	            }
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
    sala informe_sala(){
        for(int i = 0; i < salas_clinica.size(); i ++){
            cout << "Sala numéro: ";
            salas_clinica[i].print_sala();
            cout << endl;
        }
        cout << "Escolha uma sala: ";
        int esc_sala;
        cin >> esc_sala;
        for (int i = 0; i < salas_clinica.size(); i ++){
            if (esc_sala = salas_clinica[i].numero_sala){
                return salas_clinica[i];
            }
        }
    return salas_clinica[1];
    }
    void add_psi(string nome, int CRP){
	    psicologo new_psi;
	    new_psi.cadastro_psi(nome, CRP);
	    sala aux_sala = informe_sala();
	    new_psi.setSala(aux_sala);
	    psi_clinica.push_back(new_psi);
	}
	void deletePsi(string nome){
	    for (int i = 0; i < psi_clinica.size(); i++){
	        if (nome == psi_clinica[i].nome){
	            int tam_aux = psi_clinica.size() - 1;
	            psicologo aux_psi = psi_clinica[i];
	            psi_clinica[i] = psi_clinica[tam_aux];
	            psi_clinica[tam_aux] = aux_psi;
	            psi_clinica.pop_back();
	        }
	    }
	}
	void acessPsi(string psi_nome, string cliente_nome){
	    for (int i = 0; i < psi_clinica.size(); i ++){
	        if (psi_clinica[i].nome == psi_nome){
	            psi_clinica[i].procurar_cliente(cliente_nome);
	        }
	    }
	}
	~clinica(){
	    cout << "Destrutor chamado" << endl;
	}

};



int main()
{
	clinica um;
	//Parte 1 - Cadastro da clínica a ideia é que depois coloquemos um predefinido pra não ter que cadastrar sempre
	
	cout << "Bem-vindo ao sistema de gerenciamento !\nPrimenramente vamos cadastrar sua clínica" << endl;
	cout << "Informe o nome da clínica: ";
	string nome_clinica;
	getline(cin, nome_clinica);
	um.cadastrarNome(nome_clinica);
	
	cout << "Informe o endereço: ";
	string endereco_clinica;
	
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
    
    //Parte 2 - Funcionamento para o cliente/Psicologo podendo cadasatrar varias informações 
    

    int escolha_1 = 0;
    
    while (escolha_1 != 5){
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
            int escolha_3 = 0;
            while(escolha_3 != 4){
                cout << "Qual ação você deseja realizar ?" << endl << "1 - Já sou cadastrado" << endl << "2 - Me cadastrar" << endl << "3 - Desejo cancelar meu cadastro" << endl << "4 - Voltar" << endl;
                cin >> escolha_3;    
                if (escolha_3 == 1){
                cout << "Informe o seu nome: ";
                string nome_psi;
                cin.ignore();
	            getline(cin, nome_psi);
	            um.login_psi(nome_psi);
                }
                if (escolha_3 == 2){
                    cout << "Informe o seu nome: ";
                    string novo_nome;
                    cin.ignore();
                    getline(cin, novo_nome);
                    cout << "Informe o seu CRP: ";
                    int novo_crp;
                    cin >> novo_crp;
                    cout << "Informe uma sala para você, essas são as disponíveis: " << endl;
                    um.add_psi(novo_nome, novo_crp);
                    
                    cout << "Psicologo cadastrado !";
                }
                if (escolha_3 == 3) {
                    cout << "Informe o seu nome: ";
                    string nome_delete;
                    cin.ignore();
                    getline(cin, nome_delete);
                    um.deletePsi(nome_delete);
                }
                    
            }

        } else if(escolha_1 == 3) {
            int escolha_4 = 0;
            string nome_cliente;
            string nome_psics;
            cout << "Informe seu nome:";
            cin.ignore();
            getline(cin, nome_cliente);
            cout << "Informe o nome do seu Piscologo: ";
            cin.ignore();
            getline(cin, nome_psics);
            while (escolha_4 != 2){
                cout << "Qual ação deseja realizar ?" << endl << "1 - Acessar meus dados" << endl << "2 - Voltar" << endl;
                cin >> escolha_4;
                if (escolha_4 == 1){
                    um.acessPsi(nome_psics, nome_cliente);
                }
            }
        } else if(escolha_1 == 4){
            cout << "Informe a senha do administrador: ";
            int senha;
            cin >> senha;
            if (senha == 59152){
                cout << "Qual ação deseja realizar ?" << endl << "1 - Adicionar salas" << endl << "2 - Apagar clínica" << endl;
                int escolha_5;
                cin >> escolha_5;
                if (escolha_5 == 1){
                    cout << "Informe quantas salas deseja adicionar: ";
                    int new_sala;
                    cin >> new_sala;
                    um.add_sala(new_sala);
                } else if (escolha_5 == 2){
                    //delete um;
                }
            } else {
                cout << "Senha incorreta, aperte qualquer tecla para retornar";
                string voltar;
                getline(cin, voltar);
            }
        }
    }


	return 0;
}
