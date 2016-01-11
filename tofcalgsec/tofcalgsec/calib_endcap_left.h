#ifndef CALIB_ENDCAP_LEFT_H
#define CALIB_ENDCAP_LEFT_H

#include "tofcalgsec/TofCalib.h"

const int nEndcapLeft = 7;

class calib_endcap_left:public TofCalib {
 public:
  calib_endcap_left():TofCalib( nEndcapLeft ) {
    m_name = string("calib_endcap_left");
  }

  void calculate_funcs( const Record* r ) {
    double q = r->qleft();
    double z = r->zrhit();

    funcs[0] = 1.0;
    funcs[1] = 1.0/sqrt(q);
    funcs[2] = 1.0/q;
    funcs[3] = q;
    funcs[4] = z;
    funcs[5] = z*z;
    funcs[6] = z*z*z;

    return;
  }

  void calculate_y(const Record* r) {
    y = r->tleft() - r->texp();
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
	(*iter)->settleft( (*iter)->tleft() - tcorr - (*iter)->texp() );
      }
    }
    return;
  }

};

#endif
