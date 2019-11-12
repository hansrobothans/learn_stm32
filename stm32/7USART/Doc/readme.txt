1-初始化串口需要用到的GPIO
2-初始化串口，USART_InitTypeDef
3-中断配置（接收中断，中断优先级）
4-使能串口
5-编写发送和接收函数
6-编写中断服务函数







USART初始化结构体
typedef struct
{
  uint32_t USART_BaudRate;      //波特率 BRR
  uint16_t USART_WordLength;    //字长 CR1_M
  uint16_t USART_StopBits;      //停止位 CR2_STOP
  uint16_t USART_Parity;        //校验控制 CR1_PCE、CR1_PS
  uint16_t USART_Mode;          //模式选择CR1_TE、CR1_RE
  // 硬件流选择 CR3_CTSE、CR3_RTSE
  uint16_t USART_HardwareFlowControl;
} USART_InitTypeDef;


同步时钟初始化结构体
typedef struct
{
  uint16_t USART_Clock;      // 同步时钟 CR2_CLKEN
  uint16_t USART_CPOL;       // 极性 CR2_CPOL
  uint16_t USART_CPHA;       // 相位 CR2_CPHA
  uint16_t USART_LastBit;    //最后一个位的时钟脉冲 CR2_LBC
} USART_ClockInitTypeDef;


1-串口初始化函数
void USART_Init
(USART_TypeDef* USARTx, USART_InitTypeDef* USART_InitStruct)


2-中断配置函数
void USART_ITConfig
(USART_TypeDef* USARTx, uint16_t USART_IT, 
FunctionalState NewState)


3-串口使能函数
void USART_Cmd(USART_TypeDef* USARTx, 
FunctionalState NewState)


4-数据发送函数
void USART_SendData
(USART_TypeDef* USARTx, uint16_t Data)


5-数据接收函数
uint16_t USART_ReceiveData(USART_TypeDef* USARTx)


6-中断状态位获取函数
ITStatus USART_GetITStatus
(USART_TypeDef* USARTx, uint16_t USART_IT)

