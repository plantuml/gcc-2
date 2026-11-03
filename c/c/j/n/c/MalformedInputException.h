#pragma once
#include "../../../../runtime.h"
#include "CharacterCodingException.h"
#include "MalformedInputException.h"

extern void sysinitclass_jnc_MalformedInputException();
typedef struct cls_jnc_MalformedInputException {
    struct cls_jnc_CharacterCodingException parent;
    int32_t fld_length;
} cls_jnc_MalformedInputException;
extern int32_t supertypeof_jnc_MalformedInputException(TeaVM_Class*, TeaVM_Class*);
typedef struct jnc_MalformedInputException_VT {
    jnc_CharacterCodingException_VT parent;
} jnc_MalformedInputException_VT;
extern jnc_MalformedInputException_VT jnc_MalformedInputException_Cls;
