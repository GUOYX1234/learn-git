#include "tofcalgsec/TofDataSet.h"
#include <cmath>
bool Record::cutBarrel() {
  if( m_run>0 ) {
    if( m_texp<2.7 || m_texp>4.9 ) return false;
    if( fabs(m_zrhit)>115.0 ) return false;

    // 090308-090413 psip
    if( m_run>=8107 && m_run<9671 ) {
      if( ( m_tofid != 141 ) && ( m_qleft<200.|| m_qleft>20000. ) ) return false;
      if( m_qright<200.|| m_qright>20000. ) return false;
      if( ( m_tofid != 141 ) && ( m_tleft<17.5 || m_tleft>39.0 ) ) return false;
      if( m_tright<17.5 || m_tright>39.0 ) return false;
      if( ( m_tofid != 141 ) && ( fabs(m_tleft-27.4+0.07*m_zrhit ) > 4.0 ) ) return false;
      if( fabs(m_tright-27.6-0.07*m_zrhit) > 4.0 ) return false;
    }

    // 090528-090603 continue
    else if( m_run>=9671 && m_run<9947 ) {
      if( ( m_tofid != 141 ) && ( m_qleft<200.|| m_qleft>20000. ) ) return false;
      if( m_qright<200.|| m_qright>20000. ) return false;
      if( ( m_tofid != 141 ) && ( m_tleft<13.5 || m_tleft>35.0 ) ) return false;
      if( m_tright<13.5 || m_tright>35.0 ) return false;
      if( ( m_tofid != 141 ) && ( fabs(m_tleft-23.7+0.07*m_zrhit ) > 4.0 ) ) return false;
      if( fabs(m_tright-23.7-0.07*m_zrhit) > 4.0 ) return false;
    }

    // 090612-090727 jpsi
    else if( m_run>=9947 && m_run<=10878 ) {
      if( ( m_tofid != 141 ) && ( m_qleft<200.|| m_qleft>20000. ) ) return false;
      if( m_qright<200.|| m_qright>20000. ) return false;
      if( ( m_tofid != 141 ) && ( m_tleft<14.0 || m_tleft>35.0 ) ) return false;
      if( m_tright<14.0 || m_tright>35.0 ) return false;
      if( ( m_tofid != 141 ) && ( fabs(m_tleft-23.6+0.07*m_zrhit ) > 4.0 ) ) return false;
      if( fabs(m_tright-23.6-0.07*m_zrhit) > 4.0 ) return false;
    }

    // 100116-100713 psipp
    else if( m_run>=11397 && m_run<12002 ) {
      if( m_qleft<200.|| m_qleft>20000.  ) return false;
      if( m_qright<200.|| m_qright>20000. ) return false;
      if(  m_tleft<13.5 ||  m_tleft>34.5 ) return false;
      if( m_tright<13.5 || m_tright>34.5 ) return false;
      if( fabs(m_tleft-23.5+0.07*m_zrhit ) > 4.0 ) return false;
      if( fabs(m_tright-23.5-0.07*m_zrhit) > 4.0 ) return false;
    }

    // 110504-1106 psi(4040)
    else if( m_run>=23463 && m_run<=24896 ) {
      if( m_qleft<200.|| m_qleft>20000.  ) return false;
      if( m_qright<200.|| m_qright>20000. ) return false;
      if(  m_tleft<14.0 ||  m_tleft>35.0 ) return false;
      if( m_tright<14.0 || m_tright>35.0 ) return false;
      if( fabs(m_tleft-23.75+0.07*m_zrhit ) > 4.0 ) return false;
      if( fabs(m_tright-23.75-0.07*m_zrhit) > 4.0 ) return false;
    }
    
    // 111221-120331 psip
    else if( m_run>=24897 && m_run<=27101 ) {
      if( m_qleft<200.|| m_qleft>20000.  ) return false;
      if((m_tofid != 137 ) && ( m_qright<200.|| m_qright>20000.) ) return false;
      if(  m_tleft<14.5 ||  m_tleft>35.5 ) return false;
      if((m_tofid != 137 ) && ( m_tright<14.5 || m_tright>35.5 )) return false;
      if( fabs(m_tleft-24.35+0.07*m_zrhit ) > 4.0 ) return false;
      if(( m_tofid != 137 ) && (fabs(m_tright-24.35-0.07*m_zrhit) > 4.0 )) return false;
    }
  
    // 120407-120617 jpsi
    else if( m_run>=27102 && m_run<=29675 ) {
      if( m_qleft<200.|| m_qleft>20000.  ) return false;
      if((m_tofid != 137 ) && ( m_qright<200.|| m_qright>20000.) ) return false;
      if(  m_tleft<14.5 ||  m_tleft>35.5 ) return false;
      if((m_tofid != 137 ) && ( m_tright<14.5 || m_tright>35.5 )) return false;
      if( fabs(m_tleft-25.40+0.07*m_zrhit ) > 4.0 ) return false;
      if(( m_tofid != 137 ) && (fabs(m_tright-25.40-0.07*m_zrhit) > 4.0 )) return false;
    } 

    // 121215 - 130606 Y4260/4360
    else if( m_run>=29676 && m_run<33996 ) {
      if( m_qleft<200.|| m_qleft>20000.  ) return false;
      if((m_tofid != 137 ) && ( m_qright<200.|| m_qright>20000.) ) return false;
      if(  m_tleft<11 ||  m_tleft>32.5 ) return false;
      if((m_tofid != 137 ) && ( m_tright<11 || m_tright>32.5 )) return false;
      if( fabs(m_tleft-21.00+0.07*m_zrhit ) > 4.0 ) return false;
      if(( m_tofid != 137 ) && (fabs(m_tright-21.01-0.07*m_zrhit) > 4.0 )) return false;
    } 

    // 131209 - 130529  R value scan
    else if( m_run>=33997 && m_run<39355 ) {
      if( m_qleft<200.|| m_qleft>20000.  ) return false;
      if((m_tofid != 8 && m_tofid != 137 ) && ( m_qright<200.|| m_qright>20000.) ) return false;
      if(  m_tleft<11 ||  m_tleft>32.5 ) return false;
      if((m_tofid !=8 && m_tofid != 137 ) && ( m_tright<11 || m_tright>32.5 )) return false;
      if( fabs(m_tleft-21.00+0.07*m_zrhit ) > 4.0 ) return false;
      if((m_tofid !=8 && m_tofid != 137 ) && (fabs(m_tright-21.00-0.07*m_zrhit) > 4.0 )) return false;
    } 

    // 141231 - 150202 R value scan
    else if( m_run>=39355 && m_run<40208 ) {
      if( m_qleft<200.|| m_qleft>20000.  ) return false;
      if( m_qright<200.|| m_qright>20000.) return false;
      if(  m_tleft<11 ||  m_tleft>32.5 ) return false;
      if( m_tright<11 || m_tright>32.5 ) return false;
      if( fabs(m_tleft-21.00+0.07*m_zrhit ) > 3.0 ) return false;
      if( fabs(m_tright-21.00-0.07*m_zrhit) > 3.0 ) return false;
    }

    // 150202 - R value scan
    else if( m_run>=40208 && m_run<43646 ) {
      if( m_qleft<200.|| m_qleft>20000.  ) return false;
      if( m_qright<200.|| m_qright>20000.) return false;
      if(  m_tleft<11.5 ||  m_tleft>33.0 ) return false;
      if( m_tright<11.5 || m_tright>33.0 ) return false;
      if( fabs(m_tleft-21.50+0.07*m_zrhit ) > 3.0 ) return false;
      if( fabs(m_tright-21.50-0.07*m_zrhit) > 3.0 ) return false;
    }

    // 160106 - 4170
    else if( m_run>=43646 && m_run<80000 ) {
      if( m_qleft<200.|| m_qleft>20000.  ) return false;
      if( m_qright<200.|| m_qright>20000.) return false;
      if(  m_tleft<9.0 ||  m_tleft>30.0 ) return false;
      if( m_tright<9.0 || m_tright>30.0 ) return false;
      if( fabs(m_tleft-18.90+0.07*m_zrhit ) > 3.5 ) return false;
      if( fabs(m_tright-18.90-0.07*m_zrhit) > 3.5 ) return false;
    }

  }
  else {
    if( m_texp<2.7 || m_texp>4.9 ) return false;
    if( m_tleft<15.  || m_tleft>33.  ) return false;
    if( m_tright<15. || m_tright>33. ) return false;
    if( m_qleft<200. || m_qleft>20000. ) return false;
    if( m_qright<200.|| m_qright>20000.) return false;
    if( fabs(m_zrhit)>115.0 ) return false;
  }

  return true;
}


