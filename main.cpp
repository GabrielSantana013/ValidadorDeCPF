#include "cpf.hpp"

int main(int argc, char** argv){

    std::srand(std::time(0));
    auto c = std::make_unique<Cpf>();
    
    if(argc>1){
        std::string args = argv[1];
        if(args == "--format"){
            c->formatCpf();
            std::cout<< c->m_numbs <<std::endl;
        }
        else if(c->checkCpf(&args)){
            std::cout<<"\033[32;1m\u2714 CPF valido!\033[m"<< std::endl;
            return EXIT_FAILURE;
        }
        else{
            std::cerr<<"\033[31;1m\u2718 CPF invalido!\033[m"<< std::endl;
            return EXIT_FAILURE;
        }
    }
    else{
        std::cout<< c->m_numbs <<std::endl;
    }

    return 0;
}

