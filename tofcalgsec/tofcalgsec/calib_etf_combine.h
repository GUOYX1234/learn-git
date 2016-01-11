#ifndef CALIB_ETF_COMBINE_H
#define CALIB_ETF_COMBINE_H

#include "tofcalgsec/TofCalib.h"

const int nEtfCombine = 3;

class calib_etf_combine:public TofCalib {
 public:
  calib_etf_combine():TofCalib( nEtfCombine ) {
    m_name = string("calib_etf_combine");
  }

  void calculate_funcs( const Record* r ) {
    double q = ( r->qleft() + r->qright() )/2.0;
    double z = r->zrhit();

    if( q<0.0 ) {
      for( int i=0; i<nEtfCombine; i++ ) {
	funcs[i] = 1.0;
      }
    }
    else {
      funcs[0] = 1.0;
      funcs[1] = 1.0/sqrt(q);
      funcs[2] = q;
/*      funcs[2] = 1.0/q;
      funcs[3] = q;
      funcs[4] = q*q;
      funcs[5] = q*q*q;
      funcs[6] = q*q*q*q;
*/
    }

    return;
  }

  void calculate_y(const Record* r) {
    y = ( r->tleft() + r->tright() )/2.0 - r->texp();
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
	(*iter)->setT0( ( (*iter)->tleft() + (*iter)->tright() )/2.0 - tcorr - (*iter)->texp() );
      }
    }
    return;
  }

};

#endif