bool Record::cutEndcap() {
  if( m_run>0 ) {
    if( m_texp<4.6 || m_texp>5.4 ) return false;
    if( m_qleft<50.|| m_qleft>20000.) return false;
    //    if( m_path<130. || m_path>170.) return false;
    if( m_zrhit<50. || m_zrhit>83.) return false;

    // 090308-090413 psip
    if( m_run>=8107 && m_run<9671 ) {
      if( m_tleft<24.0 || m_tleft>32.0 ) return false;
      if( fabs(m_tleft-21.4-0.1*m_zrhit)>4.0 ) return false;
    }

    // 090528-090603 continue
    else if( m_run>=9671 && m_run<9947 ) {
      if( m_tleft<20.0 || m_tleft>28.0 ) return false;
      if( fabs(m_tleft-17.3-0.1*m_zrhit)>4.0 ) return false;
    }

    // 090612-090727 jpsi
    else if( m_run>=9947 && m_run<=10878 ) {
      if( m_tleft<20.5 || m_tleft>28.5 ) return false;
      if( fabs(m_tleft-17.6-0.1*m_zrhit)>4.0 ) return false;
    }

    // 100116-10713 psipp
    else if( m_run>=11397 && m_run<12002 ) {
      if( m_tleft<20.5 || m_tleft>28.5 ) return false;
      if( fabs(m_tleft-17.8-0.1*m_zrhit)>4.0 ) return false;
    }

    // 110504-11060 psi(4040)
    else if( m_run>=23463 && m_run<=24896 ) {
      if( m_tleft<20.5 || m_tleft>28.5 ) return false;
      if( fabs(m_tleft-18.0-0.1*m_zrhit)>4.0 ) return false;
    }

    // 111221-120331 psip
    else if( m_run>=24897 && m_run<=27101 ) {
      if( m_tleft<21.0 || m_tleft>30.0 ) return false;
      if( fabs(m_tleft-18.60-0.1*m_zrhit)>4.0 ) return false;
    } 

    // 120407-120617 jpsi
    else if( m_run>=27102 && m_run<=29675 ) {
      if( m_tleft<22.0 || m_tleft>30.0 ) return false;
      if( fabs(m_tleft-20.17-0.1*m_zrhit)>4.0 ) return false;
    }

    // 121215 - 130606      pisp4260
    else if( m_run>=29676 && m_run<33996 ) {
      if( m_tleft<18.0 || m_tleft>27.0 ) return false;
      if( fabs(m_tleft-15.63-0.1*m_zrhit)>4.0 ) return false;
    }

    // 131209-130529  R value scan
    else if( m_run>=33997 && m_run<39355 ) {
      if( m_tleft<17.5 || m_tleft>26.5 ) return false;
      if( fabs(m_tleft-15.44-0.1*m_zrhit)>4.0 ) return false;
    }

    // 141231-150203  R value scan
    else if( m_run>=39355 && m_run<40208 ) {
      if( m_tleft<18.0 || m_tleft>27.0 ) return false;
      if( fabs(m_tleft-15.8-0.1*m_zrhit)>3.0 ) return false;
    }

    // 150202-  R value scan
    else if( m_run>=40208 && m_run<80000 ) {
      if( m_tleft<18.5 || m_tleft>27.5 ) return false;
      if( fabs(m_tleft-16.5-0.1*m_zrhit)>3.0 ) return false;
    }

  }
  else {
    if( m_tleft<16.|| m_tleft>22.  ) return false;
    if( m_texp<4.5 ||  m_texp>5.4  ) return false;
    if( m_qleft<200.|| m_qleft>20000.) return false;
    if( m_path<120. || m_path>180.) return false;
    if( m_zrhit<50. || m_zrhit>83.) return false;
  }
  return true;
}


