
#include "stm32f4xx.h"
#include "stm32f4_discovery.h"
TIM_TimeBaseInitTypeDef TIM_InitStructer;
int count;
void TIMER_Config()
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
	TIM_InitStructer.TIM_ClockDivision=TIM_CKD_DIV1;
	TIM_InitStructer.TIM_CounterMode=TIM_CounterMode_Up;
	TIM_InitStructer.TIM_Period=9999;
	TIM_InitStructer.TIM_Prescaler=0x0000;
	TIM_InitStructer.TIM_RepetitionCounter=0;

	TIM_TimeBaseInit(TIM2,&TIM_InitStructer);

	TIM_Cmd(TIM2,ENABLE);
}

int main(void)
{
TIMER_Config();
  while (1)
  {
	  count =TIM_GetCounter(TIM2);
  }
}


/*
 * Callback used by stm32f4_discovery_audio_codec.c.
 * Refer to stm32f4_discovery_audio_codec.h for more info.
 */
void EVAL_AUDIO_TransferComplete_CallBack(uint32_t pBuffer, uint32_t Size){
  /* TODO, implement your code here */
  return;
}

/*
 * Callback used by stm324xg_eval_audio_codec.c.
 * Refer to stm324xg_eval_audio_codec.h for more info.
 */
uint16_t EVAL_AUDIO_GetSampleCallBack(void){
  /* TODO, implement your code here */
  return -1;
}
