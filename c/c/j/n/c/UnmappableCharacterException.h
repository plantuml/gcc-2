#pragma once
#include "../../../../runtime.h"
#include "CharacterCodingException.h"
#include "UnmappableCharacterException.h"

extern void sysinitclass_jnc_UnmappableCharacterException();
typedef struct cls_jnc_UnmappableCharacterException {
    struct cls_jnc_CharacterCodingException parent;
    int32_t fld_length;
} cls_jnc_UnmappableCharacterException;
extern int32_t supertypeof_jnc_UnmappableCharacterException(TeaVM_Class*, TeaVM_Class*);
typedef struct jnc_UnmappableCharacterException_VT {
    jnc_CharacterCodingException_VT parent;
} jnc_UnmappableCharacterException_VT;
extern jnc_UnmappableCharacterException_VT jnc_UnmappableCharacterException_Cls;
