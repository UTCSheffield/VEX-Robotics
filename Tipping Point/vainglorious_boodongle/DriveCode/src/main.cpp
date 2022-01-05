/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\16mossm                                          */
/*    Created:      Wed Dec 08 2021                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Drivetrain           drivetrain    1, 2            
// MotorGroupArm        motor_group   11, 12          
// MotorGroupFork       motor_group   5, 6            
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"


using namespace vex;

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  extern float SpeedMult;
  
  while(true){
    if(Controller1.ButtonX.pressing()){
    SpeedMult = 0.1f;
    }
    else{
      SpeedMult = 1.0f;
    }
  }
}
