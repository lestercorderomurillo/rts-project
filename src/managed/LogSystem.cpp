#include "managed/LogSystem.hpp"
#include <iostream>

using namespace std;

namespace RTS{

    LogSystem::LogSystem(){
      out(0, "RTS logging started.");
    }

    void LogSystem::out(string message){
      out(0, message);
    }

    void LogSystem::out(int level, string message){
      switch (level) {
        case 0: cout << "{INFO} " << message << endl; break;
        case 1: cout << "{WARN} " << message << endl; break;
        case 2: cout << "{ERR!} " << message << endl; break;
      }
    }

    int LogSystem::reportToFile(){
      return 0;
    }

 }
