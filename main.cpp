#include "ilhas.h"

int main(int argc, char const *argv[]){
    char const* const file = argv[1];
    freopen(file,"r",stdin);

    int valor, n_ilhas, prim, seg;
    std::vector<std::tuple<int, int, double>> vec_ilhas;

    // valor maximo a ser gasto por cada menina
    std::cin >> valor;

    //quantidade de ilhas
    std::cin >> n_ilhas;

    //custo beneficio pontuacao/valor da hospedagem
    double p_por_v;

    //recebendo a entrada em forma de tuplas pra facilitar posteriormente
    //criado um vector de pairs tbm original.
    for (int i = 0; i < n_ilhas; i++){
        std::cin >> prim;
        std::cin >> seg;

        //como a divisao e de inteiros e necessario fazer um casting
        p_por_v = static_cast<double>(seg) / (double)(1.0 * prim);
        vec_ilhas.push_back(std::make_tuple(prim, seg, p_por_v));
    }

    //ordenando o vector de tuplas em ordem decrescente(terceiro elemento)
    sort(vec_ilhas.begin(), vec_ilhas.end(), ord_decrescente);

    //Usados para facilitar a implementacao, como os valores foram
    //ordenados anteriormente basta separar o vector de tuplas em um unico vector 
    //com os valores por ilha de acordo com custo beneficio de pegar tal ilha
    //repesentado na terceira parcela da tupla.
    //no caso da PD a ordenacao nao importa entao serao reaproveitados
    std::vector<int> val;
    std::vector<int> pont;

    for (int i = 0; i < n_ilhas; i++){
        val.push_back(std::get<0>(vec_ilhas[i]));
        pont.push_back(std::get<1>(vec_ilhas[i]));
    }

    //resultado Guloso
    guloso(n_ilhas, valor, val, pont);
    //resultado Programacao Dinamica
    programacao_dinamica(n_ilhas, valor, val, pont);
    return 0;
}
