#pragma once
#include "../../../../runtime.h"
#include "../../i/IOException.h"
#include "CharacterCodingException.h"

extern void sysinitclass_jnc_CharacterCodingException();
typedef struct cls_jnc_CharacterCodingException {
    struct cls_ji_IOException parent;
} cls_jnc_CharacterCodingException;
extern int32_t supertypeof_jnc_CharacterCodingException(TeaVM_Class*, TeaVM_Class*);
typedef struct jnc_CharacterCodingException_VT {
    ji_IOException_VT parent;
} jnc_CharacterCodingException_VT;
extern jnc_CharacterCodingException_VT jnc_CharacterCodingException_Cls;
