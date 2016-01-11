#ifndef CALIB_BARREL_Q0_H
#define CALIB_BARREL_Q0_H

#include "tofcalgsec/TofCalibFit.h"

const int nBarrelQ0     = 3;  // number of calib_barrel_q0.txt
const int nParQ0        = 4;  // 4: mean, mean error, sigma, sigma error
const int nGraphTotalQ0 = 2;

class calib_barrel_q0:public TofCalibFit {
 public:
  calib_barrel_q0();
  ~calib_barrel_q0();

  void calculate( RecordSet*& data, unsigned int icounter );

 private:
  void fillRecord( const Record* r, unsigned int icounter );
  void fitHistogram( unsigned int icounter );
  void fillGraph();
  void fitGraph();

 private:
  std::vector<double> itofid;
  std::vector<double> itofiderr;
  double itofidstep;

  std::vector<HepVector> m_fitresult;
};

#endif

