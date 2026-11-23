#pragma once

#include <cstdint>
#include <etl/string.h>
#include <etl/circular_buffer.h>
#include "driver/uart.h"

#include "Mission.hpp"
#include "Courier.hpp"
#include "baseUart.hpp"

template<
    class Message_t
>
class SynchEsp : Uart<SynchEsp<Message_t>> {
private:
    uart_config_t uartCfg;
    uart_port_t uartNum;
    int rxPin{ 0 };
    int txPin{ 0 };
    Courier<SynchEsp<Message_t>> &answerCourier;
    uint16_t messageSize{ 0 };
    uint16_t answerBuffSize{ 0 };

    etl::circular_buffer<Message_t, answerBuffSize> answerBuffer{};

public:
    SynchEsp(uart_config_t p_uartCfg,
             uart_port_t p_uartNum,
             int p_rxPin,
             int p_txPin,
             Courier<SynchEsp> &p_answerCourier,
             uint16_t p_messageSize,
             uint16_t p_answerBuffSize);

    bool recieve(Message_t * destination);
};
#include "SynchEsp.cpp"
