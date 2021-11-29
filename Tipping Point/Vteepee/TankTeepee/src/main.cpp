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

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // Deadband stops the motors when Axis values are close to zero.
  int deadband = 5;

  while (true) {
    // Get the velocity percentage of the left motor. (Axis3 + Axis1)
    int forwardSpeed =
        Controller1.Axis3.position() + Controller1.Axis1.position();
    // Get the velocity percentage of the right motor. (Axis3 - Axis1)
    int turnSpeed =
        Controller1.Axis3.position() - Controller1.Axis1.position();

    // Set the speed of the left motor. If the value is less than the deadband,
    // set it to zero.
    if (abs(forwardSpeed) < deadband) {
      // Set the speed to zero.
      //Drivetrain.     Velocity(0, percent);
    } else {
      // Set the speed to forwardSpeed
      //LeftMotor.setVelocity(forwardSpeed, percent);
    }

    // Set the speed of the right motor. If the value is less than the deadband,
    // set it to zero.
    if (abs(turnSpeed) < deadband) {
      // Set the speed to zero
      //RightMotor.setVelocity(0, percent);
    } else {
      // Set the speed to turnSpeed
      //RightMotor.setVelocity(turnSpeed, percent);
    }

    // Spin both motors in the forward direction.
    //LeftMotor.spin(forward);
    //RightMotor.spin(forward);

    wait(25, msec);
  }
}
