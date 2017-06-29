sbit LED1 at GPIOB_ODR.B13;
unsigned on;
void main() {
               GPIO_Digital_Output(&GPIOB_BASE, _GPIO_PINMASK_13);
               UART2_Init(9600);
               Delay_ms(100);
               LED1=0;
               while(1)
               {
                   if(UART2_Data_Ready()==1)
                   {
                      on = UART2_Read();
                      if(on==1)
                      {
                          LED1 = ~LED1;
                          Delay_ms(500);
                      }
                   }
                }
              }