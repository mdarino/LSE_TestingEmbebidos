/* AUTOGENERATED FILE. DO NOT EDIT. */
#include <string.h>
#include <stdlib.h>
#include <setjmp.h>
#include "unity.h"
#include "cmock.h"
#include "mock_adc.h"

static const char* CMockString_adc_read_current = "adc_read_current";
static const char* CMockString_adc_read_output = "adc_read_output";

typedef struct _CMOCK_adc_read_current_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  uint8_t ReturnVal;
  int CallOrder;

} CMOCK_adc_read_current_CALL_INSTANCE;

typedef struct _CMOCK_adc_read_output_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  adc_output_t ReturnVal;
  int CallOrder;

} CMOCK_adc_read_output_CALL_INSTANCE;

static struct mock_adcInstance
{
  int adc_read_current_IgnoreBool;
  uint8_t adc_read_current_FinalReturn;
  CMOCK_adc_read_current_CALLBACK adc_read_current_CallbackFunctionPointer;
  int adc_read_current_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE adc_read_current_CallInstance;
  int adc_read_output_IgnoreBool;
  adc_output_t adc_read_output_FinalReturn;
  CMOCK_adc_read_output_CALLBACK adc_read_output_CallbackFunctionPointer;
  int adc_read_output_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE adc_read_output_CallInstance;
} Mock;

extern jmp_buf AbortFrame;
extern int GlobalExpectCount;
extern int GlobalVerifyOrder;

void mock_adc_Verify(void)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  if (Mock.adc_read_current_IgnoreBool)
    Mock.adc_read_current_CallInstance = CMOCK_GUTS_NONE;
  UNITY_SET_DETAIL(CMockString_adc_read_current);
  UNITY_TEST_ASSERT(CMOCK_GUTS_NONE == Mock.adc_read_current_CallInstance, cmock_line, CMockStringCalledLess);
  if (Mock.adc_read_current_CallbackFunctionPointer != NULL)
    Mock.adc_read_current_CallInstance = CMOCK_GUTS_NONE;
  if (Mock.adc_read_output_IgnoreBool)
    Mock.adc_read_output_CallInstance = CMOCK_GUTS_NONE;
  UNITY_SET_DETAIL(CMockString_adc_read_output);
  UNITY_TEST_ASSERT(CMOCK_GUTS_NONE == Mock.adc_read_output_CallInstance, cmock_line, CMockStringCalledLess);
  if (Mock.adc_read_output_CallbackFunctionPointer != NULL)
    Mock.adc_read_output_CallInstance = CMOCK_GUTS_NONE;
}

void mock_adc_Init(void)
{
  mock_adc_Destroy();
}

void mock_adc_Destroy(void)
{
  CMock_Guts_MemFreeAll();
  memset(&Mock, 0, sizeof(Mock));
  Mock.adc_read_current_CallbackFunctionPointer = NULL;
  Mock.adc_read_current_CallbackCalls = 0;
  Mock.adc_read_output_CallbackFunctionPointer = NULL;
  Mock.adc_read_output_CallbackCalls = 0;
  GlobalExpectCount = 0;
  GlobalVerifyOrder = 0;
}

uint8_t adc_read_current(void)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_adc_read_current_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_adc_read_current);
  cmock_call_instance = (CMOCK_adc_read_current_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.adc_read_current_CallInstance);
  Mock.adc_read_current_CallInstance = CMock_Guts_MemNext(Mock.adc_read_current_CallInstance);
  if (Mock.adc_read_current_IgnoreBool)
  {
    UNITY_CLR_DETAILS();
    if (cmock_call_instance == NULL)
      return Mock.adc_read_current_FinalReturn;
    Mock.adc_read_current_FinalReturn = cmock_call_instance->ReturnVal;
    return cmock_call_instance->ReturnVal;
  }
  if (Mock.adc_read_current_CallbackFunctionPointer != NULL)
  {
    return Mock.adc_read_current_CallbackFunctionPointer(Mock.adc_read_current_CallbackCalls++);
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  if (cmock_call_instance->CallOrder > ++GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledEarly);
  if (cmock_call_instance->CallOrder < GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLate);
  UNITY_CLR_DETAILS();
  return cmock_call_instance->ReturnVal;
}

