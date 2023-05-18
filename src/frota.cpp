#include "../include/frota.h"
#include <iostream>
void Frota::cadastrar_carro(std::string cor, unsigned int id)
{

    bool existe = false;

    for (auto it : _carros)
    {
        if (it->get_id() == id)
        {

            existe = true;
            break;
        }
    }

    if (existe)
    {
        throw id_ja_existe_e();
    }
    else
    {
        Carro *c = new Carro(cor, id);
        _carros.push_back(c);
    }
}

Carro *Frota::alocar_carro()
{
    if (_carros.empty())
    {
        throw zero_carros_disponiveis_e();
    }
    for (auto it : _carros)
    {
        if (it->get_ocupado() == false)
        {

            Carro *alocado = it;
            alocado->seta_ocupado(); // ocupando ele

            return alocado;
            break;
        }
    }

    throw zero_carros_disponiveis_e(); // todos estao ocupados
}
Frota::~Frota()
{

    for (auto car : _carros)
    {
        delete car;
    }
}