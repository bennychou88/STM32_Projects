#include "pwm.h"
#include "PID.h"
#include "math.h"
#include "TIM.h"
#include "DataScope_DP.h"
#include "delay.h"
void PWM_Init(u16 arr,u16 psc)
{  
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
    
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);// 
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOB , ENABLE);  	                                                                     	

   //设置该引脚为复用输出功能,输出TIM3 CH1的PWM脉冲波形
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_7;     //TIM3_CH1、2
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;     //复用推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
   
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1;     //TIM3_CH3、4
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;     //复用推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
    
	TIM_TimeBaseStructure.TIM_Period = arr; 	 
	TIM_TimeBaseStructure.TIM_Prescaler =psc; 
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; 
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure); 
 
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; 
	TIM_OCInitStructure.TIM_Pulse = 0; 
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; 
	TIM_OC1Init(TIM3, &TIM_OCInitStructure);  
    
    TIM_OCInitStructure.TIM_Pulse = 0; 
    TIM_OC2Init(TIM3, &TIM_OCInitStructure);  
    
    TIM_OCInitStructure.TIM_Pulse = 0; 
    TIM_OC3Init(TIM3, &TIM_OCInitStructure);  
    
    TIM_OCInitStructure.TIM_Pulse = 0; 
    TIM_OC4Init(TIM3, &TIM_OCInitStructure);  
    
    TIM_OC1PreloadConfig(TIM3, TIM_OCPreload_Enable); 
    TIM_OC2PreloadConfig(TIM3, TIM_OCPreload_Enable); 	
    TIM_OC3PreloadConfig(TIM3, TIM_OCPreload_Enable); 
    TIM_OC4PreloadConfig(TIM3, TIM_OCPreload_Enable); 
	
	TIM_ARRPreloadConfig(TIM3, ENABLE); //使能TIMx在ARR上的预装载寄存器
	TIM_Cmd(TIM3, ENABLE);  
}


void PWM_Init_2(u16 arr,u16 psc)
{  
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
    
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM5, ENABLE);// 
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);  	                                                                     	

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3;     //TIM3_CH1、2
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;     //复用推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
    
	TIM_TimeBaseStructure.TIM_Period = arr; 	 
	TIM_TimeBaseStructure.TIM_Prescaler =psc; 
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; 
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure); 
 
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; 
	TIM_OCInitStructure.TIM_Pulse = 00; 
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; 
	TIM_OC1Init(TIM2, &TIM_OCInitStructure);  
    
    TIM_OCInitStructure.TIM_Pulse = 00; 
    TIM_OC2Init(TIM2, &TIM_OCInitStructure);  
    
    TIM_OCInitStructure.TIM_Pulse = 00; 
    TIM_OC3Init(TIM2, &TIM_OCInitStructure);  
    
    TIM_OCInitStructure.TIM_Pulse = 00; 
    TIM_OC4Init(TIM2, &TIM_OCInitStructure);  
    
    TIM_OC1PreloadConfig(TIM2, TIM_OCPreload_Enable); 
    TIM_OC2PreloadConfig(TIM2, TIM_OCPreload_Enable); 	
    TIM_OC3PreloadConfig(TIM2, TIM_OCPreload_Enable); 
    TIM_OC4PreloadConfig(TIM2, TIM_OCPreload_Enable); 
	
	TIM_ARRPreloadConfig(TIM2, ENABLE); //使能TIMx在ARR上的预装载寄存器
	TIM_Cmd(TIM2, ENABLE);  
}
      
