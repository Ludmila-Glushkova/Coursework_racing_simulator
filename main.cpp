#include <iostream>
#include <string>
#include <limits>
#include "RacingSimulator.h"
#include "Transport/Racers.h"

void win(Race::Transport* arr, const int arr_size)
{
	Race::Transport tmp;
	std::cout << std::endl;
	for (int i = 1; i < arr_size - 1; ++i)
	{
		for (int j = i - 1; j >= 0; --j)
		{
			if (arr[j].get_race_time() > arr[j + 1].get_race_time())
			{
				std::swap(*(arr + j), *(arr + j + 1));
			}
		}
	}
	
	std::cout << "���������� �����:" << std::endl;
	int r = 1;

	for (int i = 0; i < arr_size; i++)
	{
		if (arr[i].get_race_time() != 0)
		{
			std::cout << r << ". " << arr[i].get_transport_name() << ". �����: " << arr[i].get_race_time() << std::endl;
			r++;
		}
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	int type = 0;
	float distance = 0;

	do
	{
		std::cout << "����� ���������� � �������� ���������!" << std::endl;
		type = choose_race();

		do
		{
			std::cout << "������� ����� ��������� (������ ���� ������������), ��: ";
			std::cin >> distance;
			if (distance <= 0)
			{
				std::cout << "��������� ������ ���� ������ 0." << std::endl;
			}
		} while (distance <= 0);

		Race::Transport arr[arr_size]{};

		switch (type)
		{
		case static_cast<int>(TypeRace::Ground):
			std::cout << std::endl << "�� ������� ����� ��� ��������� ����������. ����������: " << distance << std::endl;
			transport_reg(type, distance, arr, arr_size);
			break;
		case static_cast<int>(TypeRace::Air):
			std::cout << std::endl << "�� ������� ����� ��� ���������� ����������. ����������: " << distance << std::endl;
			transport_reg(type, distance, arr, arr_size);
			break;
		case static_cast<int>(TypeRace::GroundAndAir):
			std::cout << std::endl << "�� ������� ����� ��� ��������� � ���������� ����������. ����������: " << distance << std::endl;
			transport_reg(type, distance, arr, arr_size);
			break;
		default:
			std::cout << "�� ������� �������������� �����." << std::endl << std::endl;
			break;
		}
		std::cout << "����� ���������������� ������� ��� ������������ ��������!" << std::endl;
		std::cout << "������������������ ������������ ��������: ";

		for (int i = 0; i < arr_size; i++)
		{
			if (arr[i].get_registered_transport() == true)
			{
				if (i != 0 && i != (arr_size - 1))
				{
					std::cout << ", ";
				}
				std::cout << arr[i].get_transport_name();
			}
		}
		win(arr, arr_size);
		std::cout << std::endl;
	} while (!game_over());
};