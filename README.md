# BeerRobot

Description:

  Mecanum Mobile Robotics Platform to aid in the completion of everyday tasks.
  This is a low profile mobile platform measuring ~(footprint)400mm x 300mm
  This is a Mecanum driven robot (omnidirectional) with a 4-axis arm attached to it

Goal:
  Activation via Google Voice API - Robot retrieval of user specific object from within
  predetermined space.


## Build

```bash
# create the workspace catkin_ws/src
mkdir -p catkin_ws/src

cd catkin_ws/src

git clone https://github.com/vlad-mantoiu/BeerRobot.git

cd ..

catkin_make

source devel/setup.bash

```

## Commands

```bash
# rviz
roslaunch mobile_robot display.launch

# gazebo
roslaunch mobile_robot gazebo.launch
```

## Commands for mapping

```bash
roslaunch mobile_robot gazebo_house.launch

roslaunch mobile_robot_nav slam.launch

roscd mobile_robot_nav/maps

rosrun map_server map_saver -f <map_name>
```

## Commands for navigation

```bash
roslaunch mobile_robot gazebo_house.launch

roslaunch mobile_robot_nav nav.launch
```

        
