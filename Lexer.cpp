//
// Created by Lutfullin Ruslan on 16.05.16.
//

#include "Lexer.hpp"
#include <fstream>
#include <iostream>
#include <cctype>
#include <algorithm>

int Lexer::identifyKeyword1(int state, char c) {
  switch (state) {
    case 1: {
      if (c == 'a')
        return 2;
      if (c == 'b')
        return 3;
      if (c == 'c')
        return 4;
      if (c == 'd')
        return 5;
      if (c == 'e')
        return 6;
      if (c == 'f')
        return 7;
      if (c == 'g')
        return 8;
      if (c == 'i')
        return 9;
      if (c == 'l')
        return 10;
      if (c == 'r')
        return 11;
      if (c == 's')
        return 12;
      if (c == 't')
        return 13;
      if (c == 'u')
        return 14;
      if (c == 'v')
        return 15;
      if (c == 'w')
        return 16;

      return BROKEN_STATE;
    }

    case 2: {
      if (c == 'u')
        return 14;
      if (c == 'k') // break
        return -1;
      if (c == 's')
        return 12;
      if (c == 'r') // char
        return -1;
      if (c == 't') // float
        return -1;

      return BROKEN_STATE;
    }

    case 3: {
      if (c == 'r')
        return 11;

      return BROKEN_STATE;
    }

    case 4: {
      if (c == 'a')
        return 2;
      if (c == 'h')
        return 17;
      if (c == 'o')
        return 18;
      if (c == 't') // struct
        return -1;

      return BROKEN_STATE;
    }

    case 5: {
      if (c == 'e')
        return 6;
      if (c == 'o') // do
        return -1;

      return BROKEN_STATE;
    }

    case 6: {
      if (c == 'l')
        return 10;
      if (c == 'n')
        return 19;
      if (c == 'x')
        return 20;
      if (c == 'a')
        return 2;
      if (c == 'f')
        return 7;
      if (c == 'r')
        return 11;
      if (c == 'g')
        return 8;
      if (c == 't')
        return 13;
      if (c == 'd') // unsigned
        return -1;
      if (c == 'o')
        return 18;

      return BROKEN_STATE;
    }

    case 7: {
      if (c == 'l')
        return 10;
      if (c == 'o')
        return 18;
      if (c == 'a')
        return 2;

      return BROKEN_STATE;
    }

    case 8: {
      if (c == 'o')
        return 18;
      if (c == 'i')
        return 9;
      if (c == 'n')
        return 19;

      return BROKEN_STATE;
    }

    case 9: {
      if (c == 'f') // if
        return -1;
      if (c == 'n')
        return 19;
      if (c == 's')
        return 12;
      if (c == 'l')
        return 10;
      if (c == 'd') // void
        return -1;
      if (c == 'o')
        return 18;
      if (c == 'g')
        return 8;
      if (c == 'z')
        return 23;

      return BROKEN_STATE;
    }

    case 10: {
      if (c == 'o')
        return 18;
      if (c == 't') // default
        return -1;
      if (c == 's')
        return 12;
      if (c == 'e') // while
        return -1;
      if (c == 'a')
        return 2;

      return BROKEN_STATE;
    }

    case 11: {
      if (c == 'e')
        return 6;
      if (c == 'u')
        return 14;
      if (c == 'n') // extern
        return -1;

      return BROKEN_STATE;
    }

    case 12: {
      if (c == 'h')
        return 17;
      if (c == 'i')
        return 9;
      if (c == 't')
        return 13;
      if (c == 'w')
        return 16;
      if (c == 'e') // case
        return -1;

      return BROKEN_STATE;
    }

    case 13: {
      if (c == 'y')
        return 21;
      if (c == 'o') // auto
        return -1;
      if (c == 't') // const
        return -1;
      if (c == 'i')
        return 9;
      if (c == 'e')
        return 6;
      if (c == 'u')
        return 14;
      if (c == 'r')
        return 11;

      return BROKEN_STATE;
    }

    case 14: {
      if (c == 'n')
        return 19;
      if (c == 't')
        return 13;
      if (c == 'e') // continue
        return -1;
      if (c == 'l')
        return 10;
      if (c == 'm') // enum
        return -1;
      if (c == 'r')
        return 11;
      if (c == 'c')
        return 4;

      return BROKEN_STATE;
    }

    case 15: {
      if (c == 'o')
        return 18;

      return BROKEN_STATE;
    }

    case 16: {
      if (c == 'h')
        return 17;

      return BROKEN_STATE;
    }

    case 17: { // h
      if (c == 'a')
        return 2;
      if (c == 'o')
        return 18;
      if (c == 'i')
        return 9;

      return BROKEN_STATE;
    }

    case 18: { // o
      if (c == 'n')
        return 19;
      if (c == 'a')
        return 2;
      if (c == 'r') // for
        return -1;
      if (c == 't')
        return 13;
      if (c == 'i')
        return 9;
      if (c == 'l')
        return 10;
      if (c == 'f') // sizeof
        return -1;

      return BROKEN_STATE;
    }

    case 19: { // n
      if (c == 's')
        return 13;
      if (c == 't')
        return 13;
      if (c == 'u')
        return 14;
      if (c == 'g') // long
        return -1;
      if (c == 'i')
        return 9;
      if (c == 'e')
        return 6;

      return BROKEN_STATE;
    }

    case 20: { // x
      if (c == 't')
        return 13;

      return BROKEN_STATE;
    }

    case 21: { // y
      if (c == 'p')
        return 22;

      return BROKEN_STATE;
    }

    case 22: { //
      if (c == 'e')
        return 6;

      return BROKEN_STATE;
    }

    case 23: { //
      if (c == 'e')
        return 6;

      return BROKEN_STATE;
    }

    default:
      return BROKEN_STATE;
  }
}

