#pragma systemFile

//acts as a template for representing a robot
struct Robot {
	//properties of this template are the motors
	tMotor left;
	tMotor right;
	tMotor lift1;
	tMotor lift2;
};

//function that takes the powers of the left motor and right motor, along with the direction of travel as its inputs
void go(Robot robot, int lPower, int rPower, int direction){
	motor[robot.left] = direction*lPower;
	motor[robot.right] = direction*rPower;
}

//stopping function that sets the powers of the left and right motor to 0
void halt(Robot robot,int direction){
	go(robot,0,0,direction);
}

//lifting function that takes the power of the lift motors as its inputs
void lift(Robot robot, int liftPower){
	motor[robot.lift1] = liftPower;
	motor[robot.lift2] = liftPower;
}
