// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Drivetrain           drivetrain    1, 2, A         
// Controller1          controller                    
// forklift             motor_group   3, 4            
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Drivetrain           drivetrain    1, 2, A         
// Controller1          controller                    
// forklift             motor_group   3, 4            
// ---- END VEXCODE CONFIGURED DEVICES ----
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Wed Sep 25 2019                                           */
/*    Description:  Clawbot (Drivetrain) - Template                           */
/*                                                                            */
/*    Name:                                                                   */
/*    Date                                                                    */
/*    Class:                                                                  */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Drivetrain           drivetrain    1, 2, A         
// ClawMotor            motor         3               
// ArmMotor             motor         8               
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;
int forklift_positions[3] = {0, 30, 60};
int forklift_position = 0;
int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  forklift.setPosition(forklift_positions[forklift_position],degrees);
  while(true) {
    // Spin both motors in the forward direction.
    //LeftMotor.spin(forward);
    //RightMotor.spin(forward);
    if (Controller1.ButtonR2.pressing()) {
      forklift_position ++ ;
      forklift.setPosition(forklift_positions[forklift_position % 3],degrees);
    }
    wait(25, msec);
  }
}

