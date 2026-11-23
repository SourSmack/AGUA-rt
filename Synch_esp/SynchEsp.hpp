#pragma once

#include <cstdint>
#include <etl/string.h>
#include <etl/circular_buffer.h>
#include "driver/uart.h"

#include "Mission.hpp"
#include "Courier.hpp"
#include "baseUart.hpp"

template<
    class Message_t,
    size_t AnswerBuffSize,
    class Courier_t
>
class SynchEsp : Uart<SynchEsp<Message_t, AnswerBuffSize, Courier_t>> {
private:
    uart_config_t uartCfg;
    uart_port_t uartNum;
    int rxPin{ 0 };
    int txPin{ 0 };

    Courier_t &answerCourier;

    uint16_t messageSize{ 0 };

    etl::circular_buffer<Message_t, AnswerBuffSize> answerBuffer{};

public:
    SynchEsp(uart_config_t p_uartCfg,
             uart_port_t p_uartNum,
             int p_rxPin,
             int p_txPin,
             Courier_t &p_answerCourier,
             uint16_t p_messageSize);

    bool recieve(Message_t * destination);
};
#include "SynchEsp.cpp"
