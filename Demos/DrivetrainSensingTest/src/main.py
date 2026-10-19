# ----------------------------------------------------------------------------- #
#                                                                               #             
# 	Project:        Drivetrain Sensing                                          #
#   Module:         main.py                                                     #
#   Author:         VEX                                                         #
#   Created:        Fri Aug 05 2022                                             #
#	Description:    This example will show all of the available commands        #
#                   for using the Drivetrain                                    #
#                                                                               #                                                                          
#   Configuration:  V5 Speedbot (Drivetrain 2-motor, No Gyro)                   #
#                                                                               #                                                                          
# ----------------------------------------------------------------------------- #

# Library imports
from vex import *
from utime import ticks_ms, ticks_add

# Brain should be defined by default
brain=Brain()

# Robot configuration code
left_drive_smart = Motor(Ports.PORT1, GearSetting.RATIO_18_1, False)
right_drive_smart = Motor(Ports.PORT2, GearSetting.RATIO_18_1, True)
drivetrain = DriveTrain(left_drive_smart, right_drive_smart, 319.19, 295, 40, MM, 1)

ticks_add(-1 * ticks_ms())

# Begin project code
drivetrain.drive(FORWARD)

# Print all Drivetrain sensing values to the screen in an infinite loop
while True:
    # Clear the screen and set the cursor to top left corner on each loop
    brain.screen.clear_screen()
    brain.screen.set_cursor(1,1)

    # print("\033[2J") # Clear the console
    print("Ticks (ms): ", ticks_ms())
    brain.screen.print("Velocity:", drivetrain.velocity(PERCENT))
    print("Velocity:", drivetrain.velocity(PERCENT))
    brain.screen.next_row()

    brain.screen.print("Current:", drivetrain.current(CurrentUnits.AMP))
    print("Current:", drivetrain.current(CurrentUnits.AMP))

    brain.screen.next_row()

    brain.screen.print("Power:", drivetrain.power(PowerUnits.WATT))
    print("Power:", drivetrain.power(PowerUnits.WATT))

    brain.screen.next_row()

    brain.screen.print("Torque:", drivetrain.torque(TorqueUnits.NM))
    print("Torque:", drivetrain.torque(TorqueUnits.NM))
        
    brain.screen.next_row()

    brain.screen.print("Efficiency:", drivetrain.efficiency(PERCENT))
    print("Efficiency:", drivetrain.efficiency(PERCENT))
        
    brain.screen.next_row()

    brain.screen.print("Temperature:", drivetrain.temperature(TemperatureUnits.CELSIUS))
    print("Temperature:", drivetrain.temperature(TemperatureUnits.CELSIUS))
    brain.screen.next_row()

    # A brief delay to allow text to be printed without distortion or tearing
    wait(100,MSEC)
    
