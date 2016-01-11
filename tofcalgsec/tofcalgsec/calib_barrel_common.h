#ifndef CALIB_BARREL_COMMON_H
#define CALIB_BARREL_COMMON_H

#include "tofcalgsec/TofCalibFit.h"

// const int nBarrelCommon     = 4;  // number of calib_barrel_common.txt
const int nParCommon        = 4;  // 4: offset,offset error,sigma,sigma error
const int nGraphTotalCommon = 9;

class calib_barrel_common:public TofCalibFit {
 public:
  calib_barrel_common( const unsigned int nzbin );
  ~calib_barrel_common();

  void calculate( RecordSet*& data, unsigned int icounter );

 private:
  void fillRecord( const Record* r );
  void fitHistogram();
  void fillGraph();
  void fitGraph();

 private:
  std::vector<double> zpos;
  std::vector<double> zposerr;
  double zstep;

  std::vector<HepVector> m_fitresult;
};

#endif

