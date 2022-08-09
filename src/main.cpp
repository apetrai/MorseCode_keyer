#include <iostream>
#include <map>
#include <iterator>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <exception>

static std::map<std::string, std::string> C__ {{".-", "A"}, {"-...", "B"},
                                               {"-.-.", "C"}, {"-..", "D"}};
static std::map<std::string, std::string> T__{{"A", ".-"}, {"B", "-..."},
                                              {"C", "-.-."}, {"D", "-.."}};


int main(int argc, char **argv) {
    std::string buffer;
    
    std::getline(std::cin, buffer);

    for(auto it = buffer.begin(); it != buffer.end(); ++it) 
    {
      std::string buff(1, *it);

      auto res = T__.find(buff);   
      std::cout << res->second << " ";
      if(buff == " ")
        std::cout << "/ ";
      
    }
    
    return 0;
  }