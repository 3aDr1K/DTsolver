#include <iostream>
#include "matrix.h"
#include "AntagonisticGame.h"
int main(int argc, char** argv)
{
    //!!! Всё отсюда будет адекватно убрано, сейчас тут чисто проверка, что всё работает
    setlocale(LC_ALL, "Russian");
	try {
		Matrix m1("test.txt");
        AntagonisticGame game(m1);

        game.computePrices();

        double lowerPrice = game.getLowerPrice();
        double upperPrice = game.getUpperPrice();

        std::cout << "Нижняя цена игры: " << lowerPrice << std::endl;
        std::cout << "Верхняя цена игры: " << upperPrice << std::endl;
        std::vector<std::pair<int, int>> equilibriumPoints = game.findEquilibriumPoints();
        if (!equilibriumPoints.empty()) {
            std::cout << "Седловые точки:" << std::endl;
            for (const auto& point : equilibriumPoints) {
                std::cout << "u" << point.first + 1 << ", v" << point.second + 1 << std::endl;
            }
        }
        else {
            std::cout << "Нет седловых точек." << std::endl;
        }
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return 0;
}