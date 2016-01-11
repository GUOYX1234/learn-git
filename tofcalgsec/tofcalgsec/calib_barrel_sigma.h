#ifndef CALIB_BARREL_SIGMA_H
#define CALIB_BARREL_SIGMA_H

#include "tofcalgsec/TofCalibFit.h"

const int nBarrelSigma     = 15; // number of calib_barrel_sigma.txt
const int nParSigma        = 4;  // 4: offset, offset error, sigma, sigma error
const int nGraphTotalSigma = 11;

class calib_barrel_sigma:public TofCalibFit {
 public:
  calib_barrel_sigma( const unsigned int nzbin );
  ~calib_barrel_sigma();

  void calculate( RecordSet*& data, unsigned int icounter );

 private:
  void fillRecord( const Record* r, unsigned int icounter );
  void fitHistogram( unsigned int icounter );
  void fillGraph( unsigned int icounter );
  void fitGraph( unsigned int icounter );

  void updateData( Record* r, unsigned int icounter );
  void fillRecordT0( const Record* r, unsigned int icounter );
  void fitHistogramT0( unsigned int icounter );
  void fillGraphT0( unsigned int icounter );
  void fitGraphT0( unsigned int icounter );

 private:
  std::vector<double> zpos;
  std::vector<double> zposerr;
  double zstep;

  std::vector<HepVector> m_fitresult;
};

#endif

