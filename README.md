# Beer Robot

## Description

  Mecanum Mobile Robotics Platform to aid in the completion of everyday tasks.
  This is a low profile mobile platform measuring ~(footprint)400mm x 300mm
  This is a Mecanum driven robot (omnidirectional) with a 4-axis arm attached to it

## Goal

  Activation via Google Voice API - Robot retrieval of user specific object from within
  predetermined space.

# Acceptance Criteria

  - [ ] User activates Google Home system via voice from specific room in house
  - [ ] User requests "Bring me a beer"
  - [ ] Robot is aware of its current position
  - [ ] Robot activates from "sleep" state
  - [ ] Robot navigates to predetermined location of "Fridge"
  - [ ] Robot localises using Aruco Markers
  - [ ] ~~Robot uses arm gripper to pick up "beer"~~
  - [ ] Robot navigates to room containing Google device
  - [ ] Robot uses D435i to detect person
  - [ ] Robot navigates to person
  - [ ] ~~Robot presents "beer"~~
  - [ ] ~~Robot releases "beer"~~
  - [ ] Robot returns to home location
  - [ ] Robot re-enters "sleep" state

## Hardware Todo List

  - [X] Create CAD Model
  - [X] Source Aluminium Parts
  - [X] Source Electronic + Electrical
  - [ ] Create schematic
  - [X] Trim Motor Wires
  - [ ] Integrate Teensy
  - [ ] Countersink bottom holes
  - [ ] Create D435i Mount
  - [ ] Dry fit battery Test all components
  - [X] Start panicking about Arduino Code


# Mobile Robotics Platform Specifications

## Parts

    Electrical:
    
        7S3P 100000mAh LiIon Battery (https://www.aliexpress.com/item/1005006059348103.html?spm=a2g0o.order_list.order_list_main.49.21ef1802hCLrDk)
        


        5x DC-DC Buck Converter 1.25V-35V 3A (https://www.aliexpress.com/item/1005005643579541.html?spm=a2g0o.order_list.order_list_main.23.21ef1802VBfRln)
            Stepped down from 25.2V to:
                5V - LEDs
                19V - Jetson Orin Nano
                24V - Motor Drivers

        14AWG Silicone Wire - VBAT wiring loop (https://www.aliexpress.com/item/1005002701853634.html?spm=a2g0o.order_list.order_list_main.11.21ef1802VBfRln)

        4mm Banana Plugs - 3-phase motor connectors (https://www.aliexpress.com/item/1005005421540085.html?spm=a2g0o.order_list.order_list_main.35.21ef1802VBfRln)

        
  DriveTrain:

        4x 6374 170KV BDLC 24V-35V w Hall Sensor (https://www.aliexpress.com/item/33015959947.html?spm=a2g0o.order_list.order_list_main.17.5bc618029gEles)
            Power (24V): 2800W
            Weight: 809G
            Input voltage: 24V/36V
            Speed: 4100 (RPM)
            Shaft diameter: 10.0MM
            Maximum current: 120 (A)
            No-load current (24V): 1.7 (A)
            24V/36V are applicable
            Plug: 4.0 banana head
            Hall plug (optional): 2.0/5P plug    
            14 pole pairs

        100mm Mecanum Wheel (https://www.aliexpress.com/item/1005004322316722.html?spm=a2g0o.productlist.main.3.742d7b23Io1wA6&algo_pvid=2f9e3023-6e54-4dfb-9720-61ea9173b9ba&algo_exp_id=2f9e3023-6e54-4dfb-9720-61ea9173b9ba-1&pdp_npi=4%40dis%21AUD%21140.62%21140.62%21%21%21667.40%21%21%402103277f17031945637128111ecd8b%2112000028753081982%21sea%21AU%21138612706%21&curPageLogUid=fuOZjpYtogjM)
            

        10mm Shaft Wheel Coupling (https://www.aliexpress.com/item/32809138729.html?spm=a2g0o.order_list.order_list_main.29.5bc618029gEles)

  Electronics:

        Jetson Orin Nano 8GB (https://www.amazon.com.au/NVIDIA-Jetson-Orin-Nano-Developer/dp/B0BZJTQ5YP/ref=sr_1_5?keywords=jetson+nano&qid=1703194760&sr=8-5)
            Jetpack Version: 
            

        RPLidar A1M8 (https://www.amazon.com.au/Slamtec-RPLIDAR-A1M8-Avoidance-Navigation/dp/B07TJW5SXF/ref=sr_1_1?crid=392X1G97TUXNX&keywords=rplidar&qid=1703194864&sprefix=rplida%2Caps%2C367&sr=8-1)(https://github.com/Slamtec/rplidar_ros)

        Intel RealSense D435i (https://www.amazon.com.au/Intel-RealSense-Depth-Camera-D435i/dp/B07MWR2YJB/ref=sr_1_3?crid=1Q0SCDERQCANX&keywords=intel+realsense+d435&qid=1703194907&sprefix=intel+reals%2Caps%2C275&sr=8-3)

        ROS 9DOF IMU HFI-A9 (https://www.aliexpress.com/item/1005006190415425.html?spm=a2g0o.productlist.main.3.72e026d40iskKZ&algo_pvid=1c1d3fb0-dea3-4ca4-972d-1dac18a98f1c&algo_exp_id=1c1d3fb0-dea3-4ca4-972d-1dac18a98f1c-1&pdp_npi=4%40dis%21AUD%2154.04%2147.55%21%21%21256.49%21%21%402101c59117031949323855357eee27%2112000036199684567%21sea%21AU%21138612706%21&curPageLogUid=pzQXO1gJpTkT)(https://github.com/HANDS-FREE/handsfree_ros_imu)

        2x MKS Odrive 3.6 (https://www.aliexpress.com/item/1005006314725836.html?spm=a2g0o.order_list.order_list_main.41.5bc618029gEles) (https://github.com/makerbase-mks/ODrive-MKS)

        JST PH2.0 Connectors - Motor Hall Sensors (https://www.aliexpress.com/item/32959854422.html?spm=a2g0o.order_list.order_list_main.5.21ef1802VBfRln)

        CUI Devices AMT103 Motor Encoders (https://www.cuidevices.com/product/resource/amt10.pdf)

## Build

```bash
# create the workspace catkin_ws/src
mkdir -p catkin_ws/src

cd catkin_ws/src

git clone https://github.com/vlad-mantoiu/BeerRobot.git
#git clone git@github.com:vlad-mantoiu/BeerRobot.git

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
roslaunch mobile_robot_nav slam.launch

roscd mobile_robot_nav/maps

rosrun map_server map_saver -f <map_name>
```

## Commands for navigation

```bash
roslaunch mobile_robot gazebo_house.launch

roslaunch mobile_robot_nav nav.launch
```

## Commands for Testing

```bash
rosrun rosserial_python serial_node.py _port:=/dev/ttyUSB0 _baud:=57600

rostopic echo /cmd_vel

rostopic echo /buttons

```
        
