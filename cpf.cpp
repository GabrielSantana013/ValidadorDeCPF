#include "cpf.hpp"

Cpf::Cpf(){

    for(size_t i {}; i<9; ++i){
        this->m_numbs +=std::to_string(std::rand()%10);
    }
    generateFirstDigit();
    generateSecondDigit();
}

void Cpf::generateFirstDigit(){

    int d1 {};
    for(size_t i {}, k{10}; i < m_numbs.size(); ++i, --k){
        d1 +=  std::stoi(m_numbs.substr(i,1))*k;
    }

    (d1 %11 < 2) ?
    this->m_numbs += "0":
    this->m_numbs += std::to_string(11 - (d1 % 11));

}


void Cpf::generateSecondDigit(){

    int d2 {};
    for(size_t i {}, k{10}; i < m_numbs.size() -1; ++i, --k){
        d2 +=  std::stoi(m_numbs.substr(i+1,1))*k;
    }

    (d2 %11 < 2) ?
    this->m_numbs += "0":
    this->m_numbs += std::to_string(11 - (d2 % 11));

}

void Cpf::formatCpf(){
    m_numbs.insert(3,".");
    m_numbs.insert(7,".");
    m_numbs.insert(11,"-");
}

bool Cpf::checkCpf(std::string *cpf){

    //limpa o cpf
    (*cpf).erase(std::remove((*cpf).begin(), (*cpf).end(), '.'), (*cpf).end());
    (*cpf).erase(std::remove((*cpf).begin(), (*cpf).end(), '-'), (*cpf).end());

    //verifica se o cpf e somente numeros
    if(!std::all_of(cpf->begin(), cpf->end(), ::isdigit)){
        return false;
    }

    this->m_numbs = cpf->substr(0,9);
    generateFirstDigit();
    generateSecondDigit();
    return this->m_numbs == *cpf;
}