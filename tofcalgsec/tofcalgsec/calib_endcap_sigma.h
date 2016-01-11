#ifndef CALIB_ENDCAP_SIGMA_H
#define CALIB_ENDCAP_SIGMA_H

#include "tofcalgsec/TofCalibFit.h"

const int nEndcapSigma     = 3;  // number of calib_endcap_sigma.txt
const int nParEcSigma      = 4;  // 4: offset, offset error, sigma, sigma error
const int nGraphEcSigma    = 2;

class calib_endcap_sigma:public TofCalibFit {
 public:
  calib_endcap_sigma( const unsigned int nrbin );
  ~calib_endcap_sigma();

  void calculate( RecordSet*& data, unsigned int icounter );

 private:
  void fillRecord( const Record* r, unsigned int icounter );
  void fitHistogram( unsigned int icounter );
  void fillGraph( unsigned int icounter );
  void fitGraph( unsigned int icounter );

 private:
  std::vector<double> rpos;
  std::vector<double> rposerr;
  double rstep;

  std::vector<HepVector> m_fitresult;
};

#endif

