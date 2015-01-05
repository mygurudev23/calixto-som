/* $NoKeywords:$ */
/**
 * @file
 *
 * AMD CPU BrandId related functions and structures for socket C32.
 *
 * Contains code that provides CPU BrandId information
 *
 * @xrefitem bom "File Content Label" "Release Content"
 * @e project:      AGESA
 * @e sub-project:  CPU
 * @e \$Revision: 35136 $   @e \$Date: 2010-07-16 11:29:48 +0800 (Fri, 16 Jul 2010) $
 *
 */
/*
 *****************************************************************************
 *
 * Copyright (c) 2011, Advanced Micro Devices, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of Advanced Micro Devices, Inc. nor the names of
 *       its contributors may be used to endorse or promote products derived
 *       from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL ADVANCED MICRO DEVICES, INC. BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * ***************************************************************************
 *
 */

/*----------------------------------------------------------------------------------------
 *                             M O D U L E S    U S E D
 *----------------------------------------------------------------------------------------
 */
#include "AGESA.h"
#include "cpuRegisters.h"
#include "cpuEarlyInit.h"
CODE_GROUP (G2_PEI)
RDATA_GROUP (G2_PEI)


/*----------------------------------------------------------------------------------------
 *                   D E F I N I T I O N S    A N D    M A C R O S
 *----------------------------------------------------------------------------------------
 */

/*----------------------------------------------------------------------------------------
 *                  T Y P E D E F S     A N D     S T R U C T U R E S
 *----------------------------------------------------------------------------------------
 */

/*----------------------------------------------------------------------------------------
 *           P R O T O T Y P E S     O F     L O C A L     F U N C T I O N S
 *----------------------------------------------------------------------------------------
 */

/*----------------------------------------------------------------------------------------
 *                          E X P O R T E D    F U N C T I O N S
 *----------------------------------------------------------------------------------------
 */


// PRIVATE FORMAT FOR BRAND TABLE ... FOR AMD USE ONLY

// String1
CONST CHAR8 ROMDATA str_Opteron_41[] = "AMD Opteron(tm) Processor 41";
CONST CHAR8 ROMDATA str_Embedded_Opteron_C32[] = "Embedded AMD Opteron(tm) Processor ";

// String2
CONST CHAR8 ROMDATA str2_HE_C32[] = " HE";
CONST CHAR8 ROMDATA str2_EE_C32[] = " EE";
CONST CHAR8 ROMDATA str2_QS_HE_C32[] = "QS HE";
CONST CHAR8 ROMDATA str2_LE_HE_C32[] = "LE HE";
CONST CHAR8 ROMDATA str2_KX_HE_C32[] = "KX HE";
CONST CHAR8 ROMDATA str2_GL_EE_C32[] = "GL EE";

/*---------------------------------------------------------------------------------------
 *               T Y P E D E F S,   S T R U C T U R E S,    E N U M S
 *---------------------------------------------------------------------------------------
 */

CONST AMD_CPU_BRAND ROMDATA CpuF10BrandIdString1ArrayC32[] =
{
  // C32r1 string1:
  {4, 0, 0x00, DR_SOCKET_C32, str_Opteron_41, sizeof (str_Opteron_41)},
  {4, 1, 0x01, DR_SOCKET_C32, str_Embedded_Opteron_C32, sizeof (str_Embedded_Opteron_C32)},
  {6, 0, 0x00, DR_SOCKET_C32, str_Opteron_41, sizeof (str_Opteron_41)},
  {6, 1, 0x01, DR_SOCKET_C32, str_Embedded_Opteron_C32, sizeof (str_Embedded_Opteron_C32)}
};    //Cores, page, index, socket, stringstart, stringlength


CONST AMD_CPU_BRAND ROMDATA CpuF10BrandIdString2ArrayC32[] =
{
  // C32r1 string2:
  {4, 0, 0x00, DR_SOCKET_C32, str2_HE_C32, sizeof (str2_HE_C32)},
  {4, 0, 0x01, DR_SOCKET_C32, str2_EE_C32, sizeof (str2_EE_C32)},
  {4, 0, 0x0F, DR_SOCKET_C32, 0, 0},  //Size 0 for no suffix
  {4, 1, 0x01, DR_SOCKET_C32, str2_QS_HE_C32, sizeof (str2_QS_HE_C32)},
  {4, 1, 0x02, DR_SOCKET_C32, str2_LE_HE_C32, sizeof (str2_LE_HE_C32)},
  {6, 0, 0x00, DR_SOCKET_C32, str2_HE_C32, sizeof (str2_HE_C32)},
  {6, 0, 0x01, DR_SOCKET_C32, str2_EE_C32, sizeof (str2_EE_C32)},
  {6, 0, 0x0F, DR_SOCKET_C32, 0, 0},  //Size 0 for no suffix
  {6, 1, 0x01, DR_SOCKET_C32, str2_KX_HE_C32, sizeof (str2_KX_HE_C32)},
  {6, 1, 0x02, DR_SOCKET_C32, str2_GL_EE_C32, sizeof (str2_GL_EE_C32)}
};


CONST CPU_BRAND_TABLE ROMDATA F10BrandIdString1ArrayC32 = {
  (sizeof (CpuF10BrandIdString1ArrayC32) / sizeof (AMD_CPU_BRAND)),
  CpuF10BrandIdString1ArrayC32
};


CONST CPU_BRAND_TABLE ROMDATA F10BrandIdString2ArrayC32 = {
  (sizeof (CpuF10BrandIdString2ArrayC32) / sizeof (AMD_CPU_BRAND)),
  CpuF10BrandIdString2ArrayC32
};

