#include <cctype>
#include <cstdio>
#include <string>

enum class Token {
    eof = -1,

    // CMDs yh boiii
    def_ = -2,
    extern_ = -3,

    // Primaries!
    identifier = -4,
    number = -5
};


// note: not best practice to have two globals but we run with it!
static std::string IdentifierStr;
static double NumVal = 0.0;


static Token gettok() {
    static int LastChar = ' ';

    // WS skipped
    while (LastChar != EOF && std::isspace(static_cast<unsigned char>(LastChar))) {
        LastChar = std::getchar();
    }

    if (LastChar == EOF) {
        return Token::eof;
    }

    if (std::isalpha(static_cast<unsigned char>(LastChar))) {
        IdentifierStr = static_cast<char>(LastChar);

        while (true) {
            LastChar = std::getchar();
            if (LastChar == EOF) break;

            if (std::isalnum(static_cast<unsigned char>(LastChar))) {
                IdentifierStr += static_cast<char>(LastChar);
            } else {
                break;
            }
        }

        if (IdentifierStr == "def")    return Token::def_;
        if (IdentifierStr == "extern") return Token::extern_;
        return Token::identifier;
    }
    
    // Add numerical parsing!

}

int main() {

    while (true) {
        Token t = gettok();

        if (t == Token::eof) break;

        if (t == Token::identifier) {
            std::printf("id token: %s\n", IdentifierStr.c_str());

        } else if (t == Token::number) {
            std::printf("no token: %f\n", NumVal);

        } else {
            std::printf("char token: %d\n", static_cast<int>(t));
        }
    }
}