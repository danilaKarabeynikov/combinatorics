#pragma once
#include "pch.h"
#include "Combinatorics.hpp"
using namespace std;

void LexPermute(int n) {
	int i, j, temp, left, right;

	int* Permut = new int[n];

	for (j = 0; j < n; ++j)
		Permut[j] = j + 1;

	for (; ; ) {
		for (i = 0; i < n; ++i)
			std::cout << Permut[i] << " ";
		std::cout << std::endl;

		for (i = n - 2; i > -1 &&
			Permut[i] > Permut[i + 1]; --i);
		if (i == -1) break;

		j = n - 1;
		while (Permut[i] > Permut[j]) --j;

		temp = Permut[i];
		Permut[i] = Permut[j];
		Permut[j] = temp;
		left = i + 1;
		right = n - 1;
		while (right > left) {
			temp = Permut[right];
			Permut[right--] = Permut[left];
			Permut[left++] = temp;
		}
	}
	delete[] Permut;
}

void PermTr(int n) {	
	int* Permut = new int[n + 2];
	int* PermutIn = new int[n + 2];	
	int* d = new int[n + 1];
	int i, j, k, m;

	Permut[0] = n + 1;
	Permut[n + 1] = n + 1;

	m = n + 1;
	for (i = 1; i < n + 1; ++i) {
		Permut[i] = i;
		PermutIn[i] = i;
		d[i] = -1;
	}
	d[1] = 0;

	for (; ; ) {
		for (i = 1; i < n + 1; ++i)
			std::cout << Permut[i] << " ";
		std::cout << std::endl;
		m = n;

		while (Permut[PermutIn[m] + d[m]] > m) {		
			d[m] = -d[m--];
			if (m == 1) return;
		}	
		j = Permut[PermutIn[m]];
		Permut[PermutIn[m]] = Permut[PermutIn[m] + d[m]];
		Permut[PermutIn[m] + d[m]] = j;
				
		j = PermutIn[Permut[PermutIn[m]]];
		PermutIn[Permut[PermutIn[m]]] = PermutIn[m];
		PermutIn[m] = j;
	}
}

void CodåGrey(int n) {
	int* Stack = new int[n]; 	
	int top = -1;		
	int* G = new int[n];
	int i, j, k, m;
	
	for (i = 0; i < n; ++i)
		G[i] = 0;
	for (i = 0; i < n + 1; ++i)
		Stack[i] = i + 1;

	i = Stack[0];
	while (i < n + 1) {	
		for (j = 0; j < n; ++j)
			std::cout << G[j] << " ";
		std::cout << std::endl;
		G[n - i] = (G[n - i] + 1) % 2;		
		Stack[0] = 1;
		Stack[i - 1] = Stack[i];
		Stack[i] = i + 1;	
		i = Stack[0];
	}
	for (j = 0; j < n; ++j)
		std::cout << G[j] << " ";
	std::cout << std::endl;
}

std::vector<std::vector<bool>> CodeGreys(int n)
{
	std::vector<std::vector<bool>> res{};
	res.resize(pow(2, n));

	std::vector<bool> g;
	g.resize(n);

	std::vector<int> t;
	t.resize(n + 1);
	int i = 0;


	for (i = 0; i < n; ++i)
	{
		g[i] = 0;
		t[i] = i + 1;
	}

	t[i] = i + 1;

	i = 0;
	int count = 0;

	while (true)
	{
		res[count++] = g;
		i = t[0];
		if (i >= n + 1)
			break;
		g[i - 1] = (g[i - 1] + 1) % 2;
		t[0] = 1;
		t[i - 1] = t[i];
		t[i] = i + 1;
	}

	return res;
}

