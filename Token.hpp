//
// Created by Lutfullin Ruslan on 16.05.16.
//

#ifndef LEXER_TOKEN_HPP
#define LEXER_TOKEN_HPP

#include <unordered_map>
#include <string>
using namespace std;

class Token {
 public:
  unordered_map<string, string> hashtable;

 public:
  Token() { };
  ~Token();

 public:
  void save(string type, string value);
  void print(string type, string value);

 public:
  friend class Lexer;
};


#endif //LEXER_TOKEN_HPP
