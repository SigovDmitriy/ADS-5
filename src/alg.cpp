// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

int priority(char ch) {
  if (ch == '(') {
    return 0;
  }
  if (ch == ')') {
    return 1;
  }
  if (ch == '+' || ch == '-') {
    return 2;
  }
  if (ch == '*' || ch == '/') {
    return 3;
  }
  return -1;
}

std::string infx2pstfx(std::string inf) {
  TStack <char, 100> stck1;
  std::string ps;
  for (int k = 0; k < inf.size(); k++) {
    int prir = priority(inf[k]);
    if (prir == -1) {
      if (!ps.empty() && priority(inf[k-1]) != -1) {
        ps.push_back(' ');
      }
      ps.push_back(inf[k]);
    } else if (prir == 0 || prir > priority(stck1.get()) || stck1.isEmpty()) {
      stck1.push(inf[k]);
    } else {
      if (prir == 1) {
        while (stck1.get() != '(') {
          ps.push_back(' ');
          ps.push_back(stck1.get());
          stck1.pop();
        }
        stck.pop();
      } else {
        while (priority(stck1.get()) >= prir) {
          ps.push_back(' ');
          ps.push_back(stck1.get());
          stck1.pop();
        }
        stck.push(inf[k]);
      }
    }
  }
  while (!stck1.isEmpty()) {
    ps.push_back(' ');
    ps.push_back(stck1.get());
    stck1.pop();
  }
  return ps;
}

int eval(std::string pref) {
  TStack <int, 100> stck2;
  std::string temp;
  int num1 = 0, num2 = 0;
  size_t nach = 0, kon = 0;
  for (size_t k = 0; k < pref.size(); ++k) {
    if (pref[k] == ' ' || k == pref.size() - 1) {
      kon = k;
      if (k == pref.size() - 1)
        kon++;
      temp = pref.substr(nach, kon - nach);
      nach = kon + 1;
      bool tNum = true;
      for (int k = 0; k < temp.size(); ++k) {
        if (temp[k] < '0' || temp[k] > '9') {
          tNum = false;
          break;
        }
      }
      if (tNum) {
        stck2.push(std::stoi(temp));
      } else {
        num2 = stck2.get();
        stck2.pop();
        num1 = stck2.get();
        stck2.pop();
        if (temp == "+")
          stck2.push(num1 + num2);
        else if (temp == "-")
          stck2.push(num1 - num2);
        else if (temp == "*")
          stck2.push(num1 * num2);
        else if (temp == "/")
          stck2.push(num1 / num2);
      }
    }
  }
  return stck2.get();
}
