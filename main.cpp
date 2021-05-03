#include <cstdlib>
#include <functional>
#include <iostream>
#include <vector>

#define SPELL_MAX 16

#define LENGTH 25
#define VAL_MAX LENGTH - 1

#define EXPRESSION1(x, y) ((x < y) ? ". " : "# ")
#define EXPRESSION2(x, y) ((x == y) ? "# " : ". ")
#define EXPRESSION3(x, y) ((x + y == VAL_MAX) ? "# " : ". ")
#define EXPRESSION4(x, y) ((x + y < VAL_MAX + 6) ? "# " : ". ")
#define EXPRESSION5(x, y) ((x == y * 2 || x == y * 2 + 1) ? "# " : ". ")
#define EXPRESSION6(x, y) ((x <= 10 || y <= 10) ? "# " : ". ")
#define EXPRESSION7(x, y) ((x >= 16 && y >= 16) ? "# " : ". ")
#define EXPRESSION8(x, y) ((!x || !y) ? "# " : ". ")
#define EXPRESSION9(x, y) ((y >= 11 + x || x >= 11 + y) ? "# " : ". ")
#define EXPRESSION10(x, y) ((x >= y + 1 && x - y <= y + 1) ? "# " : ". ")
#define EXPRESSION11(x, y) ((x == 1 || y == 1 || x == VAL_MAX - 1 || y == VAL_MAX - 1) ? "# " : ". ")
#define EXPRESSION13(x, y) ((x < 20 - y) || (x + y > 28) ? ". " : "# ")
#define EXPRESSION18(x, y) ((x > 1 && y > 1 || (x == 0 && y == 0)) ? ". " : "# ")
#define EXPRESSION19(x, y) ((x * y == 0 || x == VAL_MAX || y == VAL_MAX) ? "# " : ". ")
#define EXPRESSION20(x, y) ((x + y) % 2 ? ". " : "# ")
#define EXPRESSION25(x, y) (!(x % 6) || !(y % 6) ? "# " : ". ")

#define MAKE_EXPRESSION(N) std::make_pair(N, [](int x, int y) { std::cout << (EXPRESSION##N(x, y)); })

int main()
{
    const std::vector<std::pair<std::uint8_t, std::function<void(int, int)>>> expressions = {
        MAKE_EXPRESSION(1),  MAKE_EXPRESSION(2),  MAKE_EXPRESSION(3),  MAKE_EXPRESSION(4),  MAKE_EXPRESSION(5),  MAKE_EXPRESSION(6),
        MAKE_EXPRESSION(7),  MAKE_EXPRESSION(8),  MAKE_EXPRESSION(9),  MAKE_EXPRESSION(10), MAKE_EXPRESSION(11), MAKE_EXPRESSION(13),
        MAKE_EXPRESSION(18), MAKE_EXPRESSION(19), MAKE_EXPRESSION(20), MAKE_EXPRESSION(25)
    };

    auto N{ 0 };
    do {
        system("clear");
        std::cout << static_cast<int>(expressions[N].first) << ": \n\n";
        for (auto y = 0; y < LENGTH; ++y) {
            for (auto x = 0; x < LENGTH; ++x) {
                expressions[N].second(x, y);
            }
            std::cout << std::endl;
        }
        std::cout << std::endl << "Press <Enter> to next spell or <Ctrl+C> to exit" << std::endl;
        if (++N == SPELL_MAX) {
            N = 0;
        }

    } while (std::cin.get());

    return 0;
}
