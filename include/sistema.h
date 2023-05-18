#ifndef PDS2_SISTEMA_H
#define PDS2_SISTEMA_H

#include <map>
#include <string>

#include "cliente.h"
#include "frota.h"

class cliente_ja_existe_e
{
};
class cliente_nao_existe_e
{
};
class sem_saldo_e
{
};
class preco_0_e
{
};

/*
 * Implementa um Sistema
 * Cada sistema armazena um map com os dados dos clientes,
 * uma frota com os carros cadastrados,
 * e o preço para as corridas
 */
class Sistema
{
private:
    std::map<std::string, Cliente *> _clientes;
    Frota _frota;
    double _preco_corrida;

public:
    /*
     * @brief Pega o saldo atual
     * @throws Lança uma exceção se outro carro como mesmo id já estiver cadastrado
     */
    void adicionar_carro(std::string cor, unsigned int id);

    /*
     * @brief Cadastra um novo cliente/usuário
     * @throws Lança uma exceção se outro cliente com o mesmo usuário já estiver cadastrado
     */
    Cliente *cadastra_cliente(std::string nome);

    /*
     * @brief Busca um carro para o usuário
     * @throws Lança uma exceção se o cliente não estiver cadastrado ou se estiver com saldo insulficiente
     */
    Carro *busca_uber(std::string nome);
    /*
     * Constroi um Sistema com o preço das corridas informado
     * @throws Lança uma exceção se o preço for menor que 0
     */
    Sistema(int preco);
    /*
     * Destrutor
     * Desaloca os dados que foram alocados na heap
     */
    ~Sistema();
};

#endif