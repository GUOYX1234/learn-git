#ifndef CALIB_BARREL_ATTEN_H
#define CALIB_BARREL_ATTEN_H

#include "tofcalgsec/TofCalib.h"

const int nBarrelAtten = 2;

class calib_barrel_atten:public TofCalib {
 public:
  calib_barrel_atten():TofCalib( nBarrelAtten ) {
    m_name = string("calib_barrel_atten");
  }

  void calculate_funcs( const Record* r ) {
    double z  = r->zrhit();
    double q1 = r->qleft();
    double q2 = r->qright();

    if( q1>0.0 && q2>0.0 ) {
      funcs[0] = 2.0*z;
      funcs[1] = 1.0;
    }
    else {
      funcs[0] = 0.0;
      funcs[1] = 0.0;
    }

    return;
  }

  void calculate_y(const Record* r) {
    double q1 = r->qleft();
    double q2 = r->qright();
    if( q1>0.0 && q2>0.0 ) {
      y = log(q1/q2);
    }
    else {
      y = 0.0;
    }
    return;
  }

  void updateData( RecordSet*& data ) {
    if( data->size() > 0 ) {
      std::vector<Record*>::iterator iter = data->begin();
      for( ; iter!=data->end(); iter++ ) {
	double z        = (*iter)->zrhit();
	double sintheta = (*iter)->theta();
	double q1       = (*iter)->qleft();
	double q2       = (*iter)->qright();
	double latten   = 1.0/X[0];
	double a1overa2 = exp(X[1]);
	double q0 = sintheta*(q1*exp((115.0-z)/latten)+q2*exp((115.0+z)/latten))/(1.0+a1overa2);
	(*iter)->setQ0( q0 );
      }
    }
    return;
  }

};

#endif
