#include <OOC/AST/XML.oh>
#include <OOC/Scanner/Symbol.oh>
#include <XML/Writer.oh>
#include <XML/UnicodeCodec/Latin1.oh>
#include <OOC/Doc.oh>
#include <OOC/Doc/Output/XML.oh>

/* run-time meta data */
static RT0__ModuleDesc _mid;
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:AST:XML", (RT0__Struct[]) { NULL }, 0 };

extern void OOC_OOC_AST_XML_open(RT0__Module client) {
  if (_mid.openCount == 0) {
    OOC_IO_open(&_mid);
    OOC_OOC_Scanner_Symbol_open(&_mid);
    OOC_OOC_AST_open(&_mid);
    OOC_XML_Writer_open(&_mid);
    OOC_XML_UnicodeCodec_Latin1_open(&_mid);
    OOC_OOC_Doc_open(&_mid);
    OOC_OOC_Doc_Output_XML_open(&_mid);
    OOC_RT0_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_Exception_open(&_mid);

    RT0__RegisterModule(&_mid);
    OOC_OOC_AST_XML_init();
  }
  _mid.openCount++;
}
extern void OOC_OOC_AST_XML_close(RT0__Module client) {
  _mid.openCount--;
  if (_mid.openCount == 0) { 
    OOC_OOC_AST_XML_destroy();
    RT0__UnregisterModule(&_mid);

    OOC_IO_close(&_mid);
    OOC_OOC_Scanner_Symbol_close(&_mid);
    OOC_OOC_AST_close(&_mid);
    OOC_XML_Writer_close(&_mid);
    OOC_XML_UnicodeCodec_Latin1_close(&_mid);
    OOC_OOC_Doc_close(&_mid);
    OOC_OOC_Doc_Output_XML_close(&_mid);
    OOC_RT0_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_Exception_close(&_mid);
  }
}

/* --- */
