#ifndef CALIB_BARREL_VEFF_H
#define CALIB_BARREL_VEFF_H

#include "tofcalgsec/TofCalib.h"

const int nBarrelVeff = 2;

class calib_barrel_veff:public TofCalib {
 public:
  calib_barrel_veff():TofCalib( nBarrelVeff ) {
    m_name = string("calib_barrel_veff");
  }

  void calculate_funcs( const Record* r ) {
    double z = r->zrhit();
    
    funcs[0] = 2.0*z;
    funcs[1] = 1.0;

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
