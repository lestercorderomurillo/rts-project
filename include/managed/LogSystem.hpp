#ifndef RTS_LOGGING
#define RTS_LOGGING
#define PROJECTNAME "RTS Project Development Build 311"

#include <SFML/System/Err.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
#include <ios>
#include <string>

using namespace std;

namespace RTS{

  class LogSystem{
    private:
    
      ofstream logFile;

    public:
      LogSystem();
      ~LogSystem();
      
      void out(string message);
      void out(int, string message);

  };

  class ErrBlock{
    private:
	    std::ios_base::iostate m_sfErrIoState;

    public:

      ErrBlock() : m_sfErrIoState(sf::err().rdstate()){
        sf::err().clear(std::ios::failbit);
      }
      ~ErrBlock()	{
        sf::err().clear(m_sfErrIoState);
      }


  };

}

#endif
