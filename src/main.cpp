#include <iostream>
#include <map>
#include <iterator>
#include <sstream>
#include <algorithm>
#include <vector>
#include <string>
#include <cctype>
#include <cassert>
#include <iterator>

#include "dictionary.h"
#include "nums.h"

static std::string buffer;
static std::vector<std::string> translated;

int main(int argc, char **argv) {
  
    
    std::getline(std::cin, buffer);
    std::cout << buffer;
    std::istringstream C__w(buffer);
    for(auto &it : buffer) 
    { 
      std::string B_chars;
      C__w >> B_chars;
     

      std::string B_letter(1, it);

      const auto C_Buff = std::find(buffer.begin(), buffer.end(), '.');
      const auto L_Buff = std::find(buffer.begin(), buffer.end(), '-');

      if(C_Buff != buffer.end() || L_Buff != buffer.end()){
           translated.push_back(C__[B_chars]);
                   if(B_chars == "/") translated.push_back(" ");
      }
      if(C_Buff == buffer.end() || L_Buff == buffer.end()) {
              translated.push_back(T__[B_letter] + static_cast<std::string>(" "));
              if(B_letter == " ") translated.push_back("/ ");
      }
       
      B_chars.clear();
      B_letter.clear();
    }
    printf("\n");

    for (const auto &i : translated)
      std::cout << i;

    return 0;
}