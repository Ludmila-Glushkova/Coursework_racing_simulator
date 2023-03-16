#pragma once
#include <iostream>
#include "Transport/Transport.h"
#include "Transport/Racers.h"


enum class TypeRace
{
	Ground = 1, Air, GroundAndAir
};

enum class TypeTransport
{
	Camel = 1, CamelFast, Centaur, AllTerrainBoots,
	MagicCarpet, Eagle, Broomstick
};

int print_choose(int type);
bool check_correct_type_race(int type);
int choose_race();
bool game_over();
bool check_transp_reg(int type_transp, Race::Transport* arr, const int ik);
int print_transport_reg(int type, int type_transp, int count_reg, bool* flag, Race::Transport* arr, const int ik);
void transport_reg(int type, float distance, Race::Transport* arr, const int ik);
