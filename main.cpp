#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Funcionario {
    int prontuario;
    string nome;
    double salario;
};

bool prontuarioExiste(const vector<Funcionario>& funcionarios, int prontuario) {
    for (const auto& f : funcionarios) {
        if (f.prontuario == prontuario) {
            return true;
        }
    }
    return false;
}

void incluirFuncionario(vector<Funcionario>& funcionarios) {
    Funcionario novo;
    
    cout << "\n--- Incluir Funcionario ---\n";
    cout << "Prontuario: ";
    cin >> novo.prontuario;
    
    if (prontuarioExiste(funcionarios, novo.prontuario)) {
        cout << "ERRO: Ja existe um funcionario com este prontuario!\n";
        return;
    }
    
    cout << "Nome: ";
    cin.ignore();
    getline(cin, novo.nome);
    
    cout << "Salario: ";
    cin >> novo.salario;
    
    funcionarios.push_back(novo);
    cout << "Funcionario cadastrado com sucesso!\n";
}

void excluirFuncionario(vector<Funcionario>& funcionarios) {
    int prontuario;
    
    cout << "\n--- Excluir Funcionario ---\n";
    cout << "Digite o prontuario: ";
    cin >> prontuario;
    
    for (auto it = funcionarios.begin(); it != funcionarios.end(); ++it) {
        if (it->prontuario == prontuario) {
            funcionarios.erase(it);
            cout << "Funcionario excluido com sucesso!\n";
            return;
        }
    }
    
    cout << "Funcionario nao encontrado!\n";
}

void pesquisarFuncionario(const vector<Funcionario>& funcionarios) {
    int prontuario;
    
    cout << "\n--- Pesquisar Funcionario ---\n";
    cout << "Digite o prontuario: ";
    cin >> prontuario;
    
    for (const auto& f : funcionarios) {
        if (f.prontuario == prontuario) {
            cout << "\nFuncionario encontrado:\n";
            cout << "Prontuario: " << f.prontuario << endl;
            cout << "Nome: " << f.nome << endl;
            cout << "Salario: " << f.salario << endl;
            return;
        }
    }
    
    cout << "Funcionario nao encontrado!\n";
}

void listarFuncionarios(const vector<Funcionario>& funcionarios) {
    double totalSalarios = 0;
    
    cout << "\n--- Lista de Funcionarios ---\n";
    
    if (funcionarios.empty()) {
        cout << "Nenhum funcionario cadastrado.\n";
        return;
    }
    
    for (const auto& f : funcionarios) {
        cout << "\nProntuario: " << f.prontuario << endl;
        cout << "Nome: " << f.nome << endl;
        cout << "Salario: " << f.salario << endl;
        cout << "------------------------\n";
        totalSalarios += f.salario;
    }
    
    cout << "Total dos salarios: " << totalSalarios << endl;
}

int main() {
    vector<Funcionario> funcionarios;
    int opcao;
    
    do {
        cout << "\n--- Menu ---\n";
        cout << "0. Sair\n";
        cout << "1. Incluir\n";
        cout << "2. Excluir\n";
        cout << "3. Pesquisar\n";
        cout << "4. Listar\n";
        cout << "Opcao: ";
        cin >> opcao;
        
        switch (opcao) {
            case 0:
                cout << "Saindo...\n";
                break;
            case 1:
                incluirFuncionario(funcionarios);
                break;
            case 2:
                excluirFuncionario(funcionarios);
                break;
            case 3:
                pesquisarFuncionario(funcionarios);
                break;
            case 4:
                listarFuncionarios(funcionarios);
                break;
            default:
                cout << "Opcao invalida!\n";
        }
        
    } while (opcao != 0);
    
    return 0;
}
