//Custom library
#include "testlibrary.c"

task main(){

	Robot ROBOT;

	//construct robot
	ROBOT.left = port1;
	ROBOT.right = port2;
	ROBOT.lift1 = port3;
	ROBOT.lift2 = port4;

	while(true){

		//move
		if(abs(vexRT[Ch1])>20 || abs(vexRT[Ch3])>20){
			go(ROBOT,vexRT[Ch3],vexRT[Ch1]);
		}

		//stop
		else{
			halt(ROBOT);
		}

		//lift up
		if(vexRT[Btn5U]==1){
			lift(ROBOT,127);
		}

		//lift down
		else if(vexRT[Btn5D]==1){
			lift(ROBOT,-127);
		}

		//lift stop
		else{
			lift(ROBOT,0);
		}

	}

}
