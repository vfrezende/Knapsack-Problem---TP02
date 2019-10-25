#ifndef _ILHAS_H_
#define _ILHAS_H_

#include <bits/stdc++.h>

//assinatura das funcoes relacionadas a instancia gulosa do problema
bool ord_decrescente(const std::tuple<int, int, double>& a, const std::tuple<int, int, double>& b);
void guloso(int n_ilhas, int valor_disp, std::vector<int> &val, std::vector<int> &pont);

//asinatura das funcoes relacionadas a instancia em programacao dinamica do problema
void backtraking_dias(int n_ilhas, int valor_disp, std::vector<std::vector<int>> &mat, std::vector<int> &val_pd);
void programacao_dinamica(int n_ilhas, int valor_disp, std::vector<int> &val_pd, std::vector<int> &pont_pd);

#endif
