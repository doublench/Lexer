//
// Created by Lutfullin Ruslan on 16.05.16.
//

#ifndef LEXER_LEXER_HPP
#define LEXER_LEXER_HPP

#include <vector>
#include <string>
#include "Token.hpp"
using namespace std;

class Lexer {
 private:
  const int INITIAL_STATE = 1;
  const int BROKEN_STATE = 0;

 private:
  Token token;
  vector<int> states;
  string code;

 private:
  int lastPosition;
  int startPosition;
  int typeIndex;
  string type;

 private:
  int identifyKeyword1(int state, char c);
  int identifyKeyword2(int state, char c);
  int identifyKeyword3(int state, char c);

  int identifyConstantInteger(int state, char c);
  int identifyConstantReal(int state, char c);
  int identifyConstantCharacter(int state, char c);

  int identifyIdentifier(int state, char c);

  int identifySpecialSymbol(int state, char c);

  int identifyOperator(int state, char c);

 public:
  Lexer();
  ~Lexer() { };
  bool allBroken();

 public:
  void analyse();

};

#endif // LEXER_LEXER_HPP
