//Custom library
#include "testlibrary.c"

task main(){
	
	int x = 1;

	Robot ROBOT;

	//construct robot
	ROBOT.left = port1;
	ROBOT.right = port2;
	ROBOT.lift1 = port3;
	ROBOT.lift2 = port4;

	while(true){
	
		if(vexRT[Btn8R]==1){
			x = x*-1;
		}
	
		//move
		if(abs(vexRT[Ch1])>20 || abs(vexRT[Ch3])>20){
			go(ROBOT,vexRT[Ch3],vexRT[Ch1],x);
		}

		//stop
		else{
			halt(ROBOT,x);
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
