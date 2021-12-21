#ifndef HCOMM_HPP
#define HCOMM_HPP

#include "hcommon.hpp"
#include "mbed.h"





class hCommunication{
public:
    hCommunication();
    virtual ~hCommunication();
    static hCommunication &getInstance();

private:
    //CAN can[4];
    int mBoardValue;
    static hCommunication *mp_Instance;

public:
    void canInit();
    void canSendData(unsigned int _canId, unsigned int _id, const unsigned char *_data, unsigned char _len = 8, CANType _type = CANData, CANFormat _format = CANStandard);
    CANMessage canRecieveData();
    static CAN &can1;

public:
    posSt canRecievePosData();
    void getPosInt(signed short &_IntVal);  

public:
    void uartInit();
    void sendUartData(const void *_buf, size_t _length);
    void receiveUartData();
    void getUartData(char *arr);
    void testUart();

private:
    char mBuff[MAXIMUM_BUFFER_SIZE]={0,};
    char mZBuff[MAXIMUM_BUFFER_SIZE]={0,};
    int Uartcnt = 0;
};



#endif //HCOMM_HPP