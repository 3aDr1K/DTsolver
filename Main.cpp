#include <iostream>
#include "matrix.h"
#include "AntagonisticGame.h"
int main(int argc, char** argv)
{
    //!!! �� ������ ����� ��������� ������, ������ ��� ����� ��������, ��� �� ��������
    setlocale(LC_ALL, "Russian");
	try {
		Matrix m1("test.txt");
        AntagonisticGame game(m1);

        game.computePrices();

        double lowerPrice = game.getLowerPrice();
        double upperPrice = game.getUpperPrice();

        std::cout << "������ ���� ����: " << lowerPrice << std::endl;
        std::cout << "������� ���� ����: " << upperPrice << std::endl;
        std::vector<std::pair<int, int>> equilibriumPoints = game.findEquilibriumPoints();
        if (!equilibriumPoints.empty()) {
            std::cout << "�������� �����:" << std::endl;
            for (const auto& point : equilibriumPoints) {
                std::cout << "u" << point.first + 1 << ", v" << point.second + 1 << std::endl;
            }
        }
        else {
            std::cout << "��� �������� �����." << std::endl;
        }
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return 0;
}