int Lexer::identifyKeyword2(int state, char c) {
  switch (state) {
    case 1: {
      if (c == 'a')
        return 2;
      if (c == 'b')
        return 3;
      if (c == 'c')
        return 4;
      if (c == 'd')
        return 5;
      if (c == 'e')
        return 6;
      if (c == 'f')
        return 7;
      if (c == 'g')
        return 8;
      if (c == 'i')
        return 9;
      if (c == 'l')
        return 10;
      if (c == 'r')
        return 11;
      if (c == 's')
        return 12;
      if (c == 't')
        return 13;
      if (c == 'u')
        return 14;
      if (c == 'v')
        return 15;
      if (c == 'w')
        return 16;

      return BROKEN_STATE;
    }

    case 2: {
      if (c == 't')
        return 13;

      return BROKEN_STATE;
    }

    case 3: {
      if (c == 'l')
        return 10;

      return BROKEN_STATE;
    }

    case 4: {
      if (c == 'h') // switch
        return -1;

      return BROKEN_STATE;
    }

    case 5: {
      if (c == 'o')
        return 18;

      return BROKEN_STATE;
    }

    case 6: {
      if (c == 'l')
        return 10;
      if (c == 'g')
        return 8;
      if (c == 't')
        return 13;
      if (c == 'd') // signed
        return -1;


      return BROKEN_STATE;
    }

    case 7: {


      return BROKEN_STATE;
    }

    case 8: {
      if (c == 'o')
        return 18;
      if (c == 'i')
        return 9;
      if (c == 'n')
        return 19;

      return BROKEN_STATE;
    }

    case 9: {
      if (c == 'n')
        return 19;
      if (c == 's')
        return 12;
      if (c == 'g')
        return 8;
      if (c == 'c') // static
        return -1;
      if (c == 't')
        return 13;
      if (c == 'o')
        return 18;

      return BROKEN_STATE;
    }

    case 10: {
      if (c == 'e') // double
        return -1;
      if (c == 's')
        return 12;
      if (c == 'a')
        return 2;

      return BROKEN_STATE;
    }

    case 11: {
      if (c == 'e')
        return 6;
      if (c == 'n') // return
        return -1;
      if (c == 't') // short
        return -1;

      return BROKEN_STATE;
    }

    case 12: {
      if (c == 'e') // else
        return -1;
      if (c == 'h')
        return 17;
      if (c == 'i')
        return 9;
      if (c == 't')
        return 13;
      if (c == 'w')
        return 16;

      return BROKEN_STATE;
    }

    case 13: {
      if (c == 'o') // goto
        return -1;
      if (c == 'u')
        return 14;
      if (c == 'a')
        return 2;
      if (c == 'i')
        return 9;
      if (c == 'c')
        return 4;
      if (c == 'y')
        return 21;

      return BROKEN_STATE;
    }

    case 14: {
      if (c == 'b')
        return 3;
      if (c == 'r')
        return 11;
      if (c == 'n')
        return 19;

      return BROKEN_STATE;
    }

    case 15: {
      if (c == 'o')
        return 18;

      return BROKEN_STATE;
    }

    case 16: {
      if (c == 'i')
        return 9;

      return BROKEN_STATE;
    }

    case 17: { // h
      if (c == 'o')
        return 18;


      return BROKEN_STATE;
    }

    case 18: { // o
      if (c == 'u')
        return 14;
      if (c == 't')
        return 13;
      if (c == 'r')
        return 11;
      if (c == 'n') // union
        return -1;
      if (c == 'l')
        return 10;

      return BROKEN_STATE;
    }

    case 19: { // n
      if (c == 't') // int
        return -1;
      if (c == 'e')
        return 6;
      if (c == 'i')
        return 9;


      return BROKEN_STATE;
    }

    case 20: { // x


      return BROKEN_STATE;
    }

    case 21: { // y
      if (c == 'p')
        return 22;

      return BROKEN_STATE;
    }

    case 22: { // p
      if (c == 'e')
        return 6;

      return BROKEN_STATE;
    }

    case 23: { //


      return BROKEN_STATE;
    }

    default:
      return BROKEN_STATE;
  }
}

