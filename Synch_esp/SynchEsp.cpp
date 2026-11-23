template<
    class Message_t,
    size_t AnswerBuffSize,
    class Courier_t
>
SynchEsp<Message_t, AnswerBuffSize, Courier_t>::SynchEsp(
    uart_config_t p_uartCfg,
    uart_port_t p_uartNum,
    int p_rxPin,
    int p_txPin,
    Courier_t &p_answerCourier,
    uint16_t p_messageSize)
    : uartCfg(p_uartCfg),
      uartNum(p_uartNum),
      rxPin(p_rxPin),
      txPin(p_txPin),
      answerCourier(p_answerCourier),
      messageSize(p_messageSize)
{}

template<
    class Message_t,
    size_t AnswerBuffSize,
    class Courier_t
>
bool SynchEsp<Message_t, AnswerBuffSize, Courier_t>::recieve(Message_t * destination) {
    verifyCourier();
    if (!destination) return false;
    if (!answerBuffer.available()) return false;
    *destination = answerBuffer.front();
    answerBuffer.pop();
    return true;
}
