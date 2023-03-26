// umt.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int nr_of_rectangles(vector < pair<int, int>> points) {
	int rectangles = 0;
	//idea algoritmului e sa parcurg puncetle date pe rand si in cazul in care nu sunt pe aceiasi axa consideram ca reprezinta o diagonala
	// dupa aceaea putand sa presupunem care ar fi pozitia celorlalte puncte si sa le caut in vector
	//A:(x:1,y:1)
	for (auto first_point : points) {
		//B(x:2, y : 4)
		for (auto secound_point : points) {
			if (first_point != secound_point) {
				//verific daca elementele se aflta pe diagonala(nu sunt pe acieasi axa x sau y), deoarece daca stim ca sunt pe diagonala putem afla unde ar trebui sa fie celalte puncte pt a fi patrulater
				// ex : avem A:(x:1,y:1) si B(x:2,y:4) -> celalte colturi ale paraleogramului sunt combinatii a valorilor celor 2 puncte C(xA,yB) D(yB,xA)
 				if ((first_point.first != secound_point.first) && (first_point.second != secound_point.second)) {
					pair<int, int> first_comb = make_pair(first_point.first, secound_point.second);// creeam primul colt: C(xA,yB)
					pair<int, int> second_comb = make_pair(secound_point.first,first_point.second);//creeam al doilea colt: D(yB,xA)
					//verific daca exista cele doua puncte in vector
					auto contains_first = std::find(points.begin(), points.end(), first_comb);
					auto contains_second = std::find(points.begin(), points.end(), second_comb);
					if (contains_first != contains_second && contains_first != points.end()) {
						//daca exista cresc numarul de aparitii
						rectangles++;
					}
				}
			}
		}
	}
	//se returneaza contorul / 4 deoarece algotritmul va gasii pentru fiecare dintre colturi pe rand solutia
	return rectangles/4;
}


int main()
{
    ifstream f("input.txt");
    cout << "Hello World!\n";
	vector<pair<int, int>> points;
	string pairs;
	while (f >> pairs)
	{
	
		points.push_back(make_pair(int(pairs[1]-'0'), int(pairs[3]-'0')));
	}
	cout << nr_of_rectangles(points);
}


