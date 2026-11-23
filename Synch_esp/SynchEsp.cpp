
template<
    class Message_t, 
    class TaskHandle,
    class TransportDataFunc,
    class RecieveCondition, 
    class TransmitCondition 
>
SynchEsp<Message_t, TaskHandle, TransportDataFunc, RecieveCondition, TransmitCondition>::SynchEsp(
    uart_config_t p_uartCfg,
    uart_port_t p_uartNum,
    int p_rxPin,
    int p_txPin,
    Courier<TaskHandle,
            SynchEsp<Message_t, TaskHandle, TransportDataFunc, RecieveCondition, TransmitCondition>,
            TransportDataFunc,
            RecieveCondition,
            TransmitCondition> &p_answerCourier,
    uint16_t p_messageSize,
    uint16_t p_answerBuffSize)
    : uartCfg(p_uartCfg),
      uartNum(p_uartNum),
      rxPin(p_rxPin),
      txPin(p_txPin),
      messageSize(p_messageSize),
      answerBuffSize(p_answerBuffSize),
      answerCourier(p_answerCourier)
{}

template<
    class Message_t, 
    class TaskHandle,
    class TransportDataFunc,
    class RecieveCondition, 
    class TransmitCondition 
>
bool SynchEsp<Message_t, TaskHandle, TransportDataFunc, RecieveCondition, TransmitCondition>::recieve(Message_t * destination) {
    check();
    if (!destination) return false;
    if (!answerBuffer.available()) return false;
    *destination = answerBuffer.front();
    answerBuffer.pop();
    return true;
}