int Lexer::identifyKeyword3(int state, char c) {
  switch (state) {
    case 1: {
      if (c == 'a')
        return 2;
      if (c == 'b')
        return 3;
      if (c == 'c')
        return 4;
      if (c == 'd')
        return 5;
      if (c == 'e')
        return 6;
      if (c == 'f')
        return 7;
      if (c == 'g')
        return 8;
      if (c == 'i')
        return 9;
      if (c == 'l')
        return 10;
      if (c == 'r')
        return 11;
      if (c == 's')
        return 12;
      if (c == 't')
        return 13;
      if (c == 'u')
        return 14;
      if (c == 'v')
        return 15;
      if (c == 'w')
        return 16;

      return BROKEN_STATE;
    }

    case 2: {
      if (c == 't')
        return 13;

      return BROKEN_STATE;
    }

    case 3: {


      return BROKEN_STATE;
    }

    case 4: {


      return BROKEN_STATE;
    }

    case 5: {
      if (c == 'e')
        return 6;


      return BROKEN_STATE;
    }

    case 6: {
      if (c == 'g')
        return 8;
      if (c == 'r') // register
        return -1;
      if (c == 'd')
        return 5;
      if (c == 'f') // typedef
        return -1;


      return BROKEN_STATE;
    }

    case 7: {


      return BROKEN_STATE;
    }

    case 8: {
      if (c == 'i')
        return 9;


      return BROKEN_STATE;
    }

    case 9: {
      if (c == 's')
        return 12;
      if (c == 'l')
        return 10;


      return BROKEN_STATE;
    }

    case 10: {
      if (c == 'a')
        return 2;
      if (c == 'e') // volatile
        return -1;


      return BROKEN_STATE;
    }

    case 11: {
      if (c == 'e')
        return 6;

      return BROKEN_STATE;
    }

    case 12: {
      if (c == 't')
        return 13;

      return BROKEN_STATE;
    }

    case 13: {
      if (c == 'e')
        return 6;
      if (c == 'y')
        return 21;
      if (c == 'i')
        return 9;


      return BROKEN_STATE;
    }

    case 14: {


      return BROKEN_STATE;
    }

    case 15: {
      if (c == 'o')
        return 18;

      return BROKEN_STATE;
    }

    case 16: {


      return BROKEN_STATE;
    }

    case 17: { // h



      return BROKEN_STATE;
    }

    case 18: { // o
      if (c == 'l')
        return 10;


      return BROKEN_STATE;
    }

    case 19: { // n



      return BROKEN_STATE;
    }

    case 20: { // x


      return BROKEN_STATE;
    }

    case 21: { // y
      if (c == 'p')
        return 22;


      return BROKEN_STATE;
    }

    case 22: { // p
      if (c == 'e')
        return 6;

      return BROKEN_STATE;
    }

    case 23: { //


      return BROKEN_STATE;
    }

    default:
      return BROKEN_STATE;
  }
}

