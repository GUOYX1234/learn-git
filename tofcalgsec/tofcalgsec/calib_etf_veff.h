#ifndef CALIB_ETF_VEFF_H
#define CALIB_ETF_VEFF_H

#include "tofcalgsec/TofCalib.h"

const int nEtfVeff = 4;

class calib_etf_veff:public TofCalib {
 public:
  calib_etf_veff():TofCalib( nEtfVeff ) {
    m_name = string("calib_etf_veff");
  }

  void calculate_funcs( const Record* r ) {
    double z = r->zrhit();

    funcs[0] = 1.0;
    funcs[1] = z;
    funcs[2] = z*z;
    funcs[3] = z*z*z;

    return;
  }

  void calculate_y(const Record* r) {
    y = r->tright() - r->tleft();
    return;
  }

  void updateData( RecordSet*& data ) {
    return;
  }

};

#endif
