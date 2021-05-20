#include <iostream>
#include <random>
#include "Block.h"
#include "BlockChain.h"
#include <Windows.h>

double GetRandomDouble()
{
    static std::uniform_real_distribution<double> unif(1, 99999);
    static std::default_random_engine re;
    return unif(re);
}

int main()
{
    BlockChain pyraCoin{3};

    std::cout << "Press enter to add a block, ESC to exit\n";

    while (!(GetAsyncKeyState(VK_ESCAPE) & 0x1))
    {
        if (GetAsyncKeyState(VK_RETURN) & 0x1)
        {
            const std::string sender = "fromAddress";
            const std::string receiver = "toAddress";
            const double randomDouble = GetRandomDouble();

            Transaction tr{ sender, receiver, randomDouble };
            pyraCoin.CraftNewBlock(tr);

            // Don't judge, it's for testing
            system("cls");
            std::cout << pyraCoin;
        }

        Sleep(500);
    }

    std::cout << "Is BlockChain valid: " << (pyraCoin.IsChainValid() ? "Yes" : "No") << '\n';

    return 0;
}