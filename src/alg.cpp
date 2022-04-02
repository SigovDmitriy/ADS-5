// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

int priority(char zn) {
  if (zn == '(') {
    return 0;
  }
  if (zn == ')') {
    return 1;
  }
  if (zn == '+' || zn == '-') {
    return 2;
  }
  if (zn == '*' || zn == '/') {
    return 3;
  }
  return -1;
}

std::string infx2pstfx(std::string inf) {
  TStack <char, 100> stck;
  std::string ps;
  for (int k = 0; k < inf.size(); k++) {
    int pri = priority(inf[k]);
    if (pri == -1) {
      if (!ps.empty() && priority(inf[k - 1]) != -1) {
        ps.push_back(' ');
      }
      ps.push_back(inf[k]);
    } else if (pri == 0 || pri > priority(stck.get()) || stck.isEmpty()) {
      stck.push(inf[k]);
    } else {
      if (pri == 1) {
        while (stck.get() != '(') {
          ps.push_back(' ');
          ps.push_back(stck.get());
          stck.pop();
        } else {
          while (priority(stck.get()) >= pri) {
            ps.push_back(' ');
            ps.push_back(stck.get());
            stck.pop();
          }
          stck.push(ing[k]);
        }
      }
    }
    while (!stck.isEmpty()) {
      ps.push_back(' ');
      ps.push_back(stck.get());
      stck.pop();
    }
    return ps;
}
  
int eval(std::string pref) {
  TStack <int, 100> stck11;
  std::string temp;
  int num = 0, num2 = 0;
  size_t nach = 0, kon = 0;
  for (size_t k = 0; k < pref.size(); ++k) {
    if (pref[k] == ' ' || k == pref.size() -1) {
      kon = k;
      if (k == pref.size() -1)
        kon++;
      temp = pref.substr(nach, kon - nach);
      nach = kon + 1;
      bool tNum = true;
      for (int k = 0; k < temp.size(); ++k) {
        if (temp[k] < '0' || temp[i] > '9') {
          tNum = false;
          break;
        }
      }
      if (tNum) {
        stck11.push(std::stoi(temp));
      } else {
        mun = stck11.get();
        stck11.pop();
        num = stck11.get();
        stck11.pop();
        if (temp == "+")
          stck11.push(num + num2);
        else if (temp == "-")
          stck11.push(num - num2);
        else if (temp == "*")
          stck11.push(num * num2);
        else if (temp == "/")
          stck11.push(num / num2);
      }
    }
  }
  return stck11.get();
}
