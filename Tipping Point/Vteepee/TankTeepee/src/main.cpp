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
int forklift_motor_degrees(int forklift_degrees) {
  return 1 * forklift_degrees;
}
// autonomous functions!s
void autonomousleft() {
  Drivetrain.turn(left);
};
void autonomousright() {
  Drivetrain.turn(right);
};
void autonomousreverse() {
  Drivetrain.drive(reverse);
}
void autonomousforward() {
  Drivetrain.drive(forward);
};
void autonomousstop() {
  Drivetrain.stop();
};
int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  forklift.resetPosition();
  forklift.setStopping(hold);
  bool forkliftpressed = false;
  //orklift.spinToPosition(forklift_motor_degrees(forklift_positions[forklift_position]),deg);
  while(true) {
    // Spin both motors in the forward direction.
    //LeftMotor.spin(forward);
    //RightMotor.spin(forward);

    // FORKLIFT
    if (Controller1.ButtonR2.pressing() && forkliftpressed==false) {
      forkliftpressed = true;
      forklift_position ++ ;
      Brain.Screen.print("\nforklift to pos ");
      Brain.Screen.print(forklift_position);
      int motorRotation = forklift_motor_degrees(forklift_positions[forklift_position]);
      Brain.Screen.print("forklift rotation ");
      Brain.Screen.print(motorRotation);
      
      forklift.spinToPosition(motorRotation ,deg);
      
    }
    else
    {
      forkliftpressed = false;
      
    }
    wait(25, msec);
  }
}

