//Custom library
#include "testlibrary.c"

task main(){
	
	//direction
	int x = 1;
	//determines whether controls can be reversed
	int allowChange = 1;
	
	Robot ROBOT;

	//construct robot
	ROBOT.left = port1;
	ROBOT.right = port10;
	ROBOT.lift1 = port3;
	ROBOT.lift2 = port4;

	while(true){
		
		//if right button pressed
		if(vexRT[Btn8R]==1){
			//controls can be reversed
			if(allowChange==1){
				//reverse controls
				x = x*-1;
				//does not allow another reversal of controls while button is held
				allowChange = 0;
			}
		}
		
		else{
			//controls can be reversed after releasing the button
			allowChange = 1;
		}

		//move
		if(abs(vexRT[Ch2])>20 || abs(vexRT[Ch3])>20){
			go(ROBOT,vexRT[Ch3],vexRT[Ch2],x);
		}

		//stop
		else{
			go(ROBOT,0,0,x);
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
