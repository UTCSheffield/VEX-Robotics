// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Drivetrain           drivetrain    1, 2, A         
// Controller1          controller                    
// LiftUpMotor          motor_group   3, 4            
// ---- END VEXCODE CONFIGURED DEVICES ----
#include "vex.h"

using namespace vex;
int auto_used = false;
int LiftUpMotor_positions[5] = {0, 45, 90, 100, 0};
int LiftUpMotor_position = 0;
int LiftUpMotor_positions_length = sizeof(LiftUpMotor_positions)/sizeof(LiftUpMotor_positions[0]);
int LiftUpMotor_motor_degrees(int pos) {
  int LiftUpMotor_degrees = LiftUpMotor_positions[pos % 3];
  return 1.5 * LiftUpMotor_degrees;
}
// int PickUpMotor_positions[3] = {0, 45, 0};
// int PickUpMotor_position = 0;
// int PickUpMotor_positions_length = sizeof(LiftUpMotor_positions)/sizeof(LiftUpMotor_positions[0]);
// int PickUpMotor_motor_degrees(int pos) {
  // int PickUpMotor_degrees = PickUpMotor_positions[pos % 3];
  // return 1 * PickUpMotor_degrees;
// }
int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  LiftUpMotor.resetPosition();
  LiftUpMotor.setStopping(hold);
  bool LiftUpMotorpressed = false;
  LiftUpMotor.setVelocity(25, percent);
  //PickUpMotor.resetPosition();
  //PickUpMotor.setStopping(hold);
  //bool PickUpMotorpressed = false;
  //PickUpMotor.setVelocity(25, percent);

  //orklift.spinToPosition(LiftUpMotor_motor_degrees(LiftUpMotor_positions[LiftUpMotor_position]),deg);
  while(true) {
    // Spin both motors in the forward direction.
    //LeftMotor.spin(forward);
    //RightMotor.spin(forward);

    // LiftUpMotor
    
    if (Controller1.ButtonR1.pressing() || Controller1.ButtonR2.pressing()) {
      if (LiftUpMotorpressed==false && Controller1.ButtonR2.pressing() ) {
        LiftUpMotorpressed = true;
        LiftUpMotor_position ++ ;
        if(LiftUpMotor_position < 0){
          LiftUpMotor_position = 0;
        }
        if(LiftUpMotor_position >= LiftUpMotor_positions_length) {
          LiftUpMotor_position = LiftUpMotor_positions_length -1;
        }
        Brain.Screen.print("ButtonR2 pos %d", LiftUpMotor_position);     
        int motorRotation = LiftUpMotor_motor_degrees(LiftUpMotor_position);
        Brain.Screen.print("motorRotation %d", motorRotation);
        Brain.Screen.newLine(); 
        
        LiftUpMotor.spinToPosition(motorRotation ,deg);
        
      }
      else if (LiftUpMotorpressed==false && Controller1.ButtonR1.pressing()) {
        LiftUpMotorpressed = true;
        LiftUpMotor_position -- ;
        if(LiftUpMotor_position < 0){
          LiftUpMotor_position = 0;
        }
        if(LiftUpMotor_position >= LiftUpMotor_positions_length) {
          LiftUpMotor_position = LiftUpMotor_positions_length -1;
        }
        Brain.Screen.print("ButtonR1 pos %d", LiftUpMotor_position);     
        int motorRotation = LiftUpMotor_motor_degrees(LiftUpMotor_position);
        Brain.Screen.print(" motorRotation %d", motorRotation);
        Brain.Screen.newLine(); 

        LiftUpMotor.spinToPosition(motorRotation ,deg);
        
      }
    }
    else
    {
      LiftUpMotorpressed = false;
      
    }
  /*---------------------------------------------------------------------------------\\
 // CODE TO DO AT BEGINING                                                            \\
//-------------------------------------------------------------------------------------*/
int auto_angle = 60;
if (Controller1.ButtonA.pressing() && auto_used == false) {
  //auto_used = true;
  // rotate
  Drivetrain.turnToRotation(auto_angle, degrees);
  Brain.Screen.print("Rotated");
  Brain.Screen.newLine();
  // hook down
  LiftUpMotor.spinToPosition(243, degrees);
  // forward
  Drivetrain.driveFor(forward, 2.5, inches);
  // hook up
  LiftUpMotor.spinToPosition(10, degrees);
  // reverse
  Drivetrain.driveFor(reverse, 5, inches);
  

}
// IGNORE
    // if (Controller1.ButtonL1.pressing() || Controller1.ButtonR2.pressing()) {
      // if (PickUpMot
      
    //o rpressed==false && Controller1.ButtonR2.pressing() ) {
      //  PickUpMotorpressed = true;
      //  PickUpMotor_position ++ ;
      //  if(PickUpMotor_position < 0){
      //   PickUpMotor_position = 0;
      //  }
      //  if(PickUpMotor_position >= PickUpMotor_positions_length) {
      //    PickUpMotor_position = PickUpMotor_positions_length -1;
      //  }
      //  Brain.Screen.print("ButtonR2 pos %d", PickUpMotor_position);     
      //  int motorRotation = PickUpMotor_motor_degrees(PickUpMotor_position);
      //  Brain.Screen.print("motorRotation %d", motorRotation);
      //  Brain.Screen.newLine(); 
      //  
      //  PickUpMotor.spinToPosition(motorRotation ,deg);
      //  
      // }
      // else if (PickUpMotorpressed==false && Controller1.ButtonL2.pressing()) {
      //  PickUpMotorpressed = true;
      //  PickUpMotor_position -- ;
      //  if(PickUpMotor_position < 0){
      //     PickUpMotor_position = 0;
      //  }
      //  if(PickUpMotor_position >= PickUpMotor_positions_length) {
      //    PickUpMotor_position = PickUpMotor_positions_length -1;
      //  }
      //  Brain.Screen.print("ButtonR1 pos %d", PickUpMotor_position);     
      //  int motorRotation = PickUpMotor_motor_degrees(PickUpMotor_position);
      //  Brain.Screen.print(" motorRotation %d", motorRotation);
      //  Brain.Screen.newLine(); 

      //  PickUpMotor.spinToPosition(motorRotation ,deg);
      //
      // }
      //
    }
    //else
    //{
    //  PickUpMotorpressed = false;
    //  
    //}
    wait(25, msec);
}

