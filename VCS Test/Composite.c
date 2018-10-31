#include "robot-config.h"
          
int main() {
    
    // Print to screen that program has started
    Brain.Screen.print("TELL CONTROL FREAKS");
    Brain.Screen.newLine();
    Brain.Screen.print("ROBOTTOM VEXT");

    int x = 1;
    int allowChange = 1;
    int reapState = 0;
    
    while(true){
        
        // If button A is pressed
        if(Controller.ButtonA.pressing()){
            
            // For the bants
            Controller.rumble(".-.-.-.-");
            
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
        
        // If button X is pressed
        if(Controller.ButtonX.pressing()){
            // Reap forwards
            reapState = reapDirection(reapState);
            reap(reapState);
        }
        
        // If button B is pressed
        else if(Controller.ButtonB.pressing()){
            // Reap backwards
            reapState = -reapDirection(reapState);
            reap(reapState);
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
        if(Controller.ButtonUp.pressing()){
            lift(1);
        }
        
        // Lower lift
        else if(Controller.ButtonDown.pressing()){
            lift(-1);
        }
        
        // Stop lift
        else{
            lift(0);
        }
               
        // Something about not wasting resources
        vex::task::sleep(20);
    }
}