void adc_read_current_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, uint8_t cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_adc_read_current_CALL_INSTANCE));
  CMOCK_adc_read_current_CALL_INSTANCE* cmock_call_instance = (CMOCK_adc_read_current_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.adc_read_current_CallInstance = CMock_Guts_MemChain(Mock.adc_read_current_CallInstance, cmock_guts_index);
  Mock.adc_read_current_IgnoreBool = (int)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->ReturnVal = cmock_to_return;
  Mock.adc_read_current_IgnoreBool = (int)1;
}

void adc_read_current_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, uint8_t cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_adc_read_current_CALL_INSTANCE));
  CMOCK_adc_read_current_CALL_INSTANCE* cmock_call_instance = (CMOCK_adc_read_current_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.adc_read_current_CallInstance = CMock_Guts_MemChain(Mock.adc_read_current_CallInstance, cmock_guts_index);
  Mock.adc_read_current_IgnoreBool = (int)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->CallOrder = ++GlobalExpectCount;
  cmock_call_instance->ReturnVal = cmock_to_return;
  UNITY_CLR_DETAILS();
}

void adc_read_current_StubWithCallback(CMOCK_adc_read_current_CALLBACK Callback)
{
  Mock.adc_read_current_IgnoreBool = (int)0;
  Mock.adc_read_current_CallbackFunctionPointer = Callback;
}

adc_output_t adc_read_output(void)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_adc_read_output_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_adc_read_output);
  cmock_call_instance = (CMOCK_adc_read_output_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.adc_read_output_CallInstance);
  Mock.adc_read_output_CallInstance = CMock_Guts_MemNext(Mock.adc_read_output_CallInstance);
  if (Mock.adc_read_output_IgnoreBool)
  {
    UNITY_CLR_DETAILS();
    if (cmock_call_instance == NULL)
      return Mock.adc_read_output_FinalReturn;
    memcpy(&Mock.adc_read_output_FinalReturn, &cmock_call_instance->ReturnVal, sizeof(adc_output_t));
    return cmock_call_instance->ReturnVal;
  }
  if (Mock.adc_read_output_CallbackFunctionPointer != NULL)
  {
    return Mock.adc_read_output_CallbackFunctionPointer(Mock.adc_read_output_CallbackCalls++);
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  if (cmock_call_instance->CallOrder > ++GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledEarly);
  if (cmock_call_instance->CallOrder < GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLate);
  UNITY_CLR_DETAILS();
  return cmock_call_instance->ReturnVal;
}

void adc_read_output_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, adc_output_t cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_adc_read_output_CALL_INSTANCE));
  CMOCK_adc_read_output_CALL_INSTANCE* cmock_call_instance = (CMOCK_adc_read_output_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.adc_read_output_CallInstance = CMock_Guts_MemChain(Mock.adc_read_output_CallInstance, cmock_guts_index);
  Mock.adc_read_output_IgnoreBool = (int)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->ReturnVal = cmock_to_return;
  Mock.adc_read_output_IgnoreBool = (int)1;
}

void adc_read_output_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, adc_output_t cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_adc_read_output_CALL_INSTANCE));
  CMOCK_adc_read_output_CALL_INSTANCE* cmock_call_instance = (CMOCK_adc_read_output_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.adc_read_output_CallInstance = CMock_Guts_MemChain(Mock.adc_read_output_CallInstance, cmock_guts_index);
  Mock.adc_read_output_IgnoreBool = (int)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->CallOrder = ++GlobalExpectCount;
  memcpy(&cmock_call_instance->ReturnVal, &cmock_to_return, sizeof(adc_output_t));
  UNITY_CLR_DETAILS();
}

void adc_read_output_StubWithCallback(CMOCK_adc_read_output_CALLBACK Callback)
{
  Mock.adc_read_output_IgnoreBool = (int)0;
  Mock.adc_read_output_CallbackFunctionPointer = Callback;
}

