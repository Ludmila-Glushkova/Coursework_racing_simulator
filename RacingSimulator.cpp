#include "RacingSimulator.h"

int print_choose(int type)
{
    std::cout << "1. Гонка для наземного транспорта" << std::endl;
    std::cout << "2. Гонка для воздушного транспорта" << std::endl;
    std::cout << "3. Гонка для наземного и воздушного транспорта" << std::endl;
    std::cout << "Выберите тип гонки: ";
    std::cin >> type;

    return type;
}

bool check_correct_type_race(int type)
{
    if (type == static_cast <int>(TypeRace::Ground))
    {
        std::cout << "Вы выбрали Гонку для наземного транспорта" << std::endl;
        return true;
    }
    else if (type == static_cast <int>(TypeRace::Air))
    {
        std::cout << "Вы выбрали Гонку для воздушного транспорта" << std::endl;
        return true;
    }
    else if (type == static_cast <int>(TypeRace::GroundAndAir))
    {
        std::cout << "Вы выбрали Гонку для наземного и воздушного транспорта" << std::endl;
        return true;
    }
    else
    {
        std::cout << "Вы выбрали несуществующий тип гонки" << std::endl;
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
    std::cout << "1. Провести еще одну гонку." << std::endl;
    std::cout << "2. Выйти" << std::endl;
    std::cout << "Выберите действие: ";
    std::cin >> tmp;

    if (tmp != 1 && tmp != 2)
    {
        do
        {
            std::cout << "Можно выбрать только 1 или 2, попробуйте еще раз:  ";
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
            std::cout << "Вы пытаетесь зарегистрировать уже зарегистрированное ТС." << std::endl;
            std::cout << "Выберите ТС (0 - для выхода): ";
            return false;
        }
    }
}

int print_transport_reg(int type, int type_transp, int count_reg, bool* flag, Race::Transport* arr, const int ik)
{
    if (count_reg != 0)
    {
        std::cout << "Зарегистрированные транспортные средства: " << std::endl;
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
        std::cout << std::endl << "Зарегистрируйте транспортные средства: " << std::endl;
        std::cout << "1. Верблюд" << std::endl;
        std::cout << "2. Верблюд-скороход" << std::endl;
        std::cout << "3. Кентавр" << std::endl;
        std::cout << "4. Ботинки-вездеходы" << std::endl;
        break;
    case static_cast<int>(TypeRace::Air):
        std::cout << std::endl << "Зарегистрируйте транспортные средства: " << std::endl;
        std::cout << "1. Ковёр-самолёт" << std::endl;
        std::cout << "2. Орёл" << std::endl;
        std::cout << "3. Метла" << std::endl;
        break;
    case static_cast<int>(TypeRace::GroundAndAir):
        std::cout << std::endl << "Зарегистрируйте транспортные средства: " << std::endl;
        std::cout << "1. Верблюд" << std::endl;
        std::cout << "2. Верблюд-скороход" << std::endl;
        std::cout << "3. Кентавр" << std::endl;
        std::cout << "4. Ботинки-вездеходы" << std::endl;
        std::cout << "5. Ковёр-самолёт" << std::endl;
        std::cout << "6. Орёл" << std::endl;
        std::cout << "7. Метла" << std::endl;
        break;
    default:
        std::cout << "Ошибка регистрации транспортного средства" << std::endl;
        break;
    }

    if (count_reg < 2)
    {
        std::cout << "Выберите транспортное средство (минимум два): " << std::endl;
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
        std::cout << "0. Закончить регистрацию и начать гонку" << std::endl;
        std::cout << "Выберите ещё транспортное средство (либо закончить регистрацию и начать гонку): ";

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
            std::cout << std::endl << "Регистрация окончена" << std::endl;

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
