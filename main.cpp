#include <iostream>
#include "Hangman.h"

            const std::string fileName("Words.txt");
            int main()
            {
                try
                {
                    Hangman game(fileName);
                    game.executeHangman();
                }
                catch(const std::exception& ex)
                {
                    std::cout<<ex.what();
                }

                return 0;
            }
