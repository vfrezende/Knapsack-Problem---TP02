#include "ilhas.h"

//usada para ordenar o segundo elemento em ordem decrescente
bool ord_decrescente(const std::tuple<int, int, double>& a, const std::tuple<int, int, double>& b) { 
    return (std::get<2>(a) > std::get<2>(b)); 
}

//Instancia do problema guloso com repeticao
void guloso(int n_ilhas, int valor_disp, std::vector<int> &val, std::vector<int> &pont){
    int n_dias = 0;
    int pontuacao = 0;
    int id = 0; //indice do while

    //Caso Base
    if(!n_ilhas || !valor_disp){
        std::cout << 0 << " " << 0 << std::endl;
        return;
    }

    //Enquanto o final do vetor de valores nao for atingido 
    //e ainda estiver valor disponivel
    while(valor_disp > 0 && id != val.size()){
        //valor da ilha for maior que valor disponivel
        if(val[id] > valor_disp && id != val.size()){
            id++;
        }
        else{
            pontuacao += pont[id]; //adiciona pontuacao da ilha 
            valor_disp -= val[id]; //retira do valor disponivel o preco da ilha
            n_dias++; //dias que as meninas vao ficar nas ilhas
        } 
    }
    std::cout << pontuacao << " " << n_dias << std::endl;
}
//BACKTRAKING  para identificar a quantidades de dias, ou seja,
//quantas vezes cada posicao do vetor val_pd foi escolhida 
void backtraking_dias(int n_ilhas, int valor_disp, std::vector<std::vector<int>> &mat, std::vector<int> &val_pd){
    int n_dias = 0;
    while(n_ilhas > 0 && valor_disp >= 0){
        if (mat[n_ilhas][valor_disp] != mat[n_ilhas-1][valor_disp]){
            valor_disp -= val_pd[n_ilhas];
            n_dias++;
        }
        n_ilhas--; 
    }
    std::cout << n_dias << std::endl;
}

void programacao_dinamica(int n_ilhas, int valor_disp, std::vector<int> &val_pd, std::vector<int> &pont_pd){
    std::vector<std::vector<int>> mat(n_ilhas+1, std::vector<int>(valor_disp+1, 0));
    //iniciando os dois indices dos for de 1 
    //para ignorar a linha 0 e coluna 0
    for (int i = 1; i <= n_ilhas; i++){
        for (int j = 1; j <= valor_disp; j++){
            //caso valor da ilha anterior for maior que o disponivel
            //preencher a matriz com valor  da ilha anterior
            //ou seja decide se deve ser incluido ou nao
            if (val_pd[i-1] > j){
                mat[i][j] = mat[i-1][j];
            }else{
                //caso for incluido pegue o maximo entre elemento anterior
                //na coluna j da matriz e a soma do peso anterior e o valor ja calculado
                mat[i][j] = std::max(mat[i-1][j], pont_pd[i-1] + mat[i-1][j - val_pd[i-1]]);
            }   
        } 
    }
    int result = mat[n_ilhas][valor_disp];
    std::cout << result << " ";
    backtraking_dias(n_ilhas, valor_disp, mat, val_pd);
}
