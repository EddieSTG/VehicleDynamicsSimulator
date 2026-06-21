# Vehicle Dynamics Simulator

Vehicle Dynamics Simulator is an honours-stage C++ project that models and visualises realistic road-vehicle behaviour. The simulation targets 14 degrees of freedom (DOF) and includes models for wheels/tyres, drivetrain, suspension, and chassis, plus a simple aerodynamic model to capture drag effects.

## Key goals
- Simulate vehicle dynamics with as much fidelity as feasible within the project timeframe.
- Validate and compare simulation outputs against manufacturer performance metrics (e.g., acceleration and braking times).
- Provide visual telemetry and diagnostics such as RPM, g-forces, steering angle, slip ratio, and weight transfer, and visualise chassis roll, pitch and yaw.

## Simulation details
- 14 DOF vehicle model covering individual wheel dynamics, suspension, drivetrain and chassis motion.
- Tyres are modelled using the Pacejka "Magic Formula" to reproduce realistic lateral and longitudinal tyre forces.
- Aerodynamics handled with a simple drag model to capture speed-dependent forces.

## Intended outcomes
- Accurate reproduction of vehicle performance metrics to enable validation against manufacturer data.
- Interactive visualisation of dynamics and telemetry to aid understanding of how vehicle subsystems interact.

## Build & Run (Windows, MSVC + Ninja)
1. Configure and generate build files:

   `cmake -S . -B build -G Ninja`

2. Build the project:

   `cmake --build build --config Release`

3. Run the executable (example):

   `./build/VehicleDynamicsSimulation/VehicleDynamicsSimulation.exe`

## Notes
- External dependencies (`external/`) include GLFW and GLAD and are tracked as source. Build artifacts are ignored by `.gitignore`.
- If CMake reports missing source files, ensure you run `cmake` from the project root and that source files are present and correctly referenced in `CMakeLists.txt`.
