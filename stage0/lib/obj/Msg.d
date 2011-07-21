#include <Msg.oh>
#include <Strings.oh>
#include <LongStrings.oh>
#include <IntStr.oh>

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_Msg__String = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, "String", 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_Msg__StringPtr = { (RT0__Struct[]){&_td_Msg__String}, NULL, NULL, &_mid, "StringPtr", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_Msg__LString = { (RT0__Struct[]){&RT0__longchar}, NULL, NULL, &_mid, "LString", 2, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_Msg__LStringPtr = { (RT0__Struct[]){&_td_Msg__LString}, NULL, NULL, &_mid, "LStringPtr", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_Msg__Attribute = { (RT0__Struct[]){&_td_Msg__AttributeDesc}, NULL, NULL, &_mid, "Attribute", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_Msg__AttributeDesc = { (RT0__Struct[]){&_td_Msg__AttributeDesc}, (void*[]){(void*)Msg__AttributeDesc_ReplacementText}, NULL, &_mid, "AttributeDesc", 8, 0, 0, RT0__strRecord };
RT0__StructDesc _td_Msg__Context = { (RT0__Struct[]){&_td_Msg__ContextDesc}, NULL, NULL, &_mid, "Context", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_Msg__ContextDesc = { (RT0__Struct[]){&_td_Msg__ContextDesc}, (void*[]){(void*)Msg__ContextDesc_GetTemplate}, NULL, &_mid, "ContextDesc", 4, 0, 0, RT0__strRecord };
RT0__StructDesc _td_Msg__Msg = { (RT0__Struct[]){&_td_Msg__MsgDesc}, NULL, NULL, &_mid, "Msg", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_Msg__MsgDesc = { (RT0__Struct[]){&_td_Msg__MsgDesc}, (void*[]){(void*)Msg__MsgDesc_SetAttribute,(void*)Msg__MsgDesc_GetAttribute,(void*)Msg__MsgDesc_GetLText,(void*)Msg__MsgDesc_GetText,(void*)Msg__MsgDesc_SetIntAttrib,(void*)Msg__MsgDesc_SetStringAttrib,(void*)Msg__MsgDesc_SetLStringAttrib,(void*)Msg__MsgDesc_SetMsgAttrib}, NULL, &_mid, "MsgDesc", 20, 0, 0, RT0__strRecord };
RT0__StructDesc _td_Msg__MsgList = { (RT0__Struct[]){&_td_Msg__MsgListDesc}, NULL, NULL, &_mid, "MsgList", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_Msg__MsgListDesc = { (RT0__Struct[]){&_td_Msg__MsgListDesc}, (void*[]){(void*)Msg__MsgListDesc_Append,(void*)Msg__MsgListDesc_AppendList}, NULL, &_mid, "MsgListDesc", 12, 0, 0, RT0__strRecord };
RT0__StructDesc _td_Msg__IntAttribute = { (RT0__Struct[]){&_td_Msg__IntAttributeDesc}, NULL, NULL, &_mid, "IntAttribute", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_Msg__IntAttributeDesc = { (RT0__Struct[]){&_td_Msg__AttributeDesc,&_td_Msg__IntAttributeDesc}, (void*[]){(void*)Msg__IntAttributeDesc_ReplacementText}, NULL, &_mid, "IntAttributeDesc", 12, 1, 0, RT0__strRecord };
RT0__StructDesc _td_Msg__StringAttribute = { (RT0__Struct[]){&_td_Msg__StringAttributeDesc}, NULL, NULL, &_mid, "StringAttribute", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_Msg__StringAttributeDesc = { (RT0__Struct[]){&_td_Msg__AttributeDesc,&_td_Msg__StringAttributeDesc}, (void*[]){(void*)Msg__StringAttributeDesc_ReplacementText}, NULL, &_mid, "StringAttributeDesc", 12, 1, 0, RT0__strRecord };
RT0__StructDesc _td_Msg__LStringAttribute = { (RT0__Struct[]){&_td_Msg__LStringAttributeDesc}, NULL, NULL, &_mid, "LStringAttribute", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_Msg__LStringAttributeDesc = { (RT0__Struct[]){&_td_Msg__AttributeDesc,&_td_Msg__LStringAttributeDesc}, (void*[]){(void*)Msg__LStringAttributeDesc_ReplacementText}, NULL, &_mid, "LStringAttributeDesc", 12, 1, 0, RT0__strRecord };
RT0__StructDesc _td_Msg__MsgAttribute = { (RT0__Struct[]){&_td_Msg__MsgAttributeDesc}, NULL, NULL, &_mid, "MsgAttribute", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_Msg__MsgAttributeDesc = { (RT0__Struct[]){&_td_Msg__AttributeDesc,&_td_Msg__MsgAttributeDesc}, (void*[]){(void*)Msg__MsgAttributeDesc_ReplacementText}, NULL, &_mid, "MsgAttributeDesc", 12, 1, 0, RT0__strRecord };
RT0__StructDesc _td_Msg__7793 = { (RT0__Struct[]){&RT0__longchar}, NULL, NULL, &_mid, NULL, 32768, 16384, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_Msg__11704 = { (RT0__Struct[]){&RT0__longchar}, NULL, NULL, &_mid, NULL, 262, 131, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_Msg__11750 = { (RT0__Struct[]){&RT0__longchar}, NULL, NULL, &_mid, NULL, 32768, 16384, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_Msg__11843 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 48, 48, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_Msg__13285 = { (RT0__Struct[]){&RT0__longchar}, NULL, NULL, &_mid, NULL, 65534, 32767, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_Msg__15658 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 48, 48, (1<<RT0__flagAtomic), RT0__strArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"Msg", (RT0__Struct[]) { &_td_Msg__String, &_td_Msg__StringPtr, &_td_Msg__LString, &_td_Msg__LStringPtr, &_td_Msg__Attribute, &_td_Msg__AttributeDesc, &_td_Msg__Context, &_td_Msg__ContextDesc, &_td_Msg__Msg, &_td_Msg__MsgDesc, &_td_Msg__MsgList, &_td_Msg__MsgListDesc, &_td_Msg__IntAttribute, &_td_Msg__IntAttributeDesc, &_td_Msg__StringAttribute, &_td_Msg__StringAttributeDesc, &_td_Msg__LStringAttribute, &_td_Msg__LStringAttributeDesc, &_td_Msg__MsgAttribute, &_td_Msg__MsgAttributeDesc, NULL } };

extern void OOC_Msg_init0() {
  RT0__RegisterModule(&_mid);
  OOC_Msg_init();
}

/* --- */
