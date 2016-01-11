#ifndef CALIB_BARREL_RIGHT_H
#define CALIB_BARREL_RIGHT_H

#include "tofcalgsec/TofCalib.h"

const int nBarrelRight = 7;

class calib_barrel_right:public TofCalib {
 public:
  calib_barrel_right():TofCalib( nBarrelRight ) {
    m_name = string("calib_barrel_right");
  }

  void calculate_funcs( const Record* r ) {
    double q = r->qright();
    double z = r->zrhit();
    
    if( q<0.0 ) {
      for( int i=0; i<nBarrelLeft; i++ ) {
	funcs[i] = 0.0;
      }
    }
    else {
      funcs[0] = 1.0;
      funcs[1] = 1./sqrt(q);
      funcs[2] = z/sqrt(q);
      funcs[3] = 1.0/q;
      funcs[4] = z;
      funcs[5] = z*z;
      funcs[6] = z*z*z;
    }

    return;
  }

  void calculate_y(const Record* r) {
    y = r->tright() - r->texp();
    return;
  }

  void updateData( RecordSet*& data ) {
    if( data->size() > 0 ) {
      std::vector<Record*>::iterator iter = data->begin();
      for( ; iter!=data->end(); iter++ ) {
	calculate_funcs( (*iter) );
	double tcorr = 0.0;
	for( int i=0; i<X.num_row(); i++ ) {
	  tcorr += X[i]*funcs[i];
	}
	(*iter)->settright( (*iter)->tright() - tcorr - (*iter)->texp() );
      }
    }
    return;
  }

};

#endif
