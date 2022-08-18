/*
 * MIT License
 *
 * Copyright (c) 2022 Christos Zosimidis
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 *
 * token_ring.h
 *
 *  Created on: 28.01.2021
 *      Author: Christos Zosimidis
 *
 *  Modified for the P2P protocol by: Bitcraze AB
 */

#ifndef SRC_RADIO_RADIO_H_
#define SRC_RADIO_RADIO_H_

#include "FreeRTOS.h"
#include "timers.h"

#include "stdint.h"
#include "stdbool.h"
#include "string.h"
#include "radiolink.h"
#include "log.h"
#include "configblock.h"


#include "DTR_types.h"
#include "DTR_timers.h"
#include "p2p_interface.h"
#include "queueing.h"

// #define UNUSED(...) ((void)sizeof((_Bool[]){__VA_ARGS__})); //Used to silence compiler warnings about unused parameters
#define UNUSED(...) ; //Used to silence compiler warnings about unused parameters

// #define DEBUG_DTR_PROTOCOL // Enable debug prints for the DTR protocol (WARNING: May cause problems )

#ifdef DEBUG_DTR_PROTOCOL
    #define DTR_DEBUG_PRINT(fmt, ... ) DEBUG_PRINT(DEBUG_FMT(fmt), ##__VA_ARGS__)
#else
    //do nothing
    #define DTR_DEBUG_PRINT( fmt,   ... ) (void) (fmt) 
#endif


#define NETWORK_SIZE 4
#define PROTOCOL_TIMEOUT_MS 4 * 1000.0f // ms 
#define DTR_P2P_PORT 15 // between 0 and 15(4 bits)

void initRadio(uint8_t networkSize, uint8_t device_id);

void initTokenRing(uint8_t networkSize, uint8_t device_id);

void setDeviceRadioAddress (uint8_t radio_address);

uint8_t getDeviceRadioAddress();

void timeOutCallBack(xTimerHandle timer);

void startRadioCommunication();

void DTRInterruptHandler(void *param);

const RadioInfo* getRadioInfo();

void resetRadioMetaInfo();

void printDTRPacket(DTRpacket* packet);

const char* getMessageType(uint8_t message_type);

const char* getRXState(uint8_t rx_state);

const char* getTXState(uint8_t tx_state);

uint8_t get_self_id(void);

// Starts the task of the Dynamic Token Ring Protocol (DTR) and initializes the protocol
void EnableDTRProtocol(void);

#endif /* SRC_RADIO_RADIO_H_ */
