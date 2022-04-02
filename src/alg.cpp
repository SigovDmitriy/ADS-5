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
  if (ch ==  '+' || ch == '-') {
    return 2;
  }
  if (ch == '*' || ch == '/') {
    return 3;
  }
  return -1;
}
std::string infx2pstfx(std::string inf) {
  TStack <char, 100> stck;
  std::string ps;
  for (int i = 0; i < inf.size(); i++) {
    int prir = priority(inf[i]);
    if (prir == -1) {
      if (!ps.empty() && priority(inf[i - 1]) != -1) {
        ps.push_back(' ');
      }
      ps.push_back(inf[i]);
    } else if (prir == 0 || prir > priority(stck.get()) || stck.isEmpty()) {
            stck.push(inf[i]);
        } else {
            if (prir == 1) {
                while (stck.get() != '(') {
                    ps.push_back(' ');
                    ps.push_back(stck.get());
                    stck.pop();
                }
                stck.pop();
            } else {
                while (priority(stck.get()) >= prir) {
                    ps.push_back(' ');
                    ps.push_back(stck.get());
                    stck.pop();
                }
                stck.push(inf[i]);
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
    TStack <int, 100> stck1;
    std::string temp;
    int num = 0, mun = 0;
    size_t beg = 0, fin = 0;
    for (size_t i = 0; i < pref.size(); ++i) {
        if (pref[i] == ' ' || i == pref.size() - 1) {
            fin = i;
            if (i == pref.size() - 1)
                fin++;
            temp = pref.substr(beg, fin - beg);
            beg = fin + 1;
            bool tNum = true;
            for (int i = 0; i < temp.size(); ++i) {
                if (temp[i] < '0' || temp[i] > '9') {
                    tNum = false;
                    break;
                }
            }
            if (tNum) {
                stck1.push(std::stoi(temp));
            } else {
                mun = stck1.get();
                stck1.pop();
                num = stck1.get();
                stck1.pop();
                if (temp == "+")
                    stck1.push(num + mun);
                else if (temp == "-")
                    stck1.push(num - mun);
                else if (temp == "*")
                    stck1.push(num * mun);
                else if (temp == "/")
                    stck1.push(num / mun);
            }
        }
    }
    return stck1.get();
}
