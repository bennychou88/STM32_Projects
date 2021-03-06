#ifndef _PID_H
#define _PID_H



typedef struct  
{ 
	int speed_target;     //设定目标 
  int out_duty;  // 输出占空比
	
	float speed_p; 		//比例常数
	float speed_i; 		//积分常数
	float speed_d;     //微分参数
	
	float ek_0;		  //当前误差
	float ek_1;		  //当前误差
	float ek_sum; 	// 积分项
}Pid_struct;


extern int Speed_PIDAdjust(Pid_struct *motor_pid,int Targe,int Feedback_speed) ;
extern void Speed_PIDInit(Pid_struct *motor_pid);

#endif
