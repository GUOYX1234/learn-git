#ifndef CALIB_ETF_WEIGHT_H
#define CALIB_ETF_WEIGHT_H

#include "tofcalgsec/TofCalib.h"

const int nEtfWeight = 4;

class calib_etf_weight:public TofCalib {
 public:
  calib_etf_weight():TofCalib( nEtfWeight ) {
    m_name = string("calib_etf_weight");
  }

  void calculate_funcs( const Record* r ) {
    double tleft  = r->tleft();
    double tright = r->tright();
    double z      = r->zrhit();

    funcs[0] = tright-tleft;
    funcs[1] = funcs[0]*z;
    funcs[2] = funcs[1]*z;
    funcs[3] = funcs[2]*z;

    return;
  }

  void calculate_y(const Record* r) {
    y = 0.0 - (r->tright());
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
	(*iter)->setT0( tcorr + (*iter)->tright() );
      }
    }
    return;
  }

};

#endif