int Lexer::identifyConstantInteger(int state, char c) {
  // [+|-]?[0-9]+[U|u]?[L|l|I|i]?
  switch (state) {
    case 1: {
      if (isdigit(c))
        return -3;
      if (c == '+' || c == '-')
        return 2;

      return BROKEN_STATE;
    }

    case 2: {
      if (isdigit(c))
        return -3;

      return BROKEN_STATE;
    }

    case -3: {
      if (isdigit(c))
        return -3;
      if (c == 'U' || c == 'u')
        return -4;
      if (c == 'I' || c == 'i' || c == 'L' || c == 'l')
        return -5;

      return BROKEN_STATE;
    }

    case -4: {
      if (c == 'U' || c == 'u')
        return -4;
      if (c == 'I' || c == 'i' || c == 'L' || c == 'l')
        return -5;

      return BROKEN_STATE;

    }

    case -5: {
      if (c == 'I' || c == 'i' || c == 'L' || c == 'l')
        return -5;

      return BROKEN_STATE;
    }

    default:
      return BROKEN_STATE;

  }
}

int Lexer::identifyConstantReal(int state, char c) {
  //[+|-]?[0-9]*.([0-9]*[E]?[0-9]+)*[L|l|F|f]?
  //[+|-]?[0-9]+E[L|l|F|f]?

  // -21.21L

  // -21.L
  // -21E-21L

  // -21.21E-21L
  // .21E-21L

  switch (state) {
    case 1: {
      if (isdigit(c))
        return 3;
      if (c == '+' || c == '-')
        return 2;
      if (c == '.')
        return 13;

      return BROKEN_STATE;
    }

    case 2: {
      if (isdigit(c))
        return 3;
      if (c == '.')
        return 13;

      return BROKEN_STATE;
    }

    case 3: {
      if (isdigit(c))
        return 3;
      if (c == '.')
        return -4;
      if (c == 'E' || c == 'e')
        return 10;

      return BROKEN_STATE;
    }

    case -4: {
      if (isdigit(c))
        return -5;
      if (c == 'F' || c == 'f' || c == 'L' || c == 'l')
        return -8;

      return BROKEN_STATE;
    }

    case -5: {
      if (isdigit(c))
        return -5;
      if (c == 'E' || c == 'e')
        return 6;
      if (c == 'F' || c == 'f' || c == 'L' || c == 'l')
        return -8;

      return BROKEN_STATE;
    }

    case 6: {
      if (c == '+' || c == '-')
        return 7;
      if (isdigit(c))
        return -8;

      return BROKEN_STATE;
    }

    case 7: {
      if (isdigit(c))
        return -8;

      return BROKEN_STATE;
    }

    case -8: {
      if (isdigit(c))
        return -8;
      if (c == 'F' || c == 'f' || c == 'L' || c == 'l')
        return -9;

      return BROKEN_STATE;

    }

    case -9: {
      if (c == 'F' || c == 'f' || c == 'L' || c == 'l')
        return -9;

      return BROKEN_STATE;
    }

    case 10: {
      if (c == '+' || c == '-')
        return 11;
      if (isdigit(c))
        return -12;

      return BROKEN_STATE;
    }

    case 11: {
      if (isdigit(c))
        return -12;


      return BROKEN_STATE;
    }

    case -12: {
      if (isdigit(c))
        return -12;
      if (c == 'F' || c == 'f' || c == 'L' || c == 'l')
        return -15;

      return BROKEN_STATE;
    }

    case 13: {
      if (isdigit(c))
        return -14;

      return BROKEN_STATE;
    }

    case -14: {
      if (isdigit(c))
        return -14;
      if (c == 'E' || c == 'e')
        return 6;

      return BROKEN_STATE;
    }

    case -15: {
      if (c == 'F' || c == 'f' || c == 'L' || c == 'l')
        return -15;

      return BROKEN_STATE;
    }

    default:
      return BROKEN_STATE;

  }
}

