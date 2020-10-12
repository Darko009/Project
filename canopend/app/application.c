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


CO_RPDO_t *objekatRPDO;
CO_RPDOCommPar_t komunikacioniRPDO;
CO_RPDOMapPar_t mapiranjeRPDO;

CO_TPDO_t *objekatTPDO;
CO_TPDOCommPar_t komunikacioniTPDO;
CO_TPDOMapPar_t mapiranjeTPDO;


/******************************************************************************/
void app_programStart(void){

komunikacioniRPDO.maxSubIndex=2;
komunikacioniRPDO.COB_IDUsedByRPDO=0x200;
komunikacioniRPDO.transmissionType=255;

mapiranjeRPDO.numberOfMappedObjects=2;
mapiranjeRPDO.mappedObject1=0x62000108;
mapiranjeRPDO.mappedObject2=0x62000208;
mapiranjeRPDO.mappedObject3=0x00000000;
mapiranjeRPDO.mappedObject4=0x00000000;
mapiranjeRPDO.mappedObject5=0x00000000;
mapiranjeRPDO.mappedObject6=0x00000000;
mapiranjeRPDO.mappedObject7=0x00000000;
mapiranjeRPDO.mappedObject8=0x00000000;

komunikacioniTPDO.maxSubIndex=6;
komunikacioniTPDO.COB_IDUsedByTPDO=0x180;
komunikacioniTPDO.transmissionType=255;
komunikacioniTPDO.inhibitTime=100;
komunikacioniTPDO.compatibilityEntry=0; //ne koristi se pise na gitu
komunikacioniTPDO.eventTimer=0;
komunikacioniTPDO.SYNCStartValue=0;

mapiranjeTPDO.numberOfMappedObjects=2;
mapiranjeTPDO.mappedObject1=0x60000108;
mapiranjeTPDO.mappedObject2=0x60000208;
mapiranjeTPDO.mappedObject3=0x00000000;
mapiranjeTPDO.mappedObject4=0x00000000;
mapiranjeTPDO.mappedObject5=0x00000000;
mapiranjeTPDO.mappedObject6=0x00000000;
mapiranjeTPDO.mappedObject7=0x00000000;
mapiranjeTPDO.mappedObject8=0x00000000;
}

/******************************************************************************/
void app_communicationReset(void){

CO_RPDO_init(objekatRPDO,objekatRPDO->em,objekatRPDO->SDO,objekatRPDO->SYNC,objekatRPDO->operatingState,objekatRPDO->nodeId,objekatRPDO->defaultCOB_ID,objekatRPDO->restrictionFlags,objekatRPDO->RPDOCommPar,objekatRPDO->RPDOMapPar,0x1400,0x6200,objekatRPDO->CANdevRx,objekatRPDO->CANdevRxIdx);

CO_TPDO_init(objekatTPDO,objekatTPDO->em,objekatTPDO->SDO,objekatTPDO->SYNC,objekatTPDO->operatingState,objekatTPDO->nodeId,objekatTPDO->defaultCOB_ID,objekatTPDO->restrictionFlags,objekatTPDO->TPDOCommPar,objekatTPDO->TPDOMapPar,0x1800,0x6000,objekatTPDO->CANdevTx,objekatTPDO->CANdevTxIdx);
}


/******************************************************************************/
void app_programEnd(void){

}


/******************************************************************************/
void app_programAsync(uint16_t timer1msDiff){
CO_TPDO_process(objekatTPDO,TRUE,1000);
}


/******************************************************************************/
void app_program1ms(void){
CO_RPDO_process(objekatRPDO,TRUE);
}
