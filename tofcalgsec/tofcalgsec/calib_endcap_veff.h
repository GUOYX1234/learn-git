#ifndef CALIB_ENDCAP_VEFF_H
#define CALIB_ENDCAP_VEFF_H

#include "tofcalgsec/TofCalib.h"

const int nEndcapVeff = 4;

class calib_endcap_veff:public TofCalib {
 public:
  calib_endcap_veff():TofCalib( nEndcapVeff ) {
    m_name = string("calib_endcap_veff");
  }

  void calculate_funcs( const Record* r ) {
    double z = r->zrhit();

    funcs[0] = 1.0;
    funcs[1] = z-44.5;
    funcs[2] = (z-44.5)*(z-44.5);
    funcs[3] = (z-44.5)*(z-44.5)*(z-44.5);

    return;
  }

  void calculate_y(const Record* r) {
    y = r->tleft() - r->texp();
    return;
  }

  void updateData( RecordSet*& data ) {
    return;
  }

};

#endif
