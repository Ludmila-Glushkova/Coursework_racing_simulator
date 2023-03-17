#include "Racers.h"

namespace Race
{
	Centaur::Centaur()
	{
		Transport::name = "Кентавр";
		Transport::speed = 15;
		Transport::time_before_rest = 8;
		Transport::time_rest_1 = 2;
		Transport::time_rest_2 = 2;
		Transport::time_rest_then = 2;
		Transport::transport_num = 1;
	};

	Camel::Camel()
	{
		Transport::name = "Верблюд";
		Transport::speed = 10;
		Transport::time_before_rest = 30;
		Transport::time_rest_1 = 5;
		Transport::time_rest_2 = 8;
		Transport::time_rest_then = 8;
		Transport::transport_num = 2;
	};

	CamelFast::CamelFast()
	{
		Transport::name = "Верблюд-быстроход";
		Transport::speed = 40;
		Transport::time_before_rest = 10;
		Transport::time_rest_1 = 5;
		Transport::time_rest_2 = 6.5;
		Transport::time_rest_then = 8;
		Transport::transport_num = 3;
	};

	AllTerrainBoots::AllTerrainBoots()
	{
		Transport::name = "Ботинки-вездеходы";
		Transport::speed = 6;
		Transport::time_before_rest = 60;
		Transport::time_rest_1 = 10;
		Transport::time_rest_2 = 5;
		Transport::time_rest_then = 5;
		Transport::transport_num = 4;
	};

	MagicCarpet::MagicCarpet()
	{
		Transport::name = "Ковёр-самолёт";
		Transport::speed = 10;
		Transport::transport_num = 5;
	};

	Broomstick::Broomstick()
	{
		Transport::name = "Метла";
		Transport::speed = 20;
		Transport::transport_num = 6;
	};
	
	Eagle::Eagle()
	{
		Transport::name = "Орёл";
		Transport::speed = 8;
		Transport::transport_num = 7;
	};
}