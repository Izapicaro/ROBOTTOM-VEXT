#include "robot-config.h"
          
int main() {
    
    // Print to screen that program has started
    Brain.Screen.print("TELL CONTROL FREAKS");
    Brain.Screen.newLine();
    Brain.Screen.print("ROBOTTOM VEXT");

    // Variables
    int x = 1;
    int allowChange = 1;
    
    int clawLevel = 0;
    int liftLevel = 0;
    
    int wheelPower = 0;
    
    int allowSwitch = 1;
    int clawMode = 1;
    
    // Reset rotations after autonomous
    Lift1.resetRotation();
    Claw1.resetRotation();
    
    while(true){
        
        // Clear screen
        Brain.Screen.clearScreen();

        // Rotation value
        Brain.Screen.printAt(1, 20, "Lift1: %f degrees", Lift1.rotation(rotationUnits::deg));
        
        // Rotation value
        Brain.Screen.printAt(1,60, "Claw: %f degrees", Claw1.rotation(rotationUnits::deg));
        
        // If button A is being pressed
        if(Controller.ButtonA.pressing()){ 
            // For the bants
            //Controller.rumble(".-.-");
   
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
        if(Controller.ButtonL1.pressing()){
            reap(1);
        }
        
        // Reap backwards
        else if(Controller.ButtonL2.pressing()){
            reap(-1);
        }
        
        // Reap stop
        else{
            reap(0);
        }
        
        // Flywheel forwards
        if(Controller.ButtonX.pressing()){
            wheel(1);
        }

        // Flywheel stop
        else{
            Fw.stop();
            Fw2.stop();
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
        if(ControllerX.ButtonR1.pressing()){
            
            //Runs as long as lift is not past limit
            if(Lift1.rotation(rotationUnits::deg)<5000){
                lift(-100);
            }
            
            else{
                lift(0);
            }

            liftLevel = Lift1.rotation(rotationUnits::deg);
        }
        
        // Lower lift
        else if(Controller.ButtonR2.pressing()){

            //Runs as long as lift is not past limit
            if(Lift1.rotation(rotationUnits::deg)>=0){
                lift(100);
            }
            
            else{
                lift(0);
            }
            
            liftLevel = Lift1.rotation(rotationUnits::deg);
        }
        
        // Maintain lift position
        else{
            setLift(liftLevel);
        }
        
        // Intake up
        if(Controller.ButtonR1.pressing()){
            intake(1);
        }
        
        // Intake down
        else if(Controller.ButtonR2.pressing()){
            intake(-1);
        }
        
        // Intake stop
        else{
            intake(0);
        }
        
        // Rotate claw to 0
        if(ControllerX.ButtonX.pressing()){
            setClaw(0);
            clawLevel = 0;
        }
        
        // Rotate claw to 90
        else if(ControllerX.ButtonA.pressing()){
            setClaw(90);
            clawLevel = 90;
        }
        
        //Rotate claw to 180
        else if(ControllerX.ButtonB.pressing()){
            setClaw(180);
            clawLevel = 180;
        }
        
        // Claw up
        if(ControllerX.ButtonL1.pressing()){
            claw(100);
            clawLevel = Claw1.rotation(rotationUnits::deg);
        }
        
        // Claw down
        else if (ControllerX.ButtonL2.pressing()){
            claw(-100);
            clawLevel = Claw1.rotation(rotationUnits::deg);
        }
        
        // Claw maintain position
        else{
            setClaw(clawLevel);
        }
               
        // Something about not wasting resources
        vex::task::sleep(20);
    }
}


/* TESTING

Competition template
Claw power/direction
Claw presets
Lift power/direction
Lift limit
Dual remotes
Autonomous

*/
