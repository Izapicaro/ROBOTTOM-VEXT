using namespace vex;

// Setup
vex::brain Brain;
vex::controller Controller = vex::controller();
vex::motor Right1 (vex::PORT10, vex::gearSetting::ratio18_1, false);
vex::motor Left1 (vex::PORT1, vex::gearSetting::ratio18_1, true);
vex::motor Lift1 (vex::PORT2, vex::gearSetting::ratio18_1, false);
vex::motor Lift2 (vex::PORT3, vex::gearSetting::ratio18_1, true);
vex::motor Reaper (vex::PORT4, vex::gearSetting::ratio18_1, false);
vex::motor Intaker (vex::PORT5, vex::gearSetting::ratio18_1, true);
vex::motor Fw (vex::PORT6, vex::gearSetting::ratio18_1, true);
vex::motor Fw2 (vex::PORT7, vex::gearSetting::ratio18_1, false);

// Move tracks
void go(int direction){
    Left1.spin(vex::directionType::fwd, Controller.Axis3.value()*direction, vex::velocityUnits::pct);
    Right1.spin(vex::directionType::fwd, Controller.Axis2.value()*direction, vex::velocityUnits::pct);
}

// Lift
void lift(int direction){
    Lift1.spin(vex::directionType::fwd, 100*direction, vex::velocityUnits::pct);
    Lift2.spin(vex::directionType::fwd, 100*direction, vex::velocityUnits::pct);
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
void intake(int power){
    Intaker.spin(vex::directionType::fwd, 100*power, vex::velocityUnits::pct);
}

