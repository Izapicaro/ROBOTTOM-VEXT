#include "robot-config.h"
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*        Description: Competition template for VCS VEX V5                    */
/*                                                                           */
/*---------------------------------------------------------------------------*/

//Creates a competition object that allows access to Competition methods.
vex::competition    Competition;

//Variables

int x = 1;
int allowChange = 1;
double clawLevel = 0;
double liftLevel = 0;


/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */ 
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton( void ) {
    // Print to screen that program has started
    //Brain.Screen.print("TELL CONTROL FREAKS");
    //Brain.Screen.newLine();
    //Brain.Screen.print("ROBOTTOM VEXT");
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous( void ) {
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
  
  while(true){
      wheel(1);
      Intaker.rotateFor(5,vex::timeUnits::sec, 0, vex::velocityUnits::pct);
      Intaker.rotateFor(10,vex::timeUnits::sec, 100, vex::velocityUnits::pct);
  }
 
  //if(Fw.velocity(velocityUnits::pct)>=70){
      //Intaker.rotateFor(15, vex::timeUnits::sec, 100, vex::velocityUnits::pct);
  //}
  //Left1.rotateFor(5, vex::timeUnits::sec, 100, vex::velocityUnits::pct);
  //Right1.rotateFor(5, vex::timeUnits::sec, 100, vex::velocityUnits::pct);
  //go(0);

}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol( void ) {
    
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
        if(Controller.ButtonLeft.pressing()){
            wheel(1);
        }
        
        // wheel backwards
        else if(Controller.ButtonRight.pressing()){
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
        
        // Track position
        if(ControllerX.Axis2.value()!=0){
            claw(ControllerX.Axis2.value());
            clawLevel = Claw1.rotation(vex::rotationUnits::deg);
        }
        
        else{
            Claw1.rotateTo(clawLevel, vex::rotationUnits::deg, 10, vex::velocityUnits::pct);
        }
        
        // Track position
        if(ControllerX.Axis3.value()!=0){
            lift(-ControllerX.Axis3.value());
            liftLevel = Lift1.rotation(vex::rotationUnits::deg);
        }
        
        else{
            Lift1.rotateTo(liftLevel, vex::rotationUnits::deg, 10, vex::velocityUnits::pct);
        }
        
        // Something about not wasting resources
        vex::task::sleep(20);
    }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
    
    //Run the pre-autonomous function. 
    pre_auton();
    
    //Set up callbacks for autonomous and driver control periods.
    Competition.autonomous( autonomous );
    Competition.drivercontrol( usercontrol );

    //Prevent main from exiting with an infinite loop.                        
    while(1) {
      vex::task::sleep(100);//Sleep the task for a short amount of time to prevent wasted resources.
    }    
       
}

