// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Drivetrain           drivetrain    1, 2, A         
// Controller1          controller                    
// forklift             motor_group   3, 4            
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;
int forklift_positions[3] = {90, 60, 0};
int forklift_position = 0;
int forklift_positions_length = sizeof(forklift_positions)/sizeof(forklift_positions[0]);

int forklift_motor_degrees(int pos) {
  int forklift_degrees = forklift_positions[pos % 3];
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
void autonomous_forklift_down() {
  forklift_position ++ ;
  if(forklift_position < 0){
    forklift_position = 0;
  }
  if(forklift_position >= forklift_positions_length) {
    forklift_position = forklift_positions_length -1;
  }
  Brain.Screen.print("ButtonR2 pos %d", forklift_position);     
  int motorRotation = forklift_motor_degrees(forklift_position);
  Brain.Screen.print("motorRotation %d", motorRotation);
  Brain.Screen.newLine(); 
        
  forklift.spinToPosition(motorRotation ,deg);
};
void autonomous_forklift_up() {
  forklift_position -- ;
  if(forklift_position < 0){
    forklift_position = 0;
  }
  if(forklift_position >= forklift_positions_length) {
    forklift_position = forklift_positions_length -1;
  }
  Brain.Screen.print("ButtonR1 pos %d", forklift_position);     
  int motorRotation = forklift_motor_degrees(forklift_position);
  Brain.Screen.print(" motorRotation %d", motorRotation);
  Brain.Screen.newLine(); 

  forklift.spinToPosition(motorRotation ,deg);
}
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
    
    if (Controller1.ButtonR1.pressing() || Controller1.ButtonR2.pressing()) {
      if (forkliftpressed==false && Controller1.ButtonR2.pressing() ) {
        forkliftpressed = true;
        forklift_position ++ ;
        if(forklift_position < 0){
          forklift_position = 0;
        }
        if(forklift_position >= forklift_positions_length) {
          forklift_position = forklift_positions_length -1;
        }
        Brain.Screen.print("ButtonR2 pos %d", forklift_position);     
        int motorRotation = forklift_motor_degrees(forklift_position);
        Brain.Screen.print("motorRotation %d", motorRotation);
        Brain.Screen.newLine(); 
        
        forklift.spinToPosition(motorRotation ,deg);
        
      }
      else if (forkliftpressed==false && Controller1.ButtonR1.pressing()) {
        forkliftpressed = true;
        forklift_position -- ;
        if(forklift_position < 0){
          forklift_position = 0;
        }
        if(forklift_position >= forklift_positions_length) {
          forklift_position = forklift_positions_length -1;
        }
        Brain.Screen.print("ButtonR1 pos %d", forklift_position);     
        int motorRotation = forklift_motor_degrees(forklift_position);
        Brain.Screen.print(" motorRotation %d", motorRotation);
        Brain.Screen.newLine(); 

        forklift.spinToPosition(motorRotation ,deg);
        
      }
    }
    else
    {
      forkliftpressed = false;
      
    }
    wait(25, msec);
  }
}

