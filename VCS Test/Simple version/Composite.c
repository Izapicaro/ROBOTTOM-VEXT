#include "robot-config.h"
          
int main() {
    
    // Print to screen that program has started
    Brain.Screen.print("TELL CONTROL FREAKS");
    Brain.Screen.newLine();
    Brain.Screen.print("ROBOTTOM VEXT");

    int x = 1;
    int allowChange = 1;
    
    while(true){

        Brain.Screen.clearScreen();

        // display the encoder value on the screen
        Brain.Screen.printAt(1, 20, "Left: %f degrees", Left1.rotation(rotationUnits::deg));

        // display the encoder velocity on the screen
        Brain.Screen.printAt(1, 40, "Right: %f degrees", Right1.rotation(rotationUnits::deg));
        
        // If button A is pressed
        if(Controller.ButtonA.pressing()){
            
            // For the bants
            Controller.rumble(".-.-");
            
            // If controls can be reversed
            if(allowChange==1){
                // Reverse controls
                x=x*-1;
                // Controls can no longer be reversed
                allowChange = 0;
            }
        }
        
        // If button A is not pressed
        else{
            // Controls can now be reversed
            allowChange = 1;
        }
        
        // Reap forwards
        if(Controller.ButtonR1.pressing()){
            reap(1);
        }
        
        // Reap backwards
        else if(Controller.ButtonR2.pressing()){
            reap(-1);
        }
        
        // Reap stop
        else{
            reap(0);
        }
        
        // wheel forwards
        if(Controller.ButtonL1.pressing()){
            wheel(1);
        }
        
        // wheel backwards
        else if(Controller.ButtonL2.pressing()){
            wheel(-1);
        }
        
        // wheel stop
        else{
            wheel(0);
        }
        
        // Move robot
        if(abs(Controller.Axis3.value())>20 || abs(Controller.Axis2.value())>20){
            go(x);
        }
       
        // Stop robot
        else{
            go(0);
        }
        
        // Raise lift
        if(Controller.ButtonX.pressing()){
            lift(1);
        }
        
        // Lower lift
        else if(Controller.ButtonY.pressing()){
            lift(-1);
        }
        
        // Stop lift
        else{
            lift(0);
        }
        
        // Intake up
        if(Controller.ButtonL1.pressing()){
            intake(1);
        }
        
        // Intake down
        else if(Controller.ButtonL2.pressing()){
            intake(-1);
        }
        
        // Intake stop
        else{
            intake(0);
        }
               
        // Something about not wasting resources
        vex::task::sleep(20);
    }
}
