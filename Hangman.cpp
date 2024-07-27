#include "Hangman.h"
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <random>
#include <chrono>
#include <ctype.h>

            Hangman::Hangman(const std::string& fileName) noexcept(false)
            {
                std::ifstream source(fileName,std::ios::in);
                if(!source)
                    throw std::runtime_error("Hangman can't read file with words!");
                while(source)
                {
                    std::string temp;
                    source>>temp;
                    if(source)
                        words.push_back(temp);
                }
            }


            void Hangman::executeHangman() const noexcept
            {
                std::string randomWord = words[chooseWord()];
                std::vector<bool> flags(randomWord.length(),false);
                unsigned int counter=0;

                std::cout<<"<<<<<<<<<<Welcome to Hangman!>>>>>>>>>>"<<std::endl<<std::endl;
                bool success=false;
                const int N=10;
                for(int i=1;!success && i<=N;i++)
                {
                    std::cout<<"Do you have any ideas:";
                    for(unsigned int i=0;i<flags.size();i++)
                        if(flags.at(i)==false)
                            std::cout<<'_'<<' ';
                        else
                            std::cout<<randomWord[i];

                    std::cout<<std::endl<<"Try with letter(1) or entire word(2)?";
                    char temp;
                    do
                    {
                        std::cin>>temp;
                    }while(temp!='1' && temp!='2');

                    if(temp=='1')
                    {
                        std::cout<<"Enter your character:";
                        char c;
                        do
                        {
                            std::cin>>c;
                        }while(!std::isalpha(c));
                        if(std::isupper(c))
                            c=std::tolower(c);

                        for(unsigned int i=0;i<randomWord.length();i++)
                            if(randomWord[i]==c && flags[i]==false)
                            {
                                ++counter;
                                flags[i].flip();
                            }
                        if(counter==randomWord.size())
                            success=true;
                    }
                    else
                    {
                        std::cout<<"Enter your word:";
                        std::string str;
                        std::cin>>str;
                        if(str==randomWord)
                            success=true;
                    }

                    std::cout<<"\n";
                }

                if(success)
                    std::cout<<"<<<<<<<<<<Congratulations!You did it!!!>>>>>>>>>>";
                else
                    std::cout<<"Better luck next time!It was the word:"<<randomWord;

                std::getchar();
                std::getchar();
            }


            Hangman::~Hangman() {}


            int Hangman::chooseWord() const noexcept
            {
                unsigned seed=std::chrono::steady_clock::now().time_since_epoch().count();
                std::default_random_engine myRandomEngine(seed);
                std::uniform_int_distribution<int> myUnifDist(0,words.size()-1);
                return myUnifDist(myRandomEngine);
            }

