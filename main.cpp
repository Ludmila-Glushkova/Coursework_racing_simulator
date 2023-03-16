#include <iostream>
#include <string>
#include <limits>
#include "RacingSimulator.h"
#include "Transport/Racers.h"

void arr_win(Race::Transport* arr, const int ik)
{
	Race::Transport tmp;
	std::cout << std::endl;
	bool swapped = false;
	do
	{
		swapped = false;
		for (int i = ik - 1; i > 0; i--)
		{
			if (arr[i - 1].get_race_time() > arr[i].get_race_time())
			{
				tmp = arr[i];
				arr[i] = arr[i - 1];
				arr[i - 1] = tmp;
				swapped = true;
			}
		}
	} while (swapped);

	std::cout << "���������� �����:" << std::endl;
	int k = 1;

	for (int i = 0; i < ik; i++)
	{
		if (arr[i].get_race_time() != 0)
		{
			std::cout << k << ". ";
			std::cout << arr[i].get_transport_name() << ". �����: " << arr[i].get_race_time() << std::endl;
			k++;
		}
	} std::cout << std::endl;
};

int main()
{
	setlocale(LC_ALL, "Russian");
	system("chcp 1251");

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

			while (!std::cin.good())
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "����� - �������� �������������� ������������ �����, ���������� � ������" << std::endl;
				std::cout << "������� ����� ��������� (������ ���� ������������), ��: ";
				std::cin >> distance;
			};

			std::cout << std::endl;
			if (distance < 0)
			{
				std::cout << "�� ����� ������������� �������� �����, �" << std::endl;
			}
		} while (distance <= 0);

		std::cout << "��������: ������ ���� ���������������� ������� ��� ������������ ��������!" << std::endl;

		const int ik = 8;

		Race::Transport arr[ik]{};

		switch (type)
		{
		case static_cast<int>(TypeRace::Ground):
			std::cout << std::endl << "**********************************************************" << std::endl;
			std::cout << std::endl << "�� ������� 1. ����� ��� ��������� ����������. ����������: " << distance << std::endl;
			transport_reg(type, distance, arr, ik);
			break;
		case static_cast<int>(TypeRace::Air):
			std::cout << std::endl << "**********************************************************" << std::endl;
			std::cout << std::endl << "�� ������� 2. ����� ��� ���������� ����������. ����������: " << distance << std::endl;
			transport_reg(type, distance, arr, ik);
			break;
		case static_cast<int>(TypeRace::GroundAndAir):
			std::cout << std::endl << "**********************************************************" << std::endl;
			std::cout << std::endl << "�� ������� 3. ����� ��� ��������� � ���������� ����������. ����������: " << distance << std::endl;
			transport_reg(type, distance, arr, ik);
			break;
		default:
			std::cout << "�� ������� �������������� �����." << std::endl << std::endl;
			break;
		}

		std::cout << "������������������ ������������ ��������: ";

		for (int i = 0; i < ik; i++)
		{
			if (arr[i].get_registered_transport() == true)
			{
				if (i != 0 && i != (ik - 1))
				{
					std::cout << ", ";
				}
				std::cout << arr[i].get_transport_name();
			}
		}
		arr_win(arr, ik);
		std::cout << std::endl << std::endl;
	} while (!game_over());
};