#include "../include/sistema.h"
#include <iostream>
Sistema::Sistema(int preco)
{
    if (preco <= 0)
    {
        std::cout << "O  preço não pode ser menor que 0 " << std::endl;
        throw preco_0_e();
    }
    else

        _preco_corrida = preco;
}

Cliente *Sistema::cadastra_cliente(std::string nome)
{
    if (_clientes.count(nome) > 0)
    {
        throw cliente_ja_existe_e();
    }

    Cliente *cliente = new Cliente(nome);
    _clientes[nome] = cliente;
    return cliente;
}

void Sistema::adicionar_carro(std::string cor, unsigned int id)
{

    _frota.cadastrar_carro(cor, id);
}

Carro *Sistema::busca_uber(std::string nome)
{
    if (_clientes.count(nome) == 0)
    {
        throw cliente_nao_existe_e();
    }

    Cliente *c = _clientes.at(nome);

    if (c->get_saldo() == 0)
    {
        throw sem_saldo_e();
    }

    if (c->get_saldo() < _preco_corrida)
    {
        throw sem_saldo_e();
    }

    Carro *car = _frota.alocar_carro();
    return car;
}

Sistema::~Sistema()
{

    for (auto client : _clientes)
    {
        delete client.second;
    }
}