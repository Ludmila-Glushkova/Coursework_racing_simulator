#pragma once
#include <iostream>
#include <string>

namespace Race
{
	class Transport
	{
	public:
		void set_registered_transport(bool r_t);
		std::string get_transport_name();
		bool get_registered_transport();
		int get_transport_num();
		float get_race_time();
		float get_race_time_with_rest(Race::Transport* arr, float distance);
		float get_race_time_for_air(Race::Transport* arr, float distance);


	protected:
		bool registered_transport = false;
		std::string name = "";
		int speed = 0;
		float coef = 0;
		int transport_num = 0;
		float time_all = 0;
		float reduced_distance = 0;
		float time_rest_all = 0;
		float time_driving_all = 0;
		float last_part_dist = 0;
		int count_rest = 0;
		int time_before_rest = 0;
		int time_rest_1 = 0;
		int time_rest_2 = 0;
		int time_rest_then = 0;

	};
}