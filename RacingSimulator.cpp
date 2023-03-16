#include "RacingSimulator.h"

int print_choose(int type)
{
    std::cout << "1. ����� ��� ��������� ����������" << std::endl;
    std::cout << "2. ����� ��� ���������� ����������" << std::endl;
    std::cout << "3. ����� ��� ��������� � ���������� ����������" << std::endl;
    std::cout << "�������� ��� �����: ";
    std::cin >> type;

    return type;
}

bool check_correct_type_race(int type)
{
    if (type == static_cast <int>(TypeRace::Ground))
    {
        std::cout << "�� ������� ����� ��� ��������� ����������" << std::endl;
        return true;
    }
    else if (type == static_cast <int>(TypeRace::Air))
    {
        std::cout << "�� ������� ����� ��� ���������� ����������" << std::endl;
        return true;
    }
    else if (type == static_cast <int>(TypeRace::GroundAndAir))
    {
        std::cout << "�� ������� ����� ��� ��������� � ���������� ����������" << std::endl;
        return true;
    }
    else
    {
        std::cout << "�� ������� �������������� ��� �����" << std::endl;
        return false;
    }
}

int choose_race()
{
    int type = 0;
    do
    {
        type = print_choose(type);
        while (!std::cin.good())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            type = print_choose(type);
        };
        std::cout << std::endl;
    } while (!check_correct_type_race(type));
    return type;
}

bool game_over()
{
    int tmp = 0;
    std::cout << "1. �������� ��� ���� �����." << std::endl;
    std::cout << "2. �����" << std::endl;
    std::cout << "�������� ��������: ";
    std::cin >> tmp;

    if (tmp != 1 && tmp != 2)
    {
        do
        {
            std::cout << "����� ������� ������ 1 ��� 2, ���������� ��� ���:  ";
            std::cin >> tmp;
        } while (!(tmp == 1 || tmp == 2));
    };
    if (tmp != 2)
    {
        return false;
    }
    return true;
}

void transport_reg(int type, float distance, Race::Transport* arr, const int ik)
{
    bool flag = false;
    int type_transp = 0;
    int count_reg = 0;
    do
    {
        type_transp = print_transport_reg(type, type_transp, count_reg, &flag, arr, ik);
        if (type_transp == static_cast<int>(TypeTransport::Camel))
        {
            Race::Camel Camel;
            Camel.set_registered_transport(true);
            Camel.get_race_time_with_rest(&Camel, distance);
            arr[count_reg] = Camel;
            count_reg++;
        }
        else if (type_transp == static_cast<int>(TypeTransport::CamelFast))
        {
            Race::CamelFast CamelFast;
            CamelFast.set_registered_transport(true);
            CamelFast.get_race_time_with_rest(&CamelFast, distance);
            arr[count_reg] = CamelFast;
            count_reg++;
        }
        else if (type_transp == static_cast<int>(TypeTransport::Centaur))
        {
            Race::Centaur Centaur;
            Centaur.set_registered_transport(true);
            Centaur.get_race_time_with_rest(&Centaur, distance);
            arr[count_reg] = Centaur;
            count_reg++;
        }
        else if (type_transp == static_cast<int>(TypeTransport::AllTerrainBoots))
        {
            Race::AllTerrainBoots AllTerrainBoots;
            AllTerrainBoots.set_registered_transport(true);
            AllTerrainBoots.get_race_time_with_rest(&AllTerrainBoots, distance);
            arr[count_reg] = AllTerrainBoots;
            count_reg++;
        }
        else if (type_transp == static_cast<int>(TypeTransport::MagicCarpet))
        {
            Race::MagicCarpet MagicCarpet;
            MagicCarpet.set_registered_transport(true);
            MagicCarpet.get_race_time_with_rest(&MagicCarpet, distance);
            arr[count_reg] = MagicCarpet;
            count_reg++;
        }
        else if (type_transp == static_cast<int>(TypeTransport::Eagle))
        {
            Race::Eagle Eagle;
            Eagle.set_registered_transport(true);
            Eagle.get_race_time_with_rest(&Eagle, distance);
            arr[count_reg] = Eagle;
            count_reg++;
        }
        else if (type_transp == static_cast<int>(TypeTransport::Broomstick))
        {
            Race::Broomstick Broomstick;
            Broomstick.set_registered_transport(true);
            Broomstick.get_race_time_with_rest(&Broomstick, distance);
            arr[count_reg] = Broomstick;
            count_reg++;
        }
    } while (!flag);
}

bool check_transp_reg(int type_transp, Race::Transport* arr, const int ik)
{
    for (int i = 0; i < ik; i++)
    {
        if (type_transp == 0)
        {
            return true;
        }
        if (arr[i].get_transport_num() == type_transp)
        {
            std::cout << "�� ��������� ���������������� ��� ������������������ ��." << std::endl;
            std::cout << "�������� �� (0 - ��� ������): ";
            return false;
        }
    }
}

int print_transport_reg(int type, int type_transp, int count_reg, bool* flag, Race::Transport* arr, const int ik)
{
    if (count_reg != 0)
    {
        std::cout << "������������������ ������������ ��������: " << std::endl;
        for (int i = 0; i < ik; i++)
        {
            if (i != 0 && i != (ik - 1))
            {
                std::cout << ", ";
            }
            std::cout << arr[i].get_transport_name();
        }
    }
    switch (type)
    {
    case static_cast<int>(TypeRace::Ground):
        std::cout << std::endl << "��������������� ������������ ��������: " << std::endl;
        std::cout << "1. �������" << std::endl;
        std::cout << "2. �������-��������" << std::endl;
        std::cout << "3. �������" << std::endl;
        std::cout << "4. �������-���������" << std::endl;
        break;
    case static_cast<int>(TypeRace::Air):
        std::cout << std::endl << "��������������� ������������ ��������: " << std::endl;
        std::cout << "1. ����-������" << std::endl;
        std::cout << "2. ���" << std::endl;
        std::cout << "3. �����" << std::endl;
        break;
    case static_cast<int>(TypeRace::GroundAndAir):
        std::cout << std::endl << "��������������� ������������ ��������: " << std::endl;
        std::cout << "1. �������" << std::endl;
        std::cout << "2. �������-��������" << std::endl;
        std::cout << "3. �������" << std::endl;
        std::cout << "4. �������-���������" << std::endl;
        std::cout << "5. ����-������" << std::endl;
        std::cout << "6. ���" << std::endl;
        std::cout << "7. �����" << std::endl;
        break;
    default:
        std::cout << "������ ����������� ������������� ��������" << std::endl;
        break;
    }

    if (count_reg < 2)
    {
        std::cout << "�������� ������������ �������� (������� ���): " << std::endl;
        do
        {
            std::cin >> type_transp;
            if (type == 2 && type_transp != 0)
            {
                type_transp += 4;
            };
        } while (!check_transp_reg(type_transp, arr, ik));
        return type_transp;
    }
    else if (count_reg >= 2)
    {
        std::cout << "0. ��������� ����������� � ������ �����" << std::endl;
        std::cout << "�������� ��� ������������ �������� (���� ��������� ����������� � ������ �����): ";

        do
        {
            std::cin >> type_transp;
            if (type_transp != 0 && type == 2)
            {
                type_transp += 4;
            };
        } while (!check_transp_reg(type_transp, arr, ik));

        if (type_transp == 0)
        {
            std::cout << std::endl << "����������� ��������" << std::endl;

            *flag = true;
            return type_transp;
        }
        return type_transp;
    }
    else
    {
       return type_transp;
    }
}
