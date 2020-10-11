/*
 * Application interface for CANopenSocket.
 *
 * @file        application.c
 * @author      Janez Paternoster
 * @copyright   2016 - 2020 Janez Paternoster
 *
 * This file is part of CANopenSocket, a Linux implementation of CANopen
 * stack with master functionality. Project home page is
 * <https://github.com/CANopenNode/CANopenSocket>. CANopenSocket is based
 * on CANopenNode: <https://github.com/CANopenNode/CANopenNode>.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


#include "CANopen.h"


/******************************************************************************/
void app_programStart(void){
CO_RPDOCommPar_t komunikacioniRPDO;
CO_RPDOMapPar_t mapiranjeRPDO;
CO_RPDO_t objekatRPDO;

CO_TPDOCommPar_t komunikacioniTPDO;
CO_TPDOMapPar_t mapiranjeTPDO;
CO_TPDO_t objekatTPDO;

komunikacioniRPDO.maxSubIndex=2;
komunikacioniRPDO.COB_IDUsedByRPDO=0x200;
komunikacioniRPDO.transmissionType=255;

mapiranjeRPDO.numberOfMappedObjects=2;
mapiranjeRPDO.mappedObject1=0x61000108;
mapiranjeRPDO.mappedObject2=0x62000108;
mapiranjeRPDO.mappedObject3=0x00000000;
mapiranjeRPDO.mappedObject4=0x00000000;
mapiranjeRPDO.mappedObject5=0x00000000;
mapiranjeRPDO.mappedObject6=0x00000000;
mapiranjeRPDO.mappedObject7=0x00000000;
mapiranjeRPDO.mappedObject8=0x00000000;

komunikacioniTPDO.maxSubIndex=6;
komunikacioniTPDO.COB_IDUsedByTPDO;
komunikacioniTPDO.transmissionType;
komunikacioniTPDO.inhibitTime;
komunikacioniTPDO.compatibilityEntry; //ne koristi se pise na gitu
komunikacioniTPDO.eventTimer;
komunikacioniTPDO.SYNCStartValue;

mapiranjeTPDO.numberOfMappedObjects;
mapiranjeTPDO.mappedObject1;
mapiranjeTPDO.mappedObject2;
mapiranjeTPDO.mappedObject3;
mapiranjeTPDO.mappedObject4;
mapiranjeTPDO.mappedObject5;
mapiranjeTPDO.mappedObject6;
mapiranjeTPDO.mappedObject7;
mapiranjeTPDO.mappedObject8;
}.


/******************************************************************************/
void app_communicationReset(void){

}


/******************************************************************************/
void app_programEnd(void){

}


/******************************************************************************/
void app_programAsync(uint16_t timer1msDiff){

}


/******************************************************************************/
void app_program1ms(void){

}
