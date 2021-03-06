#ifndef CALIB_BARREL_RIGHT_OFFSET2_BUNCH0_3_H
#define CALIB_BARREL_RIGHT_OFFSET2_BUNCH0_3_H

#include "tofcalgsec/TofCalib.h"

const int nBarrelRight_Offset2_bunch0_3 = 7;

class calib_barrel_right_offset2_bunch0_3:public TofCalib {
 public:
  calib_barrel_right_offset2_bunch0_3():TofCalib( nBarrelRight_Offset2_bunch0_3 ) {
    m_name = string("calib_barrel_right_offset2_bunch0");
  }

  void calculate_funcs( const Record* r ) {
    int  run = r->run();
    double z = r->zrhit();
    double t = r->tright();
    double t0 = r->phi();
    if( run<0 || (static_cast<int>(t0/(8.0*12000./499.8/8./3. )+0.1))%3==0){
       if( z<5.0 && abs(t)<10.0 ) {
         funcs[0] = 1.0;
         funcs[1] = z;
         funcs[2] = z*z;
         funcs[3] = z*z*z;
         funcs[4] = z*z*z*z;
         funcs[5] = z*z*z*z*z;
         funcs[6] = z*z*z*z*z*z;
       }
       else {
         funcs[0] = 0.0;
         funcs[1] = 0.0;
         funcs[2] = 0.0;
         funcs[3] = 0.0;
         funcs[4] = 0.0;
         funcs[5] = 0.0;
         funcs[6] = 0.0;
       }
    }
    return;
  }

  void calculate_y(const Record* r) {
    if( r->run()<0 || (static_cast<int>((r->phi())/(8.0*12000./499.8/8./3. )+0.1))%3==0){
       if( r->zrhit() < 5.0 ) {
         y = r->tright();
       }
       else {
         y = 0.0;
       }
    }
    return;
  }

  void updateData( RecordSet*& data ) {
    if( data->size() > 0 ) {
      std::vector<Record*>::iterator iter = data->begin();
      for( ; iter!=data->end(); iter++ ) {
	if( (*iter)->run() < 0 ) return;
        if ((static_cast<int>(((*iter)->phi())/(8.0*12000./499.8/8./3. )+0.1))%3==0){
	   if( (*iter)->zrhit() >= 0.0 ) continue;
	   calculate_funcs( (*iter) );
	   double tcorr = 0.0;
	   for( int i=0; i<X.num_row(); i++ ) {
	     tcorr += X[i]*funcs[i];
	   }
	   (*iter)->settright( (*iter)->tright() - tcorr );
        }
      }
    }
    return;
  }

};

#endif
