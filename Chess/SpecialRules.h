#pragma once

#include<iostream>
#include<vector>

#include"Piece.h"

using namespace std;
class SpecialRules
{
	
public:
	static void pawnPromotion(char playerNo, vector<Piece*>& piece, int pawnIndex);
};

