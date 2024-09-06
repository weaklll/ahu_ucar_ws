#include <thread>
#include <iostream>
#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
#include <unistd.h>
#include <cstdlib>
#include "std_msgs/Int32.h"
#include <sys/types.h>
#include <sys/wait.h>




int main(int argc,char**argv)
{

    ros::init(argc,argv,"final");
    ros::param::set("/if_follow_line", 0);
    std::cout<<"是否成功打开导航:"<<std::endl;
    std::string userInput2;
    
    std::cout << "导航是否正常? (Y/N): ";

    std::cin >> userInput2;

    while(1)
    {
        if(userInput2=="y" or userInput2=="Y")
        {
            break;
        }
    }

    std::cout<<"准备执行一系列命令:"<<std::endl;
    system("gnome-terminal -- roslaunch rknn_ros yolov5.launch");
    std::cout<<"是否完成视频采集任务："<<std::endl;
    std::string userInput;
    
    std::cout << "视觉是否正常? (Y/N): ";
    std::cin >> userInput;

    system("gnome-terminal -- rosrun send_goals visial_line5_4.py");

    std::cout<<"是否完成巡线："<<std::endl;
    std::string userInput4;
    
    std::cout << "是否正常? (Y/N): ";
    std::cin >> userInput4;
    while(1)
    {
        if(userInput4=="y" or userInput4=="Y")
        {
            break;
        }
        else
            system("gnome-terminal -- killall roslaunch");
    }
    while(1)
    {
        
        if(userInput=="y" or userInput=="Y")
        {
            std::string userInput3;
            std::cout << "是否启动语音唤醒： ";
            
            std::cin >> userInput3;
            if(userInput3=="y" or userInput3=="Y")
            {
                system("gnome-terminal -- roslaunch speech_command speech_command.launch");
                while(1)
                {
                    int result=0;
                    ros::param::get("/speech",result);
                    if(result)
                    {
                        system("gnome-terminal -- roslaunch send_goals send_final.launch");
                        break;
                    }
                        
                }
            }
            else
            {
                system("gnome-terminal -- roslaunch send_goals send_final.launch");
                break;
            }

        }
        else
            exit(0);
    }
    return 0;
}