int Lexer::identifyConstantCharacter(int state, char c) {
  switch (state) {
    case 1: {
      if (c == '\'')
        return 2;
      if (c == '\"')
        return 5;

      return BROKEN_STATE;
    }

    case 2: {
      if (isascii(c))
        return 3;

      return BROKEN_STATE;
    }

    case 3: {
      if (c == '\'')
        return -4;

      return BROKEN_STATE;
    }

    case -4: {
      return BROKEN_STATE;
    }

    case 5: {
      if (isascii(c))
        return 6;
      if (c == '\"')
        return -7;

      return BROKEN_STATE;
    }

    case 6: {
      if (isascii(c))
        return 6;
      if (c == '\"')
        return -7;

      return BROKEN_STATE;
    }

    case -7: {
      return BROKEN_STATE;
    }

    default:
      return BROKEN_STATE;
  }
}

int Lexer::identifyIdentifier(int state, char c) {
  switch (state) {
    case 1: {
      if (isalpha(c))
        return -3;
      if (c == '_')
        return 2;

      return BROKEN_STATE;
    }

    case 2: {
      if (c == '_')
        return 2;
      if (isalpha(c))
        return -3;

      return BROKEN_STATE;

    }

    case -3: {
      if (c == '_')
        return -3;
      if (isalpha(c))
        return -3;
      if (isnumber(c))
        return -3;

      return BROKEN_STATE;
    }

    default:
      return BROKEN_STATE;
  }
}

int Lexer::identifySpecialSymbol(int state, char c) {
  switch (state) {
    case 1: {
      if (c == '\n' || c == '\t' || c == '\v' ||
          c == '\b' || c == '\r' || c == '\f' ||
          c == '\a' || c == '\'' || c == '\"' ||
          c == '\\')
        return -2;


      if (c == '~' || c == '!' || c == '#' ||
          c == '$' || c == '%' || c == '^' ||
          c == '&' || c == '*' || c == '(' ||
          c == ')')
        return -2;


      if (c == '_' || c == '+' || c == '|' ||
          c == '+' || c == '`' || c == ' ' ||
          c == '-' || c == '=' || c == '{' ||
          c == '}')
        return -2;


      if (c == '[' || c == ']' || c == ':' ||
          c == ';' || c == '<' || c == '>' ||
          c == '?' || c == ',' || c == '.' ||
          c == '/')
        return -2;

      return BROKEN_STATE;
    }

    case -2: {
      if (c == '\n' || c == '\t' || c == '\v' ||
          c == '\b' || c == '\r' || c == '\f' ||
          c == '\a' || c == '\'' || c == '\"' ||
          c == '\\')
        return -2;


      if (c == '~' || c == '!' || c == '#' ||
          c == '$' || c == '%' || c == '^' ||
          c == '&' || c == '*' || c == '(' ||
          c == ')')
        return -2;


      if (c == '_' || c == '+' || c == '|' ||
          c == '+' || c == '`' || c == ' ' ||
          c == '-' || c == '=' || c == '{' ||
          c == '}')
        return -2;


      if (c == '[' || c == ']' || c == ':' ||
          c == ';' || c == '<' || c == '>' ||
          c == '?' || c == ',' || c == '.' ||
          c == '/')
        return -2;

      return BROKEN_STATE;

    }

    default:
      return BROKEN_STATE;
  }
}

