1-��ʼ��������Ҫ�õ���GPIO
2-��ʼ�����ڣ�USART_InitTypeDef
3-�ж����ã������жϣ��ж����ȼ���
4-ʹ�ܴ���
5-��д���ͺͽ��պ���
6-��д�жϷ�����







USART��ʼ���ṹ��
typedef struct
{
  uint32_t USART_BaudRate;      //������ BRR
  uint16_t USART_WordLength;    //�ֳ� CR1_M
  uint16_t USART_StopBits;      //ֹͣλ CR2_STOP
  uint16_t USART_Parity;        //У����� CR1_PCE��CR1_PS
  uint16_t USART_Mode;          //ģʽѡ��CR1_TE��CR1_RE
  // Ӳ����ѡ�� CR3_CTSE��CR3_RTSE
  uint16_t USART_HardwareFlowControl;
} USART_InitTypeDef;


ͬ��ʱ�ӳ�ʼ���ṹ��
typedef struct
{
  uint16_t USART_Clock;      // ͬ��ʱ�� CR2_CLKEN
  uint16_t USART_CPOL;       // ���� CR2_CPOL
  uint16_t USART_CPHA;       // ��λ CR2_CPHA
  uint16_t USART_LastBit;    //���һ��λ��ʱ������ CR2_LBC
} USART_ClockInitTypeDef;


1-���ڳ�ʼ������
void USART_Init
(USART_TypeDef* USARTx, USART_InitTypeDef* USART_InitStruct)


2-�ж����ú���
void USART_ITConfig
(USART_TypeDef* USARTx, uint16_t USART_IT, 
FunctionalState NewState)


3-����ʹ�ܺ���
void USART_Cmd(USART_TypeDef* USARTx, 
FunctionalState NewState)


4-���ݷ��ͺ���
void USART_SendData
(USART_TypeDef* USARTx, uint16_t Data)


5-���ݽ��պ���
uint16_t USART_ReceiveData(USART_TypeDef* USARTx)


6-�ж�״̬λ��ȡ����
ITStatus USART_GetITStatus
(USART_TypeDef* USARTx, uint16_t USART_IT)

