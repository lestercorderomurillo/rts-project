 #ifndef RTS_LOGGING
 #define RTS_LOGGING

 #include <string>

using namespace std;

 namespace RTS{

    class LogSystem{
    private:
    
      /*string       logPath;
      list<string> logData;*/

    public:
      LogSystem();

      void out(string message);
      void out(int, string message);
      int  reportToFile();

   };

 }

 #endif