int Lexer::identifyOperator(int state, char c) {
  switch (state) {
    case 1: {
      if (c == '_' || isalpha(c) || isnumber(c))
        return 2;

      return BROKEN_STATE;
    }

    case 2: {
      if (isspace(c))
        return 3;

      return BROKEN_STATE;
    }

    case 3: {
      if (c == '+' || c == '=' || c == '-' ||
          c == '*' || c == '/' || c == '%')
        return 4;
      if (isspace(c))
        return 3;

      return BROKEN_STATE;
    }

    case 4: {
      if (isspace(c))
        return 5;

      return BROKEN_STATE;
    }

    case 5: {
      if (isspace(c))
        return 5;
      if (c == '_' || isalpha(c))
        return -6;

      return BROKEN_STATE;
    }

    case -6: {
      return BROKEN_STATE;
    }

    default:
      return BROKEN_STATE;
  }
} // TODO NonSpaces a+b a/b ...

Lexer::Lexer() {
  states.resize(9);
  for (int i = 0; i < 9; ++i)
    states[i] = INITIAL_STATE;

  fstream fin;
  fin.open("/Users/doublench/ClionProjects/Lexer/in.txt");
  while (!fin.eof()) {
    char ch = fin.get();
    code.push_back(ch);
  }

  fin.close();
  code.pop_back();
  code.push_back('\0');


  startPosition = 0;
}

bool Lexer::allBroken() {
  for (int l = 0; l < 9; ++l)
    if (states[l] != 0)
      return false;

  return true;
}

void Lexer::analyse() {
  for (int i = 0; i < code.size() -1; ++i) {

    states[0] = identifyKeyword1(states[0], code[i]);
    states[1] = identifyKeyword2(states[1], code[i]);
    states[2] = identifyKeyword3(states[2], code[i]);
    states[3] = identifyConstantInteger(states[3], code[i]);
    states[4] = identifyConstantReal(states[4], code[i]);
    states[5] = identifyConstantCharacter(states[5], code[i]);
    states[6] = identifyIdentifier(states[6], code[i]);
    states[7] = identifySpecialSymbol(states[7], code[i]);
    states[8] = identifyOperator(states[8], code[i]);

    for (int k = 0; k < 9; ++k)
      if (states[k] < 0) {
        lastPosition = i + 1;
        typeIndex = k;
        break;
      }

    if (typeIndex == 0 || typeIndex == 1 || typeIndex == 2)
      type = "Keyword";
    if (typeIndex == 3)
      type = "ConstantInt";
    if (typeIndex == 4)
      type = "ConstantReal";
    if (typeIndex == 5)
      type = "ConstantCharacter";
    if (typeIndex == 6)
      type = "Identifier";
    if (typeIndex == 7)
      type = "Symbol";
    if (typeIndex == 8)
      type = "Operator";


    if (allBroken()) {
      token.print(type, code.substr(startPosition, lastPosition - startPosition));
      token.save(type, code.substr(startPosition, lastPosition - startPosition));

      i--;
      for (int j = 0; j < 9; ++j)
        states[j] = INITIAL_STATE;

      startPosition = i + 1;

    }

  }

}