#pragma systemFile

struct Robot {
	//properties of Robot struct
	tMotor left;
	tMotor right;
	tMotor lift1;
	tMotor lift2;
};

//movement
void go(Robot robot, int lPower, int rPower){
	motor[robot.left] = lPower;
	motor[robot.right] = -rPower;
}

//stopping
void halt(Robot robot){
	go(robot,0,0);
}

//lift
void lift(Robot robot, int liftPower){
	motor[robot.lift1] = liftPower;
	motor[robot.lift2] = liftPower;
}
