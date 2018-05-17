#pragma systemFile

struct Robot {
	//properties of Robot struct
	tMotor left;
	tMotor right;
	tMotor lift1;
	tMotor lift2;
};

//movement
void go(Robot robot, int lPower, int rPower, int direction){
	motor[robot.left] = direction*lPower;
	motor[robot.right] = direction*rPower;
}

//stopping
void halt(Robot robot,int direction){
	go(robot,0,0,direction);
}

//lift
void lift(Robot robot, int liftPower){
	motor[robot.lift1] = liftPower;
	motor[robot.lift2] = liftPower;
}
