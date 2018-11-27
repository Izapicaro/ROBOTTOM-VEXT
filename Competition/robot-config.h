using namespace vex;

// Setup
vex::brain Brain;
vex::controller Controller = vex::controller();
vex::controller ControllerX = vex::controller(vex::controllerType::partner);
vex::motor Right1 (vex::PORT10, vex::gearSetting::ratio18_1, true);
vex::motor Left1 (vex::PORT11, vex::gearSetting::ratio18_1, false);
vex::motor Lift1 (vex::PORT12, vex::gearSetting::ratio18_1, true);
vex::motor Reaper (vex::PORT14, vex::gearSetting::ratio18_1, false);
vex::motor Intaker (vex::PORT15, vex::gearSetting::ratio18_1, true);
vex::motor Fw (vex::PORT6, vex::gearSetting::ratio18_1, true);
vex::motor Fw2 (vex::PORT7, vex::gearSetting::ratio18_1, false);
vex::motor Claw1(vex::PORT8, vex::gearSetting::ratio18_1, false);

// Move tracks
void go(int direction){
    if(direction == 1){
        Left1.spin(vex::directionType::fwd, Controller.Axis3.value()*direction, vex::velocityUnits::pct);
        Right1.spin(vex::directionType::fwd, Controller.Axis2.value()*direction, vex::velocityUnits::pct);
    }
    
    else{
        Left1.spin(vex::directionType::fwd, Controller.Axis2.value()*direction, vex::velocityUnits::pct);
        Right1.spin(vex::directionType::fwd, Controller.Axis3.value()*direction, vex::velocityUnits::pct);
    }
}

// Lift
void lift(int power){
    Lift1.spin(vex::directionType::fwd, -power, vex::velocityUnits::pct);
}

// Flywheel
void wheel(int direction){
    Fw.spin(vex::directionType::fwd, 100*direction, vex::velocityUnits::pct);
    Fw2.spin(vex::directionType::fwd, 100*direction, vex::velocityUnits::pct);
}

// Spin reaper
void reap(int direction){
    Reaper.spin(vex::directionType::fwd, 100*direction, vex::velocityUnits::pct);
}

// Spin intake
void intake(int power){
    Intaker.spin(vex::directionType::fwd, 100*power, vex::velocityUnits::pct);
}

// Spin claw
void claw(int power){
    Claw1.spin(vex::directionType::fwd, 0.2*power, vex::velocityUnits::pct);
}
