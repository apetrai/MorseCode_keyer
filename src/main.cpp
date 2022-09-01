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

int main(int argc, char **argv) {
    std::string buffer;
    
    std::getline(std::cin, buffer);
    std::istringstream C__w(buffer);
    for(auto &it : buffer) 
    { 
      std::string B_chars;
      C__w >> B_chars;
      
      std::string B_letter(1, it);

      auto C_Buff = std::find(B_chars.begin(), B_chars.end(), '.');
      auto C__Buff = std::find(B_chars.begin(), B_chars.end(), '-');

      if(C_Buff != B_chars.end() || C__Buff != B_chars.end()) 
           std::cout << C__[B_chars];
      else 
           std::cout << T__[B_letter] << " ";
        

        if(B_chars == "/") 
         std::cout << " ";
        else if(B_letter == " ")
         std::cout << "/ ";
       
      B_chars.clear();
      B_letter.clear();
    }
    printf("\n");
    return 0;
}