bool Record::cutEtf() {
  if( m_run>0 ) {
    if( m_texp<4.5 || m_texp>5.6 ) return false;
    if( fabs(m_zrhit)>7.8 ) return false;
    // 150202 - R value scan
    if( m_run>=40208 && m_run<43646 ) {
      if( m_qleft<5.|| m_qleft>60.  ) return false;
      if( m_qright<5.|| m_qright>60.) return false;
      if(  m_tleft<21.5 ||  m_tleft>27.5 ) return false;
      if( m_tright<21.5 || m_tright>27.5 ) return false;
    }
    // 160107 - 4170
    else if( m_run>=43646 && m_run<80000 ) {
      if( m_qleft<5.|| m_qleft>60.  ) return false;
      if( m_qright<5.|| m_qright>60.) return false;
      if(  m_tleft<4 ||  m_tleft>10.0 ) return false;
      if( m_tright<4 || m_tright>10.0 ) return false;
    }

  }
  else {
    if( m_texp<4.5 || m_texp>5.6 ) return false;
    if( fabs(m_zrhit)>7.8 ) return false;
    if( m_qleft<5.|| m_qleft>60.  ) return false;
    if( m_qright<5.|| m_qright>60.) return false;
    if(  m_tleft<4.5 ||  m_tleft>7.0 ) return false;
    if( m_tright<4.5 || m_tright>7.0 ) return false;
  }

  return true;
}
