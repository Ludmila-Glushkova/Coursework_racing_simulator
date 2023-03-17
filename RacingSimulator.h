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
	Centaur = 1, Camel, CamelFast, AllTerrainBoots,
	MagicCarpet, Broomstick, Eagle
};

const int arr_size = 8;
int print_choose(int type);
int choose_race();
bool game_over();
bool check_transp_reg(int type_transp, Race::Transport* arr, const int arr_size);
int print_transport_reg(int type, int type_transp, int count_reg, bool* flag, Race::Transport* arr, const int arr_size);
void transport_reg(int type, float distance, Race::Transport* arr, const int arr_size);
