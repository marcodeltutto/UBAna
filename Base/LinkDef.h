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
#pragma link C++ class std::vector<double>+;
#pragma link C++ class std::vector<string>+;
#pragma link C++ class size_t;

#pragma link C++ class Base::sample+;
#pragma link C++ class Base::CrossSectionCalculator1D+;
#pragma link C++ class Base::CrossSectionCalculator2D+;
#pragma link C++ class Base::CovarianceCalculator2D+;
#pragma link C++ class Base::MigrationMatrix2D+;
#pragma link C++ class Base::MigrationMatrix4D+;
#pragma link C++ class Base::ReweightingPlotter+;
#pragma link C++ class Base::PlottingTools+;
#pragma link C++ class Base::CrossSectionBootstrapCalculator1D+;
#pragma link C++ class Base::CrossSectionBootstrapCalculator2D+;
#pragma link C++ class Base::CrossSectionBootstrapCalculator2DPoly+;
#pragma link C++ class Base::UBAnaLogger+;
//ADD_NEW_CLASS ... do not change this line
#endif












