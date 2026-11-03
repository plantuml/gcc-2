#include "runtime.h"
#include "strings.h"
#include "c/j/l/String.h"
#include "c/j/l/Object.h"
#include "c/j/i/Serializable.h"
#include "c/j/l/Comparable.h"
#include "c/j/l/CharSequence.h"
#include "c/j/l/Class.h"
#include "c/j/l/r/GenericDeclaration.h"
#include "c/j/l/r/AnnotatedElement.h"
#include "c/j/l/r/Type.h"
#include "c/o/t/r/Allocator.h"
#include "c/o/t/r/GC.h"
#include "c/j/l/ClassCastException.h"
#include "c/j/l/RuntimeException.h"
#include "c/j/l/Exception.h"
#include "c/j/l/Throwable.h"
#include "c/o/t/r/ExceptionHandling.h"
#include "c/o/t/r/ShadowStack.h"
#include "c/j/l/NullPointerException.h"
#include "c/j/l/ArrayIndexOutOfBoundsException.h"
#include "c/j/l/IndexOutOfBoundsException.h"
#include "c/o/t/r/Fiber.h"
#include "c/o/t/r/Fiber@dstartMain@dlambda@d_38_0.h"
#include "c/o/t/r/Fiber@dFiberRunner.h"
#include "c/o/t/r/EventQueue.h"
#include "c/j/l/Thread.h"
#include "c/j/l/Runnable.h"
#include "c/j/l/System.h"
#include "c/j/u/Arrays.h"
#include "c/o/t/r/Fiber@dPlatformObjectWrapper.h"
#include "c/o/t/r/Fiber@dPlatformFunctionWrapper.h"
#include "c/o/t/r/Fiber@dPlatformExceptionWrapper.h"
#include "c/o/t/b/c/r/CResources.h"
#include "c/o/t/b/c/r/CResources@dResource.h"
#include "c/Hello.h"
#include "c/o/t/r/MemoryTrace.h"
#include "c/o/t/r/Console.h"
#include "c/o/t/r/EventQueue@dNode.h"
#include "c/j/l/Math.h"
#include "c/j/l/r/Array.h"
#include "c/j/u/z/CRC32.h"
#include "c/j/u/z/Checksum.h"
#include "c/j/n/c/StandardCharsets.h"
#include "c/j/l/Long.h"
#include "c/j/l/Number.h"
#include "c/j/l/StringBuilder.h"
#include "c/j/l/AbstractStringBuilder.h"
#include "c/j/l/Appendable.h"
#include "c/j/l/DefaultUncaughtExceptionHandler.h"
#include "c/j/l/Thread@dUncaughtExceptionHandler.h"
#include "c/j/l/IllegalArgumentException.h"
#include "c/j/l/NegativeArraySizeException.h"
#include "c/j/u/HashMap.h"
#include "c/j/u/AbstractMap.h"
#include "c/j/u/Map.h"
#include "c/j/l/Cloneable.h"
#include "c/c/j/j/CRC32.h"
#include "c/c/j/j/Checksum.h"
#include "c/j/n/CharBuffer.h"
#include "c/j/n/Buffer.h"
#include "c/j/l/Readable.h"
#include "c/j/n/c/Charset.h"
#include "c/j/n/ByteBuffer.h"
#include "c/j/i/PrintStream.h"
#include "c/j/i/FilterOutputStream.h"
#include "c/j/i/OutputStream.h"
#include "c/j/i/Closeable.h"
#include "c/j/l/AutoCloseable.h"
#include "c/j/i/Flushable.h"
#include "c/o/t/c/i/c/StdoutOutputStream.h"
#include "c/o/t/c/i/c/ConsoleOutputStream.h"
#include "c/o/t/c/i/IntegerUtil.h"
#include "c/o/t/r/Mutator.h"
#include "c/j/l/ArrayStoreException.h"
#include "c/j/n/c/i/UTF8Charset.h"
#include "c/j/n/c/i/AsciiCharset.h"
#include "c/j/n/c/i/Iso8859Charset.h"
#include "c/j/n/c/i/UTF16Charset.h"
#include "c/j/n/c/CodingErrorAction.h"
#include "c/j/n/c/CharsetEncoder.h"
#include "c/j/n/c/CharacterCodingException.h"
#include "c/j/i/IOException.h"
#include "c/j/l/AssertionError.h"
#include "c/j/l/Error.h"
#include "c/j/l/String@d@lclinit@g@dlambda@d_118_0.h"
#include "c/j/u/Comparator.h"
#include "c/j/l/Character.h"
#include "c/j/n/CharBufferNative.h"
#include "c/j/n/CharBufferImpl.h"
#include "c/j/n/ArrayBufferViewProvider.h"
#include "c/j/n/f/AddressBasedBuffer.h"
#include "c/j/n/c/CoderResult.h"
#include "c/j/u/Objects.h"
#include "c/o/t/r/MarkQueue.h"
#include "c/o/t/b/c/r/Memory.h"
#include "c/j/l/StackTraceElement.h"
#include "c/j/n/ByteBufferNative.h"
#include "c/j/n/NativeBuffer.h"
#include "c/j/l/IllegalStateException.h"
#include "c/j/n/c/CoderMalfunctionError.h"
#include "c/j/n/c/IllegalCharsetNameException.h"
#include "c/j/l/StringIndexOutOfBoundsException.h"
#include "c/j/n/ByteOrder.h"
#include "c/j/n/c/i/Iso8859Encoder.h"
#include "c/j/n/c/i/BufferedEncoder.h"
#include "c/j/n/ReadOnlyBufferException.h"
#include "c/j/l/UnsupportedOperationException.h"
#include "c/j/n/BufferOverflowException.h"
#include "c/j/n/c/BufferUnderflowException.h"
#include "c/j/n/c/BufferOverflowException.h"
#include "c/j/n/c/MalformedInputException.h"
#include "c/j/n/c/UnmappableCharacterException.h"
#include "c/j/u/HashMap@dHashEntry.h"
#include "c/j/u/MapEntry.h"
#include "c/j/u/Map@dEntry.h"
#include "c/j/n/c/i/BufferedEncoder@dController.h"
#include "c/j/n/BufferUnderflowException.h"
#include "c/j/l/Integer.h"
#include "c/j/n/c/i/UTF8Encoder.h"
#include "c/o/t/c/i/c/Console.h"
#include "p/char.h"
#include "a/p/char.h"
#include "p/int.h"
#include "a/p/int.h"
#include "p/long.h"
#include "a/p/long.h"
#include "p/float.h"
#include "a/p/float.h"
#include "p/double.h"
#include "a/p/double.h"
#include "p/void.h"
#include "p/byte.h"
#include "a/p/byte.h"
#include "p/short.h"
#include "a/p/short.h"

