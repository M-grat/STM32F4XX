
#include "stm32f4xx.h"
#include "stm32f4_discovery.h"
int i=0;
void delay(uint32_t time)
{
	while(time--);
}
void RCC_Config()
{
	RCC->CR|=0x00010000;//HSEON  enable
		while(!(RCC->CR&0X00020000));//HSEON Ready Flag wait
		RCC->CR|=0x00080000;//CSS ENABLE
		RCC->PLLCFGR|=0X00400000;//PLL e HSE seçtik
		RCC->PLLCFGR|=0X00000004;//PLL M=4
		RCC->PLLCFGR|=0X00005A00;//PLL N =168
		RCC->PLLCFGR|=0X00000000;//PLL P=2
		RCC->CFGR|=0X00000000;//AHB Prescaler=1
		RCC->CFGR|=0x00080000;//AHB2 Prescaler=2
		RCC->CFGR|=0X00001400;//AHB1 Prescaler=4
		RCC->CIR|=0X00080000;//HSERDY Flag clear
		RCC->CIR|=0X00800000;//CSS Flag clear


}
void DAC1_Config()
{
	RCC->AHB1ENR|=0x00000001;//
	RCC->APB1ENR|=0x20000000;//DAC Clock line ENABLE
	DAC->CR|=0x00000001;//channel 1 ENABLE
	DAC->SWTRIGR|=0x00000000;//DAC Channel 1  software trigger disable
	DAC->DHR12R1|=0x00000000;//DAC Channel 1 12-bit right-aligned data (output voltage 0 voltage)


}
int main(void)
{
RCC_Config();
DAC1_Config();
  while (1)
  {
for(;i<4096;i++)
{
	DAC->DHR12R1=i;
	delay(16800);
}
i=0;
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
