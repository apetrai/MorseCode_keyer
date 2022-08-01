#include <iostream>
#include <map>
#include <iterator>
#include <sstream>
#include <algorithm>

static std::map<std::string, std::string> T__{{"A", ".-"}, {"B", "-..."},
                                              {"C", "-.-."}, {"D", "-.."} };


int main(int argc, char **argv) {
    std::string buffer;
    for(int i = 0; i != 1; i++){std::cin >> buffer; }
    for(auto it = buffer.begin(); it != buffer.end(); ++it) 
    {
      std::string buff(1, *it);   
      std::cout << T__[buff] << " ";
     

    }
    
    return 0;
}