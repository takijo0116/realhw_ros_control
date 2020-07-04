#include <ros/package.h>
#include <angles/angles.h>
#include <realhw_control/realhw.h>
#include <iostream> // for debug
#include <math.h>

TRobo::TRobo()
{

  // connect and register the joint state interface
  hardware_interface::JointStateHandle state_handle_1("joint1", &pos_[0], &vel_[0], &eff_[0]);
  jnt_state_interface.registerHandle(state_handle_1);

  registerInterface(&jnt_state_interface);

  // connect and register the joint position interface
  hardware_interface::JointHandle pos_handle_1(jnt_state_interface.getHandle("joint1"), &cmd_[0]);
  jnt_pos_interface.registerHandle(pos_handle_1);

  registerInterface(&jnt_pos_interface);
}

void TRobo::timeCallback(const std_msgs::Float32::ConstPtr& msg_sub)
{

  pos_[0]=msg_sub->data; //set pos_[0] as real_hw date

}

void TRobo::read(ros::Time time, ros::Duration period)
{
  
  sub = nh.subscribe("response" ,100000,&TRobo::timeCallback, this); //to use subscribe in class, use "this"

}

void TRobo::write(ros::Time time, ros::Duration period)
//void TRobo::write(ros::Time time, ros::Duration period,std_msgs::Float32 msg_pub)
{
  //msg_pub.data=0.01;
  std_msgs::Float32 msg_pub;
  msg_pub.data=cmd_[0];
  pub = nh.advertise<std_msgs::Float32>("request",100000,true);
  pub.publish(msg_pub);
}

