using namespace vex;

// Setup
vex::brain Brain;
vex::controller Controller = vex::controller();
vex::controller ControllerX = vex::controller(vex::controllerType::partner);
vex::motor Right1 (vex::PORT10, vex::gearSetting::ratio18_1, false);
vex::motor Left1 (vex::PORT11, vex::gearSetting::ratio18_1, true);
vex::motor Lift1 (vex::PORT12, vex::gearSetting::ratio18_1, false);
vex::motor Reaper (vex::PORT14, vex::gearSetting::ratio18_1, false);
vex::motor Intaker (vex::PORT15, vex::gearSetting::ratio18_1, true);
vex::motor Fw (vex::PORT6, vex::gearSetting::ratio18_1, true);
vex::motor Fw2 (vex::PORT7, vex::gearSetting::ratio18_1, false);
vex::motor Claw1(vex::PORT1, vex::gearSetting::ratio18_1, true);

// Move tracks
void go(int direction){
    Left1.spin(vex::directionType::fwd, Controller.Axis3.value()*direction, vex::velocityUnits::pct);
    Right1.spin(vex::directionType::fwd, Controller.Axis2.value()*direction, vex::velocityUnits::pct);
}

// Lift
void lift(int setting1){
    Lift1.spin(vex::directionType::fwd, setting1, vex::velocityUnits::pct);
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

//Spin intake
void intake(int direction){
    Intaker.spin(vex::directionType::fwd, 100*direction, vex::velocityUnits::pct);
}

// Move claw
void claw(int setting){
    Claw1.spin(vex::directionType::fwd, setting, vex::velocityUnits::pct);
}

// Set lift
void setLift(int angle){
    Lift1.rotateTo(angle, rotationUnits::deg, 20, vex::velocityUnits::pct);
}

// Set claw
void setClaw(int angle){
    Claw1.rotateTo(angle, rotationUnits::deg, 20, vex::velocityUnits::pct);
}

