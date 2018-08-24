//
// cint script to generate libraries
// Declaire namespace & classes you defined
// #pragma statement: order matters! Google it ;)
//

#ifdef __CINT__
#pragma link off all globals;
#pragma link off all classes;
#pragma link off all functions;

#pragma link C++ class string+;
#pragma link C++ class map+;
#pragma link C++ class map<string,TH1D*>+;
#pragma link C++ class map<string,TH1D>+;
#pragma link C++ class map<string,TH2D*>+;
#pragma link C++ class std::map<std::string,std::map<std::string,TH1D*>>+;
#pragma link C++ class std::map<std::string,std::map<std::string,TH2D*>>+;
#pragma link C++ class std::vector<double>+;
#pragma link C++ class std::vector<string>+;
#pragma link C++ class size_t;
#pragma link C++ class std::vector<std::vector<TH2D*>>+;
#pragma link C++ class std::map<std::string,std::vector<std::vector<TH2D*>>>+;

#pragma link C++ class Main::sample+;
#pragma link C++ class Main::Maker+;
#pragma link C++ class Main::test+;
#pragma link C++ class Main::Analyse+;
//ADD_NEW_CLASS ... do not change this line
#endif




