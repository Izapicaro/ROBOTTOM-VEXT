// Custom library (contents such as functions in a separate file)
#include "testlibrary.c"

// Main section of code
task main(){
	
	// Stores the integer value 1 in a variable called x - I use this value to represent whether the controls have been reversed or not (1 means yes, -1 means no)
	int x = 1;
	// Stores the integer value 1 in a variable called allowChange
	int allowChange = 1;
	
	// Create an instance of the Robot struct (defined in the custom library) called ROBOT
	Robot ROBOT;

	// Assign different ports to the motors (which are properties of the Robot struct)
	ROBOT.left = port1;
	ROBOT.right = port10;
	ROBOT.lift1 = port3;
	ROBOT.lift2 = port4;
	
	// Runs an infinite loop (code continues running indefinitely)
	while(true){
		
		/* If button 8R on the Vex controller (written as 'vexRT[Btn8R]') is pressed (its value is 1, instead of 0), then run the code within the if statement
		Two equal signs mean that it checks the current value of vexRT[Btn8R], rather than assigning a value to it */
		if(vexRT[Btn8R]==1){
			
			// Run code within statement if the allowChange variable has a value of 1
			if(allowChange==1){

				/* Multiply the current value of x by -1 to get its new value (so it'll either change from 1 to -1, or -1 to 1)
				This changes the direction of the controls */
				x = x*-1;

				// Assigns the value 0 to the allowChange variable, to indicate that the button has been pressed
				allowChange = 0;
				/* Now the condition 'allowChange==1' is no longer true
				Therefore the code in this if statement will not run until the value of allowChange is 1 again
				This is important, as we don't want the code to run more than once while the button is being pressed */
			
			} // End if statement

		} // End if statement
		
		/* This pairs with the if statement, so if the condition vexRT[Btn8R]==1 is not true, the code in this statement will run instead
		In other words, it will run if the button is released/is not being pressed */
		else{
			// Assigns the value 1 to allowChange, meaning that the controls can now be reversed again by pressing the 8R button
			allowChange = 1;
		}

		/* If the absolute value (as in |x|) given by the vertical direction of the LEFT joystick (known as channel 2) is greater than 20
		AND
		The absolute value of the vertical direction of the RIGHT joystick (known as channel 3) is greater than 20
		I used the absolute value, since the values of these channels can be negative, which means that the motors go in the opposite direction */
		if(abs(vexRT[Ch2])>20 || abs(vexRT[Ch3])>20){

		/* Runs the go function from the custom library, with the inputs the following inputs: ROBOT, the value of channel 3, the value of channel 2 and the direction x as its inputs
		This means that the left motor of this particular robot runs with power determined by channel 3 and the power of its right motor is determined by channel 2
		Its direction is determined by the variable x */
			go(ROBOT,vexRT[Ch3],vexRT[Ch2],x);
			
		} // End if statement

		// Similarly runs the go function so that the power in the left and right motors of the robot are both 0
		else{
			go(ROBOT,0,0,x);
		}

		// If the button 5U is pressed
		if(vexRT[Btn5U]==1){

			/* Make the motors in the lift of the robot run at full power (which is 127)
			This lift function is also from the custom library */
			lift(ROBOT,127);
		}

		// If the Button 5D is pressed
		else if(vexRT[Btn5D]==1){
			
			// Make the motors in the lift of the robot run at full power in the opposite direction
			lift(ROBOT,-127);
		}

		// If neither button is pressed
		else{
			
			//Make the motors in the lift of the robot have no power
			lift(ROBOT,0);
		}

	}

}
