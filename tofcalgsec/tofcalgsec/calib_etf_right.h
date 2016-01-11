#ifndef CALIB_ETF_RIGHT_H
#define CALIB_ETF_RIGHT_H

#include "tofcalgsec/TofCalib.h"

const int nEtfRight = 4;

class calib_etf_right:public TofCalib {
 public:
  calib_etf_right():TofCalib( nEtfRight ) {
    m_name = string("calib_etf_right");
  }

  void calculate_funcs( const Record* r ) {
    double q = r->qright();
    double z = r->zrhit();

    if( q<0.0 ) {
      for( int i=0; i<nEtfLeft; i++ ) {
	funcs[i] = 0.0;
      }
    }
    else {
      funcs[0] = 1.0;
      funcs[1] = z;
      funcs[2] = z*z;
      funcs[3] = z*z*z;
/*      funcs[1] = 1./sqrt(q);
      funcs[2] = q;
      funcs[3] = q*q;
      funcs[4] = q*q*q;
      funcs[5] = q*q*q*q;
      funcs[6] = z/sqrt(q);
      funcs[7] = 1.0/q;
      funcs[8] = z/q;
      funcs[9] = z*q;
      funcs[10] = z;
      funcs[11] = z*z;
      funcs[12] = z*z*z;
*/
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
