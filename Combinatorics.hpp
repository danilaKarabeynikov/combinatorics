#pragma once
#include "CombinatoricsApi.hpp"
#include <iostream>
#include <cmath>
#include <string>
#include <vector>

COMBINATORICS_API void LexPermute(int n);//Алгоритм порождения перестановок в лексикографическом порядке

COMBINATORICS_API void PermTr(int n); //Алгоритм порождения перестановок в порядке минимального изменения

COMBINATORICS_API void CodеGrey(int n);//Алгоритм порождения n-разрядного двоично-отражённого кода Грея 

COMBINATORICS_API std::vector<std::vector<bool>> CodeGreys(int n);