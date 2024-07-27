#ifndef HANGMAN_H
#define HANGMAN_H

#include <string>
#include <vector>

            class Hangman
            {
                private:
                    std::vector<std::string> words;

                public:
                    Hangman(const std::string&) noexcept(false);
                    void executeHangman() const noexcept;
                    virtual ~Hangman();

                private:
                    int chooseWord() const noexcept;
            };

#endif // HANGMAN_H
