#include <iostream>

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }

    for (int i = 1; i < argc; i++) // argv[0]はプログラム名なので1から開始
    {
        for (int j = 0; argv[i][j]; j++) // 文字列の各文字を処理
        {
            std::cout << (char)std::toupper(argv[i][j]);
        }
        if (i < argc - 1)
        {
            std::cout << " "; // 引数間にスペースを追加
        }
    }
    std::cout << std::endl;

    return 0;
}