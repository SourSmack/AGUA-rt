
template<class Message_t>
SynchEsp<Message_t>::SynchEsp(uart_config_t p_uartCfg,
                              uart_port_t p_uartNum,
                              int p_rxPin,
                              int p_txPin,
                              Courier<SynchEsp> &p_answerCourier,
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

template<class Message_t>
bool SynchEsp<Message_t>::recieve(Message_t * destination) {
    check();
    if (!destination) return false;
    if (!answerBuffer.available()) return false;
    *destination = answerBuffer.front();
    answerBuffer.pop();
    return true;
}