TeaVM_Class* teavm_classReferences[134] = {
    (TeaVM_Class*) &jl_String_Cls, 
    (TeaVM_Class*) &jl_Object_Cls, 
    (TeaVM_Class*) &ji_Serializable_Cls, 
    (TeaVM_Class*) &jl_Comparable_Cls, 
    (TeaVM_Class*) &jl_CharSequence_Cls, 
    (TeaVM_Class*) &jl_Class_Cls, 
    (TeaVM_Class*) &jlr_GenericDeclaration_Cls, 
    (TeaVM_Class*) &jlr_AnnotatedElement_Cls, 
    (TeaVM_Class*) &jlr_Type_Cls, 
    (TeaVM_Class*) &otr_Allocator_Cls, 
    (TeaVM_Class*) &otr_GC_Cls, 
    (TeaVM_Class*) &jl_ClassCastException_Cls, 
    (TeaVM_Class*) &jl_RuntimeException_Cls, 
    (TeaVM_Class*) &jl_Exception_Cls, 
    (TeaVM_Class*) &jl_Throwable_Cls, 
    (TeaVM_Class*) &otr_ExceptionHandling_Cls, 
    (TeaVM_Class*) &otr_ShadowStack_Cls, 
    (TeaVM_Class*) &jl_NullPointerException_Cls, 
    (TeaVM_Class*) &jl_ArrayIndexOutOfBoundsException_Cls, 
    (TeaVM_Class*) &jl_IndexOutOfBoundsException_Cls, 
    (TeaVM_Class*) &otr_Fiber_Cls, 
    (TeaVM_Class*) &otr_Fiber_startMain_lambda__38_0_Cls, 
    (TeaVM_Class*) &otr_Fiber_FiberRunner_Cls, 
    (TeaVM_Class*) &otr_EventQueue_Cls, 
    (TeaVM_Class*) &jl_Thread_Cls, 
    (TeaVM_Class*) &jl_Runnable_Cls, 
    (TeaVM_Class*) &jl_System_Cls, 
    (TeaVM_Class*) &ju_Arrays_Cls, 
    (TeaVM_Class*) &otr_Fiber_PlatformObjectWrapper_Cls, 
    (TeaVM_Class*) &otr_Fiber_PlatformFunctionWrapper_Cls, 
    (TeaVM_Class*) &otr_Fiber_PlatformExceptionWrapper_Cls, 
    (TeaVM_Class*) &otbcr_CResources_Cls, 
    (TeaVM_Class*) &otbcr_CResources_Resource_Cls, 
    (TeaVM_Class*) &Hello_Cls, 
    (TeaVM_Class*) &otr_MemoryTrace_Cls, 
    (TeaVM_Class*) &otr_Console_Cls, 
    (TeaVM_Class*) &otr_EventQueue_Node_Cls, 
    (TeaVM_Class*) &jl_Math_Cls, 
    (TeaVM_Class*) &jlr_Array_Cls, 
    (TeaVM_Class*) &juz_CRC32_Cls, 
    (TeaVM_Class*) &juz_Checksum_Cls, 
    (TeaVM_Class*) &jnc_StandardCharsets_Cls, 
    (TeaVM_Class*) &jl_Long_Cls, 
    (TeaVM_Class*) &jl_Number_Cls, 
    (TeaVM_Class*) &jl_StringBuilder_Cls, 
    (TeaVM_Class*) &jl_AbstractStringBuilder_Cls, 
    (TeaVM_Class*) &jl_Appendable_Cls, 
    (TeaVM_Class*) &jl_DefaultUncaughtExceptionHandler_Cls, 
    (TeaVM_Class*) &jl_Thread_UncaughtExceptionHandler_Cls, 
    (TeaVM_Class*) &jl_IllegalArgumentException_Cls, 
    (TeaVM_Class*) &jl_NegativeArraySizeException_Cls, 
    (TeaVM_Class*) &ju_HashMap_Cls, 
    (TeaVM_Class*) &ju_AbstractMap_Cls, 
    (TeaVM_Class*) &ju_Map_Cls, 
    (TeaVM_Class*) &jl_Cloneable_Cls, 
    (TeaVM_Class*) &cjj_CRC32_Cls, 
    (TeaVM_Class*) &cjj_Checksum_Cls, 
    (TeaVM_Class*) &jn_CharBuffer_Cls, 
    (TeaVM_Class*) &jn_Buffer_Cls, 
    (TeaVM_Class*) &jl_Readable_Cls, 
    (TeaVM_Class*) &jnc_Charset_Cls, 
    (TeaVM_Class*) &jn_ByteBuffer_Cls, 
    (TeaVM_Class*) &ji_PrintStream_Cls, 
    (TeaVM_Class*) &ji_FilterOutputStream_Cls, 
    (TeaVM_Class*) &ji_OutputStream_Cls, 
    (TeaVM_Class*) &ji_Closeable_Cls, 
    (TeaVM_Class*) &jl_AutoCloseable_Cls, 
    (TeaVM_Class*) &ji_Flushable_Cls, 
    (TeaVM_Class*) &otcic_StdoutOutputStream_Cls, 
    (TeaVM_Class*) &otcic_ConsoleOutputStream_Cls, 
    (TeaVM_Class*) &otci_IntegerUtil_Cls, 
    (TeaVM_Class*) &otr_Mutator_Cls, 
    (TeaVM_Class*) &jl_ArrayStoreException_Cls, 
    (TeaVM_Class*) &jnci_UTF8Charset_Cls, 
    (TeaVM_Class*) &jnci_AsciiCharset_Cls, 
    (TeaVM_Class*) &jnci_Iso8859Charset_Cls, 
    (TeaVM_Class*) &jnci_UTF16Charset_Cls, 
    (TeaVM_Class*) &jnc_CodingErrorAction_Cls, 
    (TeaVM_Class*) &jnc_CharsetEncoder_Cls, 
    (TeaVM_Class*) &jnc_CharacterCodingException_Cls, 
    (TeaVM_Class*) &ji_IOException_Cls, 
    (TeaVM_Class*) &jl_AssertionError_Cls, 
    (TeaVM_Class*) &jl_Error_Cls, 
    (TeaVM_Class*) &jl_String__clinit__lambda__118_0_Cls, 
    (TeaVM_Class*) &ju_Comparator_Cls, 
    (TeaVM_Class*) &jl_Character_Cls, 
    (TeaVM_Class*) &jn_CharBufferNative_Cls, 
    (TeaVM_Class*) &jn_CharBufferImpl_Cls, 
    (TeaVM_Class*) &jn_ArrayBufferViewProvider_Cls, 
    (TeaVM_Class*) &jnf_AddressBasedBuffer_Cls, 
    (TeaVM_Class*) &jnc_CoderResult_Cls, 
    (TeaVM_Class*) &ju_Objects_Cls, 
    (TeaVM_Class*) &otr_MarkQueue_Cls, 
    (TeaVM_Class*) &otbcr_Memory_Cls, 
    (TeaVM_Class*) &jl_StackTraceElement_Cls, 
    (TeaVM_Class*) &jn_ByteBufferNative_Cls, 
    (TeaVM_Class*) &jn_NativeBuffer_Cls, 
    (TeaVM_Class*) &jl_IllegalStateException_Cls, 
    (TeaVM_Class*) &jnc_CoderMalfunctionError_Cls, 
    (TeaVM_Class*) &jnc_IllegalCharsetNameException_Cls, 
    (TeaVM_Class*) &jl_StringIndexOutOfBoundsException_Cls, 
    (TeaVM_Class*) &jn_ByteOrder_Cls, 
    (TeaVM_Class*) &jnci_Iso8859Encoder_Cls, 
    (TeaVM_Class*) &jnci_BufferedEncoder_Cls, 
    (TeaVM_Class*) &jn_ReadOnlyBufferException_Cls, 
    (TeaVM_Class*) &jl_UnsupportedOperationException_Cls, 
    (TeaVM_Class*) &jn_BufferOverflowException_Cls, 
    (TeaVM_Class*) &jnc_BufferUnderflowException_Cls, 
    (TeaVM_Class*) &jnc_BufferOverflowException_Cls, 
    (TeaVM_Class*) &jnc_MalformedInputException_Cls, 
    (TeaVM_Class*) &jnc_UnmappableCharacterException_Cls, 
    (TeaVM_Class*) &ju_HashMap_HashEntry_Cls, 
    (TeaVM_Class*) &ju_MapEntry_Cls, 
    (TeaVM_Class*) &ju_Map_Entry_Cls, 
    (TeaVM_Class*) &jnci_BufferedEncoder_Controller_Cls, 
    (TeaVM_Class*) &jn_BufferUnderflowException_Cls, 
    (TeaVM_Class*) &jl_Integer_Cls, 
    (TeaVM_Class*) &jnci_UTF8Encoder_Cls, 
    (TeaVM_Class*) &otcic_Console_Cls, 
    (TeaVM_Class*) &C_Cls, 
    (TeaVM_Class*) &Arr_C_Cls, 
    (TeaVM_Class*) &I_Cls, 
    (TeaVM_Class*) &Arr_I_Cls, 
    (TeaVM_Class*) &J_Cls, 
    (TeaVM_Class*) &Arr_J_Cls, 
    (TeaVM_Class*) &F_Cls, 
    (TeaVM_Class*) &Arr_F_Cls, 
    (TeaVM_Class*) &D_Cls, 
    (TeaVM_Class*) &Arr_D_Cls, 
    (TeaVM_Class*) &V_Cls, 
    (TeaVM_Class*) &B_Cls, 
    (TeaVM_Class*) &Arr_B_Cls, 
    (TeaVM_Class*) &S_Cls, 
    (TeaVM_Class*) &Arr_S_Cls
};
int32_t teavm_classReferencesCount = 134;
int main(int argc, char** argv) {
    teavm_beforeInit();
    teavm_initHeap(1048576, 16777216);
    teavm_classClass = (TeaVM_Class*) &jl_Class_Cls;
    teavm_objectClass = (TeaVM_Class*) &jl_Object_Cls;
    teavm_stringClass = (TeaVM_Class*) &jl_String_Cls;
    teavm_charArrayClass = (TeaVM_Class*) &Arr_C_Cls;
    teavm_initClasses();
    teavm_initStringPool();
    sysinitclass_jl_String();
    sysinitclass_jl_Object();
    sysinitclass_ji_Serializable();
    sysinitclass_jl_Comparable();
    sysinitclass_jl_CharSequence();
    sysinitclass_jl_Class();
    sysinitclass_jlr_GenericDeclaration();
    sysinitclass_jlr_AnnotatedElement();
    sysinitclass_jlr_Type();
    sysinitclass_otr_Allocator();
    sysinitclass_otr_GC();
    sysinitclass_jl_ClassCastException();
    sysinitclass_jl_RuntimeException();
    sysinitclass_jl_Exception();
    sysinitclass_jl_Throwable();
    sysinitclass_otr_ExceptionHandling();
    sysinitclass_otr_ShadowStack();
    sysinitclass_jl_NullPointerException();
    sysinitclass_jl_ArrayIndexOutOfBoundsException();
    sysinitclass_jl_IndexOutOfBoundsException();
    sysinitclass_otr_Fiber();
    sysinitclass_otr_Fiber_startMain_lambda__38_0();
    sysinitclass_otr_Fiber_FiberRunner();
    sysinitclass_otr_EventQueue();
    sysinitclass_jl_Thread();
    sysinitclass_jl_Runnable();
    sysinitclass_jl_System();
    sysinitclass_ju_Arrays();
    sysinitclass_otr_Fiber_PlatformObjectWrapper();
    sysinitclass_otr_Fiber_PlatformFunctionWrapper();
    sysinitclass_otr_Fiber_PlatformExceptionWrapper();
    sysinitclass_otbcr_CResources();
    sysinitclass_otbcr_CResources_Resource();
    sysinitclass_Hello();
    sysinitclass_otr_MemoryTrace();
    sysinitclass_otr_Console();
    sysinitclass_otr_EventQueue_Node();
    sysinitclass_jl_Math();
    sysinitclass_jlr_Array();
    sysinitclass_juz_CRC32();
    sysinitclass_juz_Checksum();
    sysinitclass_jnc_StandardCharsets();
    sysinitclass_jl_Long();
    sysinitclass_jl_Number();
    sysinitclass_jl_StringBuilder();
    sysinitclass_jl_AbstractStringBuilder();
    sysinitclass_jl_Appendable();
    sysinitclass_jl_DefaultUncaughtExceptionHandler();
    sysinitclass_jl_Thread_UncaughtExceptionHandler();
    sysinitclass_jl_IllegalArgumentException();
    sysinitclass_jl_NegativeArraySizeException();
    sysinitclass_ju_HashMap();
    sysinitclass_ju_AbstractMap();
    sysinitclass_ju_Map();
    sysinitclass_jl_Cloneable();
    sysinitclass_cjj_CRC32();
    sysinitclass_cjj_Checksum();
    sysinitclass_jn_CharBuffer();
    sysinitclass_jn_Buffer();
    sysinitclass_jl_Readable();
    sysinitclass_jnc_Charset();
    sysinitclass_jn_ByteBuffer();
    sysinitclass_ji_PrintStream();
    sysinitclass_ji_FilterOutputStream();
    sysinitclass_ji_OutputStream();
    sysinitclass_ji_Closeable();
    sysinitclass_jl_AutoCloseable();
    sysinitclass_ji_Flushable();
    sysinitclass_otcic_StdoutOutputStream();
    sysinitclass_otcic_ConsoleOutputStream();
    sysinitclass_otci_IntegerUtil();
    sysinitclass_otr_Mutator();
    sysinitclass_jl_ArrayStoreException();
    sysinitclass_jnci_UTF8Charset();
    sysinitclass_jnci_AsciiCharset();
    sysinitclass_jnci_Iso8859Charset();
    sysinitclass_jnci_UTF16Charset();
    sysinitclass_jnc_CodingErrorAction();
    sysinitclass_jnc_CharsetEncoder();
    sysinitclass_jnc_CharacterCodingException();
    sysinitclass_ji_IOException();
    sysinitclass_jl_AssertionError();
    sysinitclass_jl_Error();
    sysinitclass_jl_String__clinit__lambda__118_0();
    sysinitclass_ju_Comparator();
    sysinitclass_jl_Character();
    sysinitclass_jn_CharBufferNative();
    sysinitclass_jn_CharBufferImpl();
    sysinitclass_jn_ArrayBufferViewProvider();
    sysinitclass_jnf_AddressBasedBuffer();
    sysinitclass_jnc_CoderResult();
    sysinitclass_ju_Objects();
    sysinitclass_otr_MarkQueue();
    sysinitclass_otbcr_Memory();
    sysinitclass_jl_StackTraceElement();
    sysinitclass_jn_ByteBufferNative();
    sysinitclass_jn_NativeBuffer();
    sysinitclass_jl_IllegalStateException();
    sysinitclass_jnc_CoderMalfunctionError();
    sysinitclass_jnc_IllegalCharsetNameException();
    sysinitclass_jl_StringIndexOutOfBoundsException();
    sysinitclass_jn_ByteOrder();
    sysinitclass_jnci_Iso8859Encoder();
    sysinitclass_jnci_BufferedEncoder();
    sysinitclass_jn_ReadOnlyBufferException();
    sysinitclass_jl_UnsupportedOperationException();
    sysinitclass_jn_BufferOverflowException();
    sysinitclass_jnc_BufferUnderflowException();
    sysinitclass_jnc_BufferOverflowException();
    sysinitclass_jnc_MalformedInputException();
    sysinitclass_jnc_UnmappableCharacterException();
    sysinitclass_ju_HashMap_HashEntry();
    sysinitclass_ju_MapEntry();
    sysinitclass_ju_Map_Entry();
    sysinitclass_jnci_BufferedEncoder_Controller();
    sysinitclass_jn_BufferUnderflowException();
    sysinitclass_jl_Integer();
    sysinitclass_jnci_UTF8Encoder();
    sysinitclass_otcic_Console();
    sysinitclass_C();
    sysinitclass_Arr_C();
    sysinitclass_I();
    sysinitclass_Arr_I();
    sysinitclass_J();
    sysinitclass_Arr_J();
    sysinitclass_F();
    sysinitclass_Arr_F();
    sysinitclass_D();
    sysinitclass_Arr_D();
    sysinitclass_V();
    sysinitclass_B();
    sysinitclass_Arr_B();
    sysinitclass_S();
    sysinitclass_Arr_S();
    teavm_afterInitClasses();
    meth_otr_GC__clinit_();
    meth_otr_Fiber__clinit_();
    meth_otr_EventQueue__clinit_();
    teavm_getClassObject((TeaVM_Class*) &V_Cls);
    teavm_getClassObject((TeaVM_Class*) &J_Cls);
    teavm_getClassObject((TeaVM_Class*) &C_Cls);
    teavm_getClassObject((TeaVM_Class*) &I_Cls);
    initclass_jl_String();
    meth_otr_Fiber_startMain(teavm_parseArguments(argc, argv));
    meth_otr_EventQueue_process();
    return 0;
}
