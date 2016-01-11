#ifndef CALIB_ENDCAP_ATTEN_H
#define CALIB_ENDCAP_ATTEN_H

#include "tofcalgsec/TofCalibFit.h"

const int nEndcapAtten  = 5;  // number of calib_endcap_atten.txt
const int nParEcAtten   = 4;  // 4: mean, mean error, sigma, sigma error
const int nGraphEcAtten = 2;

class calib_endcap_atten:public TofCalibFit {
 public:
  calib_endcap_atten( const unsigned int nrbin );
  ~calib_endcap_atten();

  void calculate( RecordSet*& data, unsigned int icounter );

 private:
  void fillRecord( const Record* r, unsigned int icounter );
  void fitHistogram( unsigned int icounter );
  void fillGraph( unsigned int icounter );
  void fitGraph( unsigned int icounter );

  void updateData( Record* r, unsigned int icounter );
  void fillRecordQ0( const Record* r, unsigned int icounter );
  void fitHistogramQ0( unsigned int icounter );
  void fillGraphQ0();

 private:
  std::vector<double> rpos;
  std::vector<double> rposerr;
  double rstep;
  std::vector<double> itofid;
  std::vector<double> itofiderr;
  double itofidstep;

  std::vector<HepVector> m_fitresult;
};

#endif

