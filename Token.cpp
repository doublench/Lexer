//
// Created by Lutfullin Ruslan on 16.05.16.
//

#include "Token.hpp"
#include "vector"
#include <algorithm>
#include <iostream>
#include <fstream>
using namespace std;

Token::~Token() {
  fstream fout;
  fout.open("/Users/doublench/ClionProjects/Lexer/out.txt");

  for (auto it_ = hashtable.begin(), end_ = hashtable.end(); it_ != end_; ++it_)
    fout << (*it_).first << " " << "'" << (*it_).second << "'" << endl;

  fout.close();
  hashtable.clear();
}

void Token::save(string type, string value) {
  hashtable.insert({type, value});
}

void Token::print(string type, string value) {
  cout << type << " " << "'" << value << "'" << endl;
}