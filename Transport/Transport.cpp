#include "Transport.h"

namespace Race
{
	void Transport::set_registered_transport(bool r_t)
	{
		registered_transport = r_t;
	}

	std::string Transport::get_transport_name()
	{
		return name;
	}

	bool Transport::get_registered_transport()
	{
		return registered_transport;
	}

	int Transport::get_transport_num()
	{
		return transport_num;
	}

	float Transport::get_race_time()
	{
		return time_all;
	}

	float Transport::get_race_time_for_air(Race::Transport* arr, float distance)
	{
		if (speed == 8)
		{
			coef = static_cast <float>(0.94); //-6%
			reduced_distance = distance * coef;
		}
		else if (speed == 20)
		{
			coef = 1 - (static_cast<float>((static_cast<int>(distance / 1000))) / 100);
			reduced_distance = distance * coef;
		}
		else if (speed == 10)
		{
			if (distance < 1000)
			{
				coef = 1;
			}
			else if (distance >= 1000 && distance < 5000)
			{
				coef = static_cast <float>(0.97);
			}
			else if (distance >= 5000 && distance < 10000)
			{
				coef = static_cast <float>(0.9);
			}
			else if (distance >= 10000)
			{
				coef = static_cast <float>(0.95);
			}
			reduced_distance = distance * coef;
		}

		time_all = reduced_distance / speed;

		return time_all;
	}

	float Transport::get_race_time_with_rest(Race::Transport* arr, float distance)
	{
		float distance_traveled_to_rest = static_cast<float>(speed * time_before_rest);
		int amount_of_rest = static_cast<int>(distance / distance_traveled_to_rest);
		last_part_dist = distance - amount_of_rest * distance_traveled_to_rest;

		if (amount_of_rest == 0)
		{
			time_rest_all = 0;
		}
		else if (amount_of_rest == 1)
		{
			time_rest_all = time_rest_1;
		}
		else if (amount_of_rest == 2)
		{
			time_rest_all = time_rest_1 + time_rest_2;
		}
		else
		{
			if (last_part_dist == 0)
			{
				time_rest_all = (amount_of_rest - 2) * time_rest_then + time_rest_1;
			}
			else
			{
				time_rest_all = (amount_of_rest - 2) * time_rest_then + time_rest_1 + time_rest_2;
			}
		}

		//time_driving_all = distance / speed;
		time_driving_all = time_before_rest * amount_of_rest + last_part_dist / speed;
		time_all = time_driving_all + time_rest_all;

		return time_all;
	}